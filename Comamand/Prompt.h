#ifndef Prompt_h
#define Prompt_h

#include "../Comamand/Command.h"

class Prompt : public Command {
    virtual void execute(const string& args, bool last);

};

#endif