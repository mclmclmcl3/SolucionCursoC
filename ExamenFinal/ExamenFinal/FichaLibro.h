#pragma once
#include "Libro.h"
#include "Carrito.h"
#include <msclr/marshal_cppstd.h>

namespace ExamenFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FichaLibro
	/// </summary>
	public ref class FichaLibro : public System::Windows::Forms::Form
	{
	public: Libro* libro;
	private: System::Windows::Forms::Label^ lblTitulo;
	public:
	private: System::Windows::Forms::TextBox^ txtTitulo;
	private: System::Windows::Forms::TextBox^ txtAutor;

	private: System::Windows::Forms::Label^ lblAutor;
	private: System::Windows::Forms::TextBox^ txtPrecio;

	private: System::Windows::Forms::Label^ lblPrecio;
	private: System::Windows::Forms::Button^ btnComprar;
	private: System::Windows::Forms::Label^ lblId;

	public: Carrito* carrito;

	public:
		FichaLibro(Libro* _libro, Carrito* _carrito)
		{
			InitializeComponent();
			libro = _libro;
			carrito = _carrito;

			lblId->Text = System::Convert::ToString(_libro->GetId());
			txtTitulo->Text = gcnew String(_libro->GetTitulo().c_str());
			txtAutor->Text = gcnew String(_libro->GetAutor().c_str());
			txtPrecio->Text = System::Convert::ToString(_libro->GetPrecio());

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FichaLibro()
		{
			if (components)
			{
				delete components;
			}
		}

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
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			this->txtTitulo = (gcnew System::Windows::Forms::TextBox());
			this->txtAutor = (gcnew System::Windows::Forms::TextBox());
			this->lblAutor = (gcnew System::Windows::Forms::Label());
			this->txtPrecio = (gcnew System::Windows::Forms::TextBox());
			this->lblPrecio = (gcnew System::Windows::Forms::Label());
			this->btnComprar = (gcnew System::Windows::Forms::Button());
			this->lblId = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lblTitulo
			// 
			this->lblTitulo->AutoSize = true;
			this->lblTitulo->Location = System::Drawing::Point(59, 50);
			this->lblTitulo->Name = L"lblTitulo";
			this->lblTitulo->Size = System::Drawing::Size(39, 16);
			this->lblTitulo->TabIndex = 0;
			this->lblTitulo->Text = L"Titulo";
			// 
			// txtTitulo
			// 
			this->txtTitulo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtTitulo->Location = System::Drawing::Point(62, 70);
			this->txtTitulo->Name = L"txtTitulo";
			this->txtTitulo->Size = System::Drawing::Size(421, 23);
			this->txtTitulo->TabIndex = 1;
			// 
			// txtAutor
			// 
			this->txtAutor->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtAutor->Location = System::Drawing::Point(62, 133);
			this->txtAutor->Name = L"txtAutor";
			this->txtAutor->Size = System::Drawing::Size(421, 23);
			this->txtAutor->TabIndex = 3;
			// 
			// lblAutor
			// 
			this->lblAutor->AutoSize = true;
			this->lblAutor->Location = System::Drawing::Point(59, 113);
			this->lblAutor->Name = L"lblAutor";
			this->lblAutor->Size = System::Drawing::Size(38, 16);
			this->lblAutor->TabIndex = 2;
			this->lblAutor->Text = L"Autor";
			// 
			// txtPrecio
			// 
			this->txtPrecio->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtPrecio->Location = System::Drawing::Point(62, 196);
			this->txtPrecio->Name = L"txtPrecio";
			this->txtPrecio->Size = System::Drawing::Size(421, 23);
			this->txtPrecio->TabIndex = 5;
			// 
			// lblPrecio
			// 
			this->lblPrecio->AutoSize = true;
			this->lblPrecio->Location = System::Drawing::Point(59, 176);
			this->lblPrecio->Name = L"lblPrecio";
			this->lblPrecio->Size = System::Drawing::Size(42, 16);
			this->lblPrecio->TabIndex = 4;
			this->lblPrecio->Text = L"Precio";
			// 
			// btnComprar
			// 
			this->btnComprar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnComprar->Location = System::Drawing::Point(199, 268);
			this->btnComprar->Name = L"btnComprar";
			this->btnComprar->Size = System::Drawing::Size(117, 28);
			this->btnComprar->TabIndex = 6;
			this->btnComprar->Text = L"Comprar";
			this->btnComprar->UseVisualStyleBackColor = true;
			this->btnComprar->Click += gcnew System::EventHandler(this, &FichaLibro::btnComprar_Click);
			// 
			// lblId
			// 
			this->lblId->AutoSize = true;
			this->lblId->Location = System::Drawing::Point(62, 13);
			this->lblId->Name = L"lblId";
			this->lblId->Size = System::Drawing::Size(54, 16);
			this->lblId->TabIndex = 7;
			this->lblId->Text = L"IdOculto";
			this->lblId->Visible = false;
			// 
			// FichaLibro
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(538, 347);
			this->Controls->Add(this->lblId);
			this->Controls->Add(this->btnComprar);
			this->Controls->Add(this->txtPrecio);
			this->Controls->Add(this->lblPrecio);
			this->Controls->Add(this->txtAutor);
			this->Controls->Add(this->lblAutor);
			this->Controls->Add(this->txtTitulo);
			this->Controls->Add(this->lblTitulo);
			this->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"FichaLibro";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FichaLibro";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		// Conversor de string
		std::string StringToSTDstring(String^ texto)
		{
			return msclr::interop::marshal_as < std::string>(texto);
		}


#pragma endregion



		Void btnComprar_Click(Object^ sender, EventArgs^ e)
		{
			int id = System::Convert::ToInt32(lblId->Text);
			std::string titulo = StringToSTDstring(txtTitulo->Text);
			std::string autor = StringToSTDstring(txtAutor->Text);
			double precio = System::Convert::ToDouble(txtPrecio->Text);

			Libro libro(id, titulo, autor, precio);
			carrito->ComprarLibro(libro);

			this->Close();
		}
	};
}
