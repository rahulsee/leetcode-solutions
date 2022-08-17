// https://leetcode.com/problems/kth-missing-positive-number

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int>vec;
        vec.push_back(0);
        for(int num: arr)
            vec.push_back(num);
        vec.push_back(5007);
        int sum=0;
        int prev=vec[0];
        for(int i=1;i<vec.size();i++)
        {
            prev=sum;
            int diff=vec[i]-vec[i-1]-1;
            sum+=diff;
            // cout<<diff<<endl;
            if(sum >= k)
            {
                int offset=k-prev;
                int prev_num = vec[i-1];
                return prev_num+offset;
            }
        }
        return -1;
    }
};