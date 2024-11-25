#include "Echo.h"


Echo::~Echo() {}

void Echo::execute(const std::string& args, std::string& input){
    //std::cout << this->test() << "\n";

    if (args.empty()) {
        reader = new CommandReader();

        vector<string> v;
        string s;

        while(!reader->endOfRead() && (s = reader->getNextLine()).size() != 0)
            v.push_back(s);

        for (auto& x : v)
            cout << x << endl;

        return;
    }

    size_t n = args.size();
    if (args[0] == '"' && args[n - 1] == '"')
        std::cout << args.substr(1, n - 2) << std::endl;
    else
    {
        reader = new FileReader(args);
        if (reader == nullptr) return;
        while (!reader->endOfRead())
            cout << reader->getNextLine() << endl;
    }
}
