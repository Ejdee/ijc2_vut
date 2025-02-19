# IJC - Project 2
## Score: 15/15 points
### Description
- The assignment was to rewrite the following C++ code in C and implement a simulation of the Unix `tail` command.
```cpp
#include <iostream>
#include <string>
#include <map>

int main() {
    std::string word;
    std::map<std::string,int> m;

    while (std::cin >> word) {
        m[word]++;
    }

    for(auto &x: m) {
        std::cout << x.first << "\t" << x.second << '\n';
    }
}
```
### Warning
- Project is published for showcase purposes only. Copying it is at your own risk.