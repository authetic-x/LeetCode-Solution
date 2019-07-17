#include <bits/stdc++.h>
using namespace std;

/*
 *  Info: 实现一个最近最少使用的缓存
 *  Key: 用双向链表list存储key，这样可以在O(1)的时间内实现插入删除操作，
 *       将每次更新的key都放到链表前面，当插入一个新元素并且容量满的时候，
 *       自动剔除尾部元素，关键是如何在O(1)时间内找到要更新的key，所以可以
 *       维护一个map保存每个key在lru中的位置，当更新的时候，直接先剔除该key，
 *       再将该key插入到lru的头部即可！
 */

class LRUCache {
private:
    int size;
    list<int> lru;
    unordered_map<int, list<int>::iterator> mp;
    unordered_map<int, int> kv;
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    int get(int key) {
        if (kv.count(key) == 0) return -1;
        update(key);
        return kv[key];
    }
    void put(int key, int value) {
        if (kv.size() == size && kv.count(key) == 0) {
            evict();
        }
        update(key);
        kv[key] = value;
    }
    void update(int key) {
        if (kv.count(key)) {
            lru.erase(mp[key]);
        }
        lru.push_front(key);
        mp[key] = lru.begin();
    }
    void evict() {
        mp.erase(lru.back());
        kv.erase(lru.back());
        lru.pop_back();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */