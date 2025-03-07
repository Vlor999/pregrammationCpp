#include <iostream>
#include <vector>
#include <functional>

class Solution {
public:
    int ex1() {
        std::cout << "TODO\n"; 
        return 0; 
    }
    int ex2() { 
        std::cout << "TODO\n"; 
        return 0; 
    }
    int ex3() { 
        std::cout << "TODO\n"; 
        return 0; 
    }
    int ex4() { 
        std::cout << "TODO\n"; 
        return 0; 
    }
    int ex5() { 
        std::cout << "TODO\n"; 
        return 0; 
    }
    int ex6() { 
        std::cout << "TODO\n"; 
        return 0; 
    }
};

int main() {
    Solution solution;
    int isSuccess = 0;

    std::vector<std::function<int()>> functions = {
        {std::bind(&Solution::ex1, &solution)},
        {std::bind(&Solution::ex2, &solution)},
        {std::bind(&Solution::ex3, &solution)},
        {std::bind(&Solution::ex4, &solution)},
        {std::bind(&Solution::ex5, &solution)},
        {std::bind(&Solution::ex6, &solution)}
    };

    int count = 1;
    for (const auto& func : functions) {
        std::cout << "Executing: ex " << count << "\n";
        isSuccess += func();
        count++;
    }

    return isSuccess > 0 ? EXIT_FAILURE : EXIT_SUCCESS;
}
