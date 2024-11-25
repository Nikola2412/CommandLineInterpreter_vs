#ifndef Command_H
#define Command_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>

#include "../IO/Reader/Reader.h"

using namespace std;

class Command {
public:
    virtual void execute(const string& args, string& input) = 0;
    virtual ~Command();
protected:
    //string getCommandLine();
    //string CommandInput();
    Reader* reader = nullptr;
    static string& test();

};
#endif
