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

    void minsteps(int i, int j,int k,int l, int n,vector<int> &ans, int curr,vector<vector<int>> &visit)
    {
        if(i<0 or j<0 or i>n-1 or j>n-1)
        return;

        if(visit[i][j]==1)
        return;

        if(i==k and j==k)
        {
            ans.push_back(curr);
            return;
        }
        visit[i][j]=1;
        minsteps(i-2,j+1,k,l,n,ans,1+curr,visit);
        minsteps(i-2,j-1,k,l,n,ans,1+curr,visit);

        minsteps(i+2,j+1,k,l,n,ans,1+curr,visit);
        minsteps(i+2,j-1,k,l,n,ans,1+curr,visit);

        minsteps(i+1,j-2,k,l,n,ans,1+curr,visit);
        minsteps(i-1,j-2,k,l,n,ans,1+curr,visit);

        minsteps(i+1,j+2,k,l,n,ans,1+curr,visit);
        minsteps(i-1,j+2,k,l,n,ans,1+curr,visit);
        visit[i][j]=0;
        return;

    }

};

int main() 
{
    int max=6;
    Graph graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    graph.printGraph();
    vector<int> ans;
    vector<vector<int>> visit(max,vector<int>(max));
    graph.minsteps(1,1,4,5,max,ans,0,visit);
    if(ans.size()==0)
    {
        cout<<-1<<endl;
        return 0;
    }
    sort(ans.begin(),ans.end());
    cout<<ans[0]<<endl;

    return 0;
}