
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
private:
    int minimum(int &a ,int &b){if(a>b)return b;return a;}

    void binarySearch(int&& left, int&& right, int& min, vector<int>& nums){
        if(left > right){
            return;
        }
        int mid = left+(right-left)/2;
        if(nums[mid] <= nums[(mid-1+nums.size())%nums.size()] && nums[mid] <= nums[(mid+1)%nums.size()]){
            // cout << "Is True";
            min = nums[mid];
            return;
        }
        if(nums[mid] < nums[right]){
            
            binarySearch(move(left),move(mid-1),min,nums);
        }
        else{
            binarySearch(move(mid+1),move(right),min,nums);
        }
        return;
    }
public:
    int findMin(vector<int>& nums) {
        int min = INT_MAX;
        binarySearch(0,nums.size()-1,min,nums);
        return min;
    }
};



int main() {
    Solution solution;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    int result = solution.findMin(nums);

    cout << "Minimum element in the rotated sorted array is: " << result << endl;

    return 0;
}
