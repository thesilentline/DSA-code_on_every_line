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

int solve(string s1,int l1, string s2, int l2)
{
    if(l1<0)
    return 0;

    if(l2<0)
    return 0;

    if(dp[l1][l2]!= -1)
    return dp[l1][l2];

    if(s1[l1]==s2[l2])
    return dp[l1][l2]= 1+ solve(s1,l1-1, s2, l2-1);

    return dp[l1][l2]= max(solve(s1,l1,s2,l2-1), solve(s1,l1-1,s2,l2));
}


int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int l1= s1.size();
    int l2= s2.size();
    memset(dp,-1,sizeof(dp));
    cout<<solve(s1,l1-1,s2,l2-1)<<endl;
}