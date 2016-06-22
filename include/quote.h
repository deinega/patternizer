#ifndef _QUOTE_H
#define _QUOTE_H

#include <string>
#include <vector>

using namespace std;

struct Quote{
    string date;
    long timestamp;
    double open;
    double close;

    Quote(): timestamp(0), open(0), close(0){}
};

struct QuoteHistory{
    vector<string> date;
    vector<long> timestamp;
    vector<double> open;
    vector<double> close;
    
    void add(const Quote &quote){
        date.push_back(quote.date);
        timestamp.push_back(quote.timestamp);
        open.push_back(quote.open);
        close.push_back(quote.close);
    }
    
    size_t size() const{
        return date.size();
    }
};

#endif
