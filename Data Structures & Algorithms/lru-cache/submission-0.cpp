class LRUCache {
private:
    int capacity;
    unordered_map<int,list<pair<int,int>>::iterator> mp;
    list<pair<int,int>> cache; // stores k,v pairs.

public:

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (!mp.count(key)) return -1;
        auto it = mp[key];
        int value = it->second;

        cache.splice(cache.begin(), cache, it);

        return value;
    }
    
    void put(int key, int value) {
        // Add the key:
        if (mp.count(key)) {
            auto it = mp[key];
            it->second = value;

            cache.splice(cache.begin(), cache, it);

            return;
        }

        cache.push_front({key, value});
        mp[key] = cache.begin();

        // Deal with capacity:
        if (cache.size() > capacity) {
            int remove_key = cache.back().first;
            mp.erase(remove_key);
            cache.pop_back();
        }
    }
};
