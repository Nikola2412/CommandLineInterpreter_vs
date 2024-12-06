#include "Echo.h"


Echo::~Echo() {}

void Echo::execute(const std::string& args){
    //std::cout << this->test() << "\n";
    this->set(args);


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

    writer->writeLine(this->Argument());

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
