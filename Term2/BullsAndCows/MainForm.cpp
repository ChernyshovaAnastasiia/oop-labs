#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(cli::array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    BullsAndCows::MainForm form;
    Application::Run(% form);
    return 0;
}