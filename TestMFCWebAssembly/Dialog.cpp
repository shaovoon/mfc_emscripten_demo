#include "pch.h"
#include "Dialog.h"


#ifdef __EMSCRIPTEN__
Dialog::Dialog(const char* TextBoxName, const char* CheckBoxName, const char* ButtonName)
	: m_TextBox(TextBoxName)
	, m_CheckBox(CheckBoxName)
	, m_Button(ButtonName)
#else
Dialog::Dialog(CEdit* pTextBox, CButton* pCheckBox, CButton* pButton)
	: m_TextBox(pTextBox)
	, m_CheckBox(pCheckBox)
	, m_Button(pButton)
#endif
{
	m_TextBox.SetText("Mike");
	m_Button.Clicked += EventHandler(&Dialog::OnButtonClick, this);
}

void Dialog::OnButtonClick()
{
	std::string text = m_TextBox.GetText();
	if (m_CheckBox.GetCheck())
		text = std::string("Hello ") + text;

	WADebugPrint("Button clicked!");

	WAMessageBox(text);
}
