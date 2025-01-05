#include "Truncate.h"

void Truncate::execute(const string& params, bool last) {
    ofstream outfile(params, ios::trunc);

    if (outfile.is_open()) {
        outfile.close();
    }
    else {
        cerr << "Error clearing file." << endl;
    }

    end(last);
}
