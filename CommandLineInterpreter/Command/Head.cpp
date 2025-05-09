#include "Head.h"

#include <regex>
#include <sstream>


void Head::Execute(const string& params) 
{
    regex rgx("-n(\\d{1,5})\\s?(.*)");

    smatch matches;
    if (regex_search(params, matches, rgx)) {
        unsigned int n = stoi(matches[1]);  // Captured number (1 to 5 digits)
        this->Set(matches[2]);
        if (reader && this->Argument().empty()) {
            if (testInput()) return; // check if file exists

            string s;
            while (!reader->endOfRead()) {
                s = reader->getNextLine();
                if (_EOF && "EOF" == s) break;
                if (n > 0) {
                    this->Append(s);
                    n--;
                }
            }
        }
        else {
            string s = this->Argument();
            istringstream stream(s);
            string line;
            this->Argument().clear();

            while (getline(stream, line) && n > 0) {
                this->Append(line);
                n--;
            }
        }
    }
    else {
        cout << "Error" << '\n';
    }
}

void Head::Helper()
{
    CommandHelper h;
    h.HeadHelper();
}
