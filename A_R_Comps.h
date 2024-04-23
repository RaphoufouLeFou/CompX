#pragma once

namespace CompX {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Description résumée de A_R_Comps
	/// </summary>
	public ref class A_R_Comps : public System::Windows::Forms::Form
	{
		void OkButtonHandler(char* ref, char* name, int qty, float price, int mode);

	public:
		A_R_Comps(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

		void SetItem(String^ ref, String^ name, int qty, float price) {
			this->textBoxRef->Text = ref;
			this->textBoxName->Text = name;
			this->textBoxQty->Text = qty.ToString();
			this->textBoxPrice->Text = price.ToString();
		}

		void SetTitle(String^ title) {
			this->label5->Text = title;
		}

		int mode = 0;

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~A_R_Comps()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ OkButton;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::Label^ labelRef;
	private: System::Windows::Forms::Label^ labelName;
	private: System::Windows::Forms::Label^ labelQty;
	private: System::Windows::Forms::Label^ labelPrice;




	private: System::Windows::Forms::TextBox^ textBoxRef;
	private: System::Windows::Forms::TextBox^ textBoxPrice;


	private: System::Windows::Forms::TextBox^ textBoxQty;

	private: System::Windows::Forms::TextBox^ textBoxName;

	private: System::Windows::Forms::Label^ label5;




	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(A_R_Comps::typeid));
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->OkButton = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->textBoxPrice = (gcnew System::Windows::Forms::TextBox());
			this->textBoxQty = (gcnew System::Windows::Forms::TextBox());
			this->textBoxName = (gcnew System::Windows::Forms::TextBox());
			this->labelRef = (gcnew System::Windows::Forms::Label());
			this->labelName = (gcnew System::Windows::Forms::Label());
			this->labelQty = (gcnew System::Windows::Forms::Label());
			this->labelPrice = (gcnew System::Windows::Forms::Label());
			this->textBoxRef = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->OkButton, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->button2, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->label5, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 47)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 78)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 22)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(519, 249);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// OkButton
			// 
			this->OkButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->OkButton->Location = System::Drawing::Point(174, 215);
			this->OkButton->Margin = System::Windows::Forms::Padding(3, 3, 10, 10);
			this->OkButton->Name = L"OkButton";
			this->OkButton->Size = System::Drawing::Size(75, 23);
			this->OkButton->TabIndex = 0;
			this->OkButton->Text = L"Ok";
			this->OkButton->UseVisualStyleBackColor = true;
			this->OkButton->Click += gcnew System::EventHandler(this, &A_R_Comps::OkButton_Click);
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button2->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button2->Location = System::Drawing::Point(270, 215);
			this->button2->Margin = System::Windows::Forms::Padding(10, 3, 3, 10);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Cancel";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel2->ColumnCount = 3;
			this->tableLayoutPanel1->SetColumnSpan(this->tableLayoutPanel2, 2);
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				60)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel2->Controls->Add(this->textBoxPrice, 1, 3);
			this->tableLayoutPanel2->Controls->Add(this->textBoxQty, 1, 2);
			this->tableLayoutPanel2->Controls->Add(this->textBoxName, 1, 1);
			this->tableLayoutPanel2->Controls->Add(this->labelRef, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->labelName, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->labelQty, 0, 2);
			this->tableLayoutPanel2->Controls->Add(this->labelPrice, 0, 3);
			this->tableLayoutPanel2->Controls->Add(this->textBoxRef, 1, 0);
			this->tableLayoutPanel2->Location = System::Drawing::Point(1, 49);
			this->tableLayoutPanel2->Margin = System::Windows::Forms::Padding(0);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 4;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(517, 154);
			this->tableLayoutPanel2->TabIndex = 2;
			// 
			// textBoxPrice
			// 
			this->textBoxPrice->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->textBoxPrice->Location = System::Drawing::Point(106, 124);
			this->textBoxPrice->Name = L"textBoxPrice";
			this->textBoxPrice->Size = System::Drawing::Size(304, 20);
			this->textBoxPrice->TabIndex = 7;
			// 
			// textBoxQty
			// 
			this->textBoxQty->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->textBoxQty->Location = System::Drawing::Point(106, 85);
			this->textBoxQty->Name = L"textBoxQty";
			this->textBoxQty->Size = System::Drawing::Size(304, 20);
			this->textBoxQty->TabIndex = 6;
			// 
			// textBoxName
			// 
			this->textBoxName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->textBoxName->Location = System::Drawing::Point(106, 47);
			this->textBoxName->Name = L"textBoxName";
			this->textBoxName->Size = System::Drawing::Size(304, 20);
			this->textBoxName->TabIndex = 5;
			// 
			// labelRef
			// 
			this->labelRef->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->labelRef->AutoSize = true;
			this->labelRef->Location = System::Drawing::Point(70, 12);
			this->labelRef->Name = L"labelRef";
			this->labelRef->Size = System::Drawing::Size(30, 13);
			this->labelRef->TabIndex = 1;
			this->labelRef->Text = L"Ref :";
			// 
			// labelName
			// 
			this->labelName->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->labelName->AutoSize = true;
			this->labelName->Location = System::Drawing::Point(59, 50);
			this->labelName->Name = L"labelName";
			this->labelName->Size = System::Drawing::Size(41, 13);
			this->labelName->TabIndex = 0;
			this->labelName->Text = L"Name :";
			// 
			// labelQty
			// 
			this->labelQty->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->labelQty->AutoSize = true;
			this->labelQty->Location = System::Drawing::Point(48, 88);
			this->labelQty->Name = L"labelQty";
			this->labelQty->Size = System::Drawing::Size(52, 13);
			this->labelQty->TabIndex = 2;
			this->labelQty->Text = L"Quantity :";
			// 
			// labelPrice
			// 
			this->labelPrice->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->labelPrice->AutoSize = true;
			this->labelPrice->Location = System::Drawing::Point(42, 127);
			this->labelPrice->Name = L"labelPrice";
			this->labelPrice->Size = System::Drawing::Size(58, 13);
			this->labelPrice->TabIndex = 3;
			this->labelPrice->Text = L"Unit price :";
			// 
			// textBoxRef
			// 
			this->textBoxRef->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->textBoxRef->Location = System::Drawing::Point(106, 9);
			this->textBoxRef->Name = L"textBoxRef";
			this->textBoxRef->Size = System::Drawing::Size(304, 20);
			this->textBoxRef->TabIndex = 4;
			// 
			// label5
			// 
			this->label5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label5->AutoSize = true;
			this->tableLayoutPanel1->SetColumnSpan(this->label5, 2);
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(4, 1);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(511, 47);
			this->label5->TabIndex = 3;
			this->label5->Text = L"Add component manually";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// A_R_Comps
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->button2;
			this->ClientSize = System::Drawing::Size(519, 249);
			this->Controls->Add(this->tableLayoutPanel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"A_R_Comps";
			this->Text = L"A_R_Comps";
			this->Load += gcnew System::EventHandler(this, &A_R_Comps::A_R_Comps_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void OkButton_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ ref = this->textBoxRef->Text;
		String^ name = this->textBoxName->Text;

		char* refChr = (char*)(void*)Marshal::StringToHGlobalAnsi(ref);
		char* nameChr = (char*)(void*)Marshal::StringToHGlobalAnsi(name);

		String^ qtyStr = this->textBoxQty->Text;
		if (qtyStr->Length == 0) qtyStr = "0";
		int qty = Int32::Parse(qtyStr);

		String^ priceStr = this->textBoxPrice->Text;
		priceStr = priceStr->Replace('.', ',');
		if(priceStr->Length == 0) priceStr = "0";
		float price = (float)(Convert::ToDouble(priceStr));

		OkButtonHandler(refChr, nameChr, qty, price, mode);
		this->Close();
	}
	private: System::Void A_R_Comps_Load(System::Object^ sender, System::EventArgs^ e) {
		if (mode == 1) {
			this->textBoxPrice->Enabled = false;
			this->labelPrice->Enabled = false;
			this->textBoxName->Enabled = false;
			this->labelName->Enabled = false;
		}
		if (mode == 3) {
			this->textBoxPrice->Enabled = false;
			this->labelPrice->Enabled = false;
			this->textBoxQty->Enabled = false;
			this->labelQty->Enabled = false;
			this->textBoxName->Enabled = false;
			this->labelName->Enabled = false;
		}
	}
};
}
