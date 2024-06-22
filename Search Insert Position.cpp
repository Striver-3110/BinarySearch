#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;

        if (nums[nums.size() - 1] < target) {
            return nums.size();
        }
        if (nums[0] > target) {
            return 0;
        }

        while (i <= j) {
            int mid = (i + j) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (mid + 1 < nums.size() && target > nums[mid] && target < nums[mid + 1]) {
                return mid + 1;
            }
            if (mid - 1 >= 0 && target < nums[mid] && target > nums[mid - 1]) {
                return mid;
            }
            if (nums[mid] > target) {
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return 0;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    
    int result = sol.searchInsert(nums, target);
    cout << "Insert position: " << result << endl;  // Expected output: 2
    
    target = 2;
    result = sol.searchInsert(nums, target);
    cout << "Insert position: " << result << endl;  // Expected output: 1
    
    target = 7;
    result = sol.searchInsert(nums, target);
    cout << "Insert position: " << result << endl;  // Expected output: 4
    
    target = 0;
    result = sol.searchInsert(nums, target);
    cout << "Insert position: " << result << endl;  // Expected output: 0

    return 0;
}
