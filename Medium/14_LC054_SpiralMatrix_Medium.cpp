#include <vector>
using namespace std;

class Solution {
public:
    void solve(vector<vector<int>>& m, int top, int bottom, int left, int right, vector<int>& ans) {
        if (top > bottom || left > right) return;

        for (int i = left; i <= right; i++) ans.push_back(m[top][i]);
        for (int i = top + 1; i <= bottom; i++) ans.push_back(m[i][right]);

        if (top < bottom) {
            for (int i = right - 1; i >= left; i--) ans.push_back(m[bottom][i]);
        }
        if (left < right) {
            for (int i = bottom - 1; i > top; i--) ans.push_back(m[i][left]);
        }

        solve(m, top + 1, bottom - 1, left + 1, right - 1, ans);
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        solve(matrix, 0, matrix.size() - 1, 0, matrix[0].size() - 1, ans);
        return ans;
    }
};
