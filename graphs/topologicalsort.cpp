//~ author      : DSB
#include <iostream>
#include <vector>
#include <queue>
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

    vector<int> toposort(int n)
    {
        vector<int> in(n,0);
        vector<int> ans;
        queue<int> q;

        for(int i=0;i<n;i++)
        {
            for(auto j: adjList[i])
            {
                in[j]++;
            }
        }

        for(int i=0;i<n;i++)
        {
            if(in[i]==0)
            q.push(i);
        }

        while(!q.empty())
        {
            int front= q.front();
            q.pop();
            ans.push_back(front);

            for(auto i: adjList[front])
            {
                in[i]--;
                if(in[i]==0)
                q.push(i);
            }
        }

        return ans;

    }

};

int main() 
{
    int n=6;
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.printGraph();

    vector<int> ans;
    ans= g.toposort(n);
    printvector(ans,ans.size());

    return 0;
}