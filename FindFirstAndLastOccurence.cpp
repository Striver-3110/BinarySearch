#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    // Helper function for binary search
    // Parameters:
    // - nums: reference to the vector of numbers
    // - left: left index for the current search range
    // - right: right index for the current search range
    // - target: target number to find
    // - asc: boolean flag indicating search direction (true for first occurrence, false for last)
    // - ind: reference to the index of the found target (-1 if not found)
    void BinSearch(vector<int>& nums, int left, int&& right, int &target, bool &&asc, int &ind) {
        if (left > right) {
            return; // Base case: search range is invalid
        }
        int mid = left + (right - left) / 2; // Calculate mid index to avoid overflow

        if (asc) { // Search for the first occurrence of the target
            if (nums[mid] == target) {
                ind = mid; // Update index if target is found
                BinSearch(nums, left, move(mid - 1), target, move(asc), ind); // Continue search in the left half
            }
            else if (nums[mid] > target) {
                BinSearch(nums, left, move(mid - 1), target, move(asc), ind); // Continue search in the left half
            }
            else {
                BinSearch(nums, mid + 1, move(right), target, move(asc), ind); // Continue search in the right half
            }
        }
        else { // Search for the last occurrence of the target
            if (nums[mid] == target) {
                ind = mid; // Update index if target is found
                BinSearch(nums, mid + 1, move(right), target, move(asc), ind); // Continue search in the right half
            }
            else if (nums[mid] < target) {
                BinSearch(nums, mid + 1, move(right), target, move(asc), ind); // Continue search in the right half
            }
            else {
                BinSearch(nums, left, move(mid - 1), target, move(asc), ind); // Continue search in the left half
            }
        }
    }

public:
    // Function to find the first and last position of a target number in a sorted array
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1; // Initialize the first position index
        BinSearch(nums, 0, nums.size() - 1, target, true, first); // Find the first occurrence of the target
        int last = -1; // Initialize the last position index
        BinSearch(nums, 0, nums.size() - 1, target, false, last); // Find the last occurrence of the target
        return {first, last}; // Return the indices of the first and last occurrence
    }
};

int main() {
    Solution solution;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> result = solution.searchRange(nums, target);

    cout << "First and Last Position of " << target << " are: ";
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
