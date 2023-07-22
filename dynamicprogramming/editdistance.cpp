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
int solve(string s1,string s2, int a, int b)
{
    if(a<0)
    return b+1;
    if(b<0)
    return a+1;

    if(dp[a][b]!=-1)
    return dp[a][b];

    if(s1[a]==s2[b])
    return solve(s1,s2,a-1,b-1);

    int x= 1+solve(s1,s2,a-1,b);
    int y= 1+solve(s1,s2,a,b-1);
    int z= 1+solve(s1,s2,a-1,b-1);

    return dp[a][b]= min(x,min(y,z));

}

int main()
{
    string s1, s2;
    cin>>s1>>s2;
    int a= s1.size();
    int b= s2.size();
    memset(dp,-1,sizeof(dp));
    cout<<solve(s1,s2,a-1,b-1)<<endl;
}