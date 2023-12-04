#pragma once
#include "MsqlConexion.h"
#include "FichaLibro.h"
#include "FormCarrito.h"
#include "Carrito.h"
#include "Libro.h"
#include <vector>
#include <msclr/marshal_cppstd.h>

namespace ExamenFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class TiendaOnline : public System::Windows::Forms::Form
	{
		// Crear la conexión
	public: MsqlConexion* conexion;

	public:
	public: Carrito* carrito;

	public:
		TiendaOnline(void)
		{
			InitializeComponent();
			// Inicializo el carrito para usarlo despues
			carrito = new Carrito();

			// Configuro a mi gusto el datagridview
			MiDataGridView->ReadOnly = true;
			MiDataGridView->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
			MiDataGridView->MultiSelect = false;
			MiDataGridView->ClearSelection();

			// Inicio conexion con la BBDD
			conexion = new MsqlConexion(3306, "localhost", "root", "root", "ExamenFinal");

			// Relleno la datagridview
			RellenarListadoLibros(conexion->LeerTodo());

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~TiendaOnline()
		{
			if (components)
			{
				delete components;
			}
		}

		void RellenarListadoLibros(std::vector<Libro> libros)
		{
			DataTable^ dataTable = gcnew DataTable();

			// Agrega las columnas al DataTable
			dataTable->Columns->Add("ID", Int32::typeid);
			dataTable->Columns->Add("Titulo", String::typeid);
			dataTable->Columns->Add("Autor", String::typeid);
			dataTable->Columns->Add("Precio", double::typeid);

			// Llena el DataTable con los datos de los libros
			for each (Libro libro in libros)
			{
				DataRow^ row = dataTable->NewRow();
				row["ID"] = libro.GetId();
				row["Titulo"] = gcnew String(libro.GetTitulo().c_str());
				row["Autor"] = gcnew String(libro.GetAutor().c_str());
				row["Precio"] = libro.GetPrecio().ToString("N2");
				dataTable->Rows->Add(row);
			}

			// Desactiva la selección automática
			MiDataGridView->SelectionMode = DataGridViewSelectionMode::FullRowSelect;

			// Establece el DataTable como fuente de datos para el DataGridView
			MiDataGridView->DataSource = dataTable;
			MiDataGridView->ClearSelection();

			// Define manualmente el tamaño de las columnas (ajústalos según tus necesidades)
			MiDataGridView->Columns["ID"]->Width = 50; // Tamaño de la columna ID
			MiDataGridView->Columns["Titulo"]->Width = 250; // Tamaño de la columna Titulo
			MiDataGridView->Columns["Autor"]->Width = 150; // Tamaño de la columna Autor
			MiDataGridView->Columns["Precio"]->Width = 80; // Tamaño de la columna Precio

			// Ajusta automáticamente el ancho de las columnas según el contenido
			MiDataGridView->AutoResizeColumns(DataGridViewAutoSizeColumnsMode::AllCells);

			// Activa la selección automática después de cargar los datos
			MiDataGridView->SelectionMode = DataGridViewSelectionMode::CellSelect;

			// Limpia la selección
			MiDataGridView->ClearSelection();
		}


	private: System::Windows::Forms::Panel^ PPanel;
	protected:
	private: System::Windows::Forms::Button^ btnIrCarrito;
	private: System::Windows::Forms::DataGridView^ MiDataGridView;
	private: System::Windows::Forms::Label^ label1;





	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->PPanel = (gcnew System::Windows::Forms::Panel());
			this->btnIrCarrito = (gcnew System::Windows::Forms::Button());
			this->MiDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->PPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MiDataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// PPanel
			// 
			this->PPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->PPanel->BackColor = System::Drawing::Color::DimGray;
			this->PPanel->Controls->Add(this->btnIrCarrito);
			this->PPanel->Location = System::Drawing::Point(-4, -3);
			this->PPanel->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->PPanel->Name = L"PPanel";
			this->PPanel->Size = System::Drawing::Size(226, 467);
			this->PPanel->TabIndex = 0;
			// 
			// btnIrCarrito
			// 
			this->btnIrCarrito->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnIrCarrito->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->btnIrCarrito->Location = System::Drawing::Point(30, 48);
			this->btnIrCarrito->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->btnIrCarrito->Name = L"btnIrCarrito";
			this->btnIrCarrito->Size = System::Drawing::Size(174, 45);
			this->btnIrCarrito->TabIndex = 0;
			this->btnIrCarrito->Text = L"Ir al Carrito";
			this->btnIrCarrito->UseVisualStyleBackColor = false;
			this->btnIrCarrito->Click += gcnew System::EventHandler(this, &TiendaOnline::btnIrCarrito_Click);
			// 
			// MiDataGridView
			// 
			this->MiDataGridView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->MiDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->MiDataGridView->Location = System::Drawing::Point(267, 79);
			this->MiDataGridView->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->MiDataGridView->Name = L"MiDataGridView";
			this->MiDataGridView->Size = System::Drawing::Size(626, 320);
			this->MiDataGridView->TabIndex = 1;
			this->MiDataGridView->CellMouseClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &TiendaOnline::MiDataGridView_CellMouseClick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Tahoma", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->label1->Location = System::Drawing::Point(267, 29);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(377, 25);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Selecciona un elemento de la Tabla";
			// 
			// TiendaOnline
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(928, 461);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->MiDataGridView);
			this->Controls->Add(this->PPanel);
			this->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->Name = L"TiendaOnline";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"TiendaOnline";
			this->PPanel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MiDataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


		Void btnIrCarrito_Click(Object^ sender, EventArgs^ e)
		{
			// Mostrar el carrito
			FormCarrito^ fCarrito = gcnew FormCarrito(carrito);
			this->Hide();
			fCarrito->ShowDialog();
			this->Show();

		}


		Void MiDataGridView_CellMouseClick(Object^ sender, Windows::Forms::DataGridViewCellMouseEventArgs^ e)
		{
			// Chequeo que he seleccionado un elemento de la lista
			if (e->RowIndex >= 0 && e->ColumnIndex >= 0 && e->RowIndex < MiDataGridView->RowCount)
			{
				// Extraigo sus datos
				Object^ _id = MiDataGridView->Rows[e->RowIndex]->Cells[0]->Value;
				Object^ _titulo = MiDataGridView->Rows[e->RowIndex]->Cells[1]->Value;
				Object^ _autor = MiDataGridView->Rows[e->RowIndex]->Cells[2]->Value;
				Object^ _precio = MiDataGridView->Rows[e->RowIndex]->Cells[3]->Value;

				// Verificar si los valores no son nulos ni DBNull antes de realizar conversiones
				if (_id != nullptr && _titulo != nullptr && _autor != nullptr && _precio != nullptr &&
					_id != DBNull::Value && _titulo != DBNull::Value && _autor != DBNull::Value && _precio != DBNull::Value)
				{
					// Los convierto para crear el objeto libro
					int id = System::Convert::ToInt32(_id);
					std::string titulo = msclr::interop::marshal_as<std::string>(_titulo->ToString());
					std::string autor = msclr::interop::marshal_as<std::string>(_autor->ToString());
					double precio = System::Convert::ToDouble(_precio);

					Libro* libro = new Libro(id, titulo, autor, precio);

					// Mando los datos al formulario fichalibro
					FichaLibro^ ficha = gcnew FichaLibro(libro, carrito);
					this->Hide();
					ficha->ShowDialog();
					this->Show();

					// Libero la memoria del libro
					delete libro;
				}
			}
			MiDataGridView->ClearSelection();

			// Vuelvo a Rellenar
			RellenarListadoLibros(conexion->LeerTodo());
		}
	};
}
