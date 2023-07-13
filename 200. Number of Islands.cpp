class Solution {
public:

    void left(vector<vector<char>> &m , int i , int j , vector<vector<int>> &pos , int N , int M){
        if(j>0 && m[i][j-1]=='1' && pos[i][j-1]==0){
            pos[i][j-1]=1 ;
            bfs(i,j-1,m,pos,N,M) ;
        }
    }

    void right(vector<vector<char>> &m , int i , int j , vector<vector<int>> &pos , int N , int M){
        if(j<M-1 && m[i][j+1]=='1' && pos[i][j+1]==0){
            pos[i][j+1]=1;
            bfs(i,j+1,m,pos,N,M) ;
        }
    }

    void up(vector<vector<char>> &m , int i , int j , vector<vector<int>> &pos , int N , int M){
        if(i>0 && m[i-1][j]=='1' && pos[i-1][j]==0){
            pos[i-1][j]=1;
            bfs(i-1,j,m,pos,N,M) ;
        }
    }
    void down(vector<vector<char>> &m , int i , int j , vector<vector<int>> &pos , int N , int M){
        if(i<N-1 && m[i+1][j]=='1' && pos[i+1][j]==0){
            pos[i+1][j]=1 ;
            bfs(i+1,j,m,pos,N,M) ;
        }
    }

    void bfs(int i , int j , vector<vector<char>>& grid , vector<vector<int>>& pos , int N , int M){
        left(grid,i,j,pos,N,M);
        right(grid,i,j,pos,N,M);
        up(grid,i,j,pos,N,M);
        down(grid,i,j,pos,N,M);
    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> pos ;
        vector<int> temp ;
        int N = grid.size() ;
        int M = grid[0].size() ;

        for (int i =0 ; i<grid[0].size() ; i++){
            temp.push_back(0);
        }
        for (int i =0 ; i<grid.size() ; i++){
            pos.push_back(temp);
        }

        int count = 0 ;
        for(int i = 0 ; i<grid.size() ; i++ ){
            for(int j = 0 ; j<grid[i].size() ; j++ ){
                if(pos[i][j]==0 && grid[i][j]=='1'){
                    count ++ ;
                    pos[i][j]=1 ;
                    bfs(i,j,grid,pos,N,M) ;
                }
            }
        }
        return(count) ;
    }
};