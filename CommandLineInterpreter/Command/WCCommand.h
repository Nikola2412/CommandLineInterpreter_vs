#ifndef WC_COMMAND_H
#define WC_COMMAND_H


#include "Command.h"
#include "../Command/Options/Counter.h"

#include <unordered_map>


class WCCommand : public Command {
public:
    WCCommand();
    ~WCCommand() = default;

    void Execute(const string& params);
    void Helper();
private:
    bool check(const string& params, string& opt);

private:
    unordered_map<string, unique_ptr<Counter>> counters;
};

#endif