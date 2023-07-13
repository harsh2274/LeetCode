class Solution {
public:
    bool pos_check(int N ,vector<string> &vec , int n , int m ){
        //cout << "n: " << n << " m : " << m << " N: " << N << endl ;
        for (int i = 0 ; i<N ; i++){
            if ( vec[n][i]=='Q' || vec[i][m]=='Q' ){
                return(0);
            }
        }
        int j = m ;
        int i = n ;
        int count = 0;
        while (i>-1 && j>-1){
            if (vec[i][j]=='Q'){
                return(0);
            }
            //cout << i << "  " << j << endl ;
            i-- ; j-- ;
        }
        j = m ;
        i = n ;
        while (i<N && j<N){
            if (vec[i][j]=='Q'){
                return(0);
            }
            //cout << i << "  " << j << endl ;
            i ++ ; j++ ;
        }
        j = m ;
        i = n ;
        while (i<N && j>-1){
            if (vec[i][j]=='Q'){
                return(0);
            }
            //cout << i << "  " << j << endl ;
            i++ ; j-- ;
        }
        j = m ;
        i = n ;
        while (i>-1 && j<N){
            if (vec[i][j]=='Q'){
                return(0);
            }
            //cout << i << "  " << j << endl ;
            i-- ; j++ ;
        }
        return(1) ;
    }

    void n_queens(int n , vector<string> &vec , int num_queen , vector<vector<string>> &vec2){
        if(num_queen==n){
            vec2.push_back(vec);
            return;
        }
        if(num_queen>=n)
        {
            return;
        }

        for(int i =0 ; i<n ;  i++){
            //cout << endl <<  "I am here" << endl ;
            if(pos_check(n , vec , num_queen , i )){
                vec[num_queen][i] = 'Q' ;
                n_queens(n , vec , num_queen+1 ,vec2 ) ;
                vec[num_queen][i] = '.' ;
            }
        }

        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> vec;
        vector<vector<string>> vec2;
        cout <<endl<< n << endl ;

        for (int  i = 0 ; i< n ; i++){
            string str ;

            for (int  j = 0 ; j< n ; j++){
                str += "."; 
            }
            vec.push_back(str) ;
        }

        
        

        n_queens(n , vec , 0 , vec2);

       
        return(vec2) ;
    }
};