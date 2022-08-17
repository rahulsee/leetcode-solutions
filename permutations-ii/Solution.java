// https://leetcode.com/problems/permutations-ii

class Solution {
    List<List<Integer> >perms;
    Map<Integer, Integer> counts;
    int n;
    public void permute(Map<Integer, Integer>nums, LinkedList<Integer>tmp){
        if(tmp.size()==n){
            ArrayList<Integer>ans=new ArrayList<>(tmp);
            perms.add(ans);
            return;
        }
        for(int a: nums.keySet()){
            if(nums.get(a)==0)
                continue;
            tmp.add(a);
            nums.put(a,nums.get(a)-1);
            permute(nums,tmp);
            tmp.removeLast();
            nums.put(a,nums.get(a)+1);
        }
    }
    
    public List<List<Integer>> permuteUnique(int[] nums) {
        perms=new ArrayList<>();   
        counts=new HashMap<>();
        n=nums.length;
        for(int num:nums){
            if(counts.get(num)!=null)
                counts.put(num,counts.get(num)+1);
            else
                counts.put(num,1);
        }
        permute(counts, new LinkedList<>());
        return perms;
    }
}