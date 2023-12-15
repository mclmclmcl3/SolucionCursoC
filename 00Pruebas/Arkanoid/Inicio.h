#pragma once
#include "Juego.h"

namespace Arkanoid {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Inicio
	/// </summary>
	public ref class Inicio : public System::Windows::Forms::Form
	{
		Juego* juego;
		Graphics^ g;

	public:
		Inicio(void)
		{
			InitializeComponent();

			g = this->CreateGraphics();
			juego = new Juego(g);
		}

	protected:
		~Inicio()
		{
			if (components)
			{
				delete components;
			}
			delete juego;
		}



	private: System::Windows::Forms::Timer^ clock;
	protected:

	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->clock = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// clock
			// 
			this->clock->Enabled = true;
			this->clock->Interval = 33;
			this->clock->Tick += gcnew System::EventHandler(this, &Inicio::clock_Tick);
			// 
			// Inicio
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Name = L"Inicio";
			this->Text = L"Inicio";
			this->ResumeLayout(false);

		}
#pragma endregion

		Void clock_Tick(Object^ sender, EventArgs^ e)
		{
			g->Clear(Color::Black);
			juego->Mover(g);
			juego->Mostrar(g);
		}


	};
}
