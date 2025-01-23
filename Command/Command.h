#ifndef COMMAND_H
#define COMMAND_H

#include <string>

#include "../IO/IO.h"//Reader and writer

using namespace std;

class Command {
public:
    Command();
    virtual ~Command();
    void MainExecute(const string& params, bool last, Reader* r = nullptr);
    virtual void Execute(const string& params) = 0;

protected:
    Reader* reader;
    Writer* writer;

protected:
    static string& Argument();
    static bool& _Batch();
    void Set(const string arg);
    void CollectString();
    void Append(const string s);
    void test(const string s);

protected:
    void FindInputFile(const string arg);
    void FindOutputFile(const string arg);
    bool TestInput();

    void end();

protected:
    bool _EOF = 0;
    bool last = 1;

private:
    void reset();
};
#endif
