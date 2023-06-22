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

    bool solve(int src, int par, vector<int> &visit)
    {
        visit[src]=1;
        for(int i: adjList[src])
        {
            if(!visit[i])
            {
                bool c= solve(i,src,visit);
                if(c) return true;
            }
            else if(i!=par) return true;
        }
        return false;
    }

};

int main() 
{
    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);

    g2.printGraph();

    vector<int> visit(3,0);
    for(int i=0;i<visit.size();i++)
    {
        if(!visit[i])
        {
            bool c= g2.solve(i,-1,visit);
            if(c==true)
            {
                cout<<"YES"<<endl;
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}