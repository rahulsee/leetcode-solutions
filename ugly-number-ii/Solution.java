// https://leetcode.com/problems/ugly-number-ii

class Solution {
    public int nthUglyNumber(int n) {
        int c2=0;
        int c3=0;
        int c5=0;
        ArrayList<Integer>dp=new ArrayList<Integer>(n+1);
        dp.add(1);
        for(int i=1;i<n;i++)
        {
            int a=dp.get(c2)*2;
            int b=dp.get(c3)*3;
            int c=dp.get(c5)*5;
            int mini=Math.min(a,Math.min(b,c));
            if(mini==a)
                c2++;
            if(mini==b)
                c3++;
            if(mini==c)
                c5++;
            dp.add(mini);
        }
        return dp.get(n-1);
        
    }
}