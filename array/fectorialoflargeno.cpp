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
int multip(int x, vector<int> &v, int size)
{
    int carry=0;
    for(int i=0;i<size;i++)
    {
        int t=v[i]*x+carry;
        v[i]=t%10;
        carry=t/10;
    }
    while(carry)
    {
        v[size]=carry%10;
        carry=carry/10;
        size++;
    }
    return size;

}
void solve()
{
    int n;
    cin>>n;
    vector<int> v(500);
    int res_size=1;
    v[0]=1;
    for(int i=2;i<=n;i++)
    {
        res_size=multip(i,v,res_size);
    }
    for(int i=res_size-1;i>=0;i--)
    {
        cout<<v[i];
    }
    cout<<endl;
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