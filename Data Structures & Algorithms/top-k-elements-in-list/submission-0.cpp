struct IntCount {
    int integer;
    int count;

    bool operator>(const IntCount& other_count) const {
        return (count < other_count.count);
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> int_counts;
        priority_queue<IntCount, vector<IntCount>, std::greater<>> min_heap;
        for (int n : nums) {
            if (int_counts.count(n)) {
                int_counts[n] += 1;
            } else {
                int_counts.insert({n, 1});
            }
        }
        for (const auto& [num, count] : int_counts) {
            IntCount curr_int_count = {num, count};
            min_heap.push(curr_int_count);
        }
        vector<int> answer;
        for (int i = 0; i < k; i++) {
            IntCount top_ith = min_heap.top();
            min_heap.pop();
            answer.push_back(top_ith.integer);
        }
        return answer;
    }
};