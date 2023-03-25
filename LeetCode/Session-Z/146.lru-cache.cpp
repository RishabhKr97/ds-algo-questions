/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
class LRUCache {
    int capacity;
    unordered_map<int,int> cache;
    unordered_map<int,int> ignore_count;
    queue<int> key_queue;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        if (ignore_count.find(key) == ignore_count.end()) {
            ignore_count[key] = 0;
        }
        
        key_queue.push(key);
        ignore_count[key]++;
        return cache[key];
    }
    
    void put(int key, int value) {
        if (get(key) != -1) {
            cache[key] = value;
        } else if (cache.size() < capacity) {
            cache[key] = value;
            key_queue.push(key);
        } else {
            while (true) {
                int curr_key = key_queue.front();
                key_queue.pop();
                if (ignore_count.find(curr_key) == ignore_count.end() || ignore_count[curr_key] == 0) {
                    cache.erase(curr_key);
                    cache[key] = value;
                    key_queue.push(key);
                    break;
                } else {
                    ignore_count[curr_key]--;
                }
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

