#include "JsUI.h"
#include <stdlib.h>
#include <stdio.h>
#include <emscripten.h>
  
 EM_JS(char*, GetTextFromTextBox, (const char* id), {
 
   var ctrl = document.getElementById(Module.UTF8ToString(id));
 
   var text = ctrl.value;
   var byteCount = (Module.lengthBytesUTF8(text) + 1);
  
   var textPointer = Module._malloc(byteCount);
   Module.stringToUTF8(text, textPointer, byteCount);
  
   return textPointer;
 });

std::string WATextBox::GetText() const
{
	char* p = GetTextFromTextBox(m_EditBoxID.c_str());
	std::string result = p;
	free(p);
	return result;
}
