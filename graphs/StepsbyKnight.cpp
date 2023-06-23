//~ author      : DSB
#include <iostream>
#include <vector>
#include<queue>
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

class Graph 
{
private:
    int numVertices; 
    vector<vector<int>> adjList;

public:   
    Graph(int vertices) 
    {
        numVertices = vertices;
        adjList.resize(numVertices);
    }

    void addEdge(int vertice1, int vertice2) 
    {
        adjList[vertice1].push_back(vertice2);
        adjList[vertice2].push_back(vertice1);
    }

    void printGraph() 
    {
        for (int i = 0; i < numVertices; i++) 
        {
            cout << "Vertex " << i << ": ";
            for (int j = 0; j < adjList[i].size(); j++) 
            {
                cout << adjList[i][j] << " ";
            }
            cout << endl;
        }
    }

};

int main() 
{
    int n=31;
    vector<int> v;
    vector<vector<int>> visit(n,vector<int>(n));
    queue<pair<int,int>> q;
    int i,j,k,l;
    cin>>i>>j>>k>>l;
    q.push(make_pair(i,j));
    while(!q.empty())
    {
        pair<int,int> curr= q.front();
        int a=curr.first;
        int b=curr.second;
        q.pop();
        if((a+1)>=0 and (a+1)<n and (b+2)>=0 and (b+2)<n and visit[a+1][b+2]==0)
        {
            visit[a+1][b+2]=visit[a][b]+1;
            q.push(make_pair(a+1,b+2));
        }
        if((a-1)>=0 and (a-1)<n and (b+2)>=0 and (b+2)<n and visit[a-1][b+2]==0)
        {
            visit[a-1][b+2]=visit[a][b]+1;
            q.push(make_pair(a-1,b+2));
        }
        if((a+2)>=0 and (a+2)<n and (b+1)>=0 and (b+1)<n and visit[a+2][b+1]==0)
        {
            visit[a+2][b+1]=visit[a][b]+1;
            q.push(make_pair(a+2,b+1));
        }
        if((a+2)>=0 and (a+2)<n and (b-1)>=0 and (b-1)<n and visit[a+2][b-1]==0)
        {
            visit[a+2][b-1]=visit[a][b]+1;
            q.push(make_pair(a+2,b-1));
        }
        if((a-2)>=0 and (a-2)<n and (b+1)>=0 and (b+1)<n and visit[a-2][b+1]==0)
        {
            visit[a-2][b+1]=visit[a][b]+1;
            q.push(make_pair(a-2,b+1));
        }
        if((a-2)>=0 and (a-2)<n and (b-1)>=0 and (b-1)<n and visit[a-2][b-1]==0)
        {
            visit[a-2][b-1]=visit[a][b]+1;
            q.push(make_pair(a-2,b-1));
        }
        if((a-1)>=0 and (a-1)<n and (b-2)>=0 and (b-2)<n and visit[a-1][b-2]==0)
        {
            visit[a-1][b-2]=visit[a][b]+1;
            q.push(make_pair(a-1,b-2));
        }
        if((a+1)>=0 and (a+1)<n and (b-2)>=0 and (b-2)<n and visit[a+1][b-2]==0)
        {
            visit[a+1][b-2]=visit[a][b]+1;
            q.push(make_pair(a+1,b-2));
        }

    }
    cout<<visit[k][l]<<endl;


    return 0;
}