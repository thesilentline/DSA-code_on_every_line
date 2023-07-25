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
int dp[100];

int solve(int n, int x,int y, int z)
{
    if(n==0)
    return 0;

    if(n<0)
    return -1;

    if(dp[n]!= -1)
    return dp[n];

    int a,b,c;
    a= 1+ solve(n-x,x,y,z);

    b= 1+ solve(n-y,x,y,z);

    c= 1+ solve(n-z,x,y,z);
    return dp[n]=max(a,max(b,c));
}

int main()
{
    int n,x,y,z;
    cin>>n>>x>>y>>z;
    memset(dp,-1,sizeof(dp));
    cout<<solve(n,x,y,z)<<endl;

}