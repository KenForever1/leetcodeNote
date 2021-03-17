#include <iostream>
#include <vector>

using namespace std;

// 螺旋矩阵
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return {};
        }

        int rows = matrix.size();
        int cols = matrix[0].size();

        std::vector<std::vector<bool>> location(rows, std::vector<bool>(cols));

        std::vector<std::vector<int>> directions = {{0,  1},
                                                    {1,  0},
                                                    {0,  -1},
                                                    {-1, 0}};
        int total = rows * cols;
        std::vector<int> res;

        int cur_row = 0;
        int cur_col = 0;
        int direction_index = 0;
        for (auto i = 0; i < total; i++) {
            auto data = matrix[cur_row][cur_col];
            res.push_back(data);
            location[cur_row][cur_col] = true;
            int next_row = cur_row + directions[direction_index][0];
            int next_col = cur_col + directions[direction_index][1];
            if (next_row >= rows || next_row < 0 || next_col >= cols || next_col < 0 || location[next_row][next_col]) {
                direction_index = (direction_index + 1) % 4;
            }
            cur_row += directions[direction_index][0];
            cur_col += directions[direction_index][1];
        }
        return res;
    }
};


// 不同的子序列
// 动态规划, 创建二维数组 resArray, 其中 resArray[i][j] 表示在 s[i:] 的子序列中 t[j:] 出现的个数。
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        if (m < n) {
            return 0;
        }
        std::vector<std::vector<long>> resArray(m + 1, std::vector<long>(n + 1));

        for (auto i = 0; i <= m; i++) {
            resArray[i][n] = 1;
        }

        for (auto j = 0; j < n; j++) {
            resArray[m][j] = 0;
        }

        for (auto i = m - 1; i >= 0; i--) {
            char sChar = s.at(i);
            for (auto j = n - 1; j >= 0; j--) {
                char tChar = t.at(j);
                if (sChar == tChar) {
                    resArray[i][j] = resArray[i + 1][j + 1] + resArray[i + 1][j];
                } else {
                    resArray[i][j] = resArray[i + 1][j];
                }
            }
        }

        return resArray[0][0];

    }
};
