#include "Batch.h"

#include "../Interpreter/Interpreter.h"


void Batch::execute(const string& parms, bool last){
    /*reader = new FileReader(parms);
    while (!reader->endOfRead())
        Interpreter::Instance().interpret(reader->getNextLine());
    reader = nullptr;*/
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

void Batch::executeBatch(const string& parms, bool last, Reader* r)
{
    this->execute(parms, last);
}

void Batch::Do(const string arg) {
    //Command* cmd = new Echo();
    Reader *reader2 = new FileReader(arg);
    if (reader2->endOfRead()) {
        Interpreter::Instance().interpret(arg);
    }
    else {
        string s;
        while (!reader2->endOfRead()) {
            s = reader2->getNextLine();
            //cout << s << endl;
            //if ("echo" == s.substr(0, 4)) {
            //    cmd->executeBatch(reader2, new ConsoleWriter());
            //    continue;
            //}
            Interpreter::Instance().interpretBatch(reader2,s);
            //continue;
            //Interpreter::Instance().interpret(s);
        }
    }
    //delete cmd;
    delete reader2;
}
