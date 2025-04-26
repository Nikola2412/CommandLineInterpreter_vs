#include "Prompt.h"
#include "../Interpreter/Interpreter.h"


void Prompt::Execute(const string& params) {
	if (params.size() != 3) {
		this->Error("Invalid number of characters");
	}
	if (params[0] == '"' && params[2] == '"')
		Interpreter::Instance().getSymbol() = params[1];
}

void Prompt::Helper()
{
	CommandHelper h;
	h.PromptHelper();
}
