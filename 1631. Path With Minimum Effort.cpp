class Solution {
public:

    int minimumEffortPath(vector<vector<int>>& heights) {
       
        /*cout << heights.size() ;
        if(heights.size()==1) {
            int temp = -99 ;
            if(heights[0].size()==1){
                return(0);
            }
            for (int i = 1 ; i<heights[0].size();i++){
                if (abs(heights[0][i]-heights[0][i-1])>temp){
                    temp = abs(heights[0][i]-heights[0][i-1]) ;
                }
            }
            return(temp) ;     
        }*/

        int n = heights.size() ;
        int m = heights[0].size() ;

        vector<int> temp (m,9999999) ;
        vector<vector<int>> matrix(n,temp) ;
        
        matrix[0][0] = 0 ;

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        pq.push({0,{0,0}}) ;
    

        int dr[] = {-1,0,1,0} ;
        int dc[] = {0,1,0,-1} ;


        while(!pq.empty()){
            auto it = pq.top() ;
            pq.pop() ;
            int data =  it.first ;
            int row = it.second.first ;
            int col = it.second.second ;
           

            if(row == (n-1) && col == (m-1) ){
                return(data) ;
            }
        

            for (int k = 0 ; k< 4 ; k++ )
            {
                int i = row + dr[k] ;
                int j = col + dc[k] ;

                if(i>=0 && j>=0 && j<m && i<n){
                    int temp = max(abs(heights[i][j] - heights[row][col]) , data) ;
                    if (temp<matrix[i][j]){
                        matrix[i][j] = temp ;
                        pq.push({temp,{i,j}}) ;
                    }
                }
            }
        }  
        return(-1) ;     
    }
};