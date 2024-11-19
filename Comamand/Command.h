#ifndef Command_h
#define Command_h

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>

#include "../Reader/Reader.h"

using namespace std;

class Command {
public:
    virtual void execute(const std::string& args, std::string& input) = 0;
    virtual ~Command();
protected:
    //string getCommandLine();
    //string CommandInput();
    Reader* reader = nullptr;
    static string& test();

};
#endif
