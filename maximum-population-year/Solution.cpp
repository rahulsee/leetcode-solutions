// https://leetcode.com/problems/maximum-population-year

class Solution {
public:
    
    int getIndex(int year){
        return year-1949;
    }
    
    int maximumPopulation(vector<vector<int>>& logs) {
        int arr[111];
        memset(arr, 0, sizeof(arr));
        for(int i=0;i<logs.size();i++){
            int start=getIndex(logs[i][0]);
            int end=getIndex(logs[i][1]);
            arr[start]++;
            arr[end]--;
        }
        for(int i=1;i<111;i++)
            arr[i]+=arr[i-1];
        int max=0;
        int maxindex=0;
        for(int i=0;i<111;i++){
            if(arr[i]>max){
                max=arr[i];
                maxindex=i;
            }
        }
        return maxindex+1949;
    }
};