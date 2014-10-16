/* Best Time to Buy and Sell Stock III 
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.
*/

int maxProfit(vector<int> &prices) {
    int n = prices.size();
    if (n <= 1) return 0;

    vector<int> sellBefore(n, 0);
    vector<int> buyAfter(n, 0);

    int minPrice = prices[0];
    for (int i = 1; i < n; i++) {
    	sellBefore[i] = max(sellBefore[i-1], prices[i-1] - minPrice);
    	minPrice = min(minPrice, prices[i-1]);
    }

    int maxPrice = prices[n-1];
    for (int i = n-2; i >= 0; i--) {
    	buyAfter[i] = max(buyAfter[i+1], maxPrice - prices[i]);
    	maxPrice = max(maxPrice, prices[i]);
    }

    int maxProfit = 0;
    for (int i = 0; i < n; i++) {
    	maxProfit = max(maxProfit, sellBefore[i] + buyAfter[i]);
    }
    return maxProfit;
}