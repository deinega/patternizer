#ifndef _MT_H
#define _MT_H

#include <vector>

#include "quote.h"

using namespace std;

class MT{
public:
    
    static QuoteHistory getQuotes(const string &fname);
    

};

#endif

