class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0 ;
        int right_slice = 0 ;
        while(s[s.length()-right_slice-1]==' '){
            right_slice += 1;
        }

        for(int i = 0 ; i < s.length()-right_slice ; i++){
            if(s[i]==' '){
                count = 0 ;
            }
            else{
                count += 1 ;
            }
        }
        return(count);
    }
};