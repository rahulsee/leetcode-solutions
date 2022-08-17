// https://leetcode.com/problems/validate-binary-tree-nodes

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        bool flag[n];
        memset(flag, 0, sizeof(flag));
        for(int num: leftChild)
            if(num>=0) flag[num]=true;
        for(int num: rightChild)
            if(num>=0) flag[num]=true;
        int nl=0;
        for(int i=0;i<n;i++)
            nl+=!(flag[i]);
        if(nl>1)
            return false;
        queue<int>q;
        q.push(0);
        bool visited[n];
        memset(visited, 0, sizeof(visited));
        visited[0]=true;
        while(!q.empty())
        {
            int cur=q.front();
            int left=leftChild[cur];
            int right=rightChild[cur];
            q.pop();
            if(left>=0 && !visited[left])
            {
                q.push(left);
                visited[left]=true;
            }
            else if(left>=0 && visited[left])
                return false;
            
            if(right>=0 && !visited[right])
            {
                q.push(right);
                visited[right]=true;
            }
            else if(right>=0 && visited[right])
                return false;
            
        }
        return true;
    }
};