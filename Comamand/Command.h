#ifndef COMMAND_H
#define COMMAND_H

#include <string>

#include "../IO/IO.h"//Reader and writer

using namespace std;

class Command {
public:
    Command();
    virtual ~Command();
    virtual void Execute(const string& params, bool last) = 0;
    void MainExecute(const string& params, bool last, Reader* r = nullptr);

protected:
    Reader* reader;
    Writer* writer;

protected:
    static string& Argument();
    void Set(const string arg);
    void CollectString();
    void Append(const string s);

protected:
    void FindInputFile(const string arg);
    void FindOutputFile(const string arg);
    bool TestInput();

    void end(bool last);

protected:
    bool _EOF = 0;

private:
    void reset();
};
#endif
