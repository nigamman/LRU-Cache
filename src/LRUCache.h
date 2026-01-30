#ifndef LRU_CACHE_H
#define LRU_CACHE_H

#include <unordered_map>
#include <ctime>

class Node {
public:
    int key;
    int value;
    time_t expiry;
    Node* prev;
    Node* next;

    Node(int k, int v, time_t exp)
        : key(k), value(v), expiry(exp), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    std::unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    void addToFront(Node* node);
    void removeNode(Node* node);
    void evictLRU();
    bool isExpired(Node* node);

public:
    LRUCache(int cap);
    int get(int key);
    void put(int key, int value, int ttl = -1);
    ~LRUCache();
};

#endif
