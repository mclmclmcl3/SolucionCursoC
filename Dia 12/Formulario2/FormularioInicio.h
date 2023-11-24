#pragma once
#include <vector>

namespace Formulario2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections;
	using namespace System::Collections::Generic;

	public ref class FormularioInicio : public System::Windows::Forms::Form
	{
	private:
		String^ mirespuesta = "";

	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::ListViewItem^ ListViewItem1;
	private: System::Windows::Forms::ListView^ lvNombres;


	private: System::Windows::Forms::ColumnHeader^ nombre;
	private: System::Windows::Forms::ColumnHeader^ Apellido;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;


		   List<String^>^ nombres;
		   DataTable^ DataTable1;

	public:
		FormularioInicio(void)
		{
			InitializeComponent();
			lblRespuesta->Text = "";

			nombres = gcnew List<String^>();
			lvNombres->FullRowSelect = true;

			DataTable1 = gcnew DataTable();
			DataTable1->Columns->Add("Nombre");
			DataTable1->Columns->Add("Apellido");
		}

	protected:
		~FormularioInicio()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblNombre;
	protected:
	private: System::Windows::Forms::TextBox^ txtNombre;
	private: System::Windows::Forms::TextBox^ txtApellido;
	private: System::Windows::Forms::Label^ lblApellido;
	private: System::Windows::Forms::Button^ btnEnviar;
	private: System::Windows::Forms::Button^ btnBorrar;
	private: System::Windows::Forms::Label^ lblRespuesta;

	private: System::ComponentModel::Container^ components;
	private: System::Windows::Forms::DateTimePicker^ dateFechaNacimiento;
	private: System::Windows::Forms::Label^ lblFechaNacimiento;


	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::CheckBox^ checkBox3;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::RadioButton^ RSeptiembre;
	private: System::Windows::Forms::RadioButton^ RAgosto;
	private: System::Windows::Forms::RadioButton^ RJulio;





#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->lblNombre = (gcnew System::Windows::Forms::Label());
			   this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			   this->txtApellido = (gcnew System::Windows::Forms::TextBox());
			   this->lblApellido = (gcnew System::Windows::Forms::Label());
			   this->btnEnviar = (gcnew System::Windows::Forms::Button());
			   this->btnBorrar = (gcnew System::Windows::Forms::Button());
			   this->lblRespuesta = (gcnew System::Windows::Forms::Label());
			   this->dateFechaNacimiento = (gcnew System::Windows::Forms::DateTimePicker());
			   this->lblFechaNacimiento = (gcnew System::Windows::Forms::Label());
			   this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			   this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			   this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			   this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			   this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			   this->RSeptiembre = (gcnew System::Windows::Forms::RadioButton());
			   this->RAgosto = (gcnew System::Windows::Forms::RadioButton());
			   this->RJulio = (gcnew System::Windows::Forms::RadioButton());
			   this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			   this->lvNombres = (gcnew System::Windows::Forms::ListView());
			   this->nombre = (gcnew System::Windows::Forms::ColumnHeader());
			   this->Apellido = (gcnew System::Windows::Forms::ColumnHeader());
			   this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			   this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			   this->groupBox1->SuspendLayout();
			   this->groupBox2->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // lblNombre
			   // 
			   this->lblNombre->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->lblNombre->AutoSize = true;
			   this->lblNombre->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblNombre->Location = System::Drawing::Point(53, 36);
			   this->lblNombre->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			   this->lblNombre->Name = L"lblNombre";
			   this->lblNombre->Size = System::Drawing::Size(83, 25);
			   this->lblNombre->TabIndex = 0;
			   this->lblNombre->Text = L"Nombre";
			   // 
			   // txtNombre
			   // 
			   this->txtNombre->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->txtNombre->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->txtNombre->Location = System::Drawing::Point(57, 62);
			   this->txtNombre->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->txtNombre->Name = L"txtNombre";
			   this->txtNombre->Size = System::Drawing::Size(1072, 29);
			   this->txtNombre->TabIndex = 1;
			   // 
			   // txtApellido
			   // 
			   this->txtApellido->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->txtApellido->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->txtApellido->Location = System::Drawing::Point(57, 136);
			   this->txtApellido->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->txtApellido->Name = L"txtApellido";
			   this->txtApellido->Size = System::Drawing::Size(1072, 29);
			   this->txtApellido->TabIndex = 3;
			   // 
			   // lblApellido
			   // 
			   this->lblApellido->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->lblApellido->AutoSize = true;
			   this->lblApellido->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblApellido->Location = System::Drawing::Point(53, 109);
			   this->lblApellido->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			   this->lblApellido->Name = L"lblApellido";
			   this->lblApellido->Size = System::Drawing::Size(83, 25);
			   this->lblApellido->TabIndex = 2;
			   this->lblApellido->Text = L"Apellido";
			   // 
			   // btnEnviar
			   // 
			   this->btnEnviar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			   this->btnEnviar->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btnEnviar->Location = System::Drawing::Point(57, 540);
			   this->btnEnviar->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->btnEnviar->Name = L"btnEnviar";
			   this->btnEnviar->Size = System::Drawing::Size(92, 28);
			   this->btnEnviar->TabIndex = 4;
			   this->btnEnviar->Text = L"Enviar";
			   this->btnEnviar->UseVisualStyleBackColor = true;
			   this->btnEnviar->Click += gcnew System::EventHandler(this, &FormularioInicio::btnEnviar_Click);
			   // 
			   // btnBorrar
			   // 
			   this->btnBorrar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			   this->btnBorrar->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btnBorrar->Location = System::Drawing::Point(1037, 540);
			   this->btnBorrar->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->btnBorrar->Name = L"btnBorrar";
			   this->btnBorrar->Size = System::Drawing::Size(92, 28);
			   this->btnBorrar->TabIndex = 5;
			   this->btnBorrar->Text = L"Borrar";
			   this->btnBorrar->UseVisualStyleBackColor = true;
			   this->btnBorrar->Click += gcnew System::EventHandler(this, &FormularioInicio::btnBorrar_Click);
			   // 
			   // lblRespuesta
			   // 
			   this->lblRespuesta->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->lblRespuesta->AutoSize = true;
			   this->lblRespuesta->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblRespuesta->Location = System::Drawing::Point(53, 466);
			   this->lblRespuesta->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			   this->lblRespuesta->Name = L"lblRespuesta";
			   this->lblRespuesta->Size = System::Drawing::Size(42, 25);
			   this->lblRespuesta->TabIndex = 6;
			   this->lblRespuesta->Text = L"xxx";
			   // 
			   // dateFechaNacimiento
			   // 
			   this->dateFechaNacimiento->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			   this->dateFechaNacimiento->Location = System::Drawing::Point(57, 210);
			   this->dateFechaNacimiento->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->dateFechaNacimiento->Name = L"dateFechaNacimiento";
			   this->dateFechaNacimiento->Size = System::Drawing::Size(114, 26);
			   this->dateFechaNacimiento->TabIndex = 7;
			   // 
			   // lblFechaNacimiento
			   // 
			   this->lblFechaNacimiento->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->lblFechaNacimiento->AutoSize = true;
			   this->lblFechaNacimiento->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblFechaNacimiento->Location = System::Drawing::Point(53, 184);
			   this->lblFechaNacimiento->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			   this->lblFechaNacimiento->Name = L"lblFechaNacimiento";
			   this->lblFechaNacimiento->Size = System::Drawing::Size(83, 25);
			   this->lblFechaNacimiento->TabIndex = 8;
			   this->lblFechaNacimiento->Text = L"Apellido";
			   // 
			   // checkBox1
			   // 
			   this->checkBox1->AutoSize = true;
			   this->checkBox1->Location = System::Drawing::Point(21, 34);
			   this->checkBox1->Name = L"checkBox1";
			   this->checkBox1->Size = System::Drawing::Size(91, 23);
			   this->checkBox1->TabIndex = 10;
			   this->checkBox1->Text = L"Mañanas";
			   this->checkBox1->UseVisualStyleBackColor = true;
			   // 
			   // groupBox1
			   // 
			   this->groupBox1->Controls->Add(this->checkBox3);
			   this->groupBox1->Controls->Add(this->checkBox2);
			   this->groupBox1->Controls->Add(this->checkBox1);
			   this->groupBox1->Location = System::Drawing::Point(58, 260);
			   this->groupBox1->Name = L"groupBox1";
			   this->groupBox1->Size = System::Drawing::Size(171, 133);
			   this->groupBox1->TabIndex = 11;
			   this->groupBox1->TabStop = false;
			   this->groupBox1->Text = L"Grupo CheckBox";
			   // 
			   // checkBox3
			   // 
			   this->checkBox3->AutoSize = true;
			   this->checkBox3->Location = System::Drawing::Point(21, 92);
			   this->checkBox3->Name = L"checkBox3";
			   this->checkBox3->Size = System::Drawing::Size(78, 23);
			   this->checkBox3->TabIndex = 12;
			   this->checkBox3->Text = L"Noches";
			   this->checkBox3->UseVisualStyleBackColor = true;
			   // 
			   // checkBox2
			   // 
			   this->checkBox2->AutoSize = true;
			   this->checkBox2->Location = System::Drawing::Point(21, 63);
			   this->checkBox2->Name = L"checkBox2";
			   this->checkBox2->Size = System::Drawing::Size(74, 23);
			   this->checkBox2->TabIndex = 11;
			   this->checkBox2->Text = L"Tardes";
			   this->checkBox2->UseVisualStyleBackColor = true;
			   // 
			   // groupBox2
			   // 
			   this->groupBox2->Controls->Add(this->RSeptiembre);
			   this->groupBox2->Controls->Add(this->RAgosto);
			   this->groupBox2->Controls->Add(this->RJulio);
			   this->groupBox2->Location = System::Drawing::Point(251, 260);
			   this->groupBox2->Name = L"groupBox2";
			   this->groupBox2->Size = System::Drawing::Size(171, 133);
			   this->groupBox2->TabIndex = 13;
			   this->groupBox2->TabStop = false;
			   this->groupBox2->Text = L"Grupo Radio Button";
			   // 
			   // RSeptiembre
			   // 
			   this->RSeptiembre->AutoSize = true;
			   this->RSeptiembre->Location = System::Drawing::Point(27, 92);
			   this->RSeptiembre->Name = L"RSeptiembre";
			   this->RSeptiembre->Size = System::Drawing::Size(103, 23);
			   this->RSeptiembre->TabIndex = 2;
			   this->RSeptiembre->TabStop = true;
			   this->RSeptiembre->Text = L"Septiembre";
			   this->RSeptiembre->UseVisualStyleBackColor = true;
			   // 
			   // RAgosto
			   // 
			   this->RAgosto->AutoSize = true;
			   this->RAgosto->Location = System::Drawing::Point(27, 63);
			   this->RAgosto->Name = L"RAgosto";
			   this->RAgosto->Size = System::Drawing::Size(74, 23);
			   this->RAgosto->TabIndex = 1;
			   this->RAgosto->TabStop = true;
			   this->RAgosto->Text = L"Agosto";
			   this->RAgosto->UseVisualStyleBackColor = true;
			   // 
			   // RJulio
			   // 
			   this->RJulio->AutoSize = true;
			   this->RJulio->Location = System::Drawing::Point(27, 34);
			   this->RJulio->Name = L"RJulio";
			   this->RJulio->Size = System::Drawing::Size(59, 23);
			   this->RJulio->TabIndex = 0;
			   this->RJulio->TabStop = true;
			   this->RJulio->Text = L"Julio";
			   this->RJulio->UseVisualStyleBackColor = true;
			   // 
			   // listBox1
			   // 
			   this->listBox1->FormattingEnabled = true;
			   this->listBox1->ItemHeight = 19;
			   this->listBox1->Location = System::Drawing::Point(468, 184);
			   this->listBox1->Name = L"listBox1";
			   this->listBox1->Size = System::Drawing::Size(283, 156);
			   this->listBox1->TabIndex = 15;
			   // 
			   // lvNombres
			   // 
			   this->lvNombres->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) { this->nombre, this->Apellido });
			   this->lvNombres->HideSelection = false;
			   this->lvNombres->Location = System::Drawing::Point(468, 366);
			   this->lvNombres->Name = L"lvNombres";
			   this->lvNombres->Size = System::Drawing::Size(283, 177);
			   this->lvNombres->TabIndex = 16;
			   this->lvNombres->UseCompatibleStateImageBehavior = false;
			   this->lvNombres->View = System::Windows::Forms::View::Details;
			   // 
			   // nombre
			   // 
			   this->nombre->Text = L"Nombre";
			   this->nombre->Width = 111;
			   // 
			   // Apellido
			   // 
			   this->Apellido->Text = L"Apellido";
			   this->Apellido->Width = 134;
			   // 
			   // comboBox1
			   // 
			   this->comboBox1->FormattingEnabled = true;
			   this->comboBox1->Location = System::Drawing::Point(251, 186);
			   this->comboBox1->Name = L"comboBox1";
			   this->comboBox1->Size = System::Drawing::Size(171, 27);
			   this->comboBox1->TabIndex = 17;
			   // 
			   // dataGridView1
			   // 
			   this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->dataGridView1->Location = System::Drawing::Point(782, 184);
			   this->dataGridView1->Name = L"dataGridView1";
			   this->dataGridView1->Size = System::Drawing::Size(347, 173);
			   this->dataGridView1->TabIndex = 18;
			   // 
			   // FormularioInicio
			   // 
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			   this->ClientSize = System::Drawing::Size(1185, 606);
			   this->Controls->Add(this->dataGridView1);
			   this->Controls->Add(this->comboBox1);
			   this->Controls->Add(this->lvNombres);
			   this->Controls->Add(this->listBox1);
			   this->Controls->Add(this->groupBox2);
			   this->Controls->Add(this->groupBox1);
			   this->Controls->Add(this->lblFechaNacimiento);
			   this->Controls->Add(this->dateFechaNacimiento);
			   this->Controls->Add(this->lblRespuesta);
			   this->Controls->Add(this->btnBorrar);
			   this->Controls->Add(this->btnEnviar);
			   this->Controls->Add(this->txtApellido);
			   this->Controls->Add(this->lblApellido);
			   this->Controls->Add(this->txtNombre);
			   this->Controls->Add(this->lblNombre);
			   this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			   this->Name = L"FormularioInicio";
			   this->Text = L"Mi formulario";
			   this->groupBox1->ResumeLayout(false);
			   this->groupBox1->PerformLayout();
			   this->groupBox2->ResumeLayout(false);
			   this->groupBox2->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

		   // https://skanky.dev/visualcpp/list-view/using-list-view-control
		   // https://www.youtube.com/watch?v=lXgWVZSZmVA
	private: System::Void btnEnviar_Click(System::Object^ sender, System::EventArgs^ e) {

		checkBox1->ForeColor = checkBox1->Checked ? Color::Red : Color::Black;
		checkBox2->ForeColor = checkBox2->Checked ? Color::Red : Color::Black;
		checkBox3->ForeColor = checkBox3->Checked ? Color::Red : Color::Black;

		RJulio->ForeColor = RJulio->Checked ? Color::Red : Color::Black;
		RAgosto->ForeColor = RAgosto->Checked ? Color::Red : Color::Black;
		RSeptiembre->ForeColor = RSeptiembre->Checked ? Color::Red : Color::Black;

		if (txtNombre->Text != "" && txtApellido->Text != "")
		{
			//lblRespuesta->Text = "Hola, " + txtNombre->Text + " " + txtNombre->Text;
			mirespuesta = "Hola " + txtNombre->Text + ", " + txtApellido->Text + "\nhas nacido el: " + dateFechaNacimiento->Text;

			MiComboBox(txtNombre->Text, txtApellido->Text);
			MiDataGridView(txtNombre->Text, txtApellido->Text);
			VoidListBox(txtNombre->Text, txtApellido->Text);
		}
		lblRespuesta->Text = mirespuesta;
	}
	private: System::Void btnBorrar_Click(System::Object^ sender, System::EventArgs^ e) {
		txtNombre->Text = "";
		txtApellido->Text = "";
		lblRespuesta->Text = "";
	}

	private: void MiComboBox(String^ nombre, String^ apellido)
	{
		ListViewItem^ listado = gcnew ListViewItem(nombre);
		listado->SubItems->Add(apellido);
		lvNombres->Items->Add(listado);

		comboBox1->Items->Add(listado->Text);
	}

	private: void MiDataGridView(String^ nombre, String^ apellido)
	{
		DataRow^ DataRow1;
		DataRow1 = DataTable1->NewRow();
		DataRow1[0] = nombre; DataRow1[1] = apellido;
		DataTable1->Rows->Add(DataRow1);

		dataGridView1->DataSource = DataTable1;
	}

	private: void VoidListBox(String^ nombre, String^ apellido)
	{
		listBox1->Items->Clear();
		nombres->Add(nombre + " " + apellido);
		listBox1->Items->AddRange(nombres->ToArray());
	}


	};

}
