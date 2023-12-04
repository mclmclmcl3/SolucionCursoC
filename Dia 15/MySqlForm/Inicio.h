#pragma once

#include <mysql.h>
#include <Windows.h>
#include <msclr/marshal_cppstd.h>
#include <string>

namespace MySqlForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Inicio : public System::Windows::Forms::Form
	{
	public:
		MYSQL* conectar;  // La variable tipo MYSQL para establecer el resultado de la conexión
		MYSQL_RES* resultado; // La variable tipo MYSQL para establecer el resultado de la respuesta de una consulta

	public:

	private: System::Windows::Forms::TextBox^ txtNombre;
	private: System::Windows::Forms::TextBox^ txtPass;
	private: System::Windows::Forms::Button^ btnBorrar;
	private: System::Windows::Forms::TextBox^ txtId;
	private: System::Windows::Forms::TextBox^ txtFecha;
	private: System::Windows::Forms::DataGridView^ DataGridViewTabla;
	private: System::Windows::Forms::Button^ btnActualizar;

	public:
		MYSQL_ROW fila; // Variable MYSQL en la que albergaremos datos de una fila de la respuesta de la consulta.

	public:
		Inicio(void)
		{
			InitializeComponent();
			DataGridViewTabla->ReadOnly = true;
			DataGridViewTabla->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
		}

	protected:
		~Inicio()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnEnviar;
	protected:

	protected:

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->btnEnviar = (gcnew System::Windows::Forms::Button());
			this->DataGridViewTabla = (gcnew System::Windows::Forms::DataGridView());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->txtPass = (gcnew System::Windows::Forms::TextBox());
			this->btnBorrar = (gcnew System::Windows::Forms::Button());
			this->txtId = (gcnew System::Windows::Forms::TextBox());
			this->txtFecha = (gcnew System::Windows::Forms::TextBox());
			this->btnActualizar = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DataGridViewTabla))->BeginInit();
			this->SuspendLayout();
			// 
			// btnEnviar
			// 
			this->btnEnviar->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEnviar->ForeColor = System::Drawing::Color::DodgerBlue;
			this->btnEnviar->Location = System::Drawing::Point(413, 380);
			this->btnEnviar->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnEnviar->Name = L"btnEnviar";
			this->btnEnviar->Size = System::Drawing::Size(100, 28);
			this->btnEnviar->TabIndex = 0;
			this->btnEnviar->Text = L"Enviar";
			this->btnEnviar->UseVisualStyleBackColor = true;
			this->btnEnviar->Click += gcnew System::EventHandler(this, &Inicio::btnEnviar_Click);
			// 
			// DataGridViewTabla
			// 
			this->DataGridViewTabla->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->DataGridViewTabla->Location = System::Drawing::Point(56, 42);
			this->DataGridViewTabla->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->DataGridViewTabla->Name = L"DataGridViewTabla";
			this->DataGridViewTabla->Size = System::Drawing::Size(673, 239);
			this->DataGridViewTabla->TabIndex = 1;
			this->DataGridViewTabla->SelectionChanged += gcnew System::EventHandler(this, &Inicio::DataGridViewTabla_SelectionChanged);
			// 
			// txtNombre
			// 
			this->txtNombre->Location = System::Drawing::Point(144, 314);
			this->txtNombre->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(187, 23);
			this->txtNombre->TabIndex = 2;
			// 
			// txtPass
			// 
			this->txtPass->Location = System::Drawing::Point(362, 314);
			this->txtPass->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->txtPass->Name = L"txtPass";
			this->txtPass->Size = System::Drawing::Size(132, 23);
			this->txtPass->TabIndex = 3;
			// 
			// btnBorrar
			// 
			this->btnBorrar->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Bold));
			this->btnBorrar->ForeColor = System::Drawing::Color::OrangeRed;
			this->btnBorrar->Location = System::Drawing::Point(629, 380);
			this->btnBorrar->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnBorrar->Name = L"btnBorrar";
			this->btnBorrar->Size = System::Drawing::Size(100, 28);
			this->btnBorrar->TabIndex = 4;
			this->btnBorrar->Text = L"Borrar";
			this->btnBorrar->UseVisualStyleBackColor = true;
			this->btnBorrar->Click += gcnew System::EventHandler(this, &Inicio::btnBorrar_Click);
			// 
			// txtId
			// 
			this->txtId->ForeColor = System::Drawing::Color::Gray;
			this->txtId->Location = System::Drawing::Point(56, 314);
			this->txtId->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->txtId->Name = L"txtId";
			this->txtId->ReadOnly = true;
			this->txtId->Size = System::Drawing::Size(59, 23);
			this->txtId->TabIndex = 5;
			// 
			// txtFecha
			// 
			this->txtFecha->ForeColor = System::Drawing::Color::Gray;
			this->txtFecha->Location = System::Drawing::Point(525, 314);
			this->txtFecha->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->txtFecha->Name = L"txtFecha";
			this->txtFecha->ReadOnly = true;
			this->txtFecha->Size = System::Drawing::Size(132, 23);
			this->txtFecha->TabIndex = 6;
			// 
			// btnActualizar
			// 
			this->btnActualizar->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Bold));
			this->btnActualizar->ForeColor = System::Drawing::Color::OliveDrab;
			this->btnActualizar->Location = System::Drawing::Point(521, 380);
			this->btnActualizar->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnActualizar->Name = L"btnActualizar";
			this->btnActualizar->Size = System::Drawing::Size(100, 28);
			this->btnActualizar->TabIndex = 7;
			this->btnActualizar->Text = L"Actualizar";
			this->btnActualizar->UseVisualStyleBackColor = true;
			this->btnActualizar->Click += gcnew System::EventHandler(this, &Inicio::btnActualizar_Click);
			// 
			// Inicio
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(788, 423);
			this->Controls->Add(this->btnActualizar);
			this->Controls->Add(this->txtFecha);
			this->Controls->Add(this->txtId);
			this->Controls->Add(this->btnBorrar);
			this->Controls->Add(this->txtPass);
			this->Controls->Add(this->txtNombre);
			this->Controls->Add(this->DataGridViewTabla);
			this->Controls->Add(this->btnEnviar);
			this->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Bold));
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"Inicio";
			this->Text = L"Inicio";
			this->Load += gcnew System::EventHandler(this, &Inicio::Inicio_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DataGridViewTabla))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		bool Conectar()
		{
			conectar = mysql_init(0);
			int puerto = 3306;

			String^ servidor = "localhost";
			String^ usuario = "root";
			String^ pass = "root";
			String^ nombreBaseDatos = "CursoCPlusPlus";

			std::string servidorStr = msclr::interop::marshal_as<std::string>(servidor);
			std::string usuarioStr = msclr::interop::marshal_as<std::string>(usuario);
			std::string passStr = msclr::interop::marshal_as<std::string>(pass);
			std::string nombreBaseDatosStr = msclr::interop::marshal_as<std::string>(nombreBaseDatos);


			//conectar = mysql_real_connect(conectar, "localhost", "root", "root", "CursoCPlusPlus", puerto, NULL, 0);
			conectar = mysql_real_connect(conectar, servidorStr.c_str(), usuarioStr.c_str(), passStr.c_str(), nombreBaseDatosStr.c_str(), puerto, NULL, 0);
			if (conectar) return true;
			return false;
		}

		void Desconectar()
		{
			if (conectar != nullptr)
			{
				mysql_close(conectar);
			}
		}

		std::string StringToSTDstring(String^ texto)
		{
			return msclr::interop::marshal_as < std::string>(texto);
		}

		Void btnEnviar_Click(Object^ sender, EventArgs^ e)
		{
			try
			{
				if (Conectar())
				{
					std::string nombre = StringToSTDstring(txtNombre->Text);
					std::string pass = StringToSTDstring(txtPass->Text);

					std::string insert = "INSERT INTO usuario (Nombre, Pass) VALUES ('" + nombre + "','" + pass + "');";

					if (mysql_query(conectar, insert.c_str()) == 0)
					{
						resultado = mysql_store_result(conectar);
					}
				}
				else
					MessageBox::Show("No se ha podido conectar");

				Imprimir();
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Error en la conexion");
			}
			finally
			{
				Desconectar();
			}


		}

		void Imprimir()
		{
			if (mysql_query(conectar, "SELECT * FROM usuario"))
			{
				// devuelve 0 en caso de exito, por lo que si NO es correcto devuelve 1 que es true
				MessageBox::Show("No se pudo conectar");
			}
			resultado = mysql_store_result(conectar);

			DataTable^ tabla = gcnew DataTable();
			for (unsigned int i = 0; i < mysql_num_fields(resultado); i++)
			{
				tabla->Columns->Add(gcnew String(mysql_fetch_field_direct(resultado, i)->name));
			}

			while ((fila = mysql_fetch_row(resultado)))
			{
				DataRow^ dataRow = tabla->NewRow();
				for (unsigned int i = 0; i < mysql_num_fields(resultado); i++)
				{
					dataRow[i] = gcnew String(fila[i] ? fila[i] : "NULL");
				}
				tabla->Rows->Add(dataRow);
			}

			DataGridViewTabla->DataSource = tabla;
			DataGridViewTabla->ClearSelection();

			//DataGridViewTabla->Columns[0]->ReadOnly = true;
			//DataGridViewTabla->Columns[4]->ReadOnly = true;

			mysql_free_result(resultado);
		}


		Void Inicio_Load(Object^ sender, EventArgs^ e)
		{
			try
			{
				if (Conectar())
				{
					Imprimir();
				}
				else
					MessageBox::Show("No se ha podido conectar");
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Error en la conexion" + ex->Message);
			}
			finally
			{
				Desconectar();
			}

		}
		void DataGridViewTabla_SelectionChanged(Object^ sender, EventArgs^ e)
		{
			if (DataGridViewTabla->Rows->Count > 0 && DataGridViewTabla->SelectedRows->Count > 0)
			{
				DataGridViewRow^ fila = DataGridViewTabla->SelectedRows[0];

				if (fila->Cells[0] != nullptr && fila->Cells[0]->Value != nullptr)
				{
					String^ id = fila->Cells[0]->Value->ToString();
					txtId->Text = id;
				}
				else
				{
					txtId->Text = "";
				}

				if (fila->Cells[1] != nullptr && fila->Cells[1]->Value != nullptr)
				{
					String^ nombre = fila->Cells[1]->Value->ToString();
					txtNombre->Text = nombre;
				}
				else
				{
					txtNombre->Text = "";
				}

				if (fila->Cells[2] != nullptr && fila->Cells[2]->Value != nullptr)
				{
					String^ pass = fila->Cells[2]->Value->ToString();
					txtPass->Text = pass;
				}
				else
				{
					txtPass->Text = "";
				}

				if (fila->Cells[3] != nullptr && fila->Cells[3]->Value != nullptr)
				{
					String^ fecha = fila->Cells[3]->Value->ToString();
					txtFecha->Text = fecha;
				}
				else
				{
					txtFecha->Text = "";
				}
			}
			else
			{
				// Manejar el caso en que no hay filas o no hay filas seleccionadas si es necesario
				txtId->Text = "";
				txtNombre->Text = "";
				txtPass->Text = "";
				txtFecha->Text = "";
			}
		}


		Void btnBorrar_Click(Object^ sender, EventArgs^ e)
		{
			System::Windows::Forms::DialogResult respuesta = MessageBox::Show("¿Estás seguro de querer borrar este campo?", "Advertencia", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);

			if (respuesta == System::Windows::Forms::DialogResult::Yes)
			{
				try
				{
					if (Conectar())
					{
						std::string id = StringToSTDstring(txtId->Text);

						std::string borrar = "DELETE FROM usuario WHERE Id = " + id;

						if (mysql_query(conectar, borrar.c_str()))
						{
							resultado = mysql_store_result(conectar);
						}
					}
					else
						MessageBox::Show("No se ha podido conectar");

					Imprimir();
				}
				catch (Exception^ ex)
				{
					MessageBox::Show("Error en la conexion" + ex->Message);
				}
				finally
				{
					Desconectar();
				}
			}
	
		}



		Void btnActualizar_Click(Object^ sender, EventArgs^ e)
		{
			try
			{
				if (Conectar())
				{
					if (!String::IsNullOrEmpty(txtId->Text))
					{

						std::string idStr = StringToSTDstring(txtId->Text);
						std::string nombreStdStr = StringToSTDstring(txtNombre->Text);
						std::string passStdStr = StringToSTDstring(txtPass->Text);

						std::string update = "UPDATE usuario SET Nombre = '" + nombreStdStr + "', Pass = '" + passStdStr + "' WHERE ID = " + idStr + ";";

						if (mysql_query(conectar, update.c_str()) == 0)
						{
							resultado = mysql_store_result(conectar);
						}
						else
						{
							MessageBox::Show("Error en la consulta UPDATE: " + gcnew String(mysql_error(conectar)));
						}

						Imprimir();
					}
				}
				else
				{
					MessageBox::Show("No se ha podido conectar a la base de datos");
				}
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Error en la conexión: " + ex->Message);
			}
			finally
			{
				Desconectar();
			}
		}
	};
}
