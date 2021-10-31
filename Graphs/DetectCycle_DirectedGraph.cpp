/**
 * Detect cycle in Directed Grpah
   Using Dfs
 * O(V+E)  Time
 * O(V) space
 */ 
#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int size;
    list<int>*adj;
public:
    Graph(int n)
    {
        size = n;
        adj = new list<int>[n];
    }
    ~Graph()
    {
        delete[] adj;
    }
    void addEdge(int src, int dst)
    {
        // directed graph
        adj[src].push_back(dst);
    }

    bool DfsUtil(int v, bool visited[], vector<bool> &p)
    {
        visited[v] = true;
        p[v] = true;
        for(auto i: adj[v])
        {
            if(!visited[i])
            {
                if(DfsUtil(i, visited, p))
                {
                    return true;
                }
            }
            // vertix is already visited and also in same path.
            else if(p[i])
            {
                return true;
            }
        }
        // vertix is not in same path and can be connected in other path.
        p[v] = false;
        return false;
    }

    bool isCyclic()    
    {
        bool visited[size] = {false};
        // ordering to find the vertix is in same path i.e cycle
        vector<bool>v(size, false); 
        // for disconnecte Graph
        for(int i =0; i < size; i++)
        {
            if(!visited[i])
            {
                if(DfsUtil(i, visited, v))
                {
                    return true;
                }
            }    
        }
        return false;
    }    
};

int main()
{
    Graph g(6);
    g.addEdge(5,2);
    g.addEdge(2,1);
    g.addEdge(1,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(4,0);
    // 1->3->4->5->2->1 cycle
    cout<< g.isCyclic()<<endl; // 1

    Graph g1(4);    
    g1.addEdge(1,0);
    g1.addEdge(2,3);
    g1.addEdge(3,1);
    g1.addEdge(2,0);
    cout<< g1.isCyclic()<<endl; // 0 no cycle
        
    return 0;
}

