// https://leetcode.com/problems/prison-cells-after-n-days

class Solution {

    public ArrayList<Integer> apply(ArrayList<Integer>a){
        ArrayList<Integer>b=new ArrayList<Integer>();
        b.add(0);
        for(int i=1;i<7;i++){
            if(a.get(i-1)==a.get(i+1)){
                b.add(1);
            }
            else
                b.add(0);
        }
        b.add(0);
        return b;
    }
    
    public int[] prisonAfterNDays(int[] cells, int N) {
        HashMap<Integer,ArrayList<Integer>>map=new HashMap<Integer,ArrayList<Integer>>();
        ArrayList<Integer>c=new ArrayList<Integer>();
        for(int n:cells)
            c.add(n);
        for(int i=1;i<=14;i++){
            map.put(i,apply(c));
            c=apply(c);
        }
        if(N%14==0)
         N=14;
        else
            N=N%14;
        c=map.get(N);
        System.out.println(N);
        System.out.println(c);
        for(int i=0;i<8;i++){
            cells[i]=c.get(i);
        }
        return cells;
    }
}