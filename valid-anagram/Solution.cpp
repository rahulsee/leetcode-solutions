// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[26];
        int arr2[26];
        memset(arr, 0, sizeof(arr));
        memset(arr2, 0, sizeof(arr));
        for(char c: s)
            arr[c-'a']++;
        for(char c: t)
            arr2[c-'a']++;
        for(int i=0;i<26;i++) {
            if(arr[i]!=arr2[i])
                return false;
        }
        return true;
    }
};