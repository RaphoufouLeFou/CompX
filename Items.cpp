#include <vector>

using namespace System;
using namespace System::Windows::Forms;

#pragma once
class Item {
public:

	Item(char* ref, char* name, int quantity, float unitPrice) {
		this->Ref = ref;
		this->Name = name;
		this->Quantity = quantity;
		this->UnitPrice = unitPrice;
	}

	String^ GetRef() {
		return gcnew String(Ref);
	}

	String^ GetName() {
		return gcnew String(Name);
	}

	String^ GetQuantity() {
		return Quantity.ToString();
	}

	void AddQuantity(int quantity) {
		Quantity += quantity;
	}

	String^ GetUnitPrice() {
		return UnitPrice.ToString("0.000") + " €";
	}
	char* Ref;
	char* Name;
	int Quantity;
	float UnitPrice;
};

class ItemList {
public:
	std::vector<Item> Items;
	void AddItemToList(char* ref, char* name, int quantity, float unitPrice) {

		size_t length = strlen(name);
		char* nameCpy = new char[length + 1];
		strcpy(nameCpy, name);

		length = strlen(ref);
		char* refCpy = new char[length + 1];
		strcpy(refCpy, ref);

		Item item(refCpy, nameCpy, quantity, unitPrice);
		Items.push_back(item);
	}

	void AddItemToList(Item item) {
		Items.push_back(item);
	}

	void MergeItems(ItemList list) {
		for each (Item item in list.Items) {
			Item it = GetItem(item.Ref);
			if (strcmp(it.Ref, "NOT_FOUND") == 0)
				Items.push_back(item);
			
			else 
				AddQuantity(it.Ref, item.Quantity);
					

		}
			
	}

	int RemoveItem(String^ ref) {
		for(int i = 0; i < Items.size(); i++)
			if (Items[i].GetRef() == ref) {
				Items.erase(Items.begin() + i);
				return i;
			}
		return -1;
	}

	Item GetItem(String^ ref) {
		for each (Item item in Items)
			if(item.GetRef() == ref)
				return item;			
		return Item("NOT_FOUND", "404", 404, 404);
	}

	Item GetItem(char* ref) {
		for each (Item item in Items)
			if (item.GetRef() == gcnew String(ref))
				return item;
		return Item("NOT_FOUND", "404", 404, 404);
	}

	void AddQuantity(char* ref, int quantity) {
		char* name = GetItem(ref).Name;
		int q = GetItem(ref).Quantity;
		float price = GetItem(ref).UnitPrice;
		//printf("Adding %d to %d, with a price of %f\n", quantity, q, price);
		RemoveItem(gcnew String(ref));
		AddItemToList(ref, name, q+quantity, price);
	}

	void SetProperties(char* ref, char* name, int quantity, float price) {
		RemoveItem(gcnew String(ref));
		AddItemToList(ref, name, quantity, price);
	}

	int GetSize() {
		return Items.size();
	}

	void Clear() {
		Items.clear();
	}

	void SaveItems(const char * path) {

		FILE* file = fopen(path, "w");
		if (file != nullptr) {
			for each (Item item in Items)
				fprintf(file, "%s;%s;%d;%f\n", item.Ref, item.Name, item.Quantity, item.UnitPrice);
			fclose(file);
		}
		else {
			MessageBox::Show("An error occured while saving the workspace !", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		
	}

	void LoadItems(const char * path) {
		FILE* file = fopen(path, "r");
		if (file != nullptr) {
			char ref[49];
			char name[49];
			int quantity;
			float unitPrice;
			while (fscanf(file, "%49[^;];%49[^;];%d;%f\n", ref, name, &quantity, &unitPrice) != EOF) {
				if(quantity > 0)
					AddItemToList(ref, name, quantity, unitPrice);
			}
			printf("Items loaded : %d\n", Items.size());
			fclose(file);
		}
		else {
			MessageBox::Show("An error occured while loading the workspace !", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		
	}
};

