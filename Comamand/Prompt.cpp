#include "Prompt.h"
#include "../Interpreter/Interpreter.h"


void Prompt::execute(const string& args, bool last){
	if (args.size() != 3)
		return;
	if (args[0] == '"' && args[2] == '"')
		Interpreter::Instance().getSymbol() = args[1];
}

void Prompt::executeBatch(Reader* r, Writer* w)
{
}
