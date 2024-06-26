#include<bits/stdc++.h>
using namespace std;

class Solution{

private:
    int binarySearch(vector<int> & nums, int target, int i, int j){
        while(i <= j){
            int mid = i + (j - i) / 2;
            if(mid + 1 < nums.size() && nums[mid] <= target && nums[mid + 1] > target){
                if(abs(target - nums[mid]) <= abs(target - nums[mid+1])){
                    return mid;
                }else{
                    return mid + 1;
                }
                // return mid;
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
        int j = nums.size() - 1;
        if(target <= nums[0]){
            return nums[0];
        }
        if(target >= nums[j]){
            return nums[j];
        }
        int ans = binarySearch(nums, target, i, j);

        return nums[ans];
    }
};


int main() {
    Solution solution;
    vector<int> nums = {3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170};
    int target = 80;

    int result = solution.findElement(nums, target);
    cout << result << endl;

    target = 6;
    result = solution.findElement(nums, target);
    cout << result << endl;


    target = 170;
    result = solution.findElement(nums, target);
    cout << result << endl;


    target = 2;
    result = solution.findElement(nums, target);
    cout << result << endl;


    return 0;
}