#include "Prompt.h"

void Prompt::execute(const std::string& args, std::string& input){
	if (args.size() != 3)
		return;
	if(args[0] == '"' && args[2] == '"')
		input = args[1];
}
