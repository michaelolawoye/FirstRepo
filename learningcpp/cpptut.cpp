#include <iostream>
#include <string>
using std::string, std::cout, std::cin, std::endl;

namespace first{
    int x = 1;
}

namespace second = first;

void arrayMulti(int nums[]);

int main() {


    int nums[] = {1, 2, 3, 4};
    for (int num = 0; num < sizeof(nums)/sizeof(nums[0]); num++) {
        cout << nums[num] << endl;
    }

    return 0;
}

void arrayMulti(int nums[]) {
    
    for (int i=0; sizeof(nums)/sizeof(nums[0]); i++) {
        
    }
}
