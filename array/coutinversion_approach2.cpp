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
int merge(vector<int> v,vector<int> temp,int left,int mid,int right)
{
    int i=0,j=0,k=0;
    int inv_count=0;
    i=left;
    k=left;
    j=mid;
    while((i<=mid-1) && (j<=right))
    {
        if(v[i]<=v[j])
        {
            temp[k++]=v[i++];
        }
        else
        {
            temp[k++]=v[j++];
        }
    }
    while(i<=mid-1)
    {
        temp[k++]=v[i++];
    }
    while(j<=right)
    {
        temp[k++]=v[j++];
    }

    for(int i=0;i<right+1;i++)
    {
        v[i]=temp[i];
    }
    return inv_count;
}
int _mergesort(vector<int> v, vector<int> temp, int left, int right)
{
    int mid=(right-left)/2;
    int inv_count=0;
    if(right>left)
    {
        inv_count+=_mergesort(v,temp,left,mid);
        inv_count+=_mergesort(v,temp,mid+1,right);
        inv_count+=merge(v,temp,left,mid+1,right);
    }
    return inv_count;
}
int mergesort(vector<int> v, int n)
{
    vector<int> temp;
    return _mergesort(v,temp,0,n-1);
}
void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    cout<<mergesort(v,n)<<endl;;
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