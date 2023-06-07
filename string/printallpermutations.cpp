//~ author      : DSB
#include<bits/stdc++.h>
#include<iostream>
#include<string>
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
void permutation(string s,int l,int r)
{
    if(l==r)
    cout<<s<<endl;
    else
    {
        for(int i=l;i<=r;i++)

            {
                swap(s[l],s[i]);
                permutation(s,l+1,r);
                swap(s[l],s[i]);
            }
            
    }
}
void solve()
{
    string s;
    cin>>s;
    int l=0;
    int r=s.length();
    permutation(s,l,r-1);
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