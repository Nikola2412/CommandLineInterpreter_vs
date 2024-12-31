#include "Touch.h"

void Touch::execute(const string& parms, bool last){
    ifstream file(parms);

    if (file.is_open()) {
        cerr << "Error - file \"" << parms << "\" exist" << endl;
        file.close(); // Close the file
    }
    else {
        ofstream outfile(parms);
    }

    end(last);
}