class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1 ;
        int n = digits.size() ;
        int i = 0 ;
        while(carry!=0 && (n-i-1)>-1 ){
            if (digits[n-i-1]==9){
                digits[n-i-1] = 0 ;
                carry = 1 ;
            }
            else{
                digits[n-i-1] += 1 ;
                carry = 0 ;
            }
            i++ ;
        }
        if(carry==1){
            digits.insert(digits.begin(), 1);
        }
        return(digits);
    }
};