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
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int k;
    cin>>k;
    sort(v.begin(), v.end(), greater<int>());
    int i=0;
    int sum=0;
    while(i<n-1)
    {
        int x= v[i]-v[i+1];
        if(x<k)
        {
            sum += v[i] +v[i+1];
            i=i+2;
        }
        else
        i++;
    }
    cout<<sum<<endl;

}