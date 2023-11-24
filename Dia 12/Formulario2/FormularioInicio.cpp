#include "FormularioInicio.h"

using namespace System::Windows::Forms;

int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Formulario2::FormularioInicio);
	return 0;
}