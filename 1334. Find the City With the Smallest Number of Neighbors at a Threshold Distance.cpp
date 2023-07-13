class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
				vector<int> temp(n);
        vector<vector<int>> matrix(n,temp) ;

        for (int i = 0 ; i< matrix.size() ; i++) {
	        for (int j = 0 ; j< matrix.size() ; j++) {
            	if(i == j ) { 
								matrix[i][j]=0 ; 
							}
	            else {
								matrix[i][j] = 1e8 ; 
							} 
	        }
	   		}
        
        for (int i = 0 ; i<edges.size() ; i++ ){
            matrix[edges[i][0]][edges[i][1]] = edges[i][2] ;
						matrix[edges[i][1]][edges[i][0]] = edges[i][2] ;
        }

	    
	    for (int i = 0 ; i < matrix.size() ; i++ ){
	        for (int j = 0 ; j< matrix.size() ; j++) {
	            for (int k = 0 ; k< matrix.size() ; k++) {
	                if(matrix[j][i] + matrix[i][k] < matrix[j][k] ){
	                    matrix[j][k] = matrix[j][i] + matrix[i][k] ; 
	                }
	            }
	        }
	    }

	    
			int count = 1e8 ;
			int tempi = -1 ;
			int counti = 0 ;

	    for (int i = 0 ; i< matrix.size() ; i++) {
					counti = 0 ;
	        for (int j = 0 ; j< matrix.size() ; j++) {
	            if(matrix[i][j]<=distanceThreshold && matrix[i][j]!=1e8){
								counti ++ ;
							}
	        }

					if (counti<=count){
						tempi = i ;
						//cout << i << endl ;
						count = counti ;
					}	
	    }
			return(tempi) ;
    }
};