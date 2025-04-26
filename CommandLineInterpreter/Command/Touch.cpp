#include "Touch.h"

void Touch::Execute(const string& params) {
    ifstream file(params);

    if (file.is_open()) {
        cerr << "Error - file \"" << params << "\" exist" << endl;
        file.close(); // Close the file
    }
    else {
        ofstream outfile(params);
    }
}

void Touch::Helper()
{
    CommandHelper h;
    h.TouchHelper();
}
