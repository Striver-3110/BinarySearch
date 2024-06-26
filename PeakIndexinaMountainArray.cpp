#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i = 0;
        int j = arr.size()-1;
        if(j == 0){
            return j;
        }
        if(arr[j] > arr[j-1]){
            return j;
        }
        if(arr[i] > arr[i+1]){
            return i;
        }
        i++;j--;
        while(i <= j){
            int mid = i + (j-i)/2;
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
                return mid;
            }
            else if(arr[mid] < arr[mid+1]){
                i = mid + 1;
            }
            else{
                j = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 3, 1};

    int result = solution.peakIndexInMountainArray(nums);
    cout << "Peak element found at index: " << result << ", value: " << nums[result] << endl;

    return 0;
}