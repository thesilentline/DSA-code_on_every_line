//~ author      : DSB
#include<bits/stdc++.h>
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
int calculate(string s1, string s2, int m, int n)
{
    if(n==0)
    return m;
    if(m==0)
    return n;
    if(s1[m-1]==s2[n-1])
    return calculate(s1,s2,m-1,n-1);
    else
    return 1+min(calculate(s1,s2,m-1,n),min(calculate(s1,s2,m,n-1),calculate(s1,s2,m-1,n-1)));
}
void solve()
{
    string s1,s2;
    cin>>s1>>s2;
    int m=s1.length();
    int n=s2.length();
    cout<<calculate(s1,s2,m,n);
}
int main()
{
// int t;
// cin>>t;
// for(int i=0;i<t;i++)
{
solve();
}
}