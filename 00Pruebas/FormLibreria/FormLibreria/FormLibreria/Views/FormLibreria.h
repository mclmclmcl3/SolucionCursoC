#pragma once

#include "../Models/Libreria.h"
#include "../Models/Login.h"
#include "FormLogin.h"
#include "FormCarrito.h"
#include <iostream>
#include <msclr/marshal_cppstd.h>
#include "FormAdministrador.h"

namespace FormLibreria {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class FormLibreria : public System::Windows::Forms::Form
	{
	public: FormLogin^ fLogin;
	public: FormCarrito^ fCarrito;
	public: FormAdministrador^ fAdmin;

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ lblTitulo;

	private: System::Windows::Forms::Button^ btnCarrito;
	private: System::Windows::Forms::Button^ btnLogotut;


	private: System::Windows::Forms::Button^ btnAdmin;

	public:



	public:
		Login* login;
	private: System::Windows::Forms::ListView^ lvLibros;
	public:

	private: System::Windows::Forms::ColumnHeader^ Titulo;
	private: System::Windows::Forms::ColumnHeader^ Autor;
	private: System::Windows::Forms::ColumnHeader^ Precio;
	private: System::Windows::Forms::Label^ lblTituloBody;
	private: System::Windows::Forms::Label^ lblTituloLibre;
	private: System::Windows::Forms::Label^ lblAutorLibro;
	private: System::Windows::Forms::Label^ lblPrecioLibro;
	private: System::Windows::Forms::TextBox^ txtTitulo;
	private: System::Windows::Forms::TextBox^ txtAutor;
	private: System::Windows::Forms::TextBox^ txtPrecio;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ btnCarritoUsuario;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lblNombreUsuario;

	public:
		Libreria* libreria;

	public:
		FormLibreria()
		{
			InitializeComponent();
			login = new Login();

			if (!login->IsLogin())
			{
				fLogin = gcnew FormLogin(login);
				this->Hide();
				fLogin->ShowDialog();
				this->Show();


				libreria = new Libreria(login);

				lvLibros->FullRowSelect = true;
				RellenarListadoLibros(libreria->GetAllLibros());

				lblNombreUsuario->Text = gcnew String(login->GetUsuario().GetEmail().c_str());

			}
		}

		void RellenarListadoLibros(std::vector<Libro> libros)
		{
			for each (Libro libro in libros)
			{
				ListViewItem^ listado = gcnew ListViewItem(gcnew String(libro.GetTitulo().c_str()));
				listado->SubItems->Add(gcnew String(libro.GetAutor().c_str()));

				// Convertir el precio a String^ antes de agregarlo
				listado->SubItems->Add(gcnew String(libro.GetPrecio().ToString("N2")));

				// Agregar el ListViewItem en cada iteración
				lvLibros->Items->Add(listado);
			}
		}

	protected:
		~FormLibreria()
		{
			if (login != nullptr)
				delete login;

			if (libreria != nullptr)
				delete libreria;

		}

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->btnAdmin = (gcnew System::Windows::Forms::Button());
			this->btnLogotut = (gcnew System::Windows::Forms::Button());
			this->btnCarrito = (gcnew System::Windows::Forms::Button());
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			this->lvLibros = (gcnew System::Windows::Forms::ListView());
			this->Titulo = (gcnew System::Windows::Forms::ColumnHeader());
			this->Autor = (gcnew System::Windows::Forms::ColumnHeader());
			this->Precio = (gcnew System::Windows::Forms::ColumnHeader());
			this->lblTituloBody = (gcnew System::Windows::Forms::Label());
			this->lblTituloLibre = (gcnew System::Windows::Forms::Label());
			this->lblAutorLibro = (gcnew System::Windows::Forms::Label());
			this->lblPrecioLibro = (gcnew System::Windows::Forms::Label());
			this->txtTitulo = (gcnew System::Windows::Forms::TextBox());
			this->txtAutor = (gcnew System::Windows::Forms::TextBox());
			this->txtPrecio = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->btnCarritoUsuario = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblNombreUsuario = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel1->Controls->Add(this->btnAdmin);
			this->panel1->Controls->Add(this->btnLogotut);
			this->panel1->Controls->Add(this->btnCarrito);
			this->panel1->Controls->Add(this->lblTitulo);
			this->panel1->Location = System::Drawing::Point(-2, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(239, 561);
			this->panel1->TabIndex = 0;
			// 
			// btnAdmin
			// 
			this->btnAdmin->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->btnAdmin->Location = System::Drawing::Point(34, 487);
			this->btnAdmin->Name = L"btnAdmin";
			this->btnAdmin->Size = System::Drawing::Size(180, 41);
			this->btnAdmin->TabIndex = 4;
			this->btnAdmin->Text = L"Administrador";
			this->btnAdmin->UseVisualStyleBackColor = false;
			this->btnAdmin->Click += gcnew System::EventHandler(this, &FormLibreria::btnAdmin_Click);
			// 
			// btnLogotut
			// 
			this->btnLogotut->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->btnLogotut->Location = System::Drawing::Point(34, 428);
			this->btnLogotut->Name = L"btnLogotut";
			this->btnLogotut->Size = System::Drawing::Size(180, 41);
			this->btnLogotut->TabIndex = 3;
			this->btnLogotut->Text = L"Logout";
			this->btnLogotut->UseVisualStyleBackColor = false;
			this->btnLogotut->Click += gcnew System::EventHandler(this, &FormLibreria::btnLogotut_Click);
			// 
			// btnCarrito
			// 
			this->btnCarrito->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->btnCarrito->Location = System::Drawing::Point(32, 96);
			this->btnCarrito->Name = L"btnCarrito";
			this->btnCarrito->Size = System::Drawing::Size(180, 41);
			this->btnCarrito->TabIndex = 2;
			this->btnCarrito->Text = L"Ver Carrito";
			this->btnCarrito->UseVisualStyleBackColor = false;
			this->btnCarrito->Click += gcnew System::EventHandler(this, &FormLibreria::btnCarrito_Click);
			// 
			// lblTitulo
			// 
			this->lblTitulo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblTitulo->AutoSize = true;
			this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Times New Roman", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTitulo->ForeColor = System::Drawing::Color::White;
			this->lblTitulo->Location = System::Drawing::Point(28, 24);
			this->lblTitulo->Name = L"lblTitulo";
			this->lblTitulo->Size = System::Drawing::Size(115, 32);
			this->lblTitulo->TabIndex = 1;
			this->lblTitulo->Text = L"Libreria";
			// 
			// lvLibros
			// 
			this->lvLibros->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->Titulo, this->Autor,
					this->Precio
			});
			this->lvLibros->HideSelection = false;
			this->lvLibros->Location = System::Drawing::Point(288, 70);
			this->lvLibros->Name = L"lvLibros";
			this->lvLibros->Size = System::Drawing::Size(654, 218);
			this->lvLibros->TabIndex = 1;
			this->lvLibros->UseCompatibleStateImageBehavior = false;
			this->lvLibros->View = System::Windows::Forms::View::Details;
			this->lvLibros->SelectedIndexChanged += gcnew System::EventHandler(this, &FormLibreria::lvLibros_SelectedIndexChanged);
			// 
			// Titulo
			// 
			this->Titulo->Text = L"Titulo";
			this->Titulo->Width = 363;
			// 
			// Autor
			// 
			this->Autor->Text = L"Autor";
			this->Autor->Width = 186;
			// 
			// Precio
			// 
			this->Precio->Text = L"Precio";
			this->Precio->Width = 100;
			// 
			// lblTituloBody
			// 
			this->lblTituloBody->AutoSize = true;
			this->lblTituloBody->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTituloBody->ForeColor = System::Drawing::Color::SteelBlue;
			this->lblTituloBody->Location = System::Drawing::Point(282, 24);
			this->lblTituloBody->Name = L"lblTituloBody";
			this->lblTituloBody->Size = System::Drawing::Size(432, 31);
			this->lblTituloBody->TabIndex = 2;
			this->lblTituloBody->Text = L"Listados de los libros de la Libreria";
			// 
			// lblTituloLibre
			// 
			this->lblTituloLibre->AutoSize = true;
			this->lblTituloLibre->Location = System::Drawing::Point(19, 38);
			this->lblTituloLibre->Name = L"lblTituloLibre";
			this->lblTituloLibre->Size = System::Drawing::Size(48, 19);
			this->lblTituloLibre->TabIndex = 3;
			this->lblTituloLibre->Text = L"Titulo";
			// 
			// lblAutorLibro
			// 
			this->lblAutorLibro->AutoSize = true;
			this->lblAutorLibro->Location = System::Drawing::Point(19, 76);
			this->lblAutorLibro->Name = L"lblAutorLibro";
			this->lblAutorLibro->Size = System::Drawing::Size(47, 19);
			this->lblAutorLibro->TabIndex = 4;
			this->lblAutorLibro->Text = L"Autor";
			// 
			// lblPrecioLibro
			// 
			this->lblPrecioLibro->AutoSize = true;
			this->lblPrecioLibro->Location = System::Drawing::Point(19, 113);
			this->lblPrecioLibro->Name = L"lblPrecioLibro";
			this->lblPrecioLibro->Size = System::Drawing::Size(51, 19);
			this->lblPrecioLibro->TabIndex = 5;
			this->lblPrecioLibro->Text = L"Precio";
			// 
			// txtTitulo
			// 
			this->txtTitulo->Location = System::Drawing::Point(109, 35);
			this->txtTitulo->Name = L"txtTitulo";
			this->txtTitulo->ReadOnly = true;
			this->txtTitulo->Size = System::Drawing::Size(210, 26);
			this->txtTitulo->TabIndex = 6;
			// 
			// txtAutor
			// 
			this->txtAutor->Location = System::Drawing::Point(109, 73);
			this->txtAutor->Name = L"txtAutor";
			this->txtAutor->ReadOnly = true;
			this->txtAutor->Size = System::Drawing::Size(210, 26);
			this->txtAutor->TabIndex = 7;
			// 
			// txtPrecio
			// 
			this->txtPrecio->Location = System::Drawing::Point(109, 110);
			this->txtPrecio->Name = L"txtPrecio";
			this->txtPrecio->ReadOnly = true;
			this->txtPrecio->Size = System::Drawing::Size(99, 26);
			this->txtPrecio->TabIndex = 8;
			this->txtPrecio->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->btnCarritoUsuario);
			this->groupBox1->Controls->Add(this->txtTitulo);
			this->groupBox1->Controls->Add(this->txtPrecio);
			this->groupBox1->Controls->Add(this->lblTituloLibre);
			this->groupBox1->Controls->Add(this->txtAutor);
			this->groupBox1->Controls->Add(this->lblAutorLibro);
			this->groupBox1->Controls->Add(this->lblPrecioLibro);
			this->groupBox1->Location = System::Drawing::Point(288, 315);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(335, 213);
			this->groupBox1->TabIndex = 9;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Seleccion Libro";
			// 
			// btnCarritoUsuario
			// 
			this->btnCarritoUsuario->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCarritoUsuario->ForeColor = System::Drawing::SystemColors::Highlight;
			this->btnCarritoUsuario->Location = System::Drawing::Point(23, 152);
			this->btnCarritoUsuario->Name = L"btnCarritoUsuario";
			this->btnCarritoUsuario->Size = System::Drawing::Size(296, 44);
			this->btnCarritoUsuario->TabIndex = 9;
			this->btnCarritoUsuario->Text = L"Añadir al carrito";
			this->btnCarritoUsuario->UseVisualStyleBackColor = true;
			this->btnCarritoUsuario->Click += gcnew System::EventHandler(this, &FormLibreria::btnCarritoUsuario_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::SteelBlue;
			this->label1->Location = System::Drawing::Point(660, 324);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(117, 31);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Usuario:";
			// 
			// lblNombreUsuario
			// 
			this->lblNombreUsuario->AutoSize = true;
			this->lblNombreUsuario->Location = System::Drawing::Point(666, 368);
			this->lblNombreUsuario->Name = L"lblNombreUsuario";
			this->lblNombreUsuario->Size = System::Drawing::Size(63, 19);
			this->lblNombreUsuario->TabIndex = 11;
			this->lblNombreUsuario->Text = L"Nombre";
			// 
			// FormLibreria
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 19);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 561);
			this->Controls->Add(this->lblNombreUsuario);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->lblTituloBody);
			this->Controls->Add(this->lvLibros);
			this->Controls->Add(this->panel1);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->MinimumSize = System::Drawing::Size(1000, 600);
			this->Name = L"FormLibreria";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Libreria";
			this->Activated += gcnew System::EventHandler(this, &FormLibreria::FormLibreria_Activated);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion






		Void lvLibros_SelectedIndexChanged(Object^ sender, EventArgs^ e)
		{
			if (lvLibros->SelectedItems->Count > 0)
			{
				ListViewItem^ selectedItem = lvLibros->SelectedItems[0];

				String^ titulo = selectedItem->Text;
				String^ autor = selectedItem->SubItems[1]->Text;
				String^ precio = selectedItem->SubItems[2]->Text;

				txtTitulo->Text = titulo;
				txtAutor->Text = autor;
				txtPrecio->Text = precio;
			}
		}
		Void btnCarritoUsuario_Click(Object^ sender, EventArgs^ e)
		{
			String^ titulo = txtTitulo->Text;
			String^ autor = txtAutor->Text;
			String^ precio = txtPrecio->Text;

			std::string tituloSTD = msclr::interop::marshal_as<string>(titulo);
			std::string autorSTD = msclr::interop::marshal_as<string>(autor);

			// Convertir de System::String a double
			double precioSTD = 0.0;
			if (Double::TryParse(precio, precioSTD))
			{
				// Conversión exitosa
				Libro libro(tituloSTD, autorSTD, precioSTD);
				Usuario usuario = login->GetUsuario();
				usuario.GetCarrito()->ComprarLibro(libro);

				lvLibros->SelectedItems->Clear();

				txtTitulo->Text = "";
				txtAutor->Text = "";
				txtPrecio->Text = "";

				UpdateBotonCarrito(usuario);
			}
			else
			{
				// Manejar el caso en que la conversión a double no fue exitosa
				MessageBox::Show("El precio no es un número válido.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}

		}

		void UpdateBotonCarrito(Usuario& usuario)
		{
			if (usuario.GetCarrito()->ListadoCarrito().size() > 0)
				btnCarrito->Text = "Ver Carrito (" + usuario.GetCarrito()->ListadoCarrito().size() + ") und.";
			else
			{
				btnCarrito->Text = "Ver Carrito";
			}
		}

		Void btnAdmin_Click(Object^ sender, EventArgs^ e)
		{
			// Ventana Administracion
			if (login->GetUsuario().GetPermiso() == permisoAdmin)
			{
				fAdmin = gcnew FormAdministrador(libreria);
				this->Hide();
				fAdmin->ShowDialog();
				this->Show();
			}
			else
				MessageBox::Show("(NO) Tienes permiso de administrador");

		}


		Void btnCarrito_Click(Object^ sender, EventArgs^ e)
		{
			// Ventana Ver Carrito
			fCarrito = gcnew FormCarrito(login);

			this->Hide();
			fCarrito->ShowDialog();
			this->Show();
		}




		Void FormLibreria_Activated(Object^ sender, EventArgs^ e)
		{
			UpdateBotonCarrito(login->GetUsuario());
		}
		Void btnLogotut_Click(Object^ sender, EventArgs^ e) 
		{
			login->Logout();

			fLogin = gcnew FormLogin(login);
			this->Hide();
			fLogin->ShowDialog();
			this->Show();
		}
	};
}
