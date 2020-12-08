#pragma once

#include <functional>
#include <string>
#include <emscripten.h>
 
class WACheckBox
{
public:
	WACheckBox(const char* CheckBoxID)
		: m_CheckBoxID(CheckBoxID) {}

	bool GetCheck() const
	{
		int check = EM_ASM_INT({
			var ctrl = document.getElementById(UTF8ToString($0));
			return ctrl.checked;
		}, m_CheckBoxID.c_str());
		
		return (check > 0);
	}
	void SetCheck(bool check)
	{
		EM_ASM_({
			var ctrl = document.getElementById(UTF8ToString($0));
			ctrl.checked = $1;
		}, m_CheckBoxID.c_str(), check);
	}
private:
	std::string m_CheckBoxID;
};

template<typename Callback, class T>
std::function<void()> EventHandler(Callback fn, T* t)
{
	return std::bind(fn, t);
};

class WAButton
{
public:
	WAButton(const char* ButtonID)
		: Clicked(this)
		, m_ButtonID(ButtonID) {}

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
	std::string m_ButtonID;
	std::function<void()> m_ClickHander;
};

class WATextBox
{
public:
	WATextBox(const char* EditBoxID)
	: m_EditBoxID(EditBoxID) {}

	std::string GetText() const;
	
	void SetText(const char* s)
	{
		EM_ASM_({
			var ctrl = document.getElementById(UTF8ToString($0));
			ctrl.value = UTF8ToString($1);
		}, m_EditBoxID.c_str(), s);
	}

private:
	std::string m_EditBoxID;
};

inline void WAMessageBox(const std::string& msg)
{
	EM_ASM_({
		alert(UTF8ToString($0));
	}, msg.c_str());
}

inline void WADebugPrint(const std::string& msg)
{
	EM_ASM_({
		console.log(UTF8ToString($0));
	}, msg.c_str());
}