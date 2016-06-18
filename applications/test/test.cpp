#include "stdio.h"
#include <string.h>
#include <vector>
#include "quandl.h"

using namespace std;

int main(int argc, char *argv[]){

    string dataset = "EOD";
    // string dataset = "WIKI";
    //string dataset = "CUR";
    string symb = "AAPL";
    string start = "2010-01-01";
   
    vector<Quote> quotes;
    quotes = getQuotes(dataset, symb, start);
    
    // gnuplot file
    FILE *f = fopen(symb.c_str(), "w");
    for(size_t i=0; i<quotes.size(); i++){
        fprintf(f, "%s\t%.5f\t%.5f\n", quotes[i].date.c_str(), quotes[i].open, quotes[i].close);
    }
    fclose(f);
    
    // here you can add testing strategy on historical data quotes

    
    printf("Done...\n");
    return 0;
}
