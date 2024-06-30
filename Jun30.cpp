class Solution {
    class Graph{
        public:
        vector<int> parent;
        vector<int> rank;
        Graph(int n){
            parent.resize(n+1);
            rank.resize(n+1, 1);
            for (int i=0; i<=n; i++){
                parent[i]=i;
            }
        }
        int Find(int current) 
        { 
            if (parent[current] == current) 
                return current; 

            return parent[current] = Find(parent[current]); 
        } 
        bool Union(int u, int v) 
        { 
            u = Find(u); 
            v = Find(v); 

            if (u!=v){
                rank[u]<rank[v]? parent[u] = v : parent[v] = u; 
                rank[u]+= rank[u]==rank[v];
                return true;
            }
            return false;
        }  
    };
    
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        Graph alice(n);
        Graph bob(n);
        int aliceEdges=0, bobEdges=0, removedEdges=0;
        sort(edges.begin(), edges.end(),
          [](const std::vector<int>& a, const std::vector<int>& b) {
  return a[0] > b[0];
});
    
        for (int i=0; i<edges.size(); i++){
            if (edges[i][0]==3){
                if (alice.Union(edges[i][1], edges[i][2])){
                    bob.Union(edges[i][1], edges[i][2]);
                    aliceEdges++;
                    bobEdges++;
                }else{
                    removedEdges++;
                }
            }
            else if (edges[i][0]==2){
                if (bob.Union(edges[i][1], edges[i][2])){
                    bobEdges++;
                }else{
                    removedEdges++;
                }
            }
            else{
                if (alice.Union(edges[i][1], edges[i][2])){
                    aliceEdges++;
                }else{
                    removedEdges++;
                }
            }
        }
        return (aliceEdges==n-1 && bobEdges==n-1)? removedEdges: -1;
    }
};

//T(n) = O(nlogn)
//S(n) = O(n)
