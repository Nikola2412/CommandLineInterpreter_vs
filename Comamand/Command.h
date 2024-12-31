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
    virtual void execute(const string& parms, bool last) = 0;
    virtual void executeBatch(const string& parms, bool last,Reader *r = nullptr) = 0;
    ~Command();
protected:
    Reader* reader = nullptr;
    Writer* writer = nullptr;
    static string& Argument();
    void append(const string s);
    void set(const string arg);
    void find_input_file(const string arg);
    void find_output_file(const string arg);
    bool test_input();
    void end(bool last);
};
#endif
