class Solution {
public:
    

    int longestPalindromeSubseq(string s) {
        int len = s.length() ;
        vector<int> next(len+1,0) ;
        vector<int> curr(len+1,0) ;
        for (int n = len ; n>=1 ; n-- ){
            for(int m = 1 ; m <=len ; m++ ){
                if(s[n-1]==s[m-1]){
                    curr[m]=1+next[m-1];
                }
                else {
                    curr[m]=0+max(next[m],curr[m-1]) ;
                }
            }
            next = curr ;
        }
        return(curr[len]) ;
    }
};