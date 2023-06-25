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

    void floodfill(vector<vector<int>> &flood,int i, int j, int n,int k, int t, int m,vector<vector<int>> &visit)
    {
        if(i<0 or j<0 or i>n-1 or j>k-1)
        return;

        if(visit[i][j]==1 or flood[i][j]!=t)
        return;

        visit[i][j]=1;
        flood[i][j]=m;
        floodfill(flood, i+1, j, n, k, t, m, visit);
        floodfill(flood, i-1, j, n, k, t, m, visit);
        floodfill(flood, i, j+1, n, k, t, m, visit);
        floodfill(flood, i, j-1, n, k, t, m, visit);
    }

};

int main() 
{
    Graph graph(5);

    int m=8;
    int n=8;


    vector<vector<int>> flood ={
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 0, 0},
    {1, 0, 0, 1, 1, 0, 1, 1},
    {1, 2, 2, 2, 2, 0, 1, 0},
    {1, 1, 1, 2, 2, 0, 1, 0},
    {1, 1, 1, 2, 2, 2, 2, 0},
    {1, 1, 1, 1, 1, 2, 1, 1},
    {1, 1, 1, 1, 1, 2, 2, 1}};

    int i=4;
    int j=4;

    int newn= 3;
    vector<vector<int>> visit(m,vector<int>(n));
    graph.floodfill(flood,i,j,m,n, flood[i][j], newn,visit);

    for(auto i: flood)
    {
        for(auto j: i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }

    

    return 0;
}