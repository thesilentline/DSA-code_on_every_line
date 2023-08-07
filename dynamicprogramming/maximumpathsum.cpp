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

int solve(int n,int i,int j, vector<vector<int>> v)
{
    if(i<0 or j<0 or i>=n or j>=n)
    return 0;

    if(dp[i][j]!=-1)
    return dp[i][j];

    int a=v[i][j] + solve(n,i+1,j,v);
    int b=v[i][j] + solve(n,i+1,j+1,v);
    int c=v[i][j] + solve(n,i+1,j-1,v);
    return dp[i][j]= max(a,max(b,c));
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> v;
    for(int i=0;i<n;i++)
    {
        vector<int> temp;
        for(int j=0;j<n;j++)
        {
            int a;
            cin>>a;
            temp.push_back(a);
        }
        v.push_back(temp);
    }
    memset(dp,-1,sizeof(dp));
    int m=0;
    for(int i=0;i<n;i++)
    {
        m= max(m,solve(n,0,i,v));
    }
    cout<<m<<endl;
}