#include <string>
#include <stdio.h>
#include "Items.cpp"

using namespace System;
using namespace System::Windows::Forms;


class BOM_reader {
public:ItemList items = ItemList();

public:
	BOM_reader() {
	}
	
	ItemList ReadBOMFile(String^ path) {
		String^ firstLine;
		char* filePathStr = StringToChar(path);
		FILE* file = fopen(filePathStr, "r");
		if (file != nullptr) {
			char ref[49];
			char name[49];
			int quantity;
			float unitPrice;
			while (fscanf(file, "%49[^;];%49[^;];%d;%f\n", ref, name, &quantity, &unitPrice) != EOF) {
				LineHandler(ref, name, quantity, unitPrice);
			}
			fclose(file);
			return items;
		}
		else {
			MessageBox::Show("An error occured while reading the file !", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		return items;

	}
private:

	char* StringToChar(String^ str) {
		char* res = (char*)malloc(str->Length + 1);
		if (res == nullptr) {
			MessageBox::Show("An error occured while converting the string !", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		for (int i = 0; i < str->Length; i++) {
			res[i] = (char)str[i];
		}
		res[str->Length] = '\0';
		return res;
	}


	void LineHandler(char* ref, char* name, int qty, float price) {
		size_t length = strlen(name);
		char* nameCpy = new char[length + 1];
		strcpy(nameCpy, name);
		
		length = strlen(ref);
		char* refCpy = new char[length + 1];
		strcpy(refCpy, ref);

		Item it = Item(refCpy, nameCpy, qty, price);

		items.AddItemToList(it);
		//printf("%s;%s;%d;%f\n", ref, name, qty, price);
	}
};