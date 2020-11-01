#include <emscripten.h>
#include "Dialog.h"

Dialog* g_pDialog = nullptr;

extern "C" {
void EMSCRIPTEN_KEEPALIVE OnButtonClick()
{
	g_pDialog->m_Button.CallClickHandler();
}
};

int main()
{
	g_pDialog = new Dialog("m_TextBox", "m_CheckBox", "m_Button");
}