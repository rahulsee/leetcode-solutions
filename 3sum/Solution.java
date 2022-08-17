// https://leetcode.com/problems/3sum

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        HashSet<List<Integer > >hashSet=new HashSet<List<Integer> > ();
        List<List<Integer> >answer=new ArrayList<List<Integer> >();
        for(int i=0;i<nums.length-2;i++){
            int low=i+1;
            int high=nums.length-1;
            while(low<high){
                if(nums[low]+nums[high]+nums[i]<0){
                    low++;
                }
                else if(nums[low]+nums[high]+nums[i]>0)
                {
                    high--;
                }
                else{
                    List<Integer>triplet=new ArrayList<Integer>();
                    triplet.add(nums[i]);
                    triplet.add(nums[low]);
                    triplet.add(nums[high]);
                    hashSet.add(triplet);
                    low++;
                    high--;
                }
            }
        }
        for(List<Integer>triplet : hashSet){
            answer.add(triplet);
        }
        return answer;
    }
}