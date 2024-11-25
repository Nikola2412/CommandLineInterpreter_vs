#ifndef Prompt_h
#define Prompt_h

#include "../Comamand/Command.h"

class Prompt : public Command {
    virtual void execute(const std::string& args, std::string& input);

};

#endif