#include "Head.h"

#include <regex>


void Head::execute(const string& args, bool last){
    regex rgx("-n(\\d{1,5})\\s?(.*)");

    smatch matches;
    if (regex_search(args, matches, rgx)) {
        int n = stoi(matches[1]);  // Captured number (1 to 5 digits)
        this->set(matches[2]);
        if (test_input()) return; // check if file exists

        string s;
        while (!reader->endOfRead()) {
            s = reader->getNextLine();
            if (n > 0)
                this->append(s);
            n--;
        }
    }
    else {
        cout << "Error" << endl;
    }
    end(last);
}

void Head::executeBatch(const string& args, bool last, Reader* r)
{
    this->reader = r;
    regex rgx("-n(\\d{1,5})\\s?(.*)");

    smatch matches;
    if (regex_search(args, matches, rgx)) {
        int n = stoi(matches[1]);  // Captured number (1 to 5 digits)
        this->set(matches[2]);

        string s;
        while (!reader->endOfRead()) {
            s = reader->getNextLine();
            if ("EOF" == s) break;
            if (n > 0)
                this->append(s);
            n--;
        }
    }
    else {
        cout << "Error" << endl;
    }
    end(last);
}
