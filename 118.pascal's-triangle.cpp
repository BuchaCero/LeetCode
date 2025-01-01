#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> pascal;
        for (int i = 0; i < n; i++) {
            pascal.push_back(vector<int>(i + 1, 1));
            for (int j = 1; j <= i-1; j++) {
                pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
            }
        }
        return pascal;
    }
};

void print2dVector(vector<vector<int>> pascal) {
    int m = pascal.size();
    for (int i = 0; i < m; i++) {
        int n = pascal[i].size();
        cout << "{";
        for (int j = 0; j < n; j++) {
            cout << pascal[i][j];
            if (j < n-1) cout << ",";
        }
        cout << "},"<< endl;
    }
}

int main() {
    Solution sol;
    int n;
    cin >> n;
    vector<vector<int>> pascal = sol.generate(n);
    print2dVector(pascal);
}