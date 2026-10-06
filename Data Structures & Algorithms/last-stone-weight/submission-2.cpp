class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> pile = {};
        for (int s : stones) {
            pile.push(s);
        }
        while (pile.size() > 1) {
            int s1 = pile.top();
            pile.pop();
            int s2 = pile.top();
            pile.pop();
            if (s1 > s2) { pile.push(s1 - s2); }
            else if (s2 > s1) { pile.push(s2 - s1); }
            // otherwise the two stones are broken.
            if (pile.size() == 0) { pile.push(0); }
        }

        return pile.top();
    }
};
