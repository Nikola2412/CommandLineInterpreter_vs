#include "Batch.h"

#include "../Interpreter/Interpreter.h"


void Batch::execute(const string& args, bool last){
    /*reader = new FileReader(args);
    while (!reader->endOfRead())
        Interpreter::Instance().interpret(reader->getNextLine());
    reader = nullptr;*/
    if (args == "") {
        Reader* reader2 = new ConsoleReader();
        if (reader2->endOfRead()) return;//if file does not exist
        string s;
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
        bool ehuj = false;
        string s;
        while (!reader2->endOfRead() && (s = reader2->getNextLine()).size() != 0) {
            if (s.substr(0,4) == "echo") find_output_file(s);
            if (s.substr(0,4) == "echo" || ehuj) {
                if (ehuj)
                    writer->writeLine(s);
                ehuj = 1;
            }
            else
                Interpreter::Instance().interpret(s);
        }
        writer = nullptr;
    }
    delete reader2;
}
