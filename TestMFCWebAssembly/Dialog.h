#pragma once

#ifdef __EMSCRIPTEN__
	#include "JsUI.h"
#else
	#include "CppUI.h"
#endif

class Dialog
{
public:
#ifdef __EMSCRIPTEN__
	Dialog(const char* TextBoxName, const char* CheckBoxName, const char* ButtonName);
#else
	Dialog(CEdit* pTextBox, CButton* pCheckBox, CButton* pButton);
#endif

	void OnButtonClick();

public:
	WATextBox m_TextBox;
	WACheckBox m_CheckBox;
	WAButton m_Button;
};