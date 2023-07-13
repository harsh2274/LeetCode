class Solution {
public:
    string countAndSay(int n) {
        
        string temp = "1";
        for(int j = 0 ; j<n-1 ; j++) {
            char t = temp[0];
            int count = 0 ;
            string temp2 = "" ;
            for(int i=0 ; i<temp.length() ; i++){
                if (t==temp[i]){
                    count = count+1 ;
                    continue;
                }
                temp2 = temp2 + to_string(count) + t ;
                t=temp[i];
                count = 1 ;
            }
            temp = temp2 + to_string(count) + t ;
        }
        return(temp) ;
    }
};