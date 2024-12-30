#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> result;
        unordered_map<int, int> dict;
        for (int i = 0; i < nums.size(); i++) {
            if (dict.find(target - nums[i]) != dict.end()) {
                result.push_back(dict.at(target - nums[i]));
                result.push_back(i);
                return result;
            } else {
                dict.insert({nums[i], i});
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    int target;
    cin >> target;
    
    vector<int> nums;
    int num;
    while (cin >> num) {
        nums.push_back(num);
    }

    vector<int> ans = sol.twoSum(nums, target);
    cout << ans[0] << ", " << ans[1] << endl;
}