#include "Batch.h"

#include "../Interpreter/Interpreter.h"

Batch::~Batch(){}

void Batch::execute(const std::string& args, bool last){
    /*reader = new FileReader(args);
    while (!reader->endOfRead())
        Interpreter::Instance().interpret(reader->getNextLine());
    reader = nullptr;*/
    if (args == "") {
        Reader* reader2 = new ConsoleReader();
        if (reader2->endOfRead()) return;//if file does not exist
        std::string s;
        while (!reader2->endOfRead() && (s = reader2->getNextLine()).size() != 0) {
            Do(s);
        }
        delete reader2;
    }
    else Do(args);
    end(last);
}

void Batch::Do(const string arg) {
    Reader *reader2 = new FileReader(arg);
    if (reader2->endOfRead()) {
        Interpreter::Instance().interpret(arg);
    }
    else {
        while (!reader2->endOfRead())
            Interpreter::Instance().interpret(reader2->getNextLine());
    }
    delete reader2;
}
