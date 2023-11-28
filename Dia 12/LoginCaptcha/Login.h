#pragma once

namespace LoginCaptcha {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class Login : public System::Windows::Forms::Form
	{
	private:
		int intentos = 3;
	public:
		Login(void)
		{
			InitializeComponent();
			Feedback->ForeColor = Color::Green;
			Feedback->Text = "Tienes 3 intentos.";
		}

	protected:
		~Login()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblcapCha;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::NumericUpDown^ txtnum;

	private: System::Windows::Forms::Button^ btnLogin;
	private: System::Windows::Forms::Label^ Feedback;

	protected:

	protected:

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->lblcapCha = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtnum = (gcnew System::Windows::Forms::NumericUpDown());
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->Feedback = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtnum))->BeginInit();
			this->SuspendLayout();
			// 
			// lblcapCha
			// 
			this->lblcapCha->AutoSize = true;
			this->lblcapCha->Location = System::Drawing::Point(54, 35);
			this->lblcapCha->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblcapCha->Name = L"lblcapCha";
			this->lblcapCha->Size = System::Drawing::Size(208, 19);
			this->lblcapCha->TabIndex = 0;
			this->lblcapCha->Text = L"Para detectar que eres umano\r\n";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::Color::Blue;
			this->label1->Location = System::Drawing::Point(54, 66);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(204, 19);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Ingresa el resultado de 5 + 9:";
			// 
			// txtnum
			// 
			this->txtnum->Location = System::Drawing::Point(289, 64);
			this->txtnum->Name = L"txtnum";
			this->txtnum->Size = System::Drawing::Size(63, 26);
			this->txtnum->TabIndex = 2;
			// 
			// btnLogin
			// 
			this->btnLogin->Location = System::Drawing::Point(58, 157);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(110, 31);
			this->btnLogin->TabIndex = 3;
			this->btnLogin->Text = L"Login";
			this->btnLogin->UseVisualStyleBackColor = true;
			this->btnLogin->Click += gcnew System::EventHandler(this, &Login::btnLogin_Click);
			// 
			// Feedback
			// 
			this->Feedback->AutoSize = true;
			this->Feedback->Location = System::Drawing::Point(54, 289);
			this->Feedback->Name = L"Feedback";
			this->Feedback->Size = System::Drawing::Size(49, 19);
			this->Feedback->TabIndex = 4;
			this->Feedback->Text = L"label2";
			// 
			// Login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 19);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(426, 381);
			this->Controls->Add(this->Feedback);
			this->Controls->Add(this->btnLogin);
			this->Controls->Add(this->txtnum);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lblcapCha);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Login";
			this->Text = L"Login";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtnum))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnLogin_Click(System::Object^ sender, System::EventArgs^ e) {

		int numero = Convert::ToInt32(txtnum->Text);
		if (numero == 14)
		{
			MessageBox::Show("Bienvenido, te has logeado correctamente", "Login Correcto");
		}
		else
		{
			txtnum->Text = "";
			intentos--; 

			Feedback->Font = gcnew System::Drawing::Font(Feedback->Font->FontFamily, Feedback->Font->Size * 1.5);
			intentos == 1 ? Feedback->ForeColor = Color::Red : Feedback->ForeColor = Color::Orange;
			Feedback->Text = "Te quedan " + intentos;
			if (intentos == 0)
			{
				MessageBox::Show("Has superado los intentos para logearte", "Error");
				Application::Exit();
			}
		}
	}
};
}
