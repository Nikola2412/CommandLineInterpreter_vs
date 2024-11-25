// WCCommand.h
#ifndef WCCommand_h
#define WCCommand_h


#include "Command.h"
#include "../Comamand/Options/Counter.h"

#include <unordered_map>


class WCCommand : public Command {
public:
    WCCommand();
    ~WCCommand();
    virtual void execute(const string& args, string& input);
private:
    void MultipleLines();

    void FileInput();

    //size_t WorldCount(const string&);
    //size_t CharacterCount(const string&);
    unordered_map<string,shared_ptr<Counter>> counters;
    
    shared_ptr<Counter> options;
};

#endif