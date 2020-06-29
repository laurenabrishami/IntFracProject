#pragma once
#include <string>
#include <msclr\marshal_cppstd.h>
#include <iostream>
#include "ProcessInput.h"

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	
	string UserInput;


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ input_list;
	private: System::Windows::Forms::TextBox^ sorted_list;
	private: System::Windows::Forms::Button^ sort_button;



	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::CheckBox^ ascending_button;
	private: System::Windows::Forms::CheckBox^ descending_button;
	private: System::Windows::Forms::CheckBox^ int_button;
	private: System::Windows::Forms::CheckBox^ fracButton;




	protected:

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->input_list = (gcnew System::Windows::Forms::TextBox());
			this->sorted_list = (gcnew System::Windows::Forms::TextBox());
			this->sort_button = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->ascending_button = (gcnew System::Windows::Forms::CheckBox());
			this->descending_button = (gcnew System::Windows::Forms::CheckBox());
			this->int_button = (gcnew System::Windows::Forms::CheckBox());
			this->fracButton = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(24, 41);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(109, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Original List:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(24, 70);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(102, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Sorted List:";
			// 
			// input_list
			// 
			this->input_list->Location = System::Drawing::Point(139, 43);
			this->input_list->Name = L"input_list";
			this->input_list->Size = System::Drawing::Size(300, 20);
			this->input_list->TabIndex = 2;
			//this->input_list->TextChanged += gcnew System::EventHandler(this, &MyForm::input_list_TextChanged);
			// 
			// sorted_list
			// 
			this->sorted_list->Location = System::Drawing::Point(139, 70);
			this->sorted_list->Name = L"sorted_list";
			this->sorted_list->Size = System::Drawing::Size(300, 20);
			this->sorted_list->TabIndex = 3;
			// 
			// sort_button
			// 
			this->sort_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sort_button->Location = System::Drawing::Point(206, 116);
			this->sort_button->Name = L"sort_button";
			this->sort_button->Size = System::Drawing::Size(75, 23);
			this->sort_button->TabIndex = 4;
			this->sort_button->Text = L"Sort";
			this->sort_button->UseVisualStyleBackColor = true;
			this->sort_button->Click += gcnew System::EventHandler(this, &MyForm::sort_button_Click);
			
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(12, 159);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(83, 16);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Sort Order:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(357, 162);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(109, 16);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Numeric Type:";
			// 
			// ascending_button
			// 
			this->ascending_button->AutoSize = true;
			this->ascending_button->Location = System::Drawing::Point(15, 188);
			this->ascending_button->Name = L"ascending_button";
			this->ascending_button->Size = System::Drawing::Size(75, 17);
			this->ascending_button->TabIndex = 7;
			this->ascending_button->TabStop = true;
			this->ascending_button->Text = L"Ascending";
			this->ascending_button->UseVisualStyleBackColor = true;
			
			this->descending_button->AutoSize = true;
			this->descending_button->Location = System::Drawing::Point(15, 211);
			this->descending_button->Name = L"descending_button";
			this->descending_button->Size = System::Drawing::Size(82, 17);
			this->descending_button->TabIndex = 8;
			this->descending_button->TabStop = true;
			this->descending_button->Text = L"Descending";
			this->descending_button->UseVisualStyleBackColor = true;
			
			this->int_button->AutoSize = true;
			this->int_button->Location = System::Drawing::Point(360, 188);
			this->int_button->Name = L"int_button";
			this->int_button->Size = System::Drawing::Size(58, 17);
			this->int_button->TabIndex = 9;
			this->int_button->TabStop = true;
			this->int_button->Text = L"Integer";
			this->int_button->UseVisualStyleBackColor = true;
			// 
			// fracButton
			// 
			this->fracButton->AutoSize = true;
			this->fracButton->Location = System::Drawing::Point(360, 211);
			this->fracButton->Name = L"fracButton";
			this->fracButton->Size = System::Drawing::Size(63, 17);
			this->fracButton->TabIndex = 10;
			this->fracButton->TabStop = true;
			this->fracButton->Text = L"Fraction";
			this->fracButton->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(523, 262);
			this->Controls->Add(this->fracButton);
			this->Controls->Add(this->int_button);
			this->Controls->Add(this->descending_button);
			this->Controls->Add(this->ascending_button);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->sort_button);
			this->Controls->Add(this->sorted_list);
			this->Controls->Add(this->input_list);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



private: 

	
	System::Void sort_button_Click(System::Object^ sender, System::EventArgs^ e);
	
	

	

};
}
