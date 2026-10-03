class Solution {
public:
    // bool feasible(vector<int>& piles, int h, int k) {
    //     priority_queue<pair<int, int>> pq = {};
    //     for (int i = 0; i < piles.size(); i++) {
    //         pq.push({piles[i], i});
    //     }
    //     while (h > 0 && !pq.empty()) {
    //         auto [quantity, pile] = pq.top();
    //         if (quantity <= k) {
    //             pq.pop();
    //         } else {
    //             pq.pop();
    //             pq.push({(quantity - k), pile});
    //         }
    //         h--;
    //     }
    //     return pq.empty();
    // }
    bool feasible(vector<int>& piles, int h, int k) {
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < piles.size(); i++) {
            pq.push({piles[i], i});
        }

        while (!pq.empty()) {
            auto [quantity, pile] = pq.top();
            pq.pop();

            int hours_needed = (quantity + k - 1) / k;

            if (hours_needed > h) {
                return false;
            }

            h -= hours_needed;
        }

        return true;
    }

    int binarySearch(vector<int>& piles, int h, int min_i, int max_i) {
        while (min_i < max_i) {
            int mid = min_i + ((max_i - min_i) / 2);
            if (feasible(piles, h, mid)) {
                max_i = mid;
            } else {
                min_i = mid + 1;
            }
        }
        return min_i;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        // piles of ints, piles[i] = number of bananas in ith pile.
        // integer h, number of hours to eat all bananas.
        // Each hour, choose pile i and k bananas of pile i to eat.
        // Return the minimum eating rate k such that all bananas can be eaten in h hours.

        // Greedy choice: Always choose the pile with the most bananas in it.

        // Range: [min(piles[i]), max(piles[i])]
        int max_i = 0;
        for (int i : piles) {
            if (i > max_i) max_i = i;
        }
        return binarySearch(piles, h, 1, max_i);
    }
};
