// https://leetcode.com/problems/minimum-height-trees

class Solution {
    
    public boolean []visited;
    public int[] parent;
    public int leaf;
    int n;
    int d;
    public Map<Integer, List<Integer> >g;
    
    public void DFS(int cur, int depth){
        visited[cur]=true;
        boolean flag=true;
        for(int v: g.get(cur)){
            if(!visited[v]){
                DFS(v,depth+1);
                flag=false;
                parent[v]=cur;
            }
        }
        if(flag && depth > d){
            leaf=cur;
            d=depth;
        }
    }
    
    public void clear(){
        parent=new int[n];
        for(int i=0;i<n;i++)
            parent[i]=-1;
        visited=new boolean[n];
        d=0;
    }
    
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        if(n==0)
            return List.of();
        if(n==1)
            return List.of(0);
        g=new HashMap<>();
        this.n=n;
        leaf=-1;
        for(int i=0;i<edges.length;i++){
            List<Integer>children=g.get(edges[i][0]);
            if(children==null)
                children=new ArrayList<>();
            children.add(edges[i][1]);
            g.put(edges[i][0],children);
            children=g.get(edges[i][1]);
            if(children==null)
                children=new ArrayList<>();
            children.add(edges[i][0]);
            g.put(edges[i][1],children);
        }
    
        clear();     
        DFS(edges[0][0],d);
        int A=leaf;
        clear();
        DFS(leaf,d);
        int B=leaf;
        List<Integer>path=new ArrayList<>();
        while(B!=A){
            path.add(B);
            B=parent[B];
        }
        path.add(A);
        int len=path.size();
        if(len % 2==0){
            return List.of(path.get(len/2),path.get(len/2-1));
        }
        else {
            return List.of(path.get(len/2));
        }
    }
}