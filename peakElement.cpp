#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        if (j == 0) {
            return 0;
        }
        if (nums[i] > nums[i + 1]) {
            return i;
        }
        if (nums[j] > nums[j - 1]) {
            return j;
        }
        i++;
        j--;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (mid - 1 >= 0 && mid + 1 <= nums.size() - 1 && nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            }
            else if (nums[mid] < nums[mid + 1]) {
                i = mid + 1;
            }
            else {
                j = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};

    int result = solution.findPeakElement(nums);
    cout << "Peak element found at index: " << result << ", value: " << nums[result] << endl;

    return 0;
}
