#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include "series.h"
#include "mt.h"
#include "analysis.h"

using namespace std;

int main(int argc, char *argv[]){
    
    vector<double> process;
    
   /* 
    // test with some math functions
    for(int i=0; i<10000; i++){
        double val = pow(i/100., 2.);
        //double val = sin(i/100.);
        process.push_back(val);
    }*/
   
    //vector<double> process = generateMarkovProces(100000, 0, 0, 1);

    // test with metatrader
    process = MT::getQuotes("/home/alex/eur").open;
    process.erase(process.begin() + 10000, process.end());
    
    printf("data size: %d\n", (int)process.size());
    
    // gnuplot file
    FILE *f = fopen("process.d", "w");
    for(int i=0; i<process.size(); i++){
        fprintf(f, "%d\t%g\n", i, process[i]);
    }
    fclose(f);
    
    printf("Differentiating the process...\n");
    vector<double> dprocess;        
    for(size_t i=1; i<process.size(); i++){
        double val = process[i] - process[i-1];
        dprocess.push_back(val);
    }
    
    f = fopen("dprocess.d", "w");
    for(size_t i=0; i<dprocess.size(); i++){
        fprintf(f, "%d\t%g\n", i, dprocess[i]);
    }
    fclose(f);

    printf("Distribution for process derivative...\n");
    vector<double> dprocess_distr = calculateDistribution(dprocess, -.001, .001, 40);
    f = fopen("dprocess_distr.d", "w");
    for(int i = 0; i<dprocess_distr.size(); i++){
        fprintf(f, "%d\t%.10f\n", i, dprocess_distr[i]);
        
    }
    fclose(f);
    
    printf("Analysing...\n");
    Analysis analysis;
    analysis.length = 10;
    analysis.length_future = 5;
    analysis.corr_min = .995;
    analysis.analize(process);
    
    printf("Done...\n");
    return 0;
}
