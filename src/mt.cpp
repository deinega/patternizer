#include <stdio.h>
#include <stdlib.h>

#include "mt.h"

vector<Quote> MT::getQuotes(const string &fname){
    
    vector<Quote> quotes;
    
    FILE *f = fopen(fname.c_str(), "r");
    if(!f){
        printf("File %s does not exist...\n", fname.c_str());
        return quotes;
    }
    
    char line[1000];
    
    while (fgets(line, sizeof(line), f)) {
        printf("%s", line);
        string str = line;
        Quote quote;
        quote.date = str.substr(0, 16);
        quote.open = atof(str.substr(17, 7).c_str());
        quotes.push_back(quote);
    }

    fclose(f);
    
    return quotes;
}

