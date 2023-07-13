class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int xd = coordinates[1][0]-coordinates[0][0];
        int yd = coordinates[1][1]-coordinates[0][1];
        int interceptD = coordinates[0][1]*xd - yd*coordinates[0][0];
        for(auto& c: coordinates) {
            if (xd*c[1] != yd*c[0] + interceptD)
                return false;
        }

        return true;
    }
};