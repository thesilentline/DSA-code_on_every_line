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
void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    int ans=0;
    for(int i=0,j=n-1;i<=j;)
    {
        if(v[i]==v[j])
        {
            i++;
            j--;
        }
        else if(v[i]>v[j])
        {
            j--;
            v[j]+= v[j+1];
            ans++;
        }
        else
        {
            i++;
            v[i]+=v[i-1];
            ans++;
        }
    }
    return ans;
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