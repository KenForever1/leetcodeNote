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