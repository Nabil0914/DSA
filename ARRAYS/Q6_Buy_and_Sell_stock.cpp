#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices){
    int maximumProfit = 0;
    int bestBuy = prices[0];

    for(int i = 1; i<prices.size(); i++){
        if(prices[i] > bestBuy){
            maximumProfit = max(maximumProfit, prices[i] - bestBuy);
        }
        bestBuy = min(bestBuy, prices[i]);
    }

    return maximumProfit;
}

int main(){
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    vector<int> prices(n);
    cout << "Enter stock prices: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    int profit = maxProfit(prices);
    cout << "Maximum Profit: " << profit << endl;

    return 0;

}