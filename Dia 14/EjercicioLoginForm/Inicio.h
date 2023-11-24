#pragma once

#include "Usuario.h"
#include "fstream"
#include "msclr/marshal_cppstd.h"

namespace EjercicioLoginForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Inicio : public System::Windows::Forms::Form
	{
	private: Usuario* user;
	public:
		Inicio(Usuario* usuario)
		{
			user = usuario;
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
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ lblEmail;
	private: System::Windows::Forms::Label^ lblPass;
	private: System::Windows::Forms::Label^ lblPassTxt;

	private: System::Windows::Forms::Label^ lblEmailTxt;

	private: System::Windows::Forms::Label^ label4;


	private:
		System::ComponentModel::Container ^components;

	#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblEmail = (gcnew System::Windows::Forms::Label());
			this->lblPass = (gcnew System::Windows::Forms::Label());
			this->lblPassTxt = (gcnew System::Windows::Forms::Label());
			this->lblEmailTxt = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(72, 63);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(96, 19);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Bienvenido...";
			// 
			// lblEmail
			// 
			this->lblEmail->AutoSize = true;
			this->lblEmail->Location = System::Drawing::Point(105, 110);
			this->lblEmail->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblEmail->Name = L"lblEmail";
			this->lblEmail->Size = System::Drawing::Size(45, 19);
			this->lblEmail->TabIndex = 1;
			this->lblEmail->Text = L"email";
			// 
			// lblPass
			// 
			this->lblPass->AutoSize = true;
			this->lblPass->Location = System::Drawing::Point(105, 143);
			this->lblPass->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblPass->Name = L"lblPass";
			this->lblPass->Size = System::Drawing::Size(39, 19);
			this->lblPass->TabIndex = 2;
			this->lblPass->Text = L"pass";
			// 
			// lblPassTxt
			// 
			this->lblPassTxt->AutoSize = true;
			this->lblPassTxt->Location = System::Drawing::Point(105, 259);
			this->lblPassTxt->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblPassTxt->Name = L"lblPassTxt";
			this->lblPassTxt->Size = System::Drawing::Size(39, 19);
			this->lblPassTxt->TabIndex = 4;
			this->lblPassTxt->Text = L"pass";
			// 
			// lblEmailTxt
			// 
			this->lblEmailTxt->AutoSize = true;
			this->lblEmailTxt->Location = System::Drawing::Point(105, 226);
			this->lblEmailTxt->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblEmailTxt->Name = L"lblEmailTxt";
			this->lblEmailTxt->Size = System::Drawing::Size(45, 19);
			this->lblEmailTxt->TabIndex = 3;
			this->lblEmailTxt->Text = L"email";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(72, 197);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(161, 19);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Bienvenido desde txt...";
			// 
			// Inicio
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 19);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(645, 619);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->lblPassTxt);
			this->Controls->Add(this->lblEmailTxt);
			this->Controls->Add(this->lblPass);
			this->Controls->Add(this->lblEmail);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Inicio";
			this->Text = L"Inicio";
			this->Load += gcnew System::EventHandler(this, &Inicio::Inicio_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	#pragma endregion

	Void Inicio_Load(Object^ sender, System::EventArgs^ e) 
	{
		std::string email = user->GetEmail();
		std::string pass = user->GetPass();

		Usuario usuario2 = LeerUsuario(email);
		lblEmailTxt->Text = gcnew String(usuario2.GetEmail().c_str());
		lblPassTxt->Text = gcnew String(usuario2.GetPass().c_str());

		String^ emailStr = gcnew String(email.c_str());
		String^ passStr = gcnew String(pass.c_str());

		lblEmail->Text = emailStr;
		lblPass->Text = passStr;

	}

	Usuario LeerUsuario(string email)
	{
		Usuario usuario;
		ifstream file(email + ".txt");

		if (file.is_open())
		{
			string linea;
			while (getline(file, linea))
			{
				size_t pos = linea.find(':');
				if (pos != string::npos)
				{
					string clave = linea.substr(0, pos);
					string valor = linea.substr(pos + 1);

					if (clave == "Email")
					{
						usuario.SetEmail(valor);
					}
					else if (clave == "Pass")
					{
						usuario.SetPass(valor);
					}
				}
			}
		}
		else
		{
			MessageBox::Show("No se pudo abrir el archivo para lectura.\n");
		}
		file.close();

		return usuario;
	}

	};
}
