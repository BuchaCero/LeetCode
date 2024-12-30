#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            if (numbers[i] + numbers[j] < target) {
                i++;
            } else if (numbers[i] + numbers[j] > target) {
                j--;
            } else {
                result.push_back(i + 1);
                result.push_back(j + 1);
                return result;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;

    int target;
    cin >> target;

    vector<int> numbers;
    int number;
    while (cin >> number) {
        numbers.push_back(number);
    }

    vector<int> ans = sol.twoSum(numbers, target);
    cout << ans[0] << ", " << ans[1] << endl;
}