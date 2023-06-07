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
void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    int t=0;
    for(int i =n-2;i>=0;i--)
    {
        if(v[i]>v[i+1])
        {
            t=i;
            break;
        }
    }
    if(i<0)
    {
        reverse(v.begin(),v.end());
        return v;
    }
    else
    {
        int j;
        for (j = n - 1; j > i; j--) {
            if (arr[j] > arr[i]) {
                break;
            }
        }
        swap(v[t],v[j]);
        reverse(v.begin()+t+1,v.end());
        return v;
    }
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