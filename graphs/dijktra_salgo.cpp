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

    void dijktras(int src, int n, vector<vector<pair<int,int>>> g)
    {
        vector<int> visit(n,0);
        vector<int> distance(n,INFINITY);
        set<pair<int,int>> s;
        s.insert(make_pair(0,src));
        distance[src]=0;
        while(s.size()!=0)
        {
            pair<int,int> front= *s.begin();
            int node= front.second;
            int dis= front.first;
            s.erase(s.begin());
            if(visit[node]==1) continue;
            visit[node]=1;
            for(auto i: g[node])
            {
                int child= i.second;
                int wt= i.first;
                if(wt+distance[node] < distance[child])
                {
                    distance[child]= wt+distance[node];
                    s.insert(make_pair(distance[child],child));
                }


            }
        }
    }

};

int main() 
{

    return 0;
}