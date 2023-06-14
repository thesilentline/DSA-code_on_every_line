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
    string s;
    cin>>s;
    set<char> st;
    for(int i=0;i<s.length();i++)
    {
        st.insert(s[i]);
    }
    int unique=st.size();
    int size=s.length();
    
    for(int i=0;i<s.length();i++)
    {
        int count=0;
        int visited[256]={0};
        
    }
}