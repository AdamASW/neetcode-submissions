class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        best_profit = 0
        min_priceday_before_n = {}
        for i in range(1, len(prices)):
            # i is sell_day
            if i == 1:
                min_priceday_before_n[1] = 0
                curr_profit = prices[1] - prices[0]
                if curr_profit > best_profit:
                    best_profit = curr_profit
                continue
            if prices[min_priceday_before_n[i-1]] > prices[i-1]:
                min_priceday_before_n[i] = i-1
            else:
                min_priceday_before_n[i] = min_priceday_before_n[i-1]
            curr_profit = prices[i] - prices[min_priceday_before_n[i]]
            if curr_profit > best_profit:
                best_profit = curr_profit
        return best_profit