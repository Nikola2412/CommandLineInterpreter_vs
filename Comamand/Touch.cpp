#include "Touch.h"

void Touch::execute(const string& args, bool last){
    ifstream file(args);

    if (file.is_open()) {
        cerr << "Error - file \"" << args << "\" exist" << endl;
        file.close(); // Close the file
    }
    else {
        ofstream outfile(args);
    }
}

void Touch::executeBatch(Reader* r, Writer* w)
{
}
