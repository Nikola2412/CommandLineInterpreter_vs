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
    virtual void execute(const string& params, bool last) = 0;
    void MainExecute(const string& params, bool last,Reader *r = nullptr);
    ~Command();
protected:
    Reader* reader = nullptr;
    Writer* writer = nullptr;
    static string& Argument();
    void CollectString();
    void Append(const string s);
    void set(const string arg);
    void find_input_file(const string arg);
    void find_output_file(const string arg);
    bool test_input();
    void end(bool last);

    bool _EOF = 0;
};
#endif
