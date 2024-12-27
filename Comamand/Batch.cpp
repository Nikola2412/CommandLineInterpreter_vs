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
        while (!reader2->endOfRead()) {
            s = reader2->getNextLine();
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
        bool ehuj = 0;
        string s;
        while (!reader2->endOfRead()) {
            s = reader2->getNextLine();
            if ("EOF" == s) {
                ehuj = 0;
            }
            else if ("echo" == s.substr(0, 4) && !ehuj) {
                find_output_file(s);
                ehuj = 1;
            }
            else if (ehuj) {
                writer->writeLine(s);
            }
            else
                Interpreter::Instance().interpret(s);
        }
        writer = nullptr;
    }
    delete reader2;
}
