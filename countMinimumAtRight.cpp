//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  User function template for C++


// Common file

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

class Solution {
    
    int BinarySearch(vector<int> &arr, int k){
        int ind = -1;
        int left = 0;
        int right = arr.size()-1;
        
        while( left <= right){
            int mid = right + (left - right)/2;
            if(arr[mid] >= k){
                ind = mid;
                right = mid -1;
            }else{
                left = mid + 1;
            }
        }
        return ind;
    }
  public:
    vector<int> constructLowerArray(vector<int> &a) {
        // int n = a.size();
        // vector<int> ans(n);
        // ordered_set s;
        // for(int i=n-1;i>=0;i--){
        //     s.insert(a[i]);
        //     ans[i] = s.order_of_key(a[i]);
        // }
        // return ans;
        
        approach 2
        
        vector<int> sorted;
        vector<int> ans;
        
        sorted = a;
        sort(sorted.begin(), sorted.end());
        
        for(auto &val: a){
            int index = BinarySearch(sorted, val);
            ans.push_back(index);
            sorted.erase(sorted.begin() + index);
        }
        return ans;
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        vector<int> a = ob.constructLowerArray(arr);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends