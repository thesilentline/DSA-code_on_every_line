//~ author      : DSB
#include <iostream>
#include <vector>
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
    int n,m;
    cin>>n>>m;
    set<pair<int, vector<int>>> edge;
    for(int i=0;i<m;i++)
    {
        int u,v, wt;
        cin>>u>>v>>wt;
        vector<int> nodes = {u, v};
        edge.insert(make_pair(wt, nodes));
    }

    for(auto i: edge)
    {
        int wt= i.first;
        int u= i.second[0];
        int v= i.second[1];
        
    }



    return 0;
}