#pragma once

#include "Carrito.h"

namespace ExamenFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FormCarrito
	/// </summary>
	public ref class FormCarrito : public System::Windows::Forms::Form
	{

	public: Carrito* carrito;
	public:
		FormCarrito(Carrito* _carrito)
		{
			InitializeComponent();
			carrito = _carrito;

			// Relleno los textBox
			totaltxt->Text = System::Convert::ToString(carrito->GetTotal());
			ivatxt->Text = System::Convert::ToString(carrito->GetIva());
			TotalIvatxt->Text = System::Convert::ToString(carrito->GetTotalIva());

			// Relleno el listView
			for each (Libro libro in carrito->ListadoCarrito())
			{
				ListViewItem^ listado = gcnew ListViewItem(gcnew String(libro.GetTitulo().c_str()));
				listado->SubItems->Add(gcnew String(libro.GetAutor().c_str()));

				// Convertir el precio a String^ antes de agregarlo
				listado->SubItems->Add(gcnew String(libro.GetPrecio().ToString("N2")));

				// Agregar el ListViewItem en cada iteración
				lvCarrito->Items->Add(listado);
			}
		}



	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FormCarrito()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListView^ lvCarrito;
	protected:

	protected:
	private: System::Windows::Forms::ColumnHeader^ Titulo;
	private: System::Windows::Forms::ColumnHeader^ Autor;
	private: System::Windows::Forms::ColumnHeader^ Precio;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ totaltxt;

	private: System::Windows::Forms::TextBox^ txtIva;
	private: System::Windows::Forms::TextBox^ txtTotalIva;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ ivatxt;

	private: System::Windows::Forms::TextBox^ TotalIvatxt;
	private: System::Windows::Forms::Button^ btnComprar;





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
			this->lvCarrito = (gcnew System::Windows::Forms::ListView());
			this->Titulo = (gcnew System::Windows::Forms::ColumnHeader());
			this->Autor = (gcnew System::Windows::Forms::ColumnHeader());
			this->Precio = (gcnew System::Windows::Forms::ColumnHeader());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->totaltxt = (gcnew System::Windows::Forms::TextBox());
			this->txtIva = (gcnew System::Windows::Forms::TextBox());
			this->txtTotalIva = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->ivatxt = (gcnew System::Windows::Forms::TextBox());
			this->TotalIvatxt = (gcnew System::Windows::Forms::TextBox());
			this->btnComprar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lvCarrito
			// 
			this->lvCarrito->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->Titulo, this->Autor,
					this->Precio
			});
			this->lvCarrito->HideSelection = false;
			this->lvCarrito->Location = System::Drawing::Point(69, 87);
			this->lvCarrito->Margin = System::Windows::Forms::Padding(4);
			this->lvCarrito->Name = L"lvCarrito";
			this->lvCarrito->Size = System::Drawing::Size(514, 355);
			this->lvCarrito->TabIndex = 0;
			this->lvCarrito->UseCompatibleStateImageBehavior = false;
			this->lvCarrito->View = System::Windows::Forms::View::Details;
			// 
			// Titulo
			// 
			this->Titulo->Text = L"Titulo";
			this->Titulo->Width = 200;
			// 
			// Autor
			// 
			this->Autor->Text = L"Autor";
			this->Autor->Width = 150;
			// 
			// Precio
			// 
			this->Precio->Text = L"Precio";
			this->Precio->Width = 80;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Tahoma", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->label1->Location = System::Drawing::Point(63, 28);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(85, 25);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Carrito";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(69, 470);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(36, 16);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Total";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(69, 506);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(24, 16);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Iva";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(69, 541);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(69, 16);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Total + Iva";
			// 
			// totaltxt
			// 
			this->totaltxt->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->totaltxt->Location = System::Drawing::Point(208, 465);
			this->totaltxt->Name = L"totaltxt";
			this->totaltxt->Size = System::Drawing::Size(110, 27);
			this->totaltxt->TabIndex = 7;
			// 
			// txtIva
			// 
			this->txtIva->Location = System::Drawing::Point(208, 503);
			this->txtIva->Name = L"txtIva";
			this->txtIva->Size = System::Drawing::Size(110, 23);
			this->txtIva->TabIndex = 8;
			// 
			// txtTotalIva
			// 
			this->txtTotalIva->Location = System::Drawing::Point(208, 541);
			this->txtTotalIva->Name = L"txtTotalIva";
			this->txtTotalIva->Size = System::Drawing::Size(110, 23);
			this->txtTotalIva->TabIndex = 9;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(68, 468);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(52, 19);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Total";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(70, 506);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(35, 19);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Iva";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(68, 545);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(101, 19);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Total + Iva";
			// 
			// ivatxt
			// 
			this->ivatxt->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ivatxt->Location = System::Drawing::Point(208, 503);
			this->ivatxt->Name = L"ivatxt";
			this->ivatxt->Size = System::Drawing::Size(110, 27);
			this->ivatxt->TabIndex = 8;
			// 
			// TotalIvatxt
			// 
			this->TotalIvatxt->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TotalIvatxt->Location = System::Drawing::Point(208, 541);
			this->TotalIvatxt->Name = L"TotalIvatxt";
			this->TotalIvatxt->Size = System::Drawing::Size(110, 27);
			this->TotalIvatxt->TabIndex = 9;
			// 
			// btnComprar
			// 
			this->btnComprar->Font = (gcnew System::Drawing::Font(L"Tahoma", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnComprar->Location = System::Drawing::Point(392, 465);
			this->btnComprar->Name = L"btnComprar";
			this->btnComprar->Size = System::Drawing::Size(191, 103);
			this->btnComprar->TabIndex = 10;
			this->btnComprar->Text = L"COMPRAR";
			this->btnComprar->UseVisualStyleBackColor = true;
			this->btnComprar->Click += gcnew System::EventHandler(this, &FormCarrito::btnComprar_Click);
			// 
			// FormCarrito
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(651, 655);
			this->Controls->Add(this->btnComprar);
			this->Controls->Add(this->TotalIvatxt);
			this->Controls->Add(this->txtTotalIva);
			this->Controls->Add(this->ivatxt);
			this->Controls->Add(this->txtIva);
			this->Controls->Add(this->totaltxt);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lvCarrito);
			this->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"FormCarrito";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FormCarrito";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	Void btnComprar_Click(Object^ sender, EventArgs^ e) 
	{
		// Borro el carrito ya que supuestamente he comprado y cierro la ventana

		carrito->BorrarCarrito();
		this->Close();
	}
};
}
