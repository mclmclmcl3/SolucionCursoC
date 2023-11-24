#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

//void main(array<String^>^ args)
//{
//	Application::EnableVisualStyles();
//	Application::SetCompatibleTextRenderingDefault(false);
//	Myform::MyForm form;
//	Application::Run(% form);
//}

int main()
{
	Application::Run(gcnew Myform::MyForm);
	return 0;
}