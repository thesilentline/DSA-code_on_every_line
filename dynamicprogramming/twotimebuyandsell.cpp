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
    vector<int> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    int first_buy= INT_MIN;
    int first_sell=0;
    int second_buy=INT_MIN;
    int second_sell=0;

    for(int i=0;i<n;i++)
    {
        first_buy= max(first_buy, -a[i]);
        first_sell= max(first_sell, first_buy+a[i]);
        second_buy= max(second_buy, first_sell-a[i]);
        second_sell= max(second_sell, second_buy+a[i]);
    }

    cout<<second_sell<<endl;
    return 0;
}