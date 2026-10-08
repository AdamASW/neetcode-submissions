        // if (hand.size() % groupSize != 0) return false;
        // int numGroups = hand.size() / groupSize;
        // unordered_map<int,vector<int>> groups;

        // sort(hand.begin(), hand.end());
        // for (int i = 0; i < hand.size(); i++) {
        //     int emergency_bucket = -1;
        //     bool found = false;
        //     for (int b = 0; b < numGroups; b++) {
        //         if (groups[b].empty()) { emergency_bucket = b; }
        //         else {
        //             if ((hand[i] - groups[b][(groups[b].size() - 1)] == 1) &&
        //                 (groups[b].size() < groupSize)) {
        //                 groups[b].push_back(hand[i]);
        //                 found = true;
        //                 break;
        //             }
        //         }
        //     }
        //     if (!found && emergency_bucket > -1) {
        //         groups[emergency_bucket].push_back(hand[i]);
        //         found = true;
        //     } else if (!found) {
        //         return false;
        //     }
        // }
        // return true;
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        unordered_map<int, int> frequency;
        sort(hand.begin(), hand.end());

        for (int n : hand)
            frequency[n]++;

        for (int n : hand) {
            if (frequency[n] == 0)
                continue;

            for (int i = 0; i < groupSize; i++) {
                if (frequency[n + i] == 0)
                    return false;

                frequency[n + i]--;
            }
        }

        return true;
    }
};