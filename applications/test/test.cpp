#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include "quandl.h"
#include "yahoo.h"
#include "series.h"

using namespace std;

int main(int argc, char *argv[]){
    
    string dataset = "EOD";
    // string dataset = "WIKI";
    //string dataset = "CUR";
    //string symb = "AAPL";
    string symb = "GE";
    //string start = "2010-01-01";
    //string start = "2000-01-01";
    string start = "1990-01-01";
       
    vector<Quote> quotes;
    
    // test with daily quotes from quandl
    quotes = Quandl::getQuotes(dataset, symb, start);
    
   //quotes = Yahoo::getIntradayQuotes(symb, 100);
   /* 
    // test with some math functions
    for(int i=0; i<10000; i++){
        Quote quote;
        quote.open = pow(i/100., 2.);
        //quote.open = sin(i/100.);
        quotes.push_back(quote);
    }*/
   
    /*vector<double> process = generateMarkovProces(100000, 0, 0, 1);
    
    for(size_t i = 0; i< process.size(); i++){
        Quote quote;
        quote.open = process[i];
        quotes.push_back(quote);        
    }*/

    
    printf("data size: %d\n", (int)quotes.size());
    
    // gnuplot file
    FILE *f = fopen(symb.c_str(), "w");
    for(size_t i=0; i<quotes.size(); i++){
        fprintf(f, "%s\t%ld\t%.5f\t%.5f\n", 
                quotes[i].date.c_str(), quotes[i].timestamp, quotes[i].open, quotes[i].close);
    }
    fclose(f);
    
    f = fopen((symb+"g").c_str(), "w");
    for(size_t i=1; i<quotes.size(); i++){
        fprintf(f, "%s\t%ld\t%.5f\t%.5f\n", 
                quotes[i].date.c_str(), quotes[i].timestamp, 
                quotes[i].open - quotes[i-1].open, 
                quotes[i].close - quotes[i-1].close);
    }
    fclose(f);

    vector<double> vals;
    
    /*for(size_t i=0; i<quotes.size(); i++){
        double val = quotes[i].open;
        vals.push_back(val);
    }*/

    for(size_t i=1; i<quotes.size(); i++){
        double val = quotes[i].open - quotes[i-1].open;
        vals.push_back(val);
    }
    
    vector<double> distr = calculateDistribution(vals, -5, 5, 100);
    f = fopen("distr", "w");
    for(int i = 0; i<distr.size(); i++){
        fprintf(f, "%d\t%.10f\n", i, distr[i]);
        
    }
    fclose(f);
    
    double av = calculateAverage(vals.begin(), vals.size());
    printf("average %g\n", av);
    f = fopen("auto", "w");
    for(int i = 0; i<100; i++){
        double aut = calculateAutocorrelation(vals.begin(), vals.size(), i, &av);
        printf("autocorrelation %d %g\n", i, aut);
        
        fprintf(f, "%d\t%.10f\n", i, aut);
        
    }
    fclose(f);
    
    // here you can add testing strategy on historical data quotes

    
    printf("Done...\n");
    return 0;
}
