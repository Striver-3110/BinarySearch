#include<bits/stdc++.h>
using namespace std;

class Solution{

private:
    int binarySearch(vector<int> & nums, int target, int i, int j){
        while(i <= j){
            int mid = i + (j - i) / 2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                j = mid - 1;
            }
            else {
                i = mid + 1;
            }
        }
        return -1;
    }

public:
    int findElement(vector<int>& nums, int &target){
        int i = 0;
        int j = 1;
        while(target > nums[j]){
            int temp = j + 1;
            j = j + (j - i + 1) * 2;
            i = temp;
        }
        if (j >= nums.size()) j = nums.size() - 1;
        int ans = binarySearch(nums, target, i, j);
        if(ans == -1){
            return -1;
        }
        else return ans;
    }
};


int main() {
    Solution solution;
    vector<int> nums = {3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170};
    int target = 10;

    int result = solution.findElement(nums, target);
    cout << "Element " << target << " is at index: " << result << endl;

    target = 5;
    result = solution.findElement(nums, target);
    cout << "Element " << target << " is at index: " << result << endl;

    target = 170;
    result = solution.findElement(nums, target);
    cout << "Element " << target << " is at index: " << result << endl;

    target = 15;
    result = solution.findElement(nums, target);
    cout << "Element " << target << " is at index: " << result << endl;

    return 0;
}