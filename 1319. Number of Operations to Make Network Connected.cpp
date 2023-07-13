class DisjointSet {
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
    
    int check_unique_parents(){
        int count = 0 ;
        for (int i = 0 ; i<parent.size()-1 ; i++) {
            if(parent[i]==i){
                cout << parent[i] << "  " << i << endl ;
                count ++ ;
            }
        }
        return(count) ;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n) ;
        for (auto it : connections){
            ds.unionbysize(it[0],it[1]);
            ds.unionbysize(it[1],it[0]);
        }

        int N = ds.check_unique_parents()-1 ;
        
        if((connections.size())<n-1){
            return(-1) ;
        }
        
        return(N) ;
    }
};