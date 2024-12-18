/*Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.
 
 The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.

 For example, if the prices of the stock in the last four days is [7,2,1,2] and the price of the stock today is 2, then the span of today is 4 because starting from today, the price of the stock was less than or equal 2 for 4 consecutive days.
 Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock today is 8, then the span of today is 3 because starting from today, the price of the stock was less than or equal 8 for 3 consecutive days.
 Implement the StockSpanner class:

 StockSpanner() Initializes the object of the class.
 int next(int price) Returns the span of the stock's price given that today's price is price.
*/

#include<iostream>

using namespace std;

class Stockspanner{
public:
    stack<pair<int, int>> st;
    int index = 0;
    
    Stockspanner(){}
    
    int next(int price){
        /*
         1. If the stack is empty, push the {price, index} pair onto the stack. This indicates that the current price is the first continuous element that is equal to or smaller than the previous one.
         2. For the stock price to be considered continuous, we need a price that is equal to or smaller than the previous one. If the price is greater than the current element, we don't include it.
         3. The stack will only store the previous greater elements (PGE).
         For Ex: Given prices = [100, 80, 60, 70, 60, 75, 85],
                 Initially, the stack will be:
                 Stack = [(100, 0)], then [(80, 1)] because 80 is smaller than 100. Here, 80 is the previous
                 greater element (PGE), and both 100 and 80 have a continuous span of 1.

                 Next, we push [(60, 2)] into the stack since 60 is smaller than 80. However, the next price is
                 70, which is greater than 60. We pop [(60, 2)] and check the next element in the stack (which
                 is 80), but 80 is greater than 70, so 80 becomes the PGE for 70.

                 Before pushing [(70, 3)] onto the stack, we calculate the span of continuous prices that meet
                 the condition. The answer for the span is calculated as the difference between the current
                 index and the index of the PGE, i.e., current index - st.top().index.
                    
         */
        
        int ans=0;
        if(st.empty()){
            st.push({price, index++});
            return 1;
        }
        else{
            while(!st.empty() && price >= st.top().first){
                st.pop();
            }
            ans = index - (st.empty()? -1 : st.top().second);
            st.push({price, index++});
        }
        return ans;
    }
};

int main(){
    Stockspanner* obj = new Stockspanner();
    
    vector<int> prices = {100,80,60,70,60,75,85};
    
    for(int price:prices){
        cout << "price: " << price << "->Span: " << obj->next(price) << endl;
    }
    return 0; 
}
