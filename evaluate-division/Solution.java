// https://leetcode.com/problems/evaluate-division

class Solution {
    
    HashMap<String,HashMap<String,Double> >graph;
    HashSet<String>visited;
    double answer;
        
    public void DFS(String start,String end,double value)
    {
        visited.add(start);
        
        if(graph.get(start)==null)
            return;
        
        if(start.equals(end))
        {
            answer=value;
            return;
        }
        HashMap<String, Double>h=graph.get(start);
        if(h==null)
            return;
        for(String e: h.keySet()){
            if(visited.contains(e)==false)
            {
                double v=h.get(e);
                DFS(e,end,value/v);
            }
        }
        
    }
    
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        
        
        // initialize graph
        graph=new HashMap<String,HashMap<String,Double> >();
        visited=new HashSet<String>();
        for(int i=0;i<equations.size();i++)
        {
           String a=equations.get(i).get(0);
            String b=equations.get(i).get(1);
            if(graph.get(a)==null)
                graph.put(a,new HashMap<String,Double>());
            if(graph.get(b)==null)
                graph.put(b,new HashMap<String,Double>());
            graph.get(a).put(b,values[i]);
            graph.get(b).put(a,1/values[i]);
        }
        
        double[] answers=new double[queries.size()];
        for(int i=0;i<queries.size();i++)
        {
            String start=queries.get(i).get(0);
            String end=queries.get(i).get(1);
            answer=(-1.0);
            
            DFS(start,end,1);
            visited.clear();
            answers[i]=1/answer;
            
        }
        return answers;
        
    }
}