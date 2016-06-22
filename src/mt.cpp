#include <stdio.h>
#include <stdlib.h>

#include "mt.h"
#include "string_utils.h"

QuoteHistory MT::getQuotes(const string &fname){
    
    QuoteHistory quotes;
    
    //string str = fileToString(fname);
    //printf("%s\n", fname.c_str());
    //printf("%s\n", str.substr(0, 20).c_str());
    //exit(0);
    
    FILE *f = fopen(fname.c_str(), "r");
    if(!f){
        printf("File %s does not exist...\n", fname.c_str());
        return quotes;
    }
    
    char line[1000];
    
    while (fgets(line, sizeof(line), f)) {
        //printf("%s\n", line);
        //fflush(stdout);
        string str = line;
        Quote quote;
        quote.date = str.substr(0, 16);
        quote.open = atof(str.substr(17, 7).c_str());
        //printf("%s\t%f\n", quote.date.c_str(), quote.open);
        //exit(0);
        quotes.add(quote);
    }

    fclose(f);
    
    return quotes;
}

