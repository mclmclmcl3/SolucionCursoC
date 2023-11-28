#pragma once


#include "Models/Login.h"
#include "Models/Usuario.h"
#include <iostream>
#include <msclr/marshal_cppstd.h>

namespace FormLibreria {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class FormLogin : public System::Windows::Forms::Form
	{
	private: Login* login;
	public:
		FormLogin(Login* loginInstancia)
		{
			InitializeComponent();
			login = loginInstancia;
		}

	protected:
		~FormLogin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnLogin;
	private: System::Windows::Forms::Button^ btnRegister;

	protected:


	private: System::Windows::Forms::Label^ lblEmail;
	private: System::Windows::Forms::TextBox^ txtEmail;
	private: System::Windows::Forms::TextBox^ txtPass;

	private: System::Windows::Forms::Label^ lblPass;
	private: System::Windows::Forms::Button^ btnSalir;
	protected:

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->btnRegister = (gcnew System::Windows::Forms::Button());
			this->lblEmail = (gcnew System::Windows::Forms::Label());
			this->txtEmail = (gcnew System::Windows::Forms::TextBox());
			this->txtPass = (gcnew System::Windows::Forms::TextBox());
			this->lblPass = (gcnew System::Windows::Forms::Label());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnLogin
			// 
			this->btnLogin->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnLogin->Location = System::Drawing::Point(101, 316);
			this->btnLogin->Margin = System::Windows::Forms::Padding(6);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(150, 42);
			this->btnLogin->TabIndex = 0;
			this->btnLogin->Text = L"Login";
			this->btnLogin->UseVisualStyleBackColor = true;
			this->btnLogin->Click += gcnew System::EventHandler(this, &FormLogin::btnLogin_Click);
			// 
			// btnRegister
			// 
			this->btnRegister->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnRegister->Location = System::Drawing::Point(305, 316);
			this->btnRegister->Margin = System::Windows::Forms::Padding(6);
			this->btnRegister->Name = L"btnRegister";
			this->btnRegister->Size = System::Drawing::Size(150, 42);
			this->btnRegister->TabIndex = 1;
			this->btnRegister->Text = L"Registrarse";
			this->btnRegister->UseVisualStyleBackColor = true;
			this->btnRegister->Click += gcnew System::EventHandler(this, &FormLogin::btnRegister_Click);
			// 
			// lblEmail
			// 
			this->lblEmail->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblEmail->AutoSize = true;
			this->lblEmail->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblEmail->Location = System::Drawing::Point(76, 57);
			this->lblEmail->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->lblEmail->Name = L"lblEmail";
			this->lblEmail->Size = System::Drawing::Size(62, 24);
			this->lblEmail->TabIndex = 2;
			this->lblEmail->Text = L"Email";
			// 
			// txtEmail
			// 
			this->txtEmail->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtEmail->Location = System::Drawing::Point(82, 90);
			this->txtEmail->Margin = System::Windows::Forms::Padding(6);
			this->txtEmail->Name = L"txtEmail";
			this->txtEmail->Size = System::Drawing::Size(404, 29);
			this->txtEmail->TabIndex = 3;
			// 
			// txtPass
			// 
			this->txtPass->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtPass->Location = System::Drawing::Point(82, 203);
			this->txtPass->Margin = System::Windows::Forms::Padding(6);
			this->txtPass->Name = L"txtPass";
			this->txtPass->PasswordChar = '*';
			this->txtPass->Size = System::Drawing::Size(404, 29);
			this->txtPass->TabIndex = 5;
			// 
			// lblPass
			// 
			this->lblPass->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblPass->AutoSize = true;
			this->lblPass->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPass->Location = System::Drawing::Point(76, 170);
			this->lblPass->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->lblPass->Name = L"lblPass";
			this->lblPass->Size = System::Drawing::Size(116, 24);
			this->lblPass->TabIndex = 4;
			this->lblPass->Text = L"Contraseña";
			// 
			// btnSalir
			// 
			this->btnSalir->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnSalir->Location = System::Drawing::Point(101, 380);
			this->btnSalir->Margin = System::Windows::Forms::Padding(6);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(354, 42);
			this->btnSalir->TabIndex = 6;
			this->btnSalir->Text = L"Salir";
			this->btnSalir->UseVisualStyleBackColor = true;
			this->btnSalir->Click += gcnew System::EventHandler(this, &FormLogin::btnSalir_Click);
			// 
			// FormLogin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(568, 482);
			this->ControlBox = false;
			this->Controls->Add(this->btnSalir);
			this->Controls->Add(this->txtPass);
			this->Controls->Add(this->lblPass);
			this->Controls->Add(this->txtEmail);
			this->Controls->Add(this->lblEmail);
			this->Controls->Add(this->btnRegister);
			this->Controls->Add(this->btnLogin);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"FormLogin";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FormLogin";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



		Void btnLogin_Click(Object^ sender, EventArgs^ e)
		{
			login->Logear(Intercambio());
			if (login->IsLogin())
			{
				this->Close();
			}
			else
			{
				MessageBox::Show("Usuario incorrecto.", "Error");
				txtEmail->Text = "";
				txtPass->Text = "";
			}
		}
		Void btnRegister_Click(Object^ sender, EventArgs^ e)
		{
			login->Registrar(Intercambio());
		}
		Void btnSalir_Click(Object^ sender, EventArgs^ e)
		{
			Application::Exit();
		}


		Usuario Intercambio()
		{
			String^ email = txtEmail->Text;
			String^ pass = txtPass->Text;

			string emailStd = msclr::interop::marshal_as<std::string>(email);
			string passStd = msclr::interop::marshal_as<std::string>(pass);

			Usuario user;
			user.SetEmail(emailStd);
			user.SetPass(passStd);

			return user;
		}


	};
}
