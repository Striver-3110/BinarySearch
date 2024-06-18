#include <iostream>
#include <vector>

using namespace std;
class Solution {
private:
    void BinSearch(vector<int>& nums, int left, int&& right, int &target,bool &&asc,int &ind){
        if(left > right){
            return ;
        }
        int mid = left + (right - left)/2;
        if(asc){
            if(nums[mid] == target){
                ind = mid;
                BinSearch(nums,left,move(mid-1),target,move(asc),ind);
            }
            else if(nums[mid] > target){
                BinSearch(nums,left,move(mid-1),target,move(asc),ind);
            }
            else{
                BinSearch(nums,mid+1,move(right),target,move(asc),ind);
            }
        }
        else{
            // cout<<"true"<<mid<<endl;
            if(nums[mid] == target){
                ind = mid;
                BinSearch(nums,mid+1,move(right),target,move(asc),ind);
            }
            else if(nums[mid] < target){
                BinSearch(nums,mid+1,move(right),target,move(asc),ind);
            }
            else{
                BinSearch(nums,left,move(mid-1),target,move(asc),ind);
            }
        }
    }
public:
    int searchRange(vector<int>& nums, int target) {
        // int n = nums.size();
        int first = -1;
        BinSearch(nums,0,nums.size()-1,target,true,first);
        int last = -1;
        BinSearch(nums,0,nums.size()-1,target,false,last);
        return last - first + 1;

    }
};

int main() {
    Solution solution;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    int result = solution.searchRange(nums, target);

    cout << "Occurrences of " << target << " are: ";
    cout << "[" << result << "]" << endl;
    

    return 0;
}