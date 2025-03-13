#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cache; // Doubly linked list to store key-value pairs
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap; // Hashmap for O(1) lookup

public:
    LRUCache(int cap) : capacity(cap) {}
    
    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end()) {
            return -1; // Key not found
        }
        
        // Move accessed node to front (most recently used)
        auto it = cacheMap[key];
        int value = it->second;
        cache.erase(it);
        cache.push_front({key, value});
        cacheMap[key] = cache.begin();
        
        return value;
    }
    
    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            // If key exists, update value and move to front
            auto it = cacheMap[key];
            cache.erase(it);
        } else if (cache.size() == capacity) {
            // If capacity is full, remove least recently used (LRU) element
            int lruKey = cache.back().first;
            cache.pop_back();
            cacheMap.erase(lruKey);
        }
        
        // Insert new key-value pair at front
        cache.push_front({key, value});
        cacheMap[key] = cache.begin();
    }
};

int main() {
    LRUCache lru(2); // Cache capacity = 2
    lru.put(1, 1);
    lru.put(2, 2);
    cout << lru.get(1) << endl; // Output: 1
    lru.put(3, 3); // Evicts key 2
    cout << lru.get(2) << endl; // Output: -1 (not found)
    lru.put(4, 4); // Evicts key 1
    cout << lru.get(1) << endl; // Output: -1 (not found)
    cout << lru.get(3) << endl; // Output: 3
    cout << lru.get(4) << endl; // Output: 4
    return 0;
}