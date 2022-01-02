/**
 * LeetCod 200
 * Number of islands in a grid  contains 1 and 0
 * 1 is land, 0 is water
 * 
 * An island is surrounded by water and is formed by connecting adjacent lands 
 * horizontally or vertically. You may assume all four edges of the grid are all surrounded by water. 
 * 
 * Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
  ]

  o/p: 1

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
 ]

Output: 3

vertical and horizontal connection to land 1's 
can be solved using DFS and BFS
 */
// Bfs approach
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
   /* bool isValid(int r, int c, vector<vector<char>> &grid)
    {
        return 0<=r && r <grid.size() && 0<=c && c< grid[0].size();
    }*/
    
    int numIslands(vector<vector<char>>& grid) 
    {
        if(grid.empty() || grid[0].empty())
        {
            return 0;
        }
        int r = grid.size();
        int c = grid[0].size();        

        // using lambda to make use of available variable        
        auto isValid = [&](int row, int col)
		{
			return 0<=row && row <r && 0<=col && col< c;
		};
        
        int ans = 0;
        queue<pair<int, int>>q;
        // to identify already visited or not
        vector<vector<bool> >visited(r, vector<bool>(c));            
        // 4 directions from any position.
        vector<pair<int, int> > directions{{1, 0}, {0,1}, {-1,0}, {0,-1} };
        for(int i =0; i< r; i++)
        {
            for(int j =0; j< c; j++)
            {
                // general Bfs, and checking for land
                if(!visited[i][j] && grid[i][j] == '1')  
                {
                    // connected element 
                    ans++;
                    q.push({i,j});
                    visited[i][j] = true;
                    while(!q.empty())
                    {
                        pair<int,int> p = q.front();
                        q.pop();
                        // adjacent neighbours 
                        for(pair<int, int> dir: directions )
                        {
                            int newrow = p.first + dir.first;
                            int newcol = p.second + dir.second;                        
                            if(/*isValid(newrow, newcol, grid) */ isValid(newrow, newcol) && !visited[newrow][newcol] && grid[newrow][newcol] == '1' )
                            {
                                q.push({newrow, newcol});
                                visited[newrow][newcol] = true;
                            }
                        }
                    }     
               }                                 
                                             
            }     
        }
        return ans;
    }
                                             
};

int main()
{
    Solution s;
    vector<vector<char> > grid { 
    {'1','1','1','1','0'},
    {'1','1','0','1','0'},
    {'1','1','0','0','0'},
    {'0','0','0','0','0'}
   };

   cout<<s.numIslands(grid); 
    return 0;

}