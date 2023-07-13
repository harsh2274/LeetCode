class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int n = s.length() ;
        int m = t.length() ;
        vector<int> next(m+1,0) ;
        vector<int> prev(m+1,0) ;
        for (int i = 1 ; i<=n ;i++){
            for(int j = 1;j<=m ; j++){
                if(s[i-1]==t[j-1]){
                    next[j]=1+prev[j-1];
                }
                else {
                    next[j]=0+max(prev[j],next[j-1]) ;
                }
            }
            prev = next ;
        }
        return(next[m]) ;
    }
};