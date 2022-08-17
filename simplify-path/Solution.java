// https://leetcode.com/problems/simplify-path

class Solution {
    public String simplifyPath(String path) {
        StringBuilder sb=new StringBuilder();
        String []vec=path.split("\\/");
        Deque<String>queue=new LinkedList<>();
        for(int i=0;i<vec.length;i++){
            if(vec[i].strip().equals("") || vec[i].equals(".")){
                continue;
            }
            else if(vec[i].equals("..")){
                if(!queue.isEmpty()){
                    queue.removeLast();
                }
            }
            else {
                queue.addLast(vec[i]);
            }
        }
        while(!queue.isEmpty()){
            sb.append("/");
            sb.append(queue.removeFirst());
        }
        if(sb.length()==0){
            if(path.length()!=0)
                sb.append("/");
        }
        return sb.toString();
    }
}