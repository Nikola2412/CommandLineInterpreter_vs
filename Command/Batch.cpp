#include "Batch.h"

#include "../Interpreter/Interpreter.h"


void Batch::Execute(const string& params) {
    //prepraviti da koristi this->Set(params) i bes reader2
    writer = new ConsoleWriter();
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
}

void Batch::Do(const string arg) {
    Reader* reader2 = new FileReader(arg);
    if (reader2->endOfRead()) {//commands
        Interpreter::Instance().interpret(arg);
    }
    else {
        string s;
        while (reader2 && !reader2->endOfRead()) {
            s = reader2->getNextLine();
            Interpreter::Instance().interpret(s, reader2);
        }
        //cout << this->Argument() << endl;
    }
    if (reader2) delete reader2;
}