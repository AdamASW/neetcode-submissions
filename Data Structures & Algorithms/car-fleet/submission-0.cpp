class Solution {
public:

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<float> s = {};
        // We need a stack that records whenever a car has caught up with someone,
        // at that point we add it to the stack.
        // We pop the car from the stack once it finishes.
        // Everytime the stack becomes empty, we increment the fleet count by 1.
        vector<pair<int,int>> highway_state = {};
        for (int i = 0; i < position.size(); i++) {
            highway_state.push_back({position[i], speed[i]});
        }
        sort(highway_state.begin(), highway_state.end()); // lexicographic ordering, so by position.
        for (int i = highway_state.size() - 1; i >= 0; i--) {
            auto [pos, v] = highway_state[i];
            float ttf = (target - pos) / static_cast<float>(v);
            if (i == highway_state.size() - 1) { 
                s.push(ttf);
                continue;
            }
            if (ttf > s.top()) {
                s.push(ttf);
            }
        }
        return s.size();
    }
};
