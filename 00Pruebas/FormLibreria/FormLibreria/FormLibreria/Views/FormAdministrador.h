#pragma once
#include "../Models/Libreria.h"

namespace FormLibreria {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class FormAdministrador : public System::Windows::Forms::Form
	{
	public:
		Libreria* libreria;

	public:
		FormAdministrador(Libreria* libreriaInstancia)
		{
			InitializeComponent();
			libreria = libreriaInstancia;
		}

	protected:
		~FormAdministrador()
		{
			if (components)
			{
				delete components;
			}
		}

		void RellenarListadoLibros(std::vector<Libro> libros)
		{
			lvLibros->Items->Clear();

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


	private: System::Windows::Forms::Label^ lblTituloBody;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ btnAdd;

	private: System::Windows::Forms::TextBox^ txtTitulo;
	private: System::Windows::Forms::TextBox^ txtPrecio;
	private: System::Windows::Forms::Label^ lblTituloLibre;
	private: System::Windows::Forms::TextBox^ txtAutor;
	private: System::Windows::Forms::Label^ lblAutorLibro;
	private: System::Windows::Forms::Label^ lblPrecioLibro;
	private: System::Windows::Forms::ListView^ lvLibros;
	private: System::Windows::Forms::ColumnHeader^ Titulo;
	private: System::Windows::Forms::ColumnHeader^ Autor;
	private: System::Windows::Forms::ColumnHeader^ Precio;
	private: System::Windows::Forms::Button^ btnBorrar;
	private: System::Windows::Forms::Button^ btnVolver;
	private: System::Windows::Forms::Button^ btnModificar;




	protected:

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->lblTituloBody = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->txtTitulo = (gcnew System::Windows::Forms::TextBox());
			this->txtPrecio = (gcnew System::Windows::Forms::TextBox());
			this->lblTituloLibre = (gcnew System::Windows::Forms::Label());
			this->txtAutor = (gcnew System::Windows::Forms::TextBox());
			this->lblAutorLibro = (gcnew System::Windows::Forms::Label());
			this->lblPrecioLibro = (gcnew System::Windows::Forms::Label());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->lvLibros = (gcnew System::Windows::Forms::ListView());
			this->Titulo = (gcnew System::Windows::Forms::ColumnHeader());
			this->Autor = (gcnew System::Windows::Forms::ColumnHeader());
			this->Precio = (gcnew System::Windows::Forms::ColumnHeader());
			this->btnBorrar = (gcnew System::Windows::Forms::Button());
			this->btnVolver = (gcnew System::Windows::Forms::Button());
			this->btnModificar = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// lblTituloBody
			// 
			this->lblTituloBody->AutoSize = true;
			this->lblTituloBody->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTituloBody->ForeColor = System::Drawing::Color::SteelBlue;
			this->lblTituloBody->Location = System::Drawing::Point(42, 34);
			this->lblTituloBody->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblTituloBody->Name = L"lblTituloBody";
			this->lblTituloBody->Size = System::Drawing::Size(402, 31);
			this->lblTituloBody->TabIndex = 3;
			this->lblTituloBody->Text = L"Pantalla para la gestion de libros";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->txtTitulo);
			this->groupBox1->Controls->Add(this->txtPrecio);
			this->groupBox1->Controls->Add(this->lblTituloLibre);
			this->groupBox1->Controls->Add(this->txtAutor);
			this->groupBox1->Controls->Add(this->lblAutorLibro);
			this->groupBox1->Controls->Add(this->lblPrecioLibro);
			this->groupBox1->Location = System::Drawing::Point(48, 87);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4);
			this->groupBox1->Size = System::Drawing::Size(443, 178);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Añadir libros";
			// 
			// txtTitulo
			// 
			this->txtTitulo->Location = System::Drawing::Point(90, 51);
			this->txtTitulo->Margin = System::Windows::Forms::Padding(4);
			this->txtTitulo->Name = L"txtTitulo";
			this->txtTitulo->Size = System::Drawing::Size(313, 26);
			this->txtTitulo->TabIndex = 6;
			// 
			// txtPrecio
			// 
			this->txtPrecio->Location = System::Drawing::Point(90, 130);
			this->txtPrecio->Margin = System::Windows::Forms::Padding(4);
			this->txtPrecio->Name = L"txtPrecio";
			this->txtPrecio->Size = System::Drawing::Size(146, 26);
			this->txtPrecio->TabIndex = 8;
			this->txtPrecio->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// lblTituloLibre
			// 
			this->lblTituloLibre->AutoSize = true;
			this->lblTituloLibre->Location = System::Drawing::Point(28, 56);
			this->lblTituloLibre->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblTituloLibre->Name = L"lblTituloLibre";
			this->lblTituloLibre->Size = System::Drawing::Size(48, 19);
			this->lblTituloLibre->TabIndex = 3;
			this->lblTituloLibre->Text = L"Titulo";
			// 
			// txtAutor
			// 
			this->txtAutor->Location = System::Drawing::Point(90, 90);
			this->txtAutor->Margin = System::Windows::Forms::Padding(4);
			this->txtAutor->Name = L"txtAutor";
			this->txtAutor->Size = System::Drawing::Size(313, 26);
			this->txtAutor->TabIndex = 7;
			// 
			// lblAutorLibro
			// 
			this->lblAutorLibro->AutoSize = true;
			this->lblAutorLibro->Location = System::Drawing::Point(28, 94);
			this->lblAutorLibro->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblAutorLibro->Name = L"lblAutorLibro";
			this->lblAutorLibro->Size = System::Drawing::Size(47, 19);
			this->lblAutorLibro->TabIndex = 4;
			this->lblAutorLibro->Text = L"Autor";
			// 
			// lblPrecioLibro
			// 
			this->lblPrecioLibro->AutoSize = true;
			this->lblPrecioLibro->Location = System::Drawing::Point(28, 134);
			this->lblPrecioLibro->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblPrecioLibro->Name = L"lblPrecioLibro";
			this->lblPrecioLibro->Size = System::Drawing::Size(51, 19);
			this->lblPrecioLibro->TabIndex = 5;
			this->lblPrecioLibro->Text = L"Precio";
			// 
			// btnAdd
			// 
			this->btnAdd->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAdd->ForeColor = System::Drawing::SystemColors::Highlight;
			this->btnAdd->Location = System::Drawing::Point(552, 122);
			this->btnAdd->Margin = System::Windows::Forms::Padding(4);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(169, 46);
			this->btnAdd->TabIndex = 9;
			this->btnAdd->Text = L"Añadir";
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &FormAdministrador::btnAdd_Click);
			// 
			// lvLibros
			// 
			this->lvLibros->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->Titulo, this->Autor,
					this->Precio
			});
			this->lvLibros->HideSelection = false;
			this->lvLibros->Location = System::Drawing::Point(48, 304);
			this->lvLibros->Name = L"lvLibros";
			this->lvLibros->Size = System::Drawing::Size(870, 264);
			this->lvLibros->TabIndex = 11;
			this->lvLibros->UseCompatibleStateImageBehavior = false;
			this->lvLibros->View = System::Windows::Forms::View::Details;
			this->lvLibros->SelectedIndexChanged += gcnew System::EventHandler(this, &FormAdministrador::lvLibros_SelectedIndexChanged);
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
			// btnBorrar
			// 
			this->btnBorrar->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBorrar->ForeColor = System::Drawing::SystemColors::Highlight;
			this->btnBorrar->Location = System::Drawing::Point(552, 194);
			this->btnBorrar->Margin = System::Windows::Forms::Padding(4);
			this->btnBorrar->Name = L"btnBorrar";
			this->btnBorrar->Size = System::Drawing::Size(169, 46);
			this->btnBorrar->TabIndex = 12;
			this->btnBorrar->Text = L"Borrar";
			this->btnBorrar->UseVisualStyleBackColor = true;
			this->btnBorrar->Click += gcnew System::EventHandler(this, &FormAdministrador::btnBorrar_Click);
			// 
			// btnVolver
			// 
			this->btnVolver->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnVolver->ForeColor = System::Drawing::SystemColors::Highlight;
			this->btnVolver->Location = System::Drawing::Point(749, 122);
			this->btnVolver->Margin = System::Windows::Forms::Padding(4);
			this->btnVolver->Name = L"btnVolver";
			this->btnVolver->Size = System::Drawing::Size(169, 46);
			this->btnVolver->TabIndex = 13;
			this->btnVolver->Text = L"Volver";
			this->btnVolver->UseVisualStyleBackColor = true;
			this->btnVolver->Click += gcnew System::EventHandler(this, &FormAdministrador::btnVolver_Click);
			// 
			// btnModificar
			// 
			this->btnModificar->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnModificar->ForeColor = System::Drawing::SystemColors::Highlight;
			this->btnModificar->Location = System::Drawing::Point(749, 194);
			this->btnModificar->Margin = System::Windows::Forms::Padding(4);
			this->btnModificar->Name = L"btnModificar";
			this->btnModificar->Size = System::Drawing::Size(169, 46);
			this->btnModificar->TabIndex = 14;
			this->btnModificar->Text = L"Modificar Precio";
			this->btnModificar->UseVisualStyleBackColor = true;
			this->btnModificar->Click += gcnew System::EventHandler(this, &FormAdministrador::btnModificar_Click);
			// 
			// FormAdministrador
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 19);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(968, 607);
			this->Controls->Add(this->btnModificar);
			this->Controls->Add(this->btnVolver);
			this->Controls->Add(this->btnBorrar);
			this->Controls->Add(this->btnAdd);
			this->Controls->Add(this->lvLibros);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->lblTituloBody);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"FormAdministrador";
			this->Text = L"FormAdministrador";
			this->Load += gcnew System::EventHandler(this, &FormAdministrador::FormAdministrador_Load);
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


		Libro ConvetTxtToLibro()
		{
			String^ titulo = txtTitulo->Text;
			String^ autor = txtAutor->Text;
			String^ precio = txtPrecio->Text;

			string tituloStd = msclr::interop::marshal_as<std::string>(titulo);
			string autorStd = msclr::interop::marshal_as<std::string>(autor);
			double precioDb = System::Convert::ToDouble(precio);

			Libro libro;
			libro.SetAutor(autorStd);
			libro.SetTitulo(tituloStd);
			libro.SetPrecio(precioDb);

			return libro;
		}



		Void btnAdd_Click(Object^ sender, EventArgs^ e)
		{
			libreria->InsertLibro(ConvetTxtToLibro());
			txtTitulo->Text = "";
			txtAutor->Text = "";
			txtPrecio->Text = "";

			RellenarListadoLibros(libreria->GetAllLibros());
		}

		Void btnVolver_Click(Object^ sender, EventArgs^ e)
		{
			this->Close();
		}

		//Void btnSalir_Click(Object^ sender, EventArgs^ e)
		//{
		//	Application::Exit();
		//}

		Void btnBorrar_Click(Object^ sender, EventArgs^ e)
		{
			libreria->BorrarLibro(ConvetTxtToLibro());
			txtTitulo->Text = "";
			txtAutor->Text = "";
			txtPrecio->Text = "";

			RellenarListadoLibros(libreria->GetAllLibros());
		}

		Void FormAdministrador_Load(Object^ sender, EventArgs^ e)
		{
			lvLibros->FullRowSelect = true;
			RellenarListadoLibros(libreria->GetAllLibros());
		}


		Void btnModificar_Click(Object^ sender, EventArgs^ e)
		{
			Libro libro = ConvetTxtToLibro();
			libreria->ModificarLibro(libro);
			txtTitulo->Text = "";
			txtAutor->Text = "";
			txtPrecio->Text = "";

			RellenarListadoLibros(libreria->GetAllLibros());
		}
	};
}
