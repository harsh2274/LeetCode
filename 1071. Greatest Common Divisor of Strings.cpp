class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string str3 = str1 + str2 ;
        string str4 = str2 + str1 ;
        if (str3!=str4){
            return ("") ;
        }
        
        int k = gcd(str1.length(),str2.length());
        string temp = str3.substr(0, k);
        return(temp) ;
    }
    int gcd(int n1 , int n2){
        if (n2==0){
            return n1 ;
        }
        return gcd(n2,n1%n2);
    }
};