// WCCommand.h
#ifndef WCCommand_h
#define WCCommand_h


#include "Command.h"
#include "../Comamand/Options/Counter.h"

#include <unordered_map>


class WCCommand : public Command {
public:
    WCCommand();
    void execute(const string& params, bool last);

private:
    bool check(const string& params, string& opt);

    unordered_map<string,shared_ptr<Counter>> counters;

    shared_ptr<Counter> options;
};

#endif