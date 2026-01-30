#include <iostream>
#include "LRUCache.h"

int main() {
    LRUCache cache(2);

    cache.put(1, 100);
    cache.put(2, 200);

    std::cout << cache.get(1) << std::endl; // 100

    cache.put(3, 300); // evicts key 2

    std::cout << cache.get(2) << std::endl; // -1
    std::cout << cache.get(3) << std::endl; // 300

    cache.put(4, 400, 2); // TTL = 2 seconds
    sleep(3);

    std::cout << cache.get(4) << std::endl; // -1 (expired)

    return 0;
}