#ifndef _QUANDL_H
#define _QUANDL_H

#include <string>
#include <vector>

using namespace std;

struct Quote{

  string date;
  double open;
  double close;

};  

vector<Quote> getQuotes(const string &dataset, const string &symb, 
        const string &start, const string &end = string(""));


#endif
