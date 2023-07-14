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

    void dfs_order(int src, vector<int> &order, vector<int> &visit)
    {
        visit[src]=1;
        for(auto i: adjList[src])
        {
            if(!visit[i])
            dfs_order(i,order,visit);
        }
        order.push_back(src);

    }

    void dfs(int src, vector<int> &visit_rev,vector<int> reverse[])
    {
        visit_rev[src]=1;
        for(auto i: reverse[src])
        {
            if(!visit_rev[i])
            dfs(i,visit_rev,reverse);
        }
        // cout<<src<<" ";
    }

    int kosarajualgo()
    {
        vector<int> order;
        vector<int> reverse[numVertices];
        for(int i=0;i<numVertices;i++)
        {
            for(auto j: adjList[i])
            reverse[j].push_back(i);
        }
        vector<int> visit(numVertices,0);
        for(int i=0;i<numVertices;i++)
        {
                if(!visit[i])
                dfs_order(i,order,visit);
        }
        printvector(order, order.size());

        int ans=0;
        vector<int> visit_rev(numVertices,0);
        for(int i= numVertices-1;i>=0;i--)
        {
            
            if(!visit_rev[order[i]])
            {
                dfs(order[i],visit_rev,reverse);
                ans++;
            }

        }
        return ans;

    }

};

int main() 
{
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    g.printGraph();

    int ans= g.kosarajualgo();
    cout<<ans<<endl;

    return 0;
}