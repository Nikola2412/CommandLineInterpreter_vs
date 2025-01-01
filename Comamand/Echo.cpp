#include "Echo.h"

void Echo::execute(const string& params, bool last){
    //cout << params << endl;
    this->set(params);

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
