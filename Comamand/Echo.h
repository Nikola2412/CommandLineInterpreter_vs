#ifndef Echo_h
#define Echo_h

#include "Command.h"

class Echo : public Command{
public:
    void execute(const string& args, bool last);
    void executeBatch(Reader *r = nullptr,Writer *w = nullptr);
};

#endif