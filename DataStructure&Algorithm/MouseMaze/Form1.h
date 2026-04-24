#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;

int n, x, y;
int** square;

struct dire {
	int dx, dy;
};

struct dire moving[8] = { {-2,-1} ,{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2} };
struct dire next_po[8];

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Splitter^ splitter1;
	protected:
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::CheckBox^ checkBox3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox4;

	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::CheckBox^ checkBox4;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->splitter1 = (gcnew System::Windows::Forms::Splitter());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tabControl1->SuspendLayout();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// splitter1
			// 
			this->splitter1->Location = System::Drawing::Point(0, 0);
			this->splitter1->Name = L"splitter1";
			this->splitter1->Size = System::Drawing::Size(328, 637);
			this->splitter1->TabIndex = 0;
			this->splitter1->TabStop = false;
			// 
			// tabControl1
			// 
			this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(325, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(722, 637);
			this->tabControl1->TabIndex = 1;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->dataGridView2);
			this->tabPage3->Location = System::Drawing::Point(4, 28);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(714, 605);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"color";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// dataGridView2
			// 
			this->dataGridView2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->ColumnHeadersVisible = false;
			this->dataGridView2->Location = System::Drawing::Point(0, 0);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersVisible = false;
			this->dataGridView2->RowHeadersWidth = 62;
			this->dataGridView2->RowTemplate->Height = 31;
			this->dataGridView2->Size = System::Drawing::Size(711, 605);
			this->dataGridView2->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->listBox1);
			this->tabPage1->Location = System::Drawing::Point(4, 28);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(714, 605);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"listbox";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// listBox1
			// 
			this->listBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 18;
			this->listBox1->Location = System::Drawing::Point(3, 0);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(708, 580);
			this->listBox1->TabIndex = 0;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->dataGridView1);
			this->tabPage2->Location = System::Drawing::Point(4, 28);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(714, 605);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"datagridview";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// dataGridView1
			// 
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->ColumnHeadersVisible = false;
			this->dataGridView1->Location = System::Drawing::Point(3, 0);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 62;
			this->dataGridView1->RowTemplate->Height = 31;
			this->dataGridView1->Size = System::Drawing::Size(708, 569);
			this->dataGridView1->TabIndex = 0;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->checkBox1);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->textBox3);
			this->panel1->Controls->Add(this->textBox2);
			this->panel1->Location = System::Drawing::Point(33, 111);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(230, 192);
			this->panel1->TabIndex = 2;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->checkBox1->Location = System::Drawing::Point(16, 138);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(191, 28);
			this->checkBox1->TabIndex = 5;
			this->checkBox1->Text = L"Random Position";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label4->Location = System::Drawing::Point(12, 79);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(34, 24);
			this->label4->TabIndex = 3;
			this->label4->Text = L"y=";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label3->Location = System::Drawing::Point(12, 26);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(34, 24);
			this->label3->TabIndex = 2;
			this->label3->Text = L"x=";
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox3->Location = System::Drawing::Point(53, 79);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(155, 36);
			this->textBox3->TabIndex = 1;
			this->textBox3->Text = L"0";
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox2->Location = System::Drawing::Point(53, 23);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(154, 36);
			this->textBox2->TabIndex = 0;
			this->textBox2->Text = L"0";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button1->Location = System::Drawing::Point(33, 329);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(242, 52);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Knight Tour";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox1->Location = System::Drawing::Point(85, 29);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(151, 36);
			this->textBox1->TabIndex = 3;
			this->textBox1->Text = L"10";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(45, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(34, 24);
			this->label1->TabIndex = 4;
			this->label1->Text = L"n=";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label2->Location = System::Drawing::Point(29, 84);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(132, 24);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Start Position";
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->checkBox2->Location = System::Drawing::Point(33, 387);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(88, 28);
			this->checkBox2->TabIndex = 6;
			this->checkBox2->Text = L"Trace";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(50, 421);
			this->trackBar1->Maximum = 1000;
			this->trackBar1->Minimum = 100;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(191, 69);
			this->trackBar1->TabIndex = 7;
			this->trackBar1->Value = 500;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Checked = true;
			this->checkBox3->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox3->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->checkBox3->Location = System::Drawing::Point(132, 387);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(131, 28);
			this->checkBox3->TabIndex = 8;
			this->checkBox3->Text = L"Animation";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label5->Location = System::Drawing::Point(29, 476);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(145, 24);
			this->label5->TabIndex = 9;
			this->label5->Text = L"RGB Selection";
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox4->Location = System::Drawing::Point(27, 17);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(46, 36);
			this->textBox4->TabIndex = 10;
			this->textBox4->Text = L"248";
			// 
			// textBox6
			// 
			this->textBox6->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox6->Location = System::Drawing::Point(157, 17);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(51, 36);
			this->textBox6->TabIndex = 12;
			this->textBox6->Text = L"181";
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->checkBox4);
			this->panel2->Controls->Add(this->textBox7);
			this->panel2->Controls->Add(this->textBox5);
			this->panel2->Controls->Add(this->textBox4);
			this->panel2->Controls->Add(this->textBox6);
			this->panel2->Controls->Add(this->label6);
			this->panel2->Location = System::Drawing::Point(33, 503);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(286, 120);
			this->panel2->TabIndex = 13;
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Checked = true;
			this->checkBox4->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox4->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->checkBox4->Location = System::Drawing::Point(16, 76);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(169, 28);
			this->checkBox4->TabIndex = 17;
			this->checkBox4->Text = L"Random Color";
			this->checkBox4->UseVisualStyleBackColor = true;
			// 
			// textBox7
			// 
			this->textBox7->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox7->Location = System::Drawing::Point(233, 17);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(46, 36);
			this->textBox7->TabIndex = 16;
			this->textBox7->Text = L"1";
			// 
			// textBox5
			// 
			this->textBox5->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox5->Location = System::Drawing::Point(90, 17);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(51, 36);
			this->textBox5->TabIndex = 15;
			this->textBox5->Text = L"177";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label6->Location = System::Drawing::Point(9, 20);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(218, 24);
			this->label6->TabIndex = 14;
			this->label6->Text = L"(          ,          ,          )";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1049, 637);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->splitter1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->tabControl1->ResumeLayout(false);
			this->tabPage3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->tabPage1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		int knight_tour() {
			int cnt = 0;//count howmany direction can go through
			int tx, ty;
			int speed;
			int r, g, b, change;
			r = int::Parse(textBox4->Text);
			g = int::Parse(textBox5->Text);
			b = int::Parse(textBox6->Text);
			change = int::Parse(textBox7->Text);
			dataGridView2->RowCount = n;
			dataGridView2->ColumnCount = n;
			for (int row = 0; row < n; row++) dataGridView2->Rows[row]->Height = 30;
			for (int col = 0; col < n; col++) dataGridView2->Columns[col]->Width = 30;
			dataGridView2->Rows[x]->Cells[y]->Value = square[x][y];//fill the start
			dataGridView2->Rows[x]->Cells[y]->Style->BackColor = System::Drawing::Color::FromArgb(r, g, b);

			for (int i = 2; i <= n * n; i++) {
				cnt = 0;
				for (int k = 0; k <= 7; k++) {
					tx = x + moving[k].dx;
					ty = y + moving[k].dy;
					if ((tx >= 0 && tx < n) && (ty >= 0 && ty < n) && square[tx][ty] == 0) {
						next_po[cnt].dx = tx;
						next_po[cnt].dy = ty;
						cnt++;
					}
				}

				if (cnt == 0) return 0;

				int next_move[8];
				for (int j = 0; j < 8; j++) next_move[j] = 0;
				for (int t = 0; t < cnt; t++) {
					x = next_po[t].dx;
					y = next_po[t].dy;
					for (int k = 0; k <= 7; k++) {
						tx = x + moving[k].dx;
						ty = y + moving[k].dy;
						if ((tx >= 0 && tx < n) && (ty >= 0 && ty < n) && square[tx][ty] == 0) {
							next_move[t]++;
						}

					}
				}

				int min = 0;
				for (int t = 1; t < cnt; t++) {
					if (next_move[t] < next_move[min]) min = t;
				}
				x = next_po[min].dx;
				y = next_po[min].dy;
				square[x][y] = i;
				if (checkBox2->Checked) listBox1->Items->Add("{" + x + ", " + y + ", " + square[x][y] + "}");

				//fill the cell with color
				speed = trackBar1->Value;
				dataGridView2->Rows[x]->Cells[y]->Value = square[x][y];
				dataGridView2->Rows[x]->Cells[y]->Style->BackColor = System::Drawing::Color::FromArgb(r, g, b);
				r = r - change;
				g = g - change;
				b = b - change;
				if (checkBox3->Checked) {//output with datagridview color of animation
					System::Threading::Thread::Sleep(speed);
					dataGridView2->Refresh();
				}

			}

			return 1;
		}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		srand(time(NULL));

		n = int::Parse(textBox1->Text);
		if (checkBox1->Checked) {
			textBox2->Text = (rand() % n).ToString();
			textBox3->Text = (rand() % n).ToString();
			textBox2->Refresh();
			textBox3->Refresh();
		}
		x = int::Parse(textBox2->Text);
		y = int::Parse(textBox3->Text);

		square = new int* [n];
		for (int i = 0; i < n; i++) {//initialize
			square[i] = new int[n];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				square[i][j] = 0;
			}
		}
		square[x][y] = 1;
		if (checkBox4->Checked) {//random color
			textBox4->Text = (rand() % 55 + 200).ToString();
			textBox5->Text = (rand() % 155 + 100).ToString();
			textBox6->Text = (rand() % 155 + 100).ToString();
			textBox4->Refresh();
			textBox5->Refresh();
			textBox6->Refresh();
		}

		int flag = knight_tour();
		for (int i = 0; i < n; i++) {//output in listbox
			String^ row = "";
			for (int j = 0; j < n; j++) {
				row += square[i][j].ToString() + "\t";
			}
			listBox1->Items->Add(row);
		}
		String^ str = "(x, y) = (" + textBox2->Text + ", " + textBox3->Text + ")";
		if (flag) str += " O";
		else str += " X";
		listBox1->Items->Add(str);

		dataGridView1->RowCount = n;
		dataGridView1->ColumnCount = n;
		for (int row = 0; row < n; row++) dataGridView1->Rows[row]->Height = 30;
		for (int col = 0; col < n; col++) dataGridView1->Columns[col]->Width = 30;
		for (int row = 0; row < n; row++) {//output with datagridview
			for (int col = 0; col < n; col++) {
				dataGridView1->Rows[row]->Cells[col]->Value = square[row][col];
			}
		}
		dataGridView2->Refresh();//output with colored datagridview

		for (int i = 0; i < n; i++) {//delete the array
			delete[] square[i];
		}
		delete[] square;
	}
};
}
