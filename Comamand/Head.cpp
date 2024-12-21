#include "Head.h"

#include <regex>

Head::~Head(){}

void Head::execute(const string& args, bool last){
    regex rgx("-n(\\d{1,5})\\s(.*)");

    smatch matches;
    if (regex_search(args, matches, rgx)) {
        int n = stoi(matches[1]);  // Captured number (1 to 5 digits)
        reader = new FileReader(matches[2]);
        if (reader->endOfRead()) return;

        while (!reader->endOfRead() && n > 0) {
            cout << reader->getNextLine() << endl;
            n--;
        }
    }
    else {
        cout << "Error" << endl;
    }
}
