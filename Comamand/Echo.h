#ifndef ECHO_H
#define ECHO_H

#include "Command.h"

class Echo : public Command {
public:
    void execute(const string& params, bool last);
};

#endif