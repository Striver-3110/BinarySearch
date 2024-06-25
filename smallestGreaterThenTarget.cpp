#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // takes TC:--> O(n + log n) 
    //       SC:--> O(n)  due to map
    // char nextGreatestLetter(vector<char>& letters, char target) {
    //     int n = letters.size();
    //     letters.push_back('#');
    //     if(target >= letters[n-1]){
    //         return letters[0];
    //     }
    //     map<char,int> freq;
    //     for(int i = 0; i < n; i++){
    //         freq[letters[i]] = 1;
    //     }
    //     vector<char> distinct;
    //     for(auto pair: freq){
    //         distinct.push_back(pair.first);
    //     }
    
    //     int i = 0;
    //     int j = distinct.size() - 1;

    //     while(i <= j){
    //         int mid = (i + j)/2;
    //         if(mid+1 < n && distinct[mid] <= target && distinct[mid+1] > target){
    //             return distinct[mid + 1];
    //         }
    //         if(distinct[mid] < target){
    //             i = mid + 1;
    //         }
    //         else{
    //             j = mid - 1;
    //         }
    //     }
    //     return distinct[0];
    // }

    // takes TC:--> O(log n) 
    //       SC:--> O(1)  
    char nextGreatestLetter(vector<char>& letters, char target) {
        int i = 0;
        int j = letters.size()-1;
        char ans = 'z' + 1;// max character
        while(i <= j){
            int mid = i + (j-i)/2;
            if(letters[mid] > target){
                ans = letters[mid];
                j = mid - 1;
            }
            else {
                i = mid + 1;
            }
        }
        if(ans == 'z' + 1)ans = letters[0];
        return ans;
    }
};


int main() {
    Solution solution;
    vector<char> letters = {'c', 'f', 'j'};
    char target = 'a';

    char result = solution.nextGreatestLetter(letters, target);
    cout << "Next greatest letter after '" << target << "' is: '" << result << "'" << endl;

    target = 'c';
    result = solution.nextGreatestLetter(letters, target);
    cout << "Next greatest letter after '" << target << "' is: '" << result << "'" << endl;

    target = 'd';
    result = solution.nextGreatestLetter(letters, target);
    cout << "Next greatest letter after '" << target << "' is: '" << result << "'" << endl;

    target = 'g';
    result = solution.nextGreatestLetter(letters, target);
    cout << "Next greatest letter after '" << target << "' is: '" << result << "'" << endl;

    target = 'j';
    result = solution.nextGreatestLetter(letters, target);
    cout << "Next greatest letter after '" << target << "' is: '" << result << "'" << endl;

    target = 'k';
    result = solution.nextGreatestLetter(letters, target);
    cout << "Next greatest letter after '" << target << "' is: '" << result << "'" << endl;

    return 0;
}
