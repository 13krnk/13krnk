/**
 * BFS - Breadth first search 
 * 
 * For connected and Disconncted Graph USing Recursion and itertive.
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
        //adj[dst].push_back(src);
    }
    
    // BFs in recursive
    // here just Util called as separate loop and using queue maintained interanlly for each sibiling
    void BfsUtil(queue<int>q, bool visited[])
    {        
        if(q.empty())
        {
            return ;
        }
        int tp = q.front();
        q.pop();
        cout<<tp<<" ";
        for(auto i: adj[tp])
        {
            if(!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
        BfsUtil(q, visited);
    }

    void Bfs(int v)
    {
        queue<int>q;
        q.push(v);
        bool visited[size] = {false};
        visited[v] = true;
        BfsUtil(q, visited);
    }

    void Bfs_iterative(int v)
    {
        queue<int>q;
        bool visited[size] = {false};
        q.push(v);
        visited[v] = true;
        while(!q.empty())
        {
            int tp = q.front();
            cout<<tp<<" ";
            q.pop();
            for(auto i: adj[tp])
            {                
                if(!visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }         
    } 
};

int main()
{
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,3);
    g.addEdge(3,5);
    g.addEdge(2,4);
    g.addEdge(4,6);
    g.addEdge(5,2);

    g.Bfs_iterative(0);
    g.Bfs(0);
    return 0;
}
