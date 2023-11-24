#pragma once
#include "Usuario.h"
#include "Inicio.h"
#include "fstream"
#include <msclr/marshal_cppstd.h>

namespace EjercicioLoginForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	public ref class Login : public System::Windows::Forms::Form
	{
	public:
		Login(void)
		{
			InitializeComponent();
		}

	protected:
		~Login()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnLogin;
	private: System::Windows::Forms::Label^ lblEmail;
	private: System::Windows::Forms::TextBox^ txtMail;
	private: System::Windows::Forms::TextBox^ txtPass;
	private: System::Windows::Forms::Label^ lblPass;
	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->lblEmail = (gcnew System::Windows::Forms::Label());
			this->txtMail = (gcnew System::Windows::Forms::TextBox());
			this->txtPass = (gcnew System::Windows::Forms::TextBox());
			this->lblPass = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnLogin
			// 
			this->btnLogin->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnLogin->Location = System::Drawing::Point(154, 223);
			this->btnLogin->Margin = System::Windows::Forms::Padding(4);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(83, 34);
			this->btnLogin->TabIndex = 0;
			this->btnLogin->Text = L"Login";
			this->btnLogin->UseVisualStyleBackColor = true;
			this->btnLogin->Click += gcnew System::EventHandler(this, &Login::btnLogin_Click);
			// 
			// lblEmail
			// 
			this->lblEmail->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblEmail->AutoSize = true;
			this->lblEmail->Location = System::Drawing::Point(39, 44);
			this->lblEmail->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblEmail->Name = L"lblEmail";
			this->lblEmail->Size = System::Drawing::Size(47, 19);
			this->lblEmail->TabIndex = 1;
			this->lblEmail->Text = L"Email";
			// 
			// txtMail
			// 
			this->txtMail->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtMail->Location = System::Drawing::Point(43, 70);
			this->txtMail->Margin = System::Windows::Forms::Padding(4);
			this->txtMail->Name = L"txtMail";
			this->txtMail->Size = System::Drawing::Size(300, 26);
			this->txtMail->TabIndex = 2;
			// 
			// txtPass
			// 
			this->txtPass->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtPass->Location = System::Drawing::Point(43, 152);
			this->txtPass->Margin = System::Windows::Forms::Padding(4);
			this->txtPass->Name = L"txtPass";
			this->txtPass->Size = System::Drawing::Size(300, 26);
			this->txtPass->TabIndex = 4;
			// 
			// lblPass
			// 
			this->lblPass->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblPass->AutoSize = true;
			this->lblPass->Location = System::Drawing::Point(39, 126);
			this->lblPass->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblPass->Name = L"lblPass";
			this->lblPass->Size = System::Drawing::Size(40, 19);
			this->lblPass->TabIndex = 3;
			this->lblPass->Text = L"Pass";
			// 
			// Login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 19);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(397, 303);
			this->Controls->Add(this->txtPass);
			this->Controls->Add(this->lblPass);
			this->Controls->Add(this->txtMail);
			this->Controls->Add(this->lblEmail);
			this->Controls->Add(this->btnLogin);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Login";
			this->Text = L"Login";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


		Void btnLogin_Click(Object^ sender, System::EventArgs^ e)
		{
			String^ email = txtMail->Text;
			String^ pass = txtPass->Text;

			if (email != "" && pass != "")
			{
				// Convertir System::String^ a std::string
				string emailStd = msclr::interop::marshal_as<string>(email);

				// Convertir System::String^ a std::string
				string pasStd = msclr::interop::marshal_as<string>(pass);


				Grabar(emailStd, pasStd);

				Usuario* user = new Usuario();
				user->SetEmail(emailStd);
				user->SetPass(pasStd);

				Inicio^ inicio = gcnew Inicio(user);

				this->Visible = false;
				inicio->ShowDialog();
				this->Visible = true;

				delete user;
			}

		}
		void Grabar(string email, string pass)
		{
			ofstream file(email + ".txt");
			if (file.is_open())
			{
				// Escribir el correo electrónico y la contraseña en el archivo
				file << "Email: " << email << "\n";
				file << "Pass: " << pass << "\n";

			}
			else
			{
				MessageBox::Show("No se a podido abir el archivo para escritura.\n");
			}

			file.close();
		}


};
}
