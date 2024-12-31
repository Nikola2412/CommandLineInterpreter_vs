#include "Head.h"

#include <regex>


void Head::execute(const string& parms, bool last){
    regex rgx("-n(\\d{1,5})\\s?(.*)");

    smatch matches;
    if (regex_search(parms, matches, rgx)) {
        int n = stoi(matches[1]);  // Captured number (1 to 5 digits)
        this->set(matches[2]);
        if (reader && this->Argument().empty()) {
            if (test_input()) return; // check if file exists

            string s;
            while (!reader->endOfRead()) {
                s = reader->getNextLine();
                if (_EOF && "EOF" == s) break;
                if (n > 0)
                    this->Append(s);
                n--;
            }
        }
        else
        {
            string s = this->Argument();
            istringstream stream(s);
            string line;
            this->Argument().clear();

            while (std::getline(stream, line) && n > 0) {
                this->Append(line);
                n--;
            }
        }
    }
    else {
        cout << "Error" << endl;
    }

    end(last);
}
