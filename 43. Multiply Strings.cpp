class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> string1(num1.length()) ;
        vector<int> string2(num2.length()) ;
        vector<int> string3(num1.length()+num2.length()) ;
        int carry = 0 ;
        string s = "";
        for(int i = num2.length() -1 ; i>-1 ; i--) {
            carry = 0 ;
            for (int j = num1.length() -1 ; j>-1 ; j-- ) {
                int prod = (num1[j]-'0') * (num2[i]-'0') + carry ;
                int q =  prod%10 ;
                carry =  prod/10 ;
                char p = q + '0' ;
                s += p ;
            }
            cout << strrev(s) << endl ;
            if (carry!=0){
                cout<<carry;
            }
            cout << endl ;
            string1.push_back(num1[i]-48) ;
            //cout << num1[i] << " " ;
        }
        cout << endl ;
        for(int i = 0 ; i<num2.length() ; i++) {
            string2.push_back(num2[i]-48) ;
        }
        /*for(int i = 0 ; i<string1.size() ; i++) {
            cout << string1[i] << " " ;
        }
        cout << endl ;
        for(int i = 0 ; i<string2.size() ; i++) {
            cout << string2[i] << " " ;
        } */


        return("svcb") ;
    }
};