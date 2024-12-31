#ifndef Prompt_h
#define Prompt_h

#include "../Comamand/Command.h"

class Prompt : public Command {
public:
    void execute(const string& parms, bool last);
    void executeBatch(const string& parms, bool last, Reader* r = nullptr);
};

#endif