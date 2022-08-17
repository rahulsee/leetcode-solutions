// https://leetcode.com/problems/word-ladder

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>ws(wordList.begin(), wordList.end());
        unordered_set<string>visited;
        queue<string>q;
        q.push(beginWord);
        visited.insert(beginWord);
        unordered_map<string,int>steps;
        steps[beginWord]=1;
        while(!q.empty()){
            string word=q.front();
            string parent=word;
            if(word==endWord)
                return steps[word];
            q.pop();
            int n=parent.length();
            for(int i=0;i<n;i++){
                char c=word[i];
                for(int j='a';j<='z';j++){
                    word[i]=j;
                    if(ws.find(word)!=ws.end() && visited.find(word)==visited.end()){
                        visited.insert(word);
                        steps[word]=steps[parent]+1;
                        q.push(word);
                    }
                }
                word[i]=c;
            }
        }
        return 0;
    }
};