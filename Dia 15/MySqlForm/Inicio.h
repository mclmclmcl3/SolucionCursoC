#pragma once

#include <mysql.h>
#include <Windows.h>
#include <msclr/marshal_cppstd.h>

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
	private: System::Windows::Forms::DataGridView^ Tabla;
	private: System::Windows::Forms::TextBox^ txtNombre;
	private: System::Windows::Forms::TextBox^ txtPass;
	public:
		MYSQL_ROW fila; // Variable MYSQL en la que albergaremos datos de una fila de la respuesta de la consulta.

	public:
		Inicio(void)
		{
			InitializeComponent();
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
			this->Tabla = (gcnew System::Windows::Forms::DataGridView());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->txtPass = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Tabla))->BeginInit();
			this->SuspendLayout();
			// 
			// btnEnviar
			// 
			this->btnEnviar->Location = System::Drawing::Point(242, 286);
			this->btnEnviar->Name = L"btnEnviar";
			this->btnEnviar->Size = System::Drawing::Size(75, 23);
			this->btnEnviar->TabIndex = 0;
			this->btnEnviar->Text = L"Enviar";
			this->btnEnviar->UseVisualStyleBackColor = true;
			this->btnEnviar->Click += gcnew System::EventHandler(this, &Inicio::btnEnviar_Click);
			// 
			// Tabla
			// 
			this->Tabla->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Tabla->Location = System::Drawing::Point(42, 34);
			this->Tabla->Name = L"Tabla";
			this->Tabla->Size = System::Drawing::Size(505, 194);
			this->Tabla->TabIndex = 1;
			// 
			// txtNombre
			// 
			this->txtNombre->Location = System::Drawing::Point(42, 254);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(100, 20);
			this->txtNombre->TabIndex = 2;
			// 
			// txtPass
			// 
			this->txtPass->Location = System::Drawing::Point(177, 254);
			this->txtPass->Name = L"txtPass";
			this->txtPass->Size = System::Drawing::Size(100, 20);
			this->txtPass->TabIndex = 3;
			// 
			// Inicio
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(591, 344);
			this->Controls->Add(this->txtPass);
			this->Controls->Add(this->txtNombre);
			this->Controls->Add(this->Tabla);
			this->Controls->Add(this->btnEnviar);
			this->Name = L"Inicio";
			this->Text = L"Inicio";
			this->Load += gcnew System::EventHandler(this, &Inicio::Inicio_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Tabla))->EndInit();
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
			mysql_close(conectar);
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

					if (mysql_query(conectar, insert.c_str()));
					{
						resultado = mysql_store_result(conectar);
						Imprimir();
					}
				}
				else
					MessageBox::Show("No se ha podido conectar");
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

			Tabla->DataSource = tabla;
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
				MessageBox::Show("Error en la conexion");
			}
			finally
			{
				Desconectar();
			}

		}

	};
}
