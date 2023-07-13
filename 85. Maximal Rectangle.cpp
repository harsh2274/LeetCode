class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> ps ;
        int maxi = 0 ;
        int n = heights.size() ;
        for(int i =0 ; i<=n ; i++){
            while(!ps.empty() && (i==n || heights[ps.top()]>=heights[i])){
                int top_ele = heights[ps.top()];
                ps.pop();
                if (ps.empty()){
                    maxi = max(maxi,i*top_ele);
                }
                else{
                    maxi = max(maxi,(i-ps.top()-1)*top_ele);
                }
            }
            ps.push(i);
        }
        return(maxi) ;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size() ;
        int m = matrix[0].size() ;
        int maxi = 0 ;
        vector<int> vec(m,0);
        for (int i = 0 ; i<n ; i++){
            for (int j = 0 ; j<m ; j++){
                if(matrix[i][j]=='0'){
                    vec[j]=0 ;
                }
                else{
                    vec[j] += 1 ;
                }
            }
            maxi = max(largestRectangleArea(vec),maxi);
        }    
        return(maxi) ;
    }
};