#ifndef PROMPT_H
#define PROMPT_H

#include "../Comamand/Command.h"

class Prompt : public Command {
public:
    Prompt() = default;
    ~Prompt() = default;
    void Execute(const string& params, bool last);
};

#endif