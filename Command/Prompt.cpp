#include "Prompt.h"
#include "../Interpreter/Interpreter.h"


void Prompt::Execute(const string& params, bool last) {
	if (params.size() != 3) {
		cerr << "Invalid number of characters" << endl;
	}
	if (params[0] == '"' && params[2] == '"')
		Interpreter::Instance().getSymbol() = params[1];

	end(last);
}
