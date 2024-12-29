#include <iostream>
using namespace std;

class Solution {
public:
    int sum(int num1, int num2) {
        return num1 + num2;
    }
};

int main() {
    Solution sol;
    int a, b;
    cin >> a >> b;
    int result = sol.sum(a, b);
    cout << result << endl;
    return 0;
}