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

int main()
{
    int n;
    cin>>n;
    vector<int> price(n);
    for(int i=0;i<n;i++)
    cin>>price[i];
    vector<int> ans(n);
    int minprice= price[0];
    int maxprice= price[n-1];
    for(int i=n-2;i>=0;i--)
    {
        maxprice=max(maxprice,price[i]);
        ans[i]=max(ans[i+1],maxprice-price[i]);
    }
    for(int i=1;i<n;i++)
    {
        minprice=min(minprice,price[i]);
        ans[i]=max(ans[i-1],ans[i]+price[i]-minprice);
    }

    cout<<ans[n-1]<<endl;

}