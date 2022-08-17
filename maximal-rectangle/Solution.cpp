// https://leetcode.com/problems/maximal-rectangle

class Solution {
public:
        
    int largestHistogramArea(vector<int>rowsum)
    {
        int maxarea=0;
        vector<int>leftarea(rowsum);
        stack<int>s;
        s.push(-1);
        for(int i=0;i<rowsum.size();i++){
            while(s.top()>=0 && rowsum[s.top()] > rowsum[i])
            {
                leftarea[s.top()]=rowsum[s.top()]*(i-s.top());
                s.pop();
            }
            s.push(i);
        }
        int n=rowsum.size();
        while(s.top() >= 0){
            leftarea[s.top()]=rowsum[s.top()]*(n-s.top());
            s.pop();
        }
        
        vector<int>rightarea(rowsum);
        stack<int>s2;
        s2.push(-1);
        for(int i=n-1;i>=0;i--)
        {
            while(s2.top()>=0 && rowsum[i] < rowsum[s2.top()]){
                rightarea[s2.top()]=rowsum[s2.top()]*(s2.top()-i);
                s2.pop();
            }
            s2.push(i);
        }
        while(s2.top()>=0)
        {
            rightarea[s2.top()]=rowsum[s2.top()]*(s2.top()+1);
            s2.pop();
        }
        
        for(int i=0;i<n;i++)
            maxarea=max(maxarea,rightarea[i]+leftarea[i]-rowsum[i]);
        
        return maxarea;
    }
    
    void print(vector<int>A)
    {
        for(int i=0;i<A.size();i++)
            cout<<A[i]<<" ";
        cout<<endl;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        if(matrix.size()==0 || matrix[0].size()==0)
            return 0;
        
        
        vector<vector<int> >A(matrix.size());
        for(int i=0;i<matrix.size();i++)
        {
            vector<int>tmp(matrix[0].size(),0);
            A[i]=tmp;
        }
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(i==0)
                    A[i][j]=matrix[i][j]-'0';
                else
                {
                    if(matrix[i][j]=='0')
                        A[i][j]=0;
                    else
                        A[i][j]=A[i-1][j]+1;
                }
            }
        }
        
        int ans=0;
        
        for(int i=0;i<matrix.size();i++)
        {
            int tmp=largestHistogramArea(A[i]);
            ans=max(ans,tmp);
        }
        return ans;
       
    }
};