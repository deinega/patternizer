#ifndef _QUANDL_H
#define _QUANDL_H

#include <string>
#include <vector>
#include "quote.h"

using namespace std;

class Quandl{
public:
    
    static QuoteHistory getQuotes(const string &dataset, const string &symb, 
        const string &start = string(""), const string &end = string(""));
    
};

#endif
