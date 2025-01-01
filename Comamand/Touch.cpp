#include "Touch.h"

void Touch::execute(const string& params, bool last){
    ifstream file(params);

    if (file.is_open()) {
        cerr << "Error - file \"" << params << "\" exist" << endl;
        file.close(); // Close the file
    }
    else {
        ofstream outfile(params);
    }

    end(last);
}