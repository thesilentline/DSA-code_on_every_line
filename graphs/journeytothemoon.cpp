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

    void dfs(vector<int>&visit, int src,int &k)
    {
        visit[src]=1;
        for(auto i: adjList[src])
        {
            if(!visit[i])
            {
                k=k+1;
                dfs(visit,i,k);
            }
        } 
    }

    int journeytomoon()
    {
        vector<int> visit(numVertices,0);
        int c=0;
        for(int i=0;i<numVertices;i++)
        {
            int k=0;
            if(!visit[i])
            {
                dfs(visit,i,k);
                c = c+ (k)*(k+1)/2;
            }
        }
        c=((numVertices)*(numVertices-1)/2 ) - c;
        return c;
    }

};

int main() 
{
    Graph graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(3, 2);
    graph.addEdge(0, 4);

    graph.printGraph();

    cout<<graph.journeytomoon()<<endl;;


    return 0;
}