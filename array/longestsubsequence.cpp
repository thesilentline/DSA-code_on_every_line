//~ author      : DSB
#include<bits/stdc++.h>
#include<iostream>
#include <set>
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
void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    sort(v.begin(),v.end());
    int maxcount=0;
    int c=1;
    for(int i=1;i<n;i++)
    {
        if(v[i]==v[i-1]+1)
        {
            c++;
        }
        else
        {
            maxcount= max(maxcount,c);
            c=1;
        }
    }
    cout<<maxcount<<endl;

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