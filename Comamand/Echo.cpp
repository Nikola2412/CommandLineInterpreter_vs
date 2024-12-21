#include "Echo.h"


Echo::~Echo() {}

void Echo::execute(const std::string& args, bool last){
    this->set(args);

    if (reader) {
        if (reader->endOfRead()) return;//if file does not exist
        string s;
        while (!reader->endOfRead() && (s = reader->getNextLine()).size() != 0) {
            this->Argument() += s;
        }
    }

    end(last);
}
