#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void BinarySearchFindMin(int left, int right, vector<int>& nums, int target, int &min) {
        if (left > right) {
            return;
        }
        int mid = left + (right - left) / 2;
        int n = nums.size();

        if (nums[mid] <= nums[(mid - 1 + n) % n] && nums[mid] <= nums[(mid + 1) % n]) {
            min = mid;
            return;
        }
        if (nums[mid] < nums[right]) {
            BinarySearchFindMin(left, mid - 1, nums, target, min);
        } else {
            BinarySearchFindMin(mid + 1, right, nums, target, min);
        }
    }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int min = 0; 
        BinarySearchFindMin(0, n - 1, nums, target, min);
        int i = 0;
        int mid = (min - 1 + n) % n;
        int j = n - 1;

        if (target >= nums[i] && target <= nums[mid]) {
            j = mid;
        } else {
            i = min;
        }

        while (i <= j) {
            mid = (i + j) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    
    int result = sol.search(nums, target);
    
    if (result != -1) {
        cout << "Target found at index: " << result << endl;
    } else {
        cout << "Target not found in the array." << endl;
    }

    return 0;
}
