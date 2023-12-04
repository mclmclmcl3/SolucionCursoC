#pragma once

namespace PrueaGridView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de inicio
	/// </summary>
	public ref class inicio : public System::Windows::Forms::Form
	{
	public:
		inicio(void)
		{
			InitializeComponent();
			RellenarGridView();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~inicio()
		{
			if (components)
			{
				delete components;
			}
		}

		void RellenarGridView()
		{
			DataTable^ mitabla = gcnew DataTable();
			DataRow^ fila;

			mitabla->Columns->Add("Id", Int32::typeid);
			mitabla->Columns->Add("Nombre", String::typeid);
			mitabla->Columns->Add("Apellido", String::typeid);

			for (int i = 0; i < 3; i++)
			{
				fila = mitabla->NewRow();
				fila["Id"] = i + 1;
				fila["Nombre"] = "Nombre" + (i + 1);
				fila["Apellido"] = "Apellido" + (i + 1);
				mitabla->Rows->Add(fila);
			}

			cgv->DataSource = mitabla;
		}
	private: System::Windows::Forms::DataGridView^ cgv;
	protected:


	protected:

	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->cgv = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cgv))->BeginInit();
			this->SuspendLayout();
			// 
			// cgv
			// 
			this->cgv->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->cgv->Location = System::Drawing::Point(63, 39);
			this->cgv->Name = L"cgv";
			this->cgv->Size = System::Drawing::Size(664, 208);
			this->cgv->TabIndex = 0;
			this->cgv->CellMouseClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &inicio::cgv_CellMouseClick);
			// 
			// inicio
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(808, 432);
			this->Controls->Add(this->cgv);
			this->Name = L"inicio";
			this->Text = L"inicio";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cgv))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	


	Void cgv_CellMouseClick(Object^ sender, Windows::Forms::DataGridViewCellMouseEventArgs^ e) 
	{			// Verificar si el �ndice de la celda est� dentro de los l�mites
		if (e->RowIndex >= 0 && e->ColumnIndex >= 0)
		{
			// Obtener el valor de la celda seleccionada
			Object^ nombre = cgv->Rows[e->RowIndex]->Cells[1]->Value;
			Object^ apellido = cgv->Rows[e->RowIndex]->Cells[2]->Value;

			//Object^ cellValue = cgv->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value;

			// Verificar si el valor no es nulo
			if (nombre != nullptr && apellido != nullptr)
			{
				// Convertir el valor a String y mostrar en un MessageBox
				String^ nombreSelect = nombre->ToString();
				String^ apellidoSelect = apellido->ToString();
				MessageBox::Show(nombreSelect + " " + apellidoSelect);
			}
			else
			{
				// Manejar el caso en que el valor de la celda sea nulo
				MessageBox::Show("La celda seleccionada est� vac�a");
			}
		}
		else
		{
			// Manejar el caso en que el �ndice de la celda est� fuera de los l�mites
			MessageBox::Show("�ndice de celda no v�lido");
		}
	}
};
}
