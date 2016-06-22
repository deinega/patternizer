#ifndef _MT
#define _MT

#include <vector>

#include "quote.h"

using namespace std;

class MT{
public:
    
    static QuoteHistory getQuotes(const string &fname);
    

};

#endif

