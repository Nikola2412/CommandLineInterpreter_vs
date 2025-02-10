#ifndef COMMAND_H
#define COMMAND_H

#include <string>

#include "../IO/IO.h"//Reader and writer

#include "../Helper/Helper.h"

class CommandHelper;

using namespace std;


class Command{
public:
    Command();
    virtual ~Command();
    void MainExecute(const string& params, bool last, Reader* r = nullptr);
    virtual void Execute(const string& params) = 0;
protected:
    virtual void Helper();

protected:
    Reader* reader;
    Writer* writer;

protected:
    static string& Argument();
    static bool& _Batch();
    void Set(const string& arg);
    bool CollectString();
    void Append(const string& s);
    void Info(const string& input);
    void Error(const string& input);
    void Print(const string& input);

protected:
    void FindInputFile(const string& arg);
    void FindOutputFile(const string& arg);
    bool TestInput();

    void end();


protected:
    bool _EOF = 0;
    bool last = 1;

private:
    bool clear = 0;
private:
    void reset();
};
#endif
