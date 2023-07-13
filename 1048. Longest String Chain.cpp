class Solution {
public:
    bool checker(string word1 , string word2){
        int flag = 0 ;
        int j = 0 ;
        for(int i = 0 ; i<word1.length();i++){
            if(word1[i]!=word2[j]){
                if (flag == 0 ){
                    j++;
                    flag = 1 ;
                    if(word1[i]!=word2[j]){
                        return(0);
                    }
                }
                else if (flag == 1){
                    return(0);
                }
            }
            j++ ;
        }
        return(1) ;
    }

    static bool comp(string &s1 , string &s2){
        return(s1.size()<s2.size());
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        for (auto it : words){
            cout << it << " " ;
        }
        if (words.size()==1){
            return(1);
        }
        int n = words.size() ;
        vector<int> dp(n,1) ;
        int maxi = -1 ;
        for (int i = 1 ; i<n; i++){
            for (int index=i-1 ; index>=0 ; index--){
                if (words[i].length()==(words[index].length()+1) && dp[i]<(dp[index]+1)){
                    if (checker(words[index],words[i])){
                        dp[i] = (dp[index]+1);
                    }
                }
            }
            if (dp[i]>maxi){
                maxi = dp[i] ;
            }
        }
        return(maxi) ;
    }
};