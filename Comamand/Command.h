#ifndef Command_H
#define Command_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>

#include "../IO/Reader/Reader.h"
#include "../IO/Writer/Writer.h"

using namespace std;

class Command {
public:
    Command();
    void reset();
    virtual void execute(const string& args, bool last) = 0;
    virtual ~Command();
protected:
    Reader* reader = nullptr;
    Writer* writer = nullptr;
    static string& Argument();
    void append(const string s);
    void set(const string arg);
    void find_input_file(const string arg);
    void find_output_file(const string arg);
    void end(bool last);
};
#endif
