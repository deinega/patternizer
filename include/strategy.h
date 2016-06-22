#ifndef _STRATEGY_H
#define _STRATEGY_H

#include "series.h"
#include "quote.h"

class Order{
public:
    int ticks;
    
    bool dir; // true - long, false - short
    double spot;
    double take_profit;
    double stop_loss;
    
    // add trailing stop loss
    
    Order(bool d, double s, double tp, double sl): 
        dir(d), spot(s), take_profit(tp), stop_loss(sl), ticks(0){}
    
    bool update(const double price, double &profit){
        double delta = price - spot;
        if (delta > take_profit || -delta > stop_loss){
            profit = delta;
            return true;
        }
        ticks++;
        return false;
    }
};


class Strategy{
public:
    virtual double test(const QuoteHistory &quotes) = 0;
};

class ImageStrategy: public Strategy{
public:
    int length; // length of image to compare
    int length_future;
    double corr_min; // minimal correlation value to open a deal
    double delta_min; 
    
    QuoteHistory study; // study image
    
    double take_profit;
    double stop_loss;    
  
    virtual double test(const QuoteHistory &quotes){
        
        vector<Order> orders;
        
        for(size_t i = length; i<quotes.size() -length; i++){
            int num = 0;
            double delta = 0;
            for(size_t j = 0; j < i-length; j++){
                double corr = calculateCorrelation(study.open.begin() + j, quotes.open.begin() + i, length);
                //printf("%g\n", corr);
                if(corr >= corr_min){
                    num++;
                    delta += study.open[j + length -length_future] - study.open[j + length];
                    printf("correlation %g, i = %d,j = %d\n", corr, i, j);
                    char fcorr[100];
                    sprintf(fcorr, "corr%d.d", num);
                    record(fcorr, study.open.begin() + j, quotes.open.begin() + i, length);
                }
            }
            delta /= num;
            if(fabs(delta) >= delta_min){
                orders.push_back(Order(delta>0, quotes.open[i], take_profit, stop_loss));
            }
            if(i%100 == 0)
                printf("%d points...\n", i);
        }
    }
    
};


#endif
