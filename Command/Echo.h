#ifndef ECHO_H
#define ECHO_H

#include "Command.h"

class Echo : public Command {
public:
    Echo() = default;
    ~Echo() = default;

    void Execute(const string& params);
    void Helper();
};

#endif