//~ author      : DSB
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
 
 
#define ll                      long long
#define pint                    pair<int,int>
#define plong                   pair<long long,long long>
#define vlong                   vector <long long>
#define vint                    vector <int>
#define endl                    "\n"
#define pb                      push_back
#define mp                      make_pair
#define for0(i,n)               for(int i=0;i<n;i++)
#define for1(i,n)               for(int i=1;i<=n;i++)
template <class t>              void printvector(vector<t>& v, ll n) {for0(i,n) {cout<<v[i]<<" ";} cout<<endl;}
//-----------------------------------------------------------------------------------------------------------
long long dp[1001][1001];
int solve(int n, int w, vector<int> weight, vector<int> value)
{
    // cout<<n<<" "<<w<<endl;
    if(w==0 or n==-1)
    return 0;

    if(dp[n][w]!=-1)
    return dp[n][w];

    if(weight[n]>w)
    return dp[n][w]= solve(n-1,w,weight,value);

    int a = value[n] + solve(n-1,w-weight[n],weight,value);
    int b = solve(n-1,w,weight, value);
    return dp[n][w] = max(a,b);

}
int main()
{
    int n,w;
    cin>>n>>w;
    vector<int> weight(n,0);
    vector<int> value(n,0);
    for(int i=0; i<n;i++)
    cin>>weight[i];
    for(int i=0;i<n;i++)
    cin>>value[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            dp[i][j]=-1;
        }
    }

    int ans= solve(n-1,w,weight,value);
    cout<<ans<<endl;
    

}