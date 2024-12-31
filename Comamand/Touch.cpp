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
}

void Touch::executeBatch(const string& parms, bool last, Reader* r)
{
    this->execute(parms, last);
}