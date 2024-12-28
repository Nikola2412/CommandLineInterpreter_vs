#include "Echo.h"

void Echo::execute(const string& args, bool last){
    this->set(args);

    if (reader) {
        if (test_input()) return;//if file does not exist
        string s;
        while (!reader->endOfRead()) {
            s = reader->getNextLine();
            this->append(s);
        }
    }

    end(last);
}

void Echo::executeBatch(const string& args, bool last, Reader* r){
    this->reader = r;
    this->set(args);

    string s;
    while (!r->endOfRead()) {
        s = r->getNextLine();
        if ("EOF" == s) break;
        this->append(s);
    }
    end(last);
}

