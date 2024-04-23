#include "MainForm.h"
#include "A_R_Comps.h"
#include "BOM_Form.cpp"
#include <exception>

using namespace System;
using namespace System::Windows::Forms;

#define PERMANENT_DATA_FILE "data.txt"

ItemList items = ItemList();


[STAThreadAttribute]
void main(array<String^>^ argv)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(CompX::MainForm::Instance);

}

void CompX::MainForm::AddComponentManually(void) {
	CompX::A_R_Comps^ form = gcnew CompX::A_R_Comps();
	form->SetTitle("Add a new component");
	form->mode = 0;
	form->ShowDialog();
}

void CompX::MainForm::RemoveComponentManually(void) {
	CompX::A_R_Comps^ form = gcnew CompX::A_R_Comps();
	form->SetTitle("Remove a component");
	form->mode = 1;
	form->ShowDialog();
}

void CompX::MainForm::QuitApp(void) {
	exit(0);
}


void CompX::MainForm::OpenHelpBox(void) {
	MessageBox::Show("RTFM", "Help", MessageBoxButtons::OK, MessageBoxIcon::Information);
}

void CompX::MainForm::OpenAbout(void) {
	MessageBox::Show("Raphaël Clerault\nComX.\n©2024", "About", MessageBoxButtons::OK, MessageBoxIcon::Information);
}

void CompX::MainForm::LoadItemBOM(OpenFileDialog^ openFileDialog1) {
	//openFileDialog1->InitialDirectory = "c:\\";
	openFileDialog1->Filter = "All files (*.*)|*.*|csv files (*.csv)|*.csv";
	openFileDialog1->FilterIndex = 2;
	openFileDialog1->RestoreDirectory = true;
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		BOM_reader reader = BOM_reader();
		items.MergeItems(reader.ReadBOMFile(openFileDialog1->FileName));
		items.SaveItems(PERMANENT_DATA_FILE);
		ShowItems(false);
	}
}

void CompX::MainForm::ShowItems(bool load) {

	if(load) items.LoadItems(PERMANENT_DATA_FILE);
	//clearItems();
	AddItem(items);

}

void ShowItemHandler() {
	//CompX::MainForm::Instance->ShowItems(CompX::MainForm::Instance, false);
}

void CompX::MainForm::SaveItems(void) {
	items.SaveItems(PERMANENT_DATA_FILE);
}

int SearchHandler(String^ ref) {
	Item it = items.GetItem(ref);
	if (strcmp(it.Ref, "NOT_FOUND") == 0) {
		MessageBox::Show("Item not found", "Search result", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		return -1;
	}	
	return 0;
}



void CompX::A_R_Comps::OkButtonHandler(char* ref, char* name, int qty, float price, int mode) {

	if (mode == 3) {
		printf("searching for %s\n", ref);
		int res = SearchHandler(gcnew String(ref));
		if (res != -1) {
			printf("Item found\n");
			Item it = items.GetItem(ref);
			CompX::A_R_Comps^ form = gcnew CompX::A_R_Comps();
			form->SetItem(gcnew String(it.Ref), gcnew String(it.Name), it.Quantity, it.UnitPrice);
			form->SetTitle("Edit component");
			form->mode = 2;
			form->ShowDialog();
		}
		
	}
	else {
		Item it = items.GetItem(ref);
		if (strcmp(it.Ref, "NOT_FOUND") == 0) {
			//printf("Item not found\n");
			items.AddItemToList(ref, name, qty, price);
		}
		else {
			//printf("Item already exists\ncurrent count = %d\n", it.Quantity);
			if (mode == 0) items.AddQuantity(ref, qty);
			if (mode == 1) items.AddQuantity(ref, -qty);
			if (mode == 2) items.SetProperties(ref, name, qty, price);

			//printf("New count = %d", items.GetItem(ref).Quantity);
		}
	}
	items.SaveItems(PERMANENT_DATA_FILE);
}

void CompX::MainForm::ClickOnListItemHandler(String^ ref) {
	Item it = items.GetItem(ref);
	if (strcmp(it.Ref, "NOT_FOUND") == 0) 
		return;
	
	CompX::A_R_Comps^ form = gcnew CompX::A_R_Comps();
	form->SetItem(gcnew String(it.Ref), gcnew String(it.Name), it.Quantity, it.UnitPrice);
	form->SetTitle("Edit component");
	form->mode = 2;
	form->ShowDialog();
}

void CompX::MainForm::SearchItem() {
	CompX::A_R_Comps^ form = gcnew CompX::A_R_Comps();
	form->SetTitle("Search for a component");
	form->mode = 3;
	form->ShowDialog();
}
