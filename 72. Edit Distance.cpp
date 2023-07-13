class Solution {
public:
    
    int minDistance(string word1, string word2) {
        vector<int> prev(word2.length()+1) ;
        vector<int> curr(word2.length()+1) ;
        for (int i = 0 ; i<word2.size()+1; i++){
            prev[i] = i ;
        }
    
        for (int i = 1 ; i<=word1.length() ; i++){
            curr[0] = i ;
            for (int j = 1 ; j<=word2.length() ; j++){
                if(word1[i-1]==word2[j-1]){
                    curr[j]=prev[j-1] ;
                }
                else{
                    curr[j] = 1+min(curr[j-1],min(prev[j],prev[j-1]));
                }
            }
            prev = curr ;
        }
        return(prev[word2.length()]) ;
    }
};