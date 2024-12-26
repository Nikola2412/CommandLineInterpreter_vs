#ifndef Prompt_h
#define Prompt_h

#include "../Comamand/Command.h"

class Prompt : public Command {
public:
    void execute(const string& args, bool last);
};

#endif