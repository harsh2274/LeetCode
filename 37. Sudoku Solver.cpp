class Solution {
public:
    bool pos_check(int N ,vector<vector<char>>& vec , int n , int m , char t ){
        //cout << "n: " << n << " m : " << m << " N: " << N << endl ;
        for (int i = 0 ; i<9 ; i++){
            if ( vec[n][i]==t || vec[i][m]==t ){
                return(0);
            }
        }
        int start_left = m - m%3;
        int start_up =  n - n%3;
        for (int i = start_up ; i < start_up+3 ; i++ ){
            for (int j = start_left ; j < start_left+3 ; j++ ){
                if (vec[i][j]==t){
                    return(0) ;
                }
            }
        }
        return(1);
    }

    bool put_number(vector<vector<char>>& board , int N ){
        for (int i = 0 ; i<N ; i++){
            for (int j = 0 ; j<N ; j++){
                if (board[i][j]=='.'){
                    for(char k = '1' ; k<='9' ; k++ ){
                        if(pos_check(N , board , i , j , k)){
                            board[i][j]=k ;
 
                            if(!put_number(board,N)){
                                board[i][j]='.' ;
                            }
                            else{
                                return (1);
                            }
                        }
                    }
                    return (0);
                }
            }
        }
        return(1) ;
    }

    void solveSudoku(vector<vector<char>>& board) {
         put_number( board , board.size() );
        
    }
};