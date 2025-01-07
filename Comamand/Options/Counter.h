#ifndef COUNTER_H
#define COUNTER_H

#include <sstream>
#include <string>

using namespace std;

class Counter {
public:
    virtual size_t count(const string& input) = 0;
};

class WordCounter : public Counter {
    virtual size_t count(const string& input);
};

class CharCounter : public Counter {
    virtual size_t count(const string& input);
};

class LineCounter : public Counter {
    virtual size_t count(const string& input);
};
#endif