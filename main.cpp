#include <iostream>
#include "FileCacheManager.h"

int main() {
    CacheManager<string, string> *cacheManager = new FileCacheManager();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}