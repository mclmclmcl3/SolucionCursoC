#pragma once

namespace FormLibreria {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FormAdministrador
	/// </summary>
	public ref class FormAdministrador : public System::Windows::Forms::Form
	{
	public:
		FormAdministrador(void)
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
		~FormAdministrador()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblTituloBody;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ btnCarritoUsuario;
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
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lblTituloBody = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->btnCarritoUsuario = (gcnew System::Windows::Forms::Button());
			this->txtTitulo = (gcnew System::Windows::Forms::TextBox());
			this->txtPrecio = (gcnew System::Windows::Forms::TextBox());
			this->lblTituloLibre = (gcnew System::Windows::Forms::Label());
			this->txtAutor = (gcnew System::Windows::Forms::TextBox());
			this->lblAutorLibro = (gcnew System::Windows::Forms::Label());
			this->lblPrecioLibro = (gcnew System::Windows::Forms::Label());
			this->lvLibros = (gcnew System::Windows::Forms::ListView());
			this->Titulo = (gcnew System::Windows::Forms::ColumnHeader());
			this->Autor = (gcnew System::Windows::Forms::ColumnHeader());
			this->Precio = (gcnew System::Windows::Forms::ColumnHeader());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
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
			this->groupBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox1->Size = System::Drawing::Size(443, 178);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Añadir libros";
			// 
			// btnCarritoUsuario
			// 
			this->btnCarritoUsuario->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCarritoUsuario->ForeColor = System::Drawing::SystemColors::Highlight;
			this->btnCarritoUsuario->Location = System::Drawing::Point(552, 122);
			this->btnCarritoUsuario->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnCarritoUsuario->Name = L"btnCarritoUsuario";
			this->btnCarritoUsuario->Size = System::Drawing::Size(169, 46);
			this->btnCarritoUsuario->TabIndex = 9;
			this->btnCarritoUsuario->Text = L"Añadir";
			this->btnCarritoUsuario->UseVisualStyleBackColor = true;
			// 
			// txtTitulo
			// 
			this->txtTitulo->Location = System::Drawing::Point(90, 51);
			this->txtTitulo->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->txtTitulo->Name = L"txtTitulo";
			this->txtTitulo->Size = System::Drawing::Size(313, 26);
			this->txtTitulo->TabIndex = 6;
			// 
			// txtPrecio
			// 
			this->txtPrecio->Location = System::Drawing::Point(90, 130);
			this->txtPrecio->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
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
			this->txtAutor->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
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
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::SystemColors::Highlight;
			this->button1->Location = System::Drawing::Point(552, 194);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(169, 46);
			this->button1->TabIndex = 12;
			this->button1->Text = L"Borrar";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::SystemColors::Highlight;
			this->button2->Location = System::Drawing::Point(749, 122);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(169, 46);
			this->button2->TabIndex = 13;
			this->button2->Text = L"Volver";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::SystemColors::Highlight;
			this->button3->Location = System::Drawing::Point(749, 194);
			this->button3->Margin = System::Windows::Forms::Padding(4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(169, 46);
			this->button3->TabIndex = 14;
			this->button3->Text = L"Salir";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// FormAdministrador
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 19);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(968, 607);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->btnCarritoUsuario);
			this->Controls->Add(this->lvLibros);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->lblTituloBody);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"FormAdministrador";
			this->Text = L"FormAdministrador";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
