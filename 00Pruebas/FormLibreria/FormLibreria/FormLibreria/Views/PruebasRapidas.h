#pragma once

#include "../Declaraciones.h"

namespace FormLibreria {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de PruebasRapidas
	/// </summary>
	public ref class PruebasRapidas : public System::Windows::Forms::Form
	{
	public:
		PruebasRapidas(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~PruebasRapidas()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnCodificar;
	protected:
	private: System::Windows::Forms::Label^ lblCodificado;
	private: System::Windows::Forms::TextBox^ txtTexto;
	private: System::Windows::Forms::Label^ lblDesCodificado;
	private: System::Windows::Forms::Label^ lblPermisosDesCod;
	private: System::Windows::Forms::Label^ lblPermisosCod;
	private: System::Windows::Forms::Label^ lblmail;
	private: System::Windows::Forms::Label^ lblpass;
	private: System::Windows::Forms::Label^ lblPermiso;
	private: System::Windows::Forms::Button^ btnLogin;
	private: System::Windows::Forms::Label^ CheckPermiso;


	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnCodificar = (gcnew System::Windows::Forms::Button());
			this->lblCodificado = (gcnew System::Windows::Forms::Label());
			this->txtTexto = (gcnew System::Windows::Forms::TextBox());
			this->lblDesCodificado = (gcnew System::Windows::Forms::Label());
			this->lblPermisosDesCod = (gcnew System::Windows::Forms::Label());
			this->lblPermisosCod = (gcnew System::Windows::Forms::Label());
			this->lblmail = (gcnew System::Windows::Forms::Label());
			this->lblpass = (gcnew System::Windows::Forms::Label());
			this->lblPermiso = (gcnew System::Windows::Forms::Label());
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->CheckPermiso = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnCodificar
			// 
			this->btnCodificar->Location = System::Drawing::Point(84, 101);
			this->btnCodificar->Name = L"btnCodificar";
			this->btnCodificar->Size = System::Drawing::Size(75, 23);
			this->btnCodificar->TabIndex = 1;
			this->btnCodificar->Text = L"button1";
			this->btnCodificar->UseVisualStyleBackColor = true;
			this->btnCodificar->Click += gcnew System::EventHandler(this, &PruebasRapidas::btnCodificar_Click);
			// 
			// lblCodificado
			// 
			this->lblCodificado->AutoSize = true;
			this->lblCodificado->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCodificado->Location = System::Drawing::Point(81, 148);
			this->lblCodificado->Name = L"lblCodificado";
			this->lblCodificado->Size = System::Drawing::Size(51, 20);
			this->lblCodificado->TabIndex = 2;
			this->lblCodificado->Text = L"label1";
			// 
			// txtTexto
			// 
			this->txtTexto->Location = System::Drawing::Point(84, 52);
			this->txtTexto->Name = L"txtTexto";
			this->txtTexto->Size = System::Drawing::Size(406, 20);
			this->txtTexto->TabIndex = 3;
			// 
			// lblDesCodificado
			// 
			this->lblDesCodificado->AutoSize = true;
			this->lblDesCodificado->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblDesCodificado->Location = System::Drawing::Point(81, 189);
			this->lblDesCodificado->Name = L"lblDesCodificado";
			this->lblDesCodificado->Size = System::Drawing::Size(51, 20);
			this->lblDesCodificado->TabIndex = 4;
			this->lblDesCodificado->Text = L"label2";
			// 
			// lblPermisosDesCod
			// 
			this->lblPermisosDesCod->AutoSize = true;
			this->lblPermisosDesCod->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPermisosDesCod->Location = System::Drawing::Point(363, 189);
			this->lblPermisosDesCod->Name = L"lblPermisosDesCod";
			this->lblPermisosDesCod->Size = System::Drawing::Size(51, 20);
			this->lblPermisosDesCod->TabIndex = 6;
			this->lblPermisosDesCod->Text = L"label2";
			// 
			// lblPermisosCod
			// 
			this->lblPermisosCod->AutoSize = true;
			this->lblPermisosCod->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPermisosCod->Location = System::Drawing::Point(363, 148);
			this->lblPermisosCod->Name = L"lblPermisosCod";
			this->lblPermisosCod->Size = System::Drawing::Size(51, 20);
			this->lblPermisosCod->TabIndex = 5;
			this->lblPermisosCod->Text = L"label1";
			// 
			// lblmail
			// 
			this->lblmail->AutoSize = true;
			this->lblmail->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblmail->Location = System::Drawing::Point(81, 268);
			this->lblmail->Name = L"lblmail";
			this->lblmail->Size = System::Drawing::Size(37, 20);
			this->lblmail->TabIndex = 7;
			this->lblmail->Text = L"Mail";
			// 
			// lblpass
			// 
			this->lblpass->AutoSize = true;
			this->lblpass->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblpass->Location = System::Drawing::Point(80, 299);
			this->lblpass->Name = L"lblpass";
			this->lblpass->Size = System::Drawing::Size(44, 20);
			this->lblpass->TabIndex = 8;
			this->lblpass->Text = L"Pass";
			// 
			// lblPermiso
			// 
			this->lblPermiso->AutoSize = true;
			this->lblPermiso->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPermiso->Location = System::Drawing::Point(81, 331);
			this->lblPermiso->Name = L"lblPermiso";
			this->lblPermiso->Size = System::Drawing::Size(66, 20);
			this->lblPermiso->TabIndex = 9;
			this->lblPermiso->Text = L"Permiso";
			// 
			// btnLogin
			// 
			this->btnLogin->Location = System::Drawing::Point(85, 242);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(75, 23);
			this->btnLogin->TabIndex = 10;
			this->btnLogin->Text = L"Usuarios";
			this->btnLogin->UseVisualStyleBackColor = true;
			this->btnLogin->Click += gcnew System::EventHandler(this, &PruebasRapidas::btnLogin_Click);
			// 
			// CheckPermiso
			// 
			this->CheckPermiso->AutoSize = true;
			this->CheckPermiso->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CheckPermiso->Location = System::Drawing::Point(363, 331);
			this->CheckPermiso->Name = L"CheckPermiso";
			this->CheckPermiso->Size = System::Drawing::Size(111, 20);
			this->CheckPermiso->TabIndex = 11;
			this->CheckPermiso->Text = L"CheckPermiso";
			// 
			// PruebasRapidas
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 408);
			this->Controls->Add(this->CheckPermiso);
			this->Controls->Add(this->btnLogin);
			this->Controls->Add(this->lblPermiso);
			this->Controls->Add(this->lblpass);
			this->Controls->Add(this->lblmail);
			this->Controls->Add(this->lblPermisosDesCod);
			this->Controls->Add(this->lblPermisosCod);
			this->Controls->Add(this->lblDesCodificado);
			this->Controls->Add(this->txtTexto);
			this->Controls->Add(this->lblCodificado);
			this->Controls->Add(this->btnCodificar);
			this->Name = L"PruebasRapidas";
			this->Text = L"PruebasRapidas";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		Void btnCodificar_Click(Object^ sender, EventArgs^ e)
		{
			// Datos introducidos
			string key = "afdadsdfasd";
			String^ texto = txtTexto->Text;
			Permisos permiso = permisoUsuario;

			// convertirlos a stringSTD
			string textoStd = msclr::interop::marshal_as<string>(texto);
			string permisoStd = enumToString(permiso);

			// Encriptarlos
			string codificado = CryptoUtils::Encrypt(textoStd, key);
			string pcodificado = CryptoUtils::Encrypt(permisoStd, key);

			// Mostrar encriptado
			lblCodificado->Text = gcnew String(codificado.c_str());
			lblPermisosCod->Text = gcnew String(pcodificado.c_str());

			// Desencriptar
			string descodificado = CryptoUtils::Decrypt(codificado, key);
			string permisodescodificado = CryptoUtils::Decrypt(pcodificado, key);

			// Mostrar desencriptado
			lblDesCodificado->Text = gcnew String(descodificado.c_str());
			lblPermisosDesCod->Text = gcnew String(permisodescodificado.c_str());

		}

		Void btnLogin_Click(Object^ sender, EventArgs^ e)
		{
			UsuariosDocument* doc = new UsuariosDocument("Usuarios");
			vector<Usuario> lista = doc->Leer();
			int id = 2;
			if (lista.size() > 0)
			{
				lblmail->Text = gcnew String(lista[id].GetEmail().c_str());
				lblpass->Text = gcnew String(lista[id].GetPass().c_str());
				lblPermiso->Text = gcnew String(enumToString(lista[id].GetPermiso()).c_str());
			}
			else
				MessageBox::Show("No hay datos");
		}
	};
}
