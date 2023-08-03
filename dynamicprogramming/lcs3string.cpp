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
int dp[100][100][100];

int solve(string a,string b,string c, int al,int bl,int cl)
{
    if(al<0 or bl<0 or cl<0)
    return 0;

    if(dp[al][bl][cl]!=-1)
    return dp[al][bl][cl];

    if(a[al]==b[bl] and b[bl]==c[cl])
    return dp[al][bl][cl]=1+ solve(a,b,c,al-1,bl-1,cl-1);
}

int main()
{
    string a,b,c;
    cin>>a>>b>>c;

    memset(dp,-1,sizeof(dp));
    int al=a.size();
    int bl=b.size();
    int cl=c.size();
    cout<<solve(a,b,c,al,bl,cl)<<endl;;
}