// https://leetcode.com/problems/three-equal-parts

class Solution {
public:
    
    bool check(vector<int>arr, int x, int y, string ref, int &index){
        string str;
        while(x<=y && arr[x]==0)
            x++;
        
         while((y-x+1)>ref.length() && arr[y]==0){
            y--;
         }
        index=y;
        
        while(x<=y){
            str.push_back(arr[x]+'0');
            x++;
        }
        return ref==str;
    }
    
    vector<int> threeEqualParts(vector<int>& arr) {
        int left=0;
        int right=arr.size()-1;
        int n=arr.size();
        int zc=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0)
            zc++;
        }
        if(zc==n){
            vector<int>ans;
            ans.push_back(0);
            ans.push_back(n-1);
            return ans;
        }
        while(left < right && arr[left]==0)
            left++;
        string ls="";
        string rs="";
        while(left<=right){
            ls.push_back(arr[left]+'0');
            rs=string(1,arr[right]+'0')+rs;
            if(ls==rs){
                int index=-1;
                if(check(arr,left+1, right-1, ls, index)){
                    vector<int>ans;
                    ans.push_back(left);
                    ans.push_back(index+1);
                    return ans;
                }
            }
            left++;
            right--;
        }
        vector<int>ans(2,-1);
        return ans;
    }
};