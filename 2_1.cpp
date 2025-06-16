
class Solution {
  public:
    vector<vector<bool>> visited;
    int moves[4][2] = {{0, 1},{0, -1}, {1,0},{-1, 0}};
    
    int dfs(int i, int j, int N, vector<vector<int>> &grid){
        if(i<0 || j<0 || i>=N || j >=N || visited[i][j] || grid[i][j] == 0) return 0;
        //the above step is for recursive calls
        //kind of base case this is where recusrion ends
        
        visited[i][j] = true; //this is req , beacuse in further steps of dfs cannot visit already visited grid
        
        int maxcoins = 0;
        
        //going over all 4 possibilities, when all the 4 returns back, we take max of them
        for(int k=0; k<4; k++){
           int ii = i + moves[k][0];
           int jj = j + moves[k][1];
           maxcoins = max(maxcoins, dfs(ii, jj, N, grid));
        }
        
        visited[i][j] = false;
        //going back to original  //is a critial step in dfs or recursion
        return grid[i][j]+maxcoins;
        
    }
    
    int maximumCoins(int N, vector<vector<int>> &grid) {
        // code here
        visited = vector<vector<bool>>(N, vector<bool>(N, false));
        
        int result = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if((i+j)%2 == 1){
                    result = max(result, dfs(i, j, N, grid));
                }
            }
        }
        return result;
    }
};
