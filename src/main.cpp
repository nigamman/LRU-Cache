#include <iostream>
using namespace std;
#include "LRUCache.h"
#include <windows.h>
#define sleep(x) Sleep(1000 * x)

int main() {
    LRUCache cache(2);

    cache.put(1, 100);
    cache.put(2, 200);

    cout << cache.get(1) << endl; // 100

    cache.put(3, 300); // evicts key 2

    cout << cache.get(2) << endl; // -1
    cout << cache.get(3) << endl; // 300

    cache.put(4, 400, 2); // TTL = 2 seconds
    sleep(3);

    cout << cache.get(4) << endl; // -1 (expired)

    return 0;
}