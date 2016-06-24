#include "analysis.h"
#include "series.h"

#include <algorithm>

void Analysis::analize(const vector<double> &process){
    vector<double> corr_futures, anticorr_futures;
    vector<double> corr_tot_futures;
    
    for(size_t i = length; i < process.size() - length - length_future; i++){
        for(size_t j = 0; j < i - length; j++){
            double c = calculateCorrelation(process.begin() + i, process.begin() + j, length);
            double cf =  calculateCorrelation(process.begin() + i + length, process.begin() + j + length, length_future);
            if(c >= corr_min || c <= -corr_min){
                char fname[100];
                if(c >= corr_min){
                    printf("corr: %.g -> %g\n", c, cf);
                    sprintf(fname, "corr%d.d", corr_futures.size());
                    corr_futures.push_back(cf);
                }
                else if(c <= - corr_min){
                    printf("anticorr: %g -> %g\n", c, cf);                    
                    sprintf(fname, "anticorr%d.d", anticorr_futures.size());
                    anticorr_futures.push_back(cf);
                }
                FILE *f = fopen(fname, "w");
                for(int k = 0; k < length + length_future; k++){
                    fprintf(f, "%d\t%g\t%d\t%g\t%g\n", i+k, process[i+k], j+k, process[j+k], process[j+k] - process[j] + process[i]);
                }
                fclose(f);
            }
            corr_tot_futures.push_back(cf);
        }
        if(i%1000 == 0){
            printf("%d steps...\n", i);
        }
    }
    //sort(corr_futures.begin(), corr_futures.end());
    //sort(anticorr_futures.begin(), anticorr_futures.end());
    //sort(corr_tot_futures.begin(), corr_tot_futures.end());
    
    double corr_futures_av = calculateAverage(corr_futures.begin(), corr_futures.size());
    double anticorr_futures_av = calculateAverage(anticorr_futures.begin(), anticorr_futures.size());
    double corr_tot_futures_av = calculateAverage(corr_tot_futures.begin(), corr_tot_futures.size());
    
    printf("average future correlation for correlations %g\n", corr_futures_av);
    printf("average future correlation for anticorrelations %g\n", anticorr_futures_av);
    printf("average future correlation for all %g\n", corr_tot_futures_av);
}