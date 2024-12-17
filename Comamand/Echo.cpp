#include "Echo.h"


Echo::~Echo() {}

void Echo::execute(const std::string& args, bool last){
    //std::cout << this->test() << "\n";
    //cout << this->Argument() << endl;
    this->set(args);

    if (reader) {
        string s;
        while (!reader->endOfRead() && (s = reader->getNextLine()).size() != 0) {
            this->Argument() += s;
        }
    }

    end(last);

    /*size_t n = args.size();
    if (args[0] == '"' && args[n - 1] == '"')
        std::cout << args.substr(1, n - 2) << std::endl;
    else
    {
        reader = new FileReader(args);
        if (reader == nullptr) return;
        while (!reader->endOfRead())
            cout << reader->getNextLine() << endl;
    }*/
}
