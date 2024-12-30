#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        long long xinv = 0;
        long long temp = x;

        while (temp != 0) {
            xinv = xinv * 10 + temp % 10;
            temp /= 10;
        }

        return (x == xinv);
    }
};

int main() {
    Solution sol;
    int x;
    cin >> x;

    cout << sol.isPalindrome(x) << endl;
}