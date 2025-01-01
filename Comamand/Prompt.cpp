#include "Prompt.h"
#include "../Interpreter/Interpreter.h"


void Prompt::execute(const string& params, bool last){
	if (params.size() != 3)
		return;
	if (params[0] == '"' && params[2] == '"')
		Interpreter::Instance().getSymbol() = params[1];

	end(last);
}
