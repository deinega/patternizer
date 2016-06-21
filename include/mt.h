#ifndef _MT
#define _MT

#include <vector>

#include "quote.h"

using namespace std;

class MT{
public:
    
    static vector<Quote> getQuotes(const string &fname);
    

};

#endif

