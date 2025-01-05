#ifndef PROMPT_H
#define PROMPT_H

#include "../Comamand/Command.h"

class Prompt : public Command {
public:
    void execute(const string& params, bool last);
};

#endif