#include "Echo.h"


Echo::~Echo() {}

void Echo::execute(const std::string& args, bool last){
    //std::cout << this->test() << "\n";
    //cout << this->Argument() << endl;
    if (this->Argument().size() != 0) {
        find_output_file(args);
    }
    else {
        this->set(args);
    }


    if (dynamic_cast<ConsoleReader*>(reader)) {
        vector<string> v;
        string s;

        while (!reader->endOfRead() && (s = reader->getNextLine()).size() != 0)
            v.push_back(s);

        for (auto& x : v)
            writer->writeLine(x);

        return;
    }
    

    if (dynamic_cast<FileReader*>(reader)){
        if (reader == nullptr) return;
        while (!reader->endOfRead())
            writer->writeLine(reader->getNextLine());
        return;
    }

    if (last) {
        writer->writeLine(this->Argument());
        this->reset();
    }

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
