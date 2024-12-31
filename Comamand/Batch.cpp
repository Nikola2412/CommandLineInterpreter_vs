#include "Batch.h"

#include "../Interpreter/Interpreter.h"


void Batch::execute(const string& parms, bool last){
    if (parms == "") {
        Reader* reader2 = new ConsoleReader();
        if (reader2->endOfRead()) return;//if file does not exist
        string s;
        while (!reader2->endOfRead()) {
            s = reader2->getNextLine();
            Do(s);
        }
        delete reader2;
    }
    else Do(parms);
    end(last);
}

void Batch::Do(const string arg) {
    Reader *reader2 = new FileReader(arg);
    if (reader2->endOfRead()) {
        Interpreter::Instance().interpret(arg);
    }
    else {
        string s;
        while (!reader2->endOfRead()) {
            s = reader2->getNextLine();
            Interpreter::Instance().interpret(s,reader2);
        }
    }
}
