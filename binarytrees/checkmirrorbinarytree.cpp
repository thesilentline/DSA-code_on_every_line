//{ Driver Code Starts
//Initial Template for C++

#include<iostream>
#include<vector>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        vector<vector<int>> f(n+1);
        vector<vector<int>> s(n+1);
        for(int i=0;i<e*2;i+=2)
        f[A[i]].push_back(A[i+1]);
        for(int i=0;i<e*2;i+=2)
        s[B[i]].push_back(B[i+1]);
        for(int k=1;k<=n;k++)
        {
            if(f[k].size()!=s[k].size())
            return 0;
            for(int i=0,j=f[k].size()-1;j>=0;j--,i++)
            {
                if(f[k][i]!=s[k][j])
                return 0;
            }
            
        }
        return 1;
        
        
        // code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        
        cin>>n>>e;
        int A[2*e], B[2*e];
        
        for(int i=0; i<2*e; i++)
            cin>>A[i];
            
        for(int i=0; i<2*e; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n,e,A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends