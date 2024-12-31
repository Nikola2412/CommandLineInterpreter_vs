#include "Echo.h"

void Echo::execute(const string& parms, bool last){
    //cout << parms << endl;
    this->set(parms);

    if (reader && this->Argument().empty()) {
        if (test_input()) return;//if file does not exist
        string s;
        while (!reader->endOfRead()) {
            s = reader->getNextLine();
            if (_EOF && "EOF" == s) break;
            this->Append(s);
        }
    }

    end(last);
}
