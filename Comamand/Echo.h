#ifndef Echo_h
#define Echo_h

#include "Command.h"

class Echo : public Command{
public:
    void execute(const string& params, bool last);
};

#endif