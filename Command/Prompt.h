#ifndef PROMPT_H
#define PROMPT_H

#include "../Command/Command.h"

class Prompt : public Command {
public:
    Prompt() = default;
    ~Prompt() = default;

    void Execute(const string& params);
    void Helper();
};

#endif