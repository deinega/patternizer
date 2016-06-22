#ifndef _YAHOO_H
#define _YAHOO_H

#include <string>
#include <vector>

#include "quote.h"

using namespace std;

class Yahoo{
public:

    static QuoteHistory getIntradayQuotes(const string &symb, 
        const int days);

};

#endif