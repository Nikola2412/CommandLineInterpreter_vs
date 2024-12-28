// WCCommand.h
#ifndef WCCommand_h
#define WCCommand_h


#include "Command.h"
#include "../Comamand/Options/Counter.h"

#include <unordered_map>


class WCCommand : public Command {
public:
    WCCommand();
    void execute(const string& args, bool last);
    void executeBatch(Reader* r = nullptr, Writer* w = nullptr);
private:
    //void Input(int &x);
    //size_t WorldCount(const string&);
    //size_t CharacterCount(const string&);
    unordered_map<string,shared_ptr<Counter>> counters;
    
    shared_ptr<Counter> options;
};

#endif