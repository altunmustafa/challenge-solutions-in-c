/* 
 * @name Stock Picker
 * @brief This is a coderbyte challenge.
 *        You will be given a list of stock prices for a given day and your goal is 
 *        to return the maximum profit that could have been made by buying a stock 
 *        at the given price and then selling the stock later on. 
 *        For example if the input is: [45, 24, 35, 31, 40, 38, 11] then your program should return 16 
 *        because if you bought the stock at $24 and sold it at $40, 
 *        a profit of $16 was made and this is the largest profit that could be made. 
 *        If no profit could have been made, return -1. 
 * @file stockPicker.c
 * @version 0.1
 * @author Mustafa Altun
 */

#include <stdio.h>
#include <stdlib.h>

#define max(a,b) (((a) > (b)) ? (a) : (b))
#define numberOfElements(array) (sizeof(array) / sizeof(array[0]))

int stockPicker(int prices[], int priceCount){
    int minPrice = prices[0];
    int maxProfit = -1;
    int tempProfit = -1;
    for(int i=0; i<priceCount-1; i++){
        tempProfit = prices[i+1] - minPrice;
        if(tempProfit < 0){
            minPrice = prices[i+1];
        }else{
            maxProfit = max(maxProfit, tempProfit);
        }
    }
    return maxProfit;
}

int main(){
    int prices[] = {45, 24, 35, 31, 40, 38, 11};
    int maxProfit = stockPicker(prices, numberOfElements(prices));

    printf("%d", maxProfit);
}
