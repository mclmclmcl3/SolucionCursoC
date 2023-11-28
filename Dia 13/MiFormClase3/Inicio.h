#pragma once
#include <exception>

namespace MiFormClase3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Inicio : public System::Windows::Forms::Form
	{
	public:
		Inicio(void)
		{
			InitializeComponent();
		}

	protected:
		~Inicio()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^ txtNum1;
	protected:
	private: System::Windows::Forms::TextBox^ txtNum2;
	private: System::Windows::Forms::Label^ lblNum1;
	private: System::Windows::Forms::Label^ lblNum2;
	private: System::Windows::Forms::Button^ btnSumar;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::ListBox^ listBox2;
	private: System::Windows::Forms::CheckBox^ chPeras;
	private: System::Windows::Forms::CheckBox^ chManzanas;
	private: System::Windows::Forms::CheckBox^ chPlatanos;
	private: System::Windows::Forms::CheckBox^ chCiruelas;
	private: System::Windows::Forms::CheckBox^ chNaranjas;
	private: System::Windows::Forms::CheckBox^ chPapayas;
	private: System::Windows::Forms::Button^ btnFrutas;
	private: System::Windows::Forms::Label^ lblSuma;

	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->txtNum1 = (gcnew System::Windows::Forms::TextBox());
			   this->txtNum2 = (gcnew System::Windows::Forms::TextBox());
			   this->lblNum1 = (gcnew System::Windows::Forms::Label());
			   this->lblNum2 = (gcnew System::Windows::Forms::Label());
			   this->btnSumar = (gcnew System::Windows::Forms::Button());
			   this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			   this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			   this->chPeras = (gcnew System::Windows::Forms::CheckBox());
			   this->chManzanas = (gcnew System::Windows::Forms::CheckBox());
			   this->chPlatanos = (gcnew System::Windows::Forms::CheckBox());
			   this->chCiruelas = (gcnew System::Windows::Forms::CheckBox());
			   this->chNaranjas = (gcnew System::Windows::Forms::CheckBox());
			   this->chPapayas = (gcnew System::Windows::Forms::CheckBox());
			   this->btnFrutas = (gcnew System::Windows::Forms::Button());
			   this->lblSuma = (gcnew System::Windows::Forms::Label());
			   this->SuspendLayout();
			   // 
			   // txtNum1
			   // 
			   this->txtNum1->Location = System::Drawing::Point(79, 90);
			   this->txtNum1->Margin = System::Windows::Forms::Padding(4);
			   this->txtNum1->Name = L"txtNum1";
			   this->txtNum1->Size = System::Drawing::Size(118, 26);
			   this->txtNum1->TabIndex = 0;
			   // 
			   // txtNum2
			   // 
			   this->txtNum2->Location = System::Drawing::Point(286, 90);
			   this->txtNum2->Margin = System::Windows::Forms::Padding(4);
			   this->txtNum2->Name = L"txtNum2";
			   this->txtNum2->Size = System::Drawing::Size(115, 26);
			   this->txtNum2->TabIndex = 1;
			   // 
			   // lblNum1
			   // 
			   this->lblNum1->AutoSize = true;
			   this->lblNum1->Location = System::Drawing::Point(74, 53);
			   this->lblNum1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->lblNum1->Name = L"lblNum1";
			   this->lblNum1->Size = System::Drawing::Size(75, 19);
			   this->lblNum1->TabIndex = 2;
			   this->lblNum1->Text = L"Numero 1";
			   // 
			   // lblNum2
			   // 
			   this->lblNum2->AutoSize = true;
			   this->lblNum2->Location = System::Drawing::Point(281, 53);
			   this->lblNum2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->lblNum2->Name = L"lblNum2";
			   this->lblNum2->Size = System::Drawing::Size(75, 19);
			   this->lblNum2->TabIndex = 3;
			   this->lblNum2->Text = L"Numero 2";
			   // 
			   // btnSumar
			   // 
			   this->btnSumar->Location = System::Drawing::Point(79, 153);
			   this->btnSumar->Margin = System::Windows::Forms::Padding(4);
			   this->btnSumar->Name = L"btnSumar";
			   this->btnSumar->Size = System::Drawing::Size(189, 53);
			   this->btnSumar->TabIndex = 4;
			   this->btnSumar->Text = L"Sumar";
			   this->btnSumar->UseVisualStyleBackColor = true;
			   this->btnSumar->Click += gcnew System::EventHandler(this, &Inicio::btnSumar_Click);
			   // 
			   // listBox1
			   // 
			   this->listBox1->FormattingEnabled = true;
			   this->listBox1->ItemHeight = 19;
			   this->listBox1->Location = System::Drawing::Point(465, 35);
			   this->listBox1->Name = L"listBox1";
			   this->listBox1->Size = System::Drawing::Size(182, 270);
			   this->listBox1->TabIndex = 5;
			   // 
			   // listBox2
			   // 
			   this->listBox2->FormattingEnabled = true;
			   this->listBox2->ItemHeight = 19;
			   this->listBox2->Location = System::Drawing::Point(680, 35);
			   this->listBox2->Name = L"listBox2";
			   this->listBox2->Size = System::Drawing::Size(182, 270);
			   this->listBox2->TabIndex = 6;
			   // 
			   // chPeras
			   // 
			   this->chPeras->AutoSize = true;
			   this->chPeras->Location = System::Drawing::Point(79, 269);
			   this->chPeras->Name = L"chPeras";
			   this->chPeras->Size = System::Drawing::Size(66, 23);
			   this->chPeras->TabIndex = 7;
			   this->chPeras->Text = L"Peras";
			   this->chPeras->UseVisualStyleBackColor = true;
			   // 
			   // chManzanas
			   // 
			   this->chManzanas->AutoSize = true;
			   this->chManzanas->Location = System::Drawing::Point(172, 269);
			   this->chManzanas->Name = L"chManzanas";
			   this->chManzanas->Size = System::Drawing::Size(97, 23);
			   this->chManzanas->TabIndex = 8;
			   this->chManzanas->Text = L"Manzanas";
			   this->chManzanas->UseVisualStyleBackColor = true;
			   // 
			   // chPlatanos
			   // 
			   this->chPlatanos->AutoSize = true;
			   this->chPlatanos->Location = System::Drawing::Point(273, 269);
			   this->chPlatanos->Name = L"chPlatanos";
			   this->chPlatanos->Size = System::Drawing::Size(85, 23);
			   this->chPlatanos->TabIndex = 9;
			   this->chPlatanos->Text = L"Platanos";
			   this->chPlatanos->UseVisualStyleBackColor = true;
			   // 
			   // chCiruelas
			   // 
			   this->chCiruelas->AutoSize = true;
			   this->chCiruelas->Location = System::Drawing::Point(79, 320);
			   this->chCiruelas->Name = L"chCiruelas";
			   this->chCiruelas->Size = System::Drawing::Size(84, 23);
			   this->chCiruelas->TabIndex = 10;
			   this->chCiruelas->Text = L"Ciruelas";
			   this->chCiruelas->UseVisualStyleBackColor = true;
			   // 
			   // chNaranjas
			   // 
			   this->chNaranjas->AutoSize = true;
			   this->chNaranjas->Location = System::Drawing::Point(172, 320);
			   this->chNaranjas->Name = L"chNaranjas";
			   this->chNaranjas->Size = System::Drawing::Size(89, 23);
			   this->chNaranjas->TabIndex = 11;
			   this->chNaranjas->Text = L"Naranjas";
			   this->chNaranjas->UseVisualStyleBackColor = true;
			   // 
			   // chPapayas
			   // 
			   this->chPapayas->AutoSize = true;
			   this->chPapayas->Location = System::Drawing::Point(273, 320);
			   this->chPapayas->Name = L"chPapayas";
			   this->chPapayas->Size = System::Drawing::Size(84, 23);
			   this->chPapayas->TabIndex = 12;
			   this->chPapayas->Text = L"Papayas";
			   this->chPapayas->UseVisualStyleBackColor = true;
			   // 
			   // btnFrutas
			   // 
			   this->btnFrutas->Location = System::Drawing::Point(148, 362);
			   this->btnFrutas->Margin = System::Windows::Forms::Padding(4);
			   this->btnFrutas->Name = L"btnFrutas";
			   this->btnFrutas->Size = System::Drawing::Size(157, 38);
			   this->btnFrutas->TabIndex = 13;
			   this->btnFrutas->Text = L"Elejir Fruta";
			   this->btnFrutas->UseVisualStyleBackColor = true;
			   this->btnFrutas->Click += gcnew System::EventHandler(this, &Inicio::btnFrutas_Click);
			   // 
			   // lblSuma
			   // 
			   this->lblSuma->AutoSize = true;
			   this->lblSuma->Location = System::Drawing::Point(315, 170);
			   this->lblSuma->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->lblSuma->Name = L"lblSuma";
			   this->lblSuma->Size = System::Drawing::Size(75, 19);
			   this->lblSuma->TabIndex = 14;
			   this->lblSuma->Text = L"Numero 1";
			   // 
			   // Inicio
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(9, 19);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(918, 693);
			   this->Controls->Add(this->lblSuma);
			   this->Controls->Add(this->btnFrutas);
			   this->Controls->Add(this->chPapayas);
			   this->Controls->Add(this->chNaranjas);
			   this->Controls->Add(this->chCiruelas);
			   this->Controls->Add(this->chPlatanos);
			   this->Controls->Add(this->chManzanas);
			   this->Controls->Add(this->chPeras);
			   this->Controls->Add(this->listBox2);
			   this->Controls->Add(this->listBox1);
			   this->Controls->Add(this->btnSumar);
			   this->Controls->Add(this->lblNum2);
			   this->Controls->Add(this->lblNum1);
			   this->Controls->Add(this->txtNum2);
			   this->Controls->Add(this->txtNum1);
			   this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Margin = System::Windows::Forms::Padding(4);
			   this->Name = L"Inicio";
			   this->Text = L"Inicio";
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

	private:
		array<String^>^ Sumas = gcnew array<String^>(10);
		List<String^>^ listaSumas = gcnew List<String^>();
		int i = 0, i2 = 0;


	private: System::Void btnSumar_Click(System::Object^ sender, System::EventArgs^ e)
	{
		try
		{
			int NumSuma1 = Convert::ToInt32(txtNum1->Text);
			int NumSuma2 = Convert::ToInt32(txtNum2->Text);
			int suma = NumSuma1 + NumSuma2;
			
			String^ todos = "\nNumeros introducidos: ";
			for each (Control ^ Nintroducido in this->Controls)
			{
				TextBox^ numero = dynamic_cast<TextBox^>(Nintroducido);
				if (numero != nullptr)
				{
					todos += numero->Text + " ";
				}
			}
			MessageBox::Show(todos);

			Sumas[i] = suma.ToString();
			i++;
			String^ ListaTexto;

			// Array::Reverse(Sumas);
			for each (String ^ numero in Sumas)
			{
				ListaTexto += "\n " + numero;
			}
			MessageBox::Show(ListaTexto);

			Listados(suma);
			//MessageBox::Show("La suma es: " + suma, "Sumar");
		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Error" + ex->Message);
		}

	}

	private: void Listados(int suma)
	{
		listaSumas->Add(suma.ToString());
		if (i2 < 10)
		{
			Sumas[i2] = suma.ToString();
			i2++;

			listBox1->Items->Clear();
			// Agregar elementos a listBox1
			for (int j = 0; j < Sumas->Length; j++)
			{
				if (Sumas[j] != nullptr)
					listBox1->Items->Add(Sumas[j]);
			}
		}

		listBox2->Items->Clear();
		for each (String^ item in listaSumas)
		{
			listBox2->Items->Add(item);
		}
	}


	private: System::Void btnFrutas_Click(System::Object^ sender, System::EventArgs^ e) {
		
		String^ todos = "Frutas elejidas: \n";
		for each (Control ^ Nintroducido in this->Controls)
		{
			CheckBox^ fruta = dynamic_cast<CheckBox^>(Nintroducido);
			if (fruta != nullptr)
			{
				if(fruta->Checked)
					todos += fruta->Text + " ";
			}
		}
		MessageBox::Show(todos);
	}
	};
}
