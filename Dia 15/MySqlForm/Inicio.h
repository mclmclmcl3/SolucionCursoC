#pragma once

#include <mysql.h>
#include <Windows.h>

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
	private: System::Windows::Forms::Button^ button1;
	protected:

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(105, 189);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Inicio::button1_Click);
			// 
			// Inicio
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->button1);
			this->Name = L"Inicio";
			this->Text = L"Inicio";
			this->ResumeLayout(false);

		}
#pragma endregion

		Void button1_Click(Object^ sender, EventArgs^ e)
		{
			try
			{
				conectar = mysql_init(0);
				int puerto = 3306;
				conectar = mysql_real_connect(conectar, "localhost", "root", "root", "CursoCPlusPlus", puerto, NULL, 0);

				if (!conectar) {
					MessageBox::Show("No se a podido conectar");
				}
				else
				{
					MessageBox::Show("Conexion correcta");
				}
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Erro en la conexion");
			}


		}




	};
}
