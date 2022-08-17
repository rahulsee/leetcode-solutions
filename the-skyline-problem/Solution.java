// https://leetcode.com/problems/the-skyline-problem

class Solution {
    
    static class Edge implements Comparable<Edge>{
        int pos;
        int height;
        boolean isLeft;
        
        Edge(int p, int h, boolean isL){
            pos=p;
            height=h;
            isLeft=isL;
        }
        
        public int compareTo(Edge that){
            if(this.pos != that.pos)
                return this.pos - that.pos;
            if(this.isLeft && that.isLeft)
                return that.height-this.height;
            else if(!this.isLeft && !that.isLeft)
                return this.height-that.height;
            else {
                if(this.isLeft)
                    return -1;
                return 1;
            }
        }
        
        public String toString(){
            return pos+" "+height+" "+isLeft;
        }
        
    }
    
    public List<List<Integer>> getSkyline(int[][] buildings) {
        List<Edge>edges=new ArrayList<>();
        for(int i=0;i<buildings.length;i++){
            edges.add(new Edge(buildings[i][0], buildings[i][2], true));
            edges.add(new Edge(buildings[i][1], buildings[i][2], false));
        }
        Collections.sort(edges);
        TreeMap<Integer, Integer> map=new TreeMap<>();
        map.put(0,1);
        int prevMax=0;
        List<List<Integer>>skyline=new ArrayList<>();
        for(Edge e: edges){
            // System.out.println(e);
            if(e.isLeft){
                map.compute(e.height, (key,value)->{
                    if(value==null)
                        return 1;
                    return value+1;
                });
            }
            else {
                map.compute(e.height, (key, value)->{
                    if(value==1)
                        return null;
                    return value-1;
                });
            }
            int curMax=map.lastKey();
            if(curMax != prevMax){
                skyline.add(List.of(e.pos, curMax));
                prevMax=curMax;
            }
        }
        return skyline;
    }
}