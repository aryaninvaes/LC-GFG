class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int direction = 0;
        // direction=0 left->right
        // direction=0 up->down
        // direction=0 right->left
        // direction=0 down->up
        int top = 0;
        int down = m - 1;
        int left = 0;
        int right = n - 1;

        vector<int> result;

            while (top <= down && left <= right) {
            //
            if (direction == 0) {
                // left to right print
                // row - fixed(top)
                for (int i = left; i <= right; i++) {
                    result.push_back(matrix[top][i]);
                }
                top++;
            }
            else if (direction == 1) {
                // up to down
                // column is fixed(right)
                for (int i = top; i <= down; i++) {
                    result.push_back(matrix[i][right]);
                }
                right--;
            }
            else if (direction == 2) {
                // right to left
                // row is fixed(down)

                for (int i = right; i >= left; i--) {
                    result.push_back(matrix[down][i]);
                }
                down--;
                
            }
            else {
                // down to up
                // column is fixed

                for (int i = down; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++;
                
            }

            direction = (direction + 1) % 4;
            }
    

    return result;
    }
};