#ifndef COUNTER_H
#define COUNTER_H

#include "../../Reader/Reader.h"

using namespace std;

class Counter {
public:
    virtual int count(const string& input) = 0;
};

class WordCounter : public Counter {
    virtual int count(const string& input);
};

class CharCounter : public Counter {
    virtual int count(const string& input);
};

class LineCounter : public Counter {
    virtual int count(const string& input);
};
#endif