#pragma once
#include "Items.cpp"

namespace CompX {



	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

		
	/// <summary>
	/// Description résumée de MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
		void OpenHelpBox(void);
		void OpenAbout(void);
		void LoadItemBOM(System::Windows::Forms::OpenFileDialog^);
		void QuitApp(void);
		void ShowItems(bool load);
		void SaveItems(void);
		void AddComponentManually(void);
		void RemoveComponentManually(void);
		void ClickOnListItemHandler(String^ ref);
		void SearchItem(void);



	private: System::Windows::Forms::ToolStripMenuItem^ searchToolStripMenuItem;
	private: static MainForm^ instance = nullptr;


	public:
		System::Drawing::Font^ font = gcnew System::Drawing::Font("Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0));

		MainForm(void)
		{
			InitializeComponent();

		}

		static property MainForm^ Instance {
			MainForm^ get() {
				if (instance == nullptr) {
					instance = gcnew MainForm();
				}
				return instance;
			}
		}

		void AddTitles(void) {
			flowLayoutPanel1->Controls->Add(tableLayoutPanel1);
		}

		void AddItem(ItemList items) {

			printf("Adding items\n");

			flowLayoutPanel1->Controls->Clear();

			AddTitles();

			array<TableLayoutPanel^>^ tableLayoutPanels = gcnew array<TableLayoutPanel^>(items.GetSize());
			for (int j = 0; j < items.GetSize(); j++) {

				tableLayoutPanels[j] = gcnew TableLayoutPanel();
				tableLayoutPanels[j]->RowCount = 1;
				tableLayoutPanels[j]->ColumnCount = 4;
				tableLayoutPanels[j]->Anchor = AnchorStyles::Left | AnchorStyles::Top | AnchorStyles::Right | AnchorStyles::Bottom;
				tableLayoutPanels[j]->Dock = DockStyle::Fill;
				tableLayoutPanels[j]->CellBorderStyle = TableLayoutPanelCellBorderStyle::Single;
				tableLayoutPanels[j]->AutoSize = true;
				tableLayoutPanels[j]->Margin = System::Windows::Forms::Padding(3, 0, 3, 0);
				tableLayoutPanels[j]->Size.Height = 28;
				tableLayoutPanels[j]->Name = items.Items[j].GetRef();


				array<Label^>^ labels = { gcnew Label(), gcnew Label(), gcnew Label(), gcnew Label() };

				for (int i = 0; i < tableLayoutPanels[j]->ColumnCount; i++)
				{
					tableLayoutPanels[j]->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 25));
					labels[i]->Dock = DockStyle::Fill;
					labels[i]->TextAlign = ContentAlignment::MiddleCenter;
					labels[i]->Click += gcnew System::EventHandler(this, &MainForm::ClickOnListItem);
					labels[i]->Font = font;
					switch (i) {
					case 0:labels[i]->Text = items.Items[j].GetRef(); break;
					case 1:labels[i]->Text = items.Items[j].GetName(); break;
					case 2:labels[i]->Text = items.Items[j].GetQuantity(); break;
					case 3:labels[i]->Text = items.Items[j].GetUnitPrice(); break;
					}
					
					tableLayoutPanels[j]->Controls->Add(labels[i], i, 0);

				}
			}
			// Add the TableLayoutPanel to the FlowLayoutPanel
			
			flowLayoutPanel1->Controls->AddRange(tableLayoutPanels);
			printf("Items added !\n");
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ addComponentsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ removeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ removeComponentsToolStripMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^ helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ helpToolStripMenuItem1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ folderToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ settingsToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ quitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator1;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator2;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Label^ NameLabel;
	private: System::Windows::Forms::Label^ QtyLabel;
	private: System::Windows::Forms::Label^ PriceLabel;



	private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::ToolStripMenuItem^ addComponentManuallyToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ removeComponentsManuallyToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ addToolStripMenuItem;

			
	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addComponentsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addComponentManuallyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->removeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->removeComponentsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->removeComponentsManuallyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->searchToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->folderToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->settingsToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->quitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->QtyLabel = (gcnew System::Windows::Forms::Label());
			this->PriceLabel = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->NameLabel = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->fileToolStripMenuItem,
					this->folderToolStripMenuItem, this->helpToolStripMenuItem, this->quitToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
			this->menuStrip1->Size = System::Drawing::Size(831, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			this->menuStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &MainForm::menuStrip1_ItemClicked);
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->addToolStripMenuItem,
					this->removeToolStripMenuItem, this->toolStripSeparator1, this->saveToolStripMenuItem, this->searchToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			this->fileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::fileToolStripMenuItem_Click);
			// 
			// addToolStripMenuItem
			// 
			this->addToolStripMenuItem->BackColor = System::Drawing::SystemColors::Control;
			this->addToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->addToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->addComponentsToolStripMenuItem,
					this->addComponentManuallyToolStripMenuItem
			});
			this->addToolStripMenuItem->Name = L"addToolStripMenuItem";
			this->addToolStripMenuItem->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->addToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::A));
			this->addToolStripMenuItem->ShowShortcutKeys = false;
			this->addToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->addToolStripMenuItem->Text = L"Add";
			// 
			// addComponentsToolStripMenuItem
			// 
			this->addComponentsToolStripMenuItem->Name = L"addComponentsToolStripMenuItem";
			this->addComponentsToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift)
				| System::Windows::Forms::Keys::A));
			this->addComponentsToolStripMenuItem->Size = System::Drawing::Size(297, 22);
			this->addComponentsToolStripMenuItem->Text = L"Add Components from BOM";
			this->addComponentsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::addComponentsToolStripMenuItem_Click);
			// 
			// addComponentManuallyToolStripMenuItem
			// 
			this->addComponentManuallyToolStripMenuItem->Name = L"addComponentManuallyToolStripMenuItem";
			this->addComponentManuallyToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Alt)
				| System::Windows::Forms::Keys::A));
			this->addComponentManuallyToolStripMenuItem->Size = System::Drawing::Size(297, 22);
			this->addComponentManuallyToolStripMenuItem->Text = L"Add Component manually";
			this->addComponentManuallyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::addComponentManuallyToolStripMenuItem_Click);
			// 
			// removeToolStripMenuItem
			// 
			this->removeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->removeComponentsToolStripMenuItem,
					this->removeComponentsManuallyToolStripMenuItem
			});
			this->removeToolStripMenuItem->Name = L"removeToolStripMenuItem";
			this->removeToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::R));
			this->removeToolStripMenuItem->ShowShortcutKeys = false;
			this->removeToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->removeToolStripMenuItem->Text = L"Remove";
			// 
			// removeComponentsToolStripMenuItem
			// 
			this->removeComponentsToolStripMenuItem->Name = L"removeComponentsToolStripMenuItem";
			this->removeComponentsToolStripMenuItem->Size = System::Drawing::Size(248, 22);
			this->removeComponentsToolStripMenuItem->Text = L"Remove Components from BOM";
			// 
			// removeComponentsManuallyToolStripMenuItem
			// 
			this->removeComponentsManuallyToolStripMenuItem->Name = L"removeComponentsManuallyToolStripMenuItem";
			this->removeComponentsManuallyToolStripMenuItem->Size = System::Drawing::Size(248, 22);
			this->removeComponentsManuallyToolStripMenuItem->Text = L"Remove Components manually";
			this->removeComponentsManuallyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::removeComponentsManuallyToolStripMenuItem_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(177, 6);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->saveToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::saveToolStripMenuItem_Click);
			// 
			// searchToolStripMenuItem
			// 
			this->searchToolStripMenuItem->Name = L"searchToolStripMenuItem";
			this->searchToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::F));
			this->searchToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->searchToolStripMenuItem->Text = L"Search";
			this->searchToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::searchToolStripMenuItem_Click);
			// 
			// folderToolStripMenuItem
			// 
			this->folderToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->settingsToolStripMenuItem1 });
			this->folderToolStripMenuItem->Name = L"folderToolStripMenuItem";
			this->folderToolStripMenuItem->Size = System::Drawing::Size(39, 20);
			this->folderToolStripMenuItem->Text = L"Edit";
			// 
			// settingsToolStripMenuItem1
			// 
			this->settingsToolStripMenuItem1->Name = L"settingsToolStripMenuItem1";
			this->settingsToolStripMenuItem1->Size = System::Drawing::Size(116, 22);
			this->settingsToolStripMenuItem1->Text = L"Settings";
			this->settingsToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainForm::settingsToolStripMenuItem1_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->helpToolStripMenuItem1,
					this->toolStripSeparator2, this->aboutToolStripMenuItem
			});
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// helpToolStripMenuItem1
			// 
			this->helpToolStripMenuItem1->Name = L"helpToolStripMenuItem1";
			this->helpToolStripMenuItem1->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::H));
			this->helpToolStripMenuItem1->Size = System::Drawing::Size(142, 22);
			this->helpToolStripMenuItem1->Text = L"Help";
			this->helpToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainForm::helpToolStripMenuItem1_Click);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(139, 6);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(142, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::aboutToolStripMenuItem_Click);
			// 
			// quitToolStripMenuItem
			// 
			this->quitToolStripMenuItem->Name = L"quitToolStripMenuItem";
			this->quitToolStripMenuItem->Size = System::Drawing::Size(42, 20);
			this->quitToolStripMenuItem->Text = L"Quit";
			this->quitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::quitToolStripMenuItem_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MainForm::openFileDialog1_FileOk);
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->AutoScroll = true;
			this->flowLayoutPanel1->Controls->Add(this->tableLayoutPanel1);
			this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel1->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->flowLayoutPanel1->Location = System::Drawing::Point(0, 24);
			this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(0);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(831, 511);
			this->flowLayoutPanel1->TabIndex = 0;
			this->flowLayoutPanel1->WrapContents = false;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->AutoSize = true;
			this->tableLayoutPanel1->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->tableLayoutPanel1->ColumnCount = 4;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel1->Controls->Add(this->QtyLabel, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->PriceLabel, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->NameLabel, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 29)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(685, 30);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// QtyLabel
			// 
			this->QtyLabel->AutoSize = true;
			this->QtyLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->QtyLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->QtyLabel->Location = System::Drawing::Point(346, 1);
			this->QtyLabel->Name = L"QtyLabel";
			this->QtyLabel->Size = System::Drawing::Size(164, 28);
			this->QtyLabel->TabIndex = 3;
			this->QtyLabel->Text = L"Quantity";
			this->QtyLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// PriceLabel
			// 
			this->PriceLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PriceLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PriceLabel->Location = System::Drawing::Point(517, 1);
			this->PriceLabel->Name = L"PriceLabel";
			this->PriceLabel->Size = System::Drawing::Size(164, 28);
			this->PriceLabel->TabIndex = 2;
			this->PriceLabel->Text = L"Unit price";
			this->PriceLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(4, 1);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(164, 28);
			this->label1->TabIndex = 1;
			this->label1->Text = L"LCSC reference";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// NameLabel
			// 
			this->NameLabel->AutoSize = true;
			this->NameLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->NameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NameLabel->Location = System::Drawing::Point(175, 1);
			this->NameLabel->Name = L"NameLabel";
			this->NameLabel->Size = System::Drawing::Size(164, 28);
			this->NameLabel->TabIndex = 0;
			this->NameLabel->Text = L"Part name";
			this->NameLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(831, 535);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainForm";
			this->Text = L"CompX";
			this->Activated += gcnew System::EventHandler(this, &MainForm::MainForm_Enter);
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->Resize += gcnew System::EventHandler(this, &MainForm::MainForm_Resize);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion 
	private: System::Void addComponentsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		LoadItemBOM(this->openFileDialog1);
	}
	private: System::Void helpToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenHelpBox();
	}
	private: System::Void menuStrip1_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e) {
		
	}
	private: System::Void fileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void aboutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenAbout();
	}
	private: System::Void quitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {


		if (MessageBox::Show("Remeber to save before quiting !", "Quit", MessageBoxButtons::OKCancel, MessageBoxIcon::Exclamation) == System::Windows::Forms::DialogResult::OK) {
			QuitApp();
		}
	}
	private: System::Void openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
		
	}
	private: void resize(){
		flowLayoutPanel1->SuspendLayout();
		int newWidth = (this->Width - 27) >> 2;
		for (int i = 0; i < 4; i++) {
			this->tableLayoutPanel1->ColumnStyles[i]->Width = newWidth;
		}
		flowLayoutPanel1->ResumeLayout();
		
	}
	private: System::Void MainForm_Resize(System::Object^ sender, System::EventArgs^ e) {
		resize();
	}
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
		flowLayoutPanel1->SuspendLayout();
		for (int i = 0; i < 4; i++) {
			this->tableLayoutPanel1->ColumnStyles[i] = gcnew ColumnStyle(SizeType::Absolute, (this->Width - 27) >> 2);
		}
		DoubleBuffered = true;
		
		ShowItems(true);
		flowLayoutPanel1->ResumeLayout();
		//printf("loaded\n");
	}

	private: System::Void saveToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		SaveItems();
	}
	private: System::Void addComponentManuallyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		AddComponentManually();
	}
	private: System::Void MainForm_Enter(System::Object^ sender, System::EventArgs^ e) {
		flowLayoutPanel1->SuspendLayout();
		ShowItems(false);
		flowLayoutPanel1->ResumeLayout();
		//printf("Refreshing...\n");
	}
	private: System::Void ClickOnListItem(System::Object^ sender, System::EventArgs^ e) {
		
		ClickOnListItemHandler(((Label^)sender)->Parent->Name);
	}
	private: System::Void removeComponentsManuallyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		RemoveComponentManually();
	}

	private: System::Void settingsToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Settings are not implemented yet", "Settings", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	}

	private: System::Void searchToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		SearchItem();
	}
};
}
