#pragma once


#include "../Models/Login.h"
#include "../Models/Usuario.h"
#include <iostream>
#include <msclr/marshal_cppstd.h>

namespace FormLibreria {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class FormCarrito : public System::Windows::Forms::Form
	{
	private: Login* login;
	public:
		FormCarrito(Login* loginInstancia)
		{
			InitializeComponent();
			login = loginInstancia;

		}

	protected:
		~FormCarrito()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblTituloBody;
	protected:
	private: System::Windows::Forms::ListView^ lvLibros;
	private: System::Windows::Forms::ColumnHeader^ Titulo;
	private: System::Windows::Forms::ColumnHeader^ Autor;
	private: System::Windows::Forms::ColumnHeader^ Precio;
	private: System::Windows::Forms::Label^ lblTotal;
	private: System::Windows::Forms::Label^ lblIva;
	private: System::Windows::Forms::Label^ lblTotalIva;
	private: System::Windows::Forms::TextBox^ txtTotal;
	private: System::Windows::Forms::TextBox^ txtIva;
	private: System::Windows::Forms::TextBox^ txtTotaIva;
	private: System::Windows::Forms::Button^ btnComprar;

	private: System::Windows::Forms::Button^ btnVolver;
	private: System::Windows::Forms::Button^ btnBorrarCarrito;


	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->lblTituloBody = (gcnew System::Windows::Forms::Label());
			this->lvLibros = (gcnew System::Windows::Forms::ListView());
			this->Titulo = (gcnew System::Windows::Forms::ColumnHeader());
			this->Autor = (gcnew System::Windows::Forms::ColumnHeader());
			this->Precio = (gcnew System::Windows::Forms::ColumnHeader());
			this->lblTotal = (gcnew System::Windows::Forms::Label());
			this->lblIva = (gcnew System::Windows::Forms::Label());
			this->lblTotalIva = (gcnew System::Windows::Forms::Label());
			this->txtTotal = (gcnew System::Windows::Forms::TextBox());
			this->txtIva = (gcnew System::Windows::Forms::TextBox());
			this->txtTotaIva = (gcnew System::Windows::Forms::TextBox());
			this->btnComprar = (gcnew System::Windows::Forms::Button());
			this->btnVolver = (gcnew System::Windows::Forms::Button());
			this->btnBorrarCarrito = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblTituloBody
			// 
			this->lblTituloBody->AutoSize = true;
			this->lblTituloBody->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTituloBody->ForeColor = System::Drawing::Color::SteelBlue;
			this->lblTituloBody->Location = System::Drawing::Point(22, 25);
			this->lblTituloBody->Name = L"lblTituloBody";
			this->lblTituloBody->Size = System::Drawing::Size(262, 31);
			this->lblTituloBody->TabIndex = 4;
			this->lblTituloBody->Text = L"Carrito de la compra";
			// 
			// lvLibros
			// 
			this->lvLibros->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->Titulo, this->Autor,
					this->Precio
			});
			this->lvLibros->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lvLibros->HideSelection = false;
			this->lvLibros->Location = System::Drawing::Point(28, 75);
			this->lvLibros->Name = L"lvLibros";
			this->lvLibros->Size = System::Drawing::Size(654, 218);
			this->lvLibros->TabIndex = 3;
			this->lvLibros->UseCompatibleStateImageBehavior = false;
			this->lvLibros->View = System::Windows::Forms::View::Details;
			// 
			// Titulo
			// 
			this->Titulo->Text = L"Titulo";
			this->Titulo->Width = 320;
			// 
			// Autor
			// 
			this->Autor->Text = L"Autor";
			this->Autor->Width = 225;
			// 
			// Precio
			// 
			this->Precio->Text = L"Precio";
			this->Precio->Width = 100;
			// 
			// lblTotal
			// 
			this->lblTotal->AutoSize = true;
			this->lblTotal->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTotal->ForeColor = System::Drawing::Color::IndianRed;
			this->lblTotal->Location = System::Drawing::Point(28, 329);
			this->lblTotal->Name = L"lblTotal";
			this->lblTotal->Size = System::Drawing::Size(57, 22);
			this->lblTotal->TabIndex = 5;
			this->lblTotal->Text = L"Total:";
			// 
			// lblIva
			// 
			this->lblIva->AutoSize = true;
			this->lblIva->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblIva->ForeColor = System::Drawing::Color::IndianRed;
			this->lblIva->Location = System::Drawing::Point(28, 364);
			this->lblIva->Name = L"lblIva";
			this->lblIva->Size = System::Drawing::Size(100, 22);
			this->lblIva->TabIndex = 6;
			this->lblIva->Text = L"IVA (21%):";
			// 
			// lblTotalIva
			// 
			this->lblTotalIva->AutoSize = true;
			this->lblTotalIva->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTotalIva->ForeColor = System::Drawing::Color::IndianRed;
			this->lblTotalIva->Location = System::Drawing::Point(28, 399);
			this->lblTotalIva->Name = L"lblTotalIva";
			this->lblTotalIva->Size = System::Drawing::Size(109, 22);
			this->lblTotalIva->TabIndex = 7;
			this->lblTotalIva->Text = L"Total + IVA:";
			// 
			// txtTotal
			// 
			this->txtTotal->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtTotal->ForeColor = System::Drawing::Color::SteelBlue;
			this->txtTotal->Location = System::Drawing::Point(172, 326);
			this->txtTotal->Name = L"txtTotal";
			this->txtTotal->ReadOnly = true;
			this->txtTotal->Size = System::Drawing::Size(151, 29);
			this->txtTotal->TabIndex = 8;
			this->txtTotal->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// txtIva
			// 
			this->txtIva->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtIva->ForeColor = System::Drawing::Color::SteelBlue;
			this->txtIva->Location = System::Drawing::Point(172, 361);
			this->txtIva->Name = L"txtIva";
			this->txtIva->ReadOnly = true;
			this->txtIva->Size = System::Drawing::Size(151, 29);
			this->txtIva->TabIndex = 9;
			this->txtIva->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// txtTotaIva
			// 
			this->txtTotaIva->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtTotaIva->ForeColor = System::Drawing::Color::SteelBlue;
			this->txtTotaIva->Location = System::Drawing::Point(172, 396);
			this->txtTotaIva->Name = L"txtTotaIva";
			this->txtTotaIva->ReadOnly = true;
			this->txtTotaIva->Size = System::Drawing::Size(151, 29);
			this->txtTotaIva->TabIndex = 10;
			this->txtTotaIva->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// btnComprar
			// 
			this->btnComprar->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnComprar->ForeColor = System::Drawing::Color::DarkGreen;
			this->btnComprar->Location = System::Drawing::Point(386, 326);
			this->btnComprar->Name = L"btnComprar";
			this->btnComprar->Size = System::Drawing::Size(144, 46);
			this->btnComprar->TabIndex = 11;
			this->btnComprar->Text = L"Comprar";
			this->btnComprar->UseVisualStyleBackColor = true;
			this->btnComprar->Click += gcnew System::EventHandler(this, &FormCarrito::btnComprar_Click);
			// 
			// btnVolver
			// 
			this->btnVolver->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnVolver->ForeColor = System::Drawing::Color::Gray;
			this->btnVolver->Location = System::Drawing::Point(538, 326);
			this->btnVolver->Name = L"btnVolver";
			this->btnVolver->Size = System::Drawing::Size(144, 46);
			this->btnVolver->TabIndex = 12;
			this->btnVolver->Text = L"Volver";
			this->btnVolver->UseVisualStyleBackColor = true;
			this->btnVolver->Click += gcnew System::EventHandler(this, &FormCarrito::btnVolver_Click);
			// 
			// btnBorrarCarrito
			// 
			this->btnBorrarCarrito->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBorrarCarrito->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnBorrarCarrito->Location = System::Drawing::Point(386, 379);
			this->btnBorrarCarrito->Name = L"btnBorrarCarrito";
			this->btnBorrarCarrito->Size = System::Drawing::Size(296, 46);
			this->btnBorrarCarrito->TabIndex = 13;
			this->btnBorrarCarrito->Text = L"Borrar Carrito";
			this->btnBorrarCarrito->UseVisualStyleBackColor = true;
			this->btnBorrarCarrito->Click += gcnew System::EventHandler(this, &FormCarrito::btnBorrarCarrito_Click);
			// 
			// FormCarrito
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(718, 452);
			this->ControlBox = false;
			this->Controls->Add(this->btnBorrarCarrito);
			this->Controls->Add(this->btnVolver);
			this->Controls->Add(this->btnComprar);
			this->Controls->Add(this->txtTotaIva);
			this->Controls->Add(this->txtIva);
			this->Controls->Add(this->txtTotal);
			this->Controls->Add(this->lblTotalIva);
			this->Controls->Add(this->lblIva);
			this->Controls->Add(this->lblTotal);
			this->Controls->Add(this->lblTituloBody);
			this->Controls->Add(this->lvLibros);
			this->Name = L"FormCarrito";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FormCarrito";
			this->Load += gcnew System::EventHandler(this, &FormCarrito::FormCarrito_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


		Void btnBorrarCarrito_Click(Object^ sender, EventArgs^ e)
		{
			login->GetUsuario().GetCarrito()->BorrarCarrito();
			this->Close();
		}

		Void btnVolver_Click(System::Object^ sender, System::EventArgs^ e)
		{
			this->Close();
		}
		Void btnComprar_Click(Object^ sender, EventArgs^ e)
		{

		}
		Void FormCarrito_Load(Object^ sender, EventArgs^ e)
		{
			RellenarListadoLibros(login->GetUsuario().GetCarrito()->ListadoCarrito());

			txtTotal->Text = gcnew String(login->GetUsuario().GetCarrito()->GetTotal().ToString("N2"));
			txtIva->Text = gcnew String(login->GetUsuario().GetCarrito()->GetIva().ToString("N2"));
			txtTotaIva->Text = gcnew String(login->GetUsuario().GetCarrito()->GetTotalIva().ToString("N2"));

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
	};
}
