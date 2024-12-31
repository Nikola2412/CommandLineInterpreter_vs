#include "Prompt.h"
#include "../Interpreter/Interpreter.h"


void Prompt::execute(const string& parms, bool last){
	if (parms.size() != 3)
		return;
	if (parms[0] == '"' && parms[2] == '"')
		Interpreter::Instance().getSymbol() = parms[1];

	end(last);
}
