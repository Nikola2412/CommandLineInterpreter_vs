#include "Batch.h"

#include "../Interpreter/Interpreter.h"


void Batch::Execute(const string& params) {
    //prepraviti da koristi this->Set(params) i bes reader2
    this->_Batch() = 1;

    writer = new ConsoleWriter();
    if (params == "") {
        Reader* reader2 = new ConsoleReader();
        if (reader2->endOfRead()) return;//if file does not exist
        string s;
        while (!reader2->endOfRead()) {
            s = reader2->getNextLine();
            if(!s.empty()) Do(s);
        }
        delete reader2;
    }
    else Do(params);

    this->_Batch() = 0;
    this->Argument() = output;
    output = "";
}

void Batch::Do(const string arg) {
    Reader* reader2 = new FileReader(arg);
    if (reader2->endOfRead()) {//commands
        Interpreter::Instance().interpret(arg);
        output += this->Argument() + "\n";
        this->Argument().clear();
    }
    else {
        string s;
        while (reader2 && !reader2->endOfRead()) {
            s = reader2->getNextLine();
            Interpreter::Instance().interpret(s, reader2);
            output += this->Argument() + "\n";
            this->Argument().clear();
        }
    }
    if (reader2) delete reader2;
}