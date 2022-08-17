// https://leetcode.com/problems/course-schedule-ii

class Solution {
    
    Stack<Integer>stack;
    boolean []visited;
    int color[];
    boolean cycle=false;
    public void topologicalSort(int cur,int [][]prereq){
        if(visited[cur]==true)
            return;
        visited[cur]=true;
        for(int i=0;i<prereq.length;i++){
            if(prereq[i][1]==cur){
                topologicalSort(prereq[i][0],prereq);
            }
        }
        stack.add(cur);
    }
    
    public boolean cycleExists(int cur,int [][]prereq){
        color[cur]=1;
        for(int i=0;i<prereq.length;i++){
            if(prereq[i][1]==cur){
                if(color[prereq[i][0]]==1){
                    return true;
                }
                else if(color[prereq[i][0]]==2){
                    continue;
                }
                else{
                    if(cycleExists(prereq[i][0],prereq))
                        return true;
                }
            }
        }
        color[cur]=2;
        return false;
    }
    
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        stack=new Stack<Integer>();
        visited=new boolean[numCourses];
        int arr[]=new int[numCourses];
        int cur=0;
        color=new int[numCourses];
        
        for(int i=0;i<numCourses;i++)
        {
            if(cycleExists(i,prerequisites))
                return new int[0];
        }
        
        for(int i=0;i<numCourses;i++)
        topologicalSort(i,prerequisites);
        
        cur=0;
        while(!stack.isEmpty()){
            arr[cur++]=stack.pop();
        }
        
        if(cur!=numCourses)
            return new int[0];
        return arr;
    }
}