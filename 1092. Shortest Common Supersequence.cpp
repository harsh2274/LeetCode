class Solution {
public:

    string shortestCommonSupersequence(string s, string t) {
        int n = s.length() ;
        int m = t.length() ;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0)) ;

        for (int i = 1 ; i<=n ;i++){
            for(int j = 1;j<=m ; j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else {
                    dp[i][j]=0+max(dp[i-1][j],dp[i][j-1]) ;
                }
            }
        }

        int i = n ;
        int j = m ;

        vector<int> vec_str1 ;
        vector<int> vec_str2 ;
        while(i>0 && j>0){
            if (dp[i][j]==dp[i-1][j]){
                i-- ;
            }
            else if (dp[i][j]==dp[i][j-1]){
                j--;
            }
            else {
                vec_str1.push_back(i-1) ;
                vec_str2.push_back(j-1) ;
                i-- ;
                j-- ;
            }
        }
        reverse(vec_str1.begin(),vec_str1.end()) ;
        vec_str1.push_back(s.length()) ;
        reverse(vec_str2.begin(),vec_str2.end()) ;
        vec_str2.push_back(t.length()) ;


        i = 0 ;
        int siz1 = vec_str1.size() ;
        string to_submit = "" ; 
        j = 0 ;
        int k = 0 ;
        while(i<siz1){
            while(j<vec_str1[i]){
                to_submit += s[j] ;
                j++ ;
            }
            while(k<vec_str2[i]){
                to_submit += t[k] ;
                k++ ;
            } 
            if(j<s.size()){  
                to_submit += s[j] ;
            }
            j++ ;
            k++ ;
            i++ ;
        }

        return(to_submit) ;
    }
};