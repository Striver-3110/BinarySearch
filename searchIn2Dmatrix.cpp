#include <iostream>
#include <vector>

using namespace std;




class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int i = 0;     // row
        int j = m - 1; // column
        while (i < n && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] > target) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     int left = 0;
    //     int right = m * n - 1;

    //     while (left <= right) {
    //         int mid = left + (right - left) / 2;
    //         int midRow = mid / n;
    //         int midCol = mid % n;

    //         if (matrix[midRow][midCol] == target) {
    //             return true;
    //         }
    //         if (matrix[midRow][midCol] > target) {
    //             right = mid - 1;
    //         } else {
    //             left = mid + 1;
    //         }
    //     }
    //     return false;
    // }
};




int main() {
    Solution solution;

    vector<vector<int>> matrix = {
        {1,  4,  7, 11, 15},
        {2,  5,  8, 12, 19},
        {3,  6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int target1 = 5;
    int target2 = 20;

    // Test the first searchMatrix method
    bool result1 = solution.searchMatrix(matrix, target1);
    cout << "searchMatrix (method 1) - Target " << target1 << (result1 ? " found." : " not found.") << endl;

    bool result2 = solution.searchMatrix(matrix, target2);
    cout << "searchMatrix (method 1) - Target " << target2 << (result2 ? " found." : " not found.") << endl;

    // Test the second searchMatrix method
    bool result3 = solution.searchMatrix(matrix, target1);
    cout << "searchMatrix (method 2) - Target " << target1 << (result3 ? " found." : " not found.") << endl;

    bool result4 = solution.searchMatrix(matrix, target2);
    cout << "searchMatrix (method 2) - Target " << target2 << (result4 ? " found." : " not found.") << endl;

    return 0;
}
