#pragma once

#include "framework.h"
#include <functional>
#include <string>

class WACheckBox
{
public:
	WACheckBox(CButton* pCheckBox)
		: m_pCheckBox(pCheckBox) {}

	bool GetCheck() const
	{
		return (m_pCheckBox->GetCheck() == BST_CHECKED);
	}
	void SetCheck(bool check)
	{
		int v = check ? BST_CHECKED : BST_UNCHECKED;
		m_pCheckBox->SetCheck(check);
	}
private:
	CButton* m_pCheckBox;
};

template<typename Callback, class T>
std::function<void()> EventHandler(Callback fn, T* t)
{
	return std::bind(fn, t);
};

class WAButton
{
public:
	WAButton(CButton* pButton)
		: Clicked(this)
		, m_pButton(pButton) {}

private:

	class ClickEvent
	{
	public:
		ClickEvent(WAButton* pParent)
			: m_pParent(pParent) {}
		void operator+=(std::function<void()> fn)
		{
			m_pParent->m_ClickHander = fn;
		}
	private:
		WAButton* m_pParent;
	};
public:
	ClickEvent Clicked;
	void CallClickHandler()
	{
		if (m_ClickHander)
			m_ClickHander();
	}
private:
	CButton* m_pButton;
	std::function<void()> m_ClickHander;
};

class WATextBox
{
public:
	WATextBox(CEdit* pEditBox)
	: m_pEditBox(pEditBox) {}

	std::string GetText() const
	{
		CString s;
		m_pEditBox->GetWindowText(s);

		return (LPCTSTR)s;
	}
	void SetText(const char* s)
	{
		m_pEditBox->SetWindowText(s);
	}

private:
	CEdit* m_pEditBox;
};

inline void WAMessageBox(const std::string& msg)
{
	MessageBoxA(AfxGetApp()->GetMainWnd()->GetSafeHwnd(), msg.c_str(), "Title", MB_OK);
}