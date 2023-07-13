/*class DisjointSet {
    vector<int> rank , parent , size ;
public :
    DisjointSet(int n){
        rank.resize(n+1,0) ;
        parent.resize(n+1) ;
        size.resize(n+1) ;
        for (int i = 0 ; i<n ; i++ ){
            parent[i] = i ;
            size[i] = 1 ;
        }
    }

    int findUPar(int node){
        if(node==parent[node]){
            return(node) ;
        }
        return parent[node] = findUPar(parent[node]) ;
    }

    void unionbyrank(int u, int v ){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u==ulp_v) return ;
        if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v] = ulp_u ;
        }
        else if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u] = ulp_v ;
        }
        else{
            parent[ulp_v] = ulp_u ;
            rank[ulp_u]++ ;
        }
    }

    void unionbysize(int u, int v ){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u==ulp_v) return ;
        if(size[ulp_u]>size[ulp_v]){
            parent[ulp_v] = ulp_u ;
            size[ulp_u] += size[ulp_v] ;
        }
        else{
            parent[ulp_u] = ulp_v ;
            size[ulp_v] += size[ulp_u] ;
        }
    }

    int findUPari(int i){
        return(parent[i]) ;
    }     

    unordered_map<int,int> parenti(){
        unordered_map<int,int> mapi;
        cout << "parent : " << endl  ; 
        int i = 0 ; 
        for (auto it : parent){
            cout << it << "  " ;
            if(i!=parent.size()-1){
                if(mapi.find(it)!=mapi.end()){
                    mapi[it] += 1 ; 
                }
                else{
                    mapi[it] = 1 ; 
                }
            }
            i++ ;
            if(i%5==0) {
                cout << endl; } 
        }
        cout << endl;
        for (auto it : mapi) {
            cout << it.first << ":" << it.second << "   " ;
        }
        cout << endl ; 
        return(mapi) ;
   
    }
};



class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int count_1 = 0 ;
        int n  = grid.size() ;
        DisjointSet ds(n*n) ;

        for (int i = 0 ; i < n ; i++ ) {
            for (int j = 0 ; j < n ; j++ ){
                if(grid[i][j]){
                    count_1 += 1 ;
                }
                if(i!=0){
                    if(grid[i][j]==1){
                        if(grid[i-1][j]==1){
                            ds.unionbysize(((i-1)*n)+j , (i*n)+j) ;
                        }
                    }
                }
                if(j!=0){
                    if(grid[i][j]==1){
                        if(grid[i][j-1]==1){
                            ds.unionbysize((i*n)+j-1 , (i*n)+j) ;
                        }
                    }
                }
            }
        }
        if(count_1==(n*n)){
            return(count_1) ;
        }

        unordered_map<int,int> parent1 = ds.parenti() ;

        int f_count = -999 ;
        for (int i = 0 ; i<n ; i++ ) {
            for (int j = 0 ; j < n ; j++ ){
                int count = 0 ;
                int father=-1,father2=-1,father3=-1 ;
                cout << "i : " << i << " j : " << j << endl ; 
                if (grid[i][j]==0){
                    if (i>0 && grid[i-1][j]) {
                        
                        father = ds.findUPari((i-1)*n + j);
                        //parent1 = ds.parenti() ;
                        count += parent1[father] ;
                        cout << "1: " << count << " father : " << father << endl ;
                    }
                    if (j>0 && grid[i][j-1]) {
                        int temp = ds.findUPari((i)*n + j-1);
                        cout <<"2l: "<< count << " father :  " << temp << endl ;
                        if (temp!=father){
                            //parent1 = ds.parenti() ;
                            count += parent1[temp] ;
                            father2 = temp ;
                            cout <<"2: "<< count << " father :  " << temp << endl ;
                        }
                    }

                    if (i<(n-1) && grid[i+1][j]) {
                        int temp = ds.findUPari((i+1)*n + j);
                        cout <<"3l: "<< count << " father :  " << ds.findUPar((i+1)*n + j) << "  " << (i+1)*n + j << endl ;
                        if (temp!=father && temp!=father2){
                            //parent1 = ds.parenti() ;
                            count += parent1[temp] ;
                            father3 = temp ;
                            cout <<"3: "<< count << " father :  " << temp << endl ;
                        }
                    }

                    if (j<(n-1) && grid[i][j+1]) {
                        int temp = ds.findUPari((i)*n + j+1);
                        cout <<"4l: "<< count << " father :  " << temp << endl ;
                        if (temp!=father && temp!=father2 && temp!=father3){
                            //parent1 = ds.parenti() ;
                            count += parent1[temp] ;
                            cout <<"4:"<< count << " father :  " << temp << endl ;
                        }
                    }
                }

                if(count>f_count){
                    f_count = count ;
                }
            }
        }

        if(f_count==0){
            return(1) ;
        }

        return(f_count+1) ;
    }
};*/


class DisjointSet {

public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
    private:
    bool isValid(int newr, int newc, int n) {
        return newr >= 0 && newr < n && newc >= 0 && newc < n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        // step - 1
        for (int row = 0; row < n ; row++) {
            for (int col = 0; col < n ; col++) {
                if (grid[row][col] == 0) continue;
                int dr[] = { -1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                for (int ind = 0; ind < 4; ind++) {
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];
                    if (isValid(newr, newc, n) && grid[newr][newc] == 1) {
                        int nodeNo = row * n + col;
                        int adjNodeNo = newr * n + newc;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }
        // step 2
        int mx = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) continue;
                int dr[] = { -1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                set<int> components;
                for (int ind = 0; ind < 4; ind++) {
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];
                    if (isValid(newr, newc, n)) {
                        if (grid[newr][newc] == 1) {
                            components.insert(ds.findUPar(newr * n + newc));
                        }
                    }
                }
                int sizeTotal = 0;
                for (auto it : components) {
                    sizeTotal += ds.size[it];
                }
                mx = max(mx, sizeTotal + 1);
            }
        }

        for (int cellNo = 0; cellNo < n * n; cellNo++) {
            mx = max(mx, ds.size[ds.findUPar(cellNo)]);
        }
        
        return mx;      
    }
};