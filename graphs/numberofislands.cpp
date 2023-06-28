//~ author      : DSB
#include <iostream>
#include <vector>
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

    void islands(vector<vector<int>> &visit, vector<vector<int>> &map, int i, int j, int n)
    {
        if(i<0 or j<0 or i>n-1 or j>n-1)    return;
        if(map[i][j]==0)    return;
        if(!visit[i][j])
        {
            visit[i][j]=1;
            islands(visit, map, i+1, j, n);
            islands(visit, map, i+1, j+1, n);
            islands(visit, map, i-1, j, n);
            islands(visit, map, i-1, j-1, n);
            islands(visit, map, i, j-1, n);
            islands(visit, map, i, j+1, n);
            islands(visit, map, i+1, j-1, n);
            islands(visit, map, i-1, j+1, n);
        }

    }

};

int main() 
{
    int n=5;
    Graph g(n);
    vector<vector<int>> map= {  { 1, 1, 0, 0, 0 },
                                { 0, 1, 0, 0, 1 },
                                { 1, 0, 0, 1, 1 },
                                { 0, 0, 0, 0, 0 },
                                { 1, 0, 1, 0, 1 } };

    vector<vector<int>> visit(n,vector<int>(n));
    int c=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!visit[i][j] and map[i][j]==1)
            {
                c++;
                g.islands(visit, map,i, j, n);
            }
        }
    }

    cout<<c<<endl;



    return 0;
}