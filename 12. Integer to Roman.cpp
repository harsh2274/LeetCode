class Solution {
public:
    string intToRoman(int num) {
        map<int,string> mymap = {{1,"I"},{4,"IV"},{5,"V"},{9,"IX"},{10,"X"},{40,"XL"},{50,"L"},{90,"XC"},{100,"C"},{400,"CD"},{500,"D"},{900,"CM"},{1000,"M"}};

    vector <int> vec = {1,4,5,9,10,40,50,90,100,400,500,900,1000,4000} ;
    string stri = "" ;
    int k = 0 ;
    int temp = num ;
    int cross = 0 ;
    
    while(true) {
        for (int i =0 ; i<vec.size() ; i++){
            if (temp < vec[i]) {
                cross = vec[i-1] ;
                int r  = temp / cross ;
                for (int p = 0 ; p<r ; p++) {
                    stri = stri + mymap.at(cross) ; 
                }
                cout << temp << endl ;
                temp = temp - r * cross ;
                break ;
            }
        }
        if (temp == 0){
            break ;
        }
    }
    return(stri) ;
    }
};