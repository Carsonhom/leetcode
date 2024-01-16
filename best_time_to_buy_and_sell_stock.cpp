class Solution {
public:

    // Greedy algorithm solution
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX; // lowest buy price
        int bestProfit = 0; 

        for (int price : prices)
        {
            if (price < minPrice) // check if price is lowest buy price
                minPrice = price;
            
            int profit = price - minPrice;
            bestProfit = max(profit, bestProfit); // choose the better profit
        }
        return bestProfit;
    }
};
