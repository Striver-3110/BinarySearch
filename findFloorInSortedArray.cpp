//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x){
        
        // Your code here
        if(x < v[0]){
            return -1;
        }
        if(x > v[n-1]){
            return n-1;
        }
        
        long long i = 0, j = n-1;
        while(i <= j){
            long long mid = i + (j - i)/2;
            if(v[mid] == x){
                return mid;
            }
            else if (mid + 1 < n && v[mid] < x && v[mid + 1] > x){
                return mid;
            }
            else if(v[mid] > x){
                j = mid - 1;
            }
            else{
                i = mid + 1;
            }
        }
        return -1;
        
    }
};


//{ Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}
// } Driver Code Ends