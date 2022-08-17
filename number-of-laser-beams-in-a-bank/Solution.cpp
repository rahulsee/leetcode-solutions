// https://leetcode.com/problems/number-of-laser-beams-in-a-bank

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<size_t>arr;
        for(string b: bank)
        {
            size_t oc=std::count(b.begin(), b.end(), '1');
            if(oc>0)
                arr.push_back(oc);
        }
        if(arr.size() == 1)
            return 0;
        size_t prod=0;
        for(int i=1;i<arr.size();i++)
        {
            prod+=(arr[i]*arr[i-1]);
        }
        return prod;
    }
};