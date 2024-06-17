# Binary Search Implementation

This repository contains a C++ implementation of the binary search algorithm. Binary search is a classic algorithm used to find the position of a target value within a sorted array. It operates by repeatedly dividing the search interval in half, making it an efficient solution for search problems.

## Features

- Efficiently searches for a target value in a sorted array.
- Logarithmic time complexity: O(log n).
- Simple and easy-to-understand implementation.

## Binary Search Algorithm

Binary search works on the principle of divide and conquer. The steps involved in the algorithm are:

1. Start with two pointers, `left` and `right`, at the beginning and end of the sorted array.
2. Calculate the middle index, `mid`, of the array.
3. Compare the target value with the value at the middle index:
   - If the target is equal to the middle value, the search is complete.
   - If the target is less than the middle value, repeat the search on the left subarray.
   - If the target is greater than the middle value, repeat the search on the right subarray.
4. Repeat the process until the target is found or the search interval is empty.

## Usage

To use this implementation, include the provided `BinarySearch` function in your C++ project and call it with your sorted array and target value.

### Example

Here is an example of how to use the binary search implementation in your project:

```cpp
#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Target not found
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 5;

    int result = binarySearch(nums, target);

    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
