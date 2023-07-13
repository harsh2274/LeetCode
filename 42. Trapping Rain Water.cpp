class Solution {
public:
    int trap(vector<int>& height) {
        int maxi_left = 0 ;
        int maxi_right = 0 ; 
        vector<int> m_left ;
        vector<int> m_right(height.size()) ;
        int n = height.size() ;
        for (int i = 0 ; i< height.size() ; i++)
        {   
            if (height[i]>maxi_left){
                maxi_left = height[i] ;
            }
            if (height[n-i-1]>maxi_right){
                maxi_right = height[n-i-1] ;
            }
            m_left.push_back(maxi_left) ;
            m_right[n-i-1] = maxi_right ;
        }

        int sumi = 0 ;
        for (int i = 0 ; i<height.size() ; i++ ){
            sumi = sumi  + ((min(m_left[i],m_right[i])) - height[i]) ;
            cout << (min(m_left[i],m_right[i])) - height[i] << "  " ;
        }
        return(sumi) ;
    }
};