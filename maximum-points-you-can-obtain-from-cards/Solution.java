// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards

class Solution {
    public int maxScore(int[] cardPoints, int k) {
        int ans=Integer.MAX_VALUE;
        int n=cardPoints.length;
        int w=n-k;
        int sum=0;
        
        for(int i=0;i<w;i++)
            sum+=cardPoints[i];
        
        // System.out.println(sum);
        
        int total=0;
        
        for(int i=0;i<n;i++)
            total+=cardPoints[i];
        
        ans=Math.min(ans,sum);
        
        for(int i=w;i<n;i++)
        {
            sum=sum-cardPoints[i-w]+cardPoints[i];
            // System.out.println(sum);
            ans=Math.min(ans,sum);
        }
        
        return total-ans;
        
    }
}