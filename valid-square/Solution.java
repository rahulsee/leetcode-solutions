// https://leetcode.com/problems/valid-square

class Solution {
    
    public int distance(int []a, int []b){
        return (int)Math.pow(a[0]-b[0],2)+(int)Math.pow(a[1]-b[1],2);
    }
    
    
    public boolean validSquare(int[] p1, int[] p2, int[] p3, int[] p4) {
        int [][]points=new int[][]{p1,p2,p3,p4};
        int dist[]=new int[6];
        int cur=0;
        for(int i=0;i<4;i++){
            for(int j=i+1;j<4;j++){
                dist[cur++]=distance(points[i],points[j]);
            }
        }
        Arrays.sort(dist);
        boolean cond1=(dist[0]==dist[1] && dist[1]==dist[2] && dist[2]==dist[3]);
        boolean cond2=(dist[4]==dist[5]);
        boolean cond3=(dist[0] < dist[4] && dist[0]*2==dist[4]);
        return cond1 && cond2 && cond3;
    }
}