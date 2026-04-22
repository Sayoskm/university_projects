#pragma once
#include <time.h>
# include <stdlib.h>
#include <iostream>
using namespace std;

int x, n, k, poly;
long long arr[100000000],newarr[100000000];



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

	protected:

	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::CheckBox^ checkBox3;
	private: System::Windows::Forms::CheckBox^ checkBox4;
	private: System::Windows::Forms::Panel^ panel1;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::CheckBox^ checkBox5;
	private: System::Windows::Forms::CheckBox^ checkBox7;
	private: System::Windows::Forms::ListBox^ listBox2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;




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
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox7 = (gcnew System::Windows::Forms::CheckBox());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(545, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(661, 492);
			this->tabControl1->TabIndex = 2;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->listBox1);
			this->tabPage1->Location = System::Drawing::Point(4, 28);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(653, 460);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"tabPage1";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// listBox1
			// 
			this->listBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 18;
			this->listBox1->Location = System::Drawing::Point(1, 3);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(805, 472);
			this->listBox1->TabIndex = 0;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->listBox2);
			this->tabPage2->Location = System::Drawing::Point(4, 28);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(653, 460);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"tabPage2";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->HorizontalScrollbar = true;
			this->listBox2->ItemHeight = 18;
			this->listBox2->Location = System::Drawing::Point(3, 0);
			this->listBox2->Name = L"listBox2";
			this->listBox2->ScrollAlwaysVisible = true;
			this->listBox2->Size = System::Drawing::Size(650, 454);
			this->listBox2->TabIndex = 16;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(99, 41);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(132, 29);
			this->textBox1->TabIndex = 3;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(99, 92);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(132, 29);
			this->textBox2->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(12, 40);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(43, 30);
			this->label1->TabIndex = 5;
			this->label1->Text = L"x=";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label2->Location = System::Drawing::Point(12, 92);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 30);
			this->label2->TabIndex = 6;
			this->label2->Text = L"n=";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button1->Location = System::Drawing::Point(12, 18);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(214, 60);
			this->button1->TabIndex = 7;
			this->button1->Text = L"exponation";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label3->Location = System::Drawing::Point(280, 41);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(153, 30);
			this->label3->TabIndex = 8;
			this->label3->Text = L"do \? times =";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(314, 74);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(185, 29);
			this->textBox3->TabIndex = 9;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->checkBox1->Location = System::Drawing::Point(27, 147);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(161, 34);
			this->checkBox1->TabIndex = 10;
			this->checkBox1->Text = L"pow( x , n )";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Checked = true;
			this->checkBox2->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox2->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->checkBox2->Location = System::Drawing::Point(27, 187);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(128, 34);
			this->checkBox2->TabIndex = 11;
			this->checkBox2->Text = L"for loop";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Checked = true;
			this->checkBox3->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox3->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->checkBox3->Location = System::Drawing::Point(27, 227);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(116, 34);
			this->checkBox3->TabIndex = 12;
			this->checkBox3->Text = L"square";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Checked = true;
			this->checkBox4->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox4->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->checkBox4->Location = System::Drawing::Point(27, 262);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(169, 34);
			this->checkBox4->TabIndex = 13;
			this->checkBox4->Text = L"square _>>";
			this->checkBox4->UseVisualStyleBackColor = true;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->checkBox1);
			this->panel1->Controls->Add(this->checkBox4);
			this->panel1->Controls->Add(this->checkBox2);
			this->panel1->Controls->Add(this->checkBox3);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Location = System::Drawing::Point(17, 168);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(240, 340);
			this->panel1->TabIndex = 14;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label4->Location = System::Drawing::Point(22, 100);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(166, 30);
			this->label4->TabIndex = 16;
			this->label4->Text = L"compute x^n";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button2->Location = System::Drawing::Point(14, 14);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(214, 60);
			this->button2->TabIndex = 15;
			this->button2->Text = L"polynomial";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->checkBox5);
			this->panel2->Controls->Add(this->button2);
			this->panel2->Controls->Add(this->checkBox7);
			this->panel2->Location = System::Drawing::Point(285, 168);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(240, 335);
			this->panel2->TabIndex = 15;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label5->Location = System::Drawing::Point(15, 91);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(213, 90);
			this->label5->TabIndex = 17;
			this->label5->Text = L"compute f(0)~f(x)\r\nf(k)=a[0]k+...\r\n          ...+a[n]k^n";
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->Checked = true;
			this->checkBox5->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox5->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->checkBox5->Location = System::Drawing::Point(29, 209);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(128, 34);
			this->checkBox5->TabIndex = 10;
			this->checkBox5->Text = L"for loop";
			this->checkBox5->UseVisualStyleBackColor = true;
			// 
			// checkBox7
			// 
			this->checkBox7->AutoSize = true;
			this->checkBox7->Checked = true;
			this->checkBox7->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox7->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->checkBox7->Location = System::Drawing::Point(29, 249);
			this->checkBox7->Name = L"checkBox7";
			this->checkBox7->Size = System::Drawing::Size(176, 34);
			this->checkBox7->TabIndex = 11;
			this->checkBox7->Text = L"Hornor Rule";
			this->checkBox7->UseVisualStyleBackColor = true;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1206, 520);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->tabControl1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void gn_arr() {
			for (int i = 0; i <= n; i++) {
				arr[i] = rand() % 1000000;
			}
		}

#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		x = long::Parse(textBox1->Text);
		n = long::Parse(textBox2->Text);
		k = long::Parse(textBox3->Text);
		listBox1->Items->Clear();
		long long ans ;
		if (checkBox1->Checked) {
			clock_t start = clock();
			for (int j = 0; j < k; j++) {
				ans = x;
				ans = pow(ans, n);
			}
			clock_t end = clock();
			double CPUTime =(double) (end - start) / CLOCKS_PER_SEC;
			listBox1->Items->Add(" x ^ n = "+ans+" for "+ k+"times use "+CPUTime+"sec. by pow(x,n)");
		}
		if (checkBox2->Checked) {
			clock_t start = clock();
			for (int j = 0; j < k; j++) {
				ans = 1;
				for (int i = 0; i < n; i++) ans *= x;
			}
			clock_t end = clock();
			double CPUTime = (double) (end - start) / CLOCKS_PER_SEC;
			listBox1->Items->Add(" x ^ n = " + ans + " for " + k + "times use " + CPUTime + "sec. by for-loop");
		}
		if (checkBox3->Checked) {
			clock_t start = clock();
			for (int j = 0; j < k; j++) {
				long long tmpx = x, tmpn = n;
				ans = 1;
				while (tmpn > 0) {
					if (tmpn % 2 == 1) {
						ans *= tmpx;
					}
					tmpx *= tmpx; // Square x
					tmpn /= 2; // Divide n by 2
				}
			}
			clock_t end = clock();
			double CPUTime = (double) (end - start) / CLOCKS_PER_SEC;
			listBox1->Items->Add(" x ^ n = " + ans + " for " + k + "times use " + CPUTime + "sec. by square");
		}
		if (checkBox4->Checked) {
			clock_t start = clock();
			for (int j = 0; j < k; j++) {
				long long tmpx = x, tmpn = n;
				ans = 1;
				while (tmpn > 0) {
					if (tmpn % 2 == 1) {
						ans *= tmpx;
					}
					tmpx *= tmpx; // Square x
					tmpn = tmpn >> 1; // Divide n by 2
				}
			}
			clock_t end = clock();
			double CPUTime = (double) (end - start) / CLOCKS_PER_SEC;
			listBox1->Items->Add(" x ^ n = " + ans + " for " + k + "times use " + CPUTime + "sec. by square_>>");
		}

	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		x = long::Parse(textBox1->Text);
		n = long::Parse(textBox2->Text);
		k = long::Parse(textBox3->Text);//do ? time
		listBox2->Items->Clear();
		Int64 ans;
		gn_arr();
		if (checkBox5->Checked) {
			listBox2->Items->Add("the coeficient array is :");
			String^ str = "";
			for (int i = 0; i <= n; i++) {
				if (i != n) str += (arr[i].ToString() + "+");
				else str += (arr[i].ToString());
			}
			listBox2->Items->Add(str);
			clock_t start = clock();
			for (int j = 0; j < k; j++) {
				for (int num = 0; num <= x; num++) {
					for (int i = 0; i <= n; i++) newarr[i] = arr[i];
					ans = 0;
					for (long t = 0; t < n; t++) {
						for (long i = 0; i < n - t; i++) {
							newarr[t] *= num;
						}
						ans += newarr[t];
					}
					ans += newarr[n];
					if (!j) listBox2->Items->Add("f(" + num + ") is :"+ans);
				}
			}
			clock_t end = clock();
			double CPUTime = (double)(end - start) / CLOCKS_PER_SEC;
			listBox2->Items->Add("calculate for " + k + "times use " + CPUTime + "sec. by naive method");
		}
		if (checkBox7->Checked) {
			listBox2->Items->Add("the coeficient array is :");
			String^ str = "";
			for (int i = 0; i <= n; i++) {
				if (i != n) str += (arr[i].ToString() + "+");
				else str += (arr[i].ToString());
			}
			listBox2->Items->Add(str);
			clock_t start = clock();
			for (int j = 0; j < k; j++) {
				for (int num = 0; num <= x; num++) {
					for (int i = 0; i <= n; i++) newarr[i] = arr[i];
					ans = newarr[0];
					for (int i = 1; i <= n; i++) {
						ans = ans * num+newarr[i];
					}
					if (!j) listBox2->Items->Add("f(" + num + ") is :" + ans);
				}
			}
			clock_t end = clock();
			double CPUTime = (double)(end - start) / CLOCKS_PER_SEC;
			listBox2->Items->Add("calculate for " + k + "times use " + CPUTime + "sec. by Horner's method");
		}
	}
private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
	srand(time(NULL));
}
};
}
