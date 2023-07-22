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
int dp[100][100];

bool solve(int n,int sum,vector<int> arr)
{
    if(n<0)
    {
        if(sum==0)
            return true;
        return false;
    }
    if(sum<0)
    return false;

    if(sum==0)
    return true;

    if(dp[n][sum]!=-1)
    return dp[n][sum];

    if(sum==arr[n])
    return dp[n][sum]=true;

    return dp[n][sum] = solve(n-1,sum,arr) or solve(n-1,sum-arr[n],arr);
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum += arr[i];
    }
    if(sum%2!=0)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    memset(dp,-1,sizeof(dp));
    sum=sum/2;
    if(solve(n-1,sum,arr))
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;

}