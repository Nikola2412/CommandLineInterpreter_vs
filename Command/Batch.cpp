#include "Batch.h"

#include "../Interpreter/Interpreter.h"


void Batch::Execute(const string& params, bool last) {
    if (params == "") {
        Reader* reader2 = new ConsoleReader();
        if (reader2->endOfRead()) return;//if file does not exist
        string s;
        while (!reader2->endOfRead()) {
            s = reader2->getNextLine();
            Do(s);
        }
        delete reader2;
    }
    else Do(params);
    end(last);
}

void Batch::Do(const string arg) {
    Reader* reader2 = new FileReader(arg);
    if (reader2->endOfRead()) {
        Interpreter::Instance().interpret(arg);
    }
    else {
        string s;
        while (reader2 && !reader2->endOfRead()) {
            s = reader2->getNextLine();
            Interpreter::Instance().interpret(s, reader2);
        }
    }
    if (reader2) delete reader2;
}