class Solution {
public:
    int checker(int p , int t , vector<vector<int>>& grid , int m , int n ) {
        set<int> up ;
        set<int> down ;
        int i = p ;
        int j = t ;
        //cout << i << "  " << j << endl ;
        while(i+1<m && j+1<n){
            //cout << " di" << endl ;
            i++ ;
            j++ ;
            //cout << i << "  " << j << "  " << grid[i][j] << endl ;
            up.insert(grid[i][j]);
        }
        //cout << "out" << endl ;
        i = p ;
        j = t ;
        //cout << "out2" << endl ;
        while(i-1>-1 && j-1>-1){
            i-- ;
            j-- ;
            //cout << i << "  " << j << "  " << grid[i][j] << endl ;
            down.insert(grid[i][j]);
        }
        int sumi = up.size() - down.size() ;
        //cout << "out3" << endl ;
        if (sumi<0){
            sumi = sumi*-1 ;
        }
        //cout << "out4" << endl ;
        return(sumi);
    }
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        vector<vector<int>> main ;
        for (int i = 0 ; i<n ; i++){
            vector<int> temp ;
            for (int j = 0 ; j< m ; j++){
                temp.push_back(checker(i,j,grid,n,m));
            }
            main.push_back(temp) ;
        }
        return(main);
        
    }
};