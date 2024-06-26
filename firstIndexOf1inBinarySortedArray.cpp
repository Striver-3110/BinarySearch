//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int firstIndex(int a[], int n) 
    {
        // Your code goes here
        int i = 0;
        int j = n - 1;
        int ans = -1;
        
        while(i <= j){
            int mid = i + ( j - i )/2;
            if(a[mid] == 0){
                i = mid + 1;
            }else{
                ans = mid;
                j = mid - 1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        cout << ob.firstIndex(a, n) << endl;
    }
}
// } Driver Code Ends