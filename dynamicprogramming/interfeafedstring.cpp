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

int solve(string a, string b, string c, int x, int y, int len)
{
    if(len==0)
    return 1;

    if(dp[x][y]!=-1)
    return dp[x][y];

    int m=0,n=0;

    if(x-1>=0 and a[x-1]==c[len-1])
    m= solve(a,b,c,x-1,y,len-1);

    if(y-1>=0 and b[y-1]==c[len-1])
    n= solve(a,b,c,x,y-1,len-1);

    return dp[x][y]= m or n;

}

int main()
{
    string a,b,c;
    cin>>a>>b>>c;
    int x=a.size();
    int y=b.size();
    int len=c.size();

    if(x+y != len)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    memset(dp,-1,sizeof(dp));

    if(solve(a,b,c,x,y,len))
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;


}