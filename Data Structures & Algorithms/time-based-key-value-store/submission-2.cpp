class TimeMap {
public:
    TimeMap() {}

    unordered_map<string,vector<pair<int, string>>> kvTime = {};
    
    void set(string key, string value, int timestamp) {
        pair<int, string> data = {timestamp, value};
        (kvTime[key]).push_back(data);
    }
    
    string get(string key, int timestamp) {
        auto& values = kvTime[key];

        int lo = 0, hi = values.size() - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (values[mid].first <= timestamp)
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        return hi >= 0 ? values[hi].second : "";
    }
};
