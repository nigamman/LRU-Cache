#include "LRUCache.h"

LRUCache::LRUCache(int cap) : capacity(cap) {
    head = new Node(-1, -1, -1);
    tail = new Node(-1, -1, -1);
    head->next = tail;
    tail->prev = head;
}

void LRUCache::addToFront(Node* node) {
    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;
}

void LRUCache::removeNode(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

bool LRUCache::isExpired(Node* node) {
    if (node->expiry == -1) return false;
    return std::time(nullptr) > node->expiry;
}

void LRUCache::evictLRU() {
    Node* lru = tail->prev;
    if (lru == head) return;
    removeNode(lru);
    cache.erase(lru->key);
    delete lru;
}

int LRUCache::get(int key) {
    if (cache.find(key) == cache.end()) {
        return -1;
    }

    Node* node = cache[key];

    if (isExpired(node)) {
        removeNode(node);
        cache.erase(key);
        delete node;
        return -1;
    }

    removeNode(node);
    addToFront(node);
    return node->value;
}

void LRUCache::put(int key, int value, int ttl) {
    if (cache.find(key) != cache.end()) {
        Node* node = cache[key];
        removeNode(node);
        cache.erase(key);
        delete node;
    }

    if ((int)cache.size() >= capacity) {
        evictLRU();
    }

    time_t expiryTime = (ttl == -1) ? -1 : std::time(nullptr) + ttl;
    Node* node = new Node(key, value, expiryTime);
    addToFront(node);
    cache[key] = node;
}

LRUCache::~LRUCache() {
    Node* curr = head;
    while (curr) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
}
