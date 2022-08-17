// https://leetcode.com/problems/text-justification

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<vector<string> >sentences;
        vector<string>sent;
        int tot=0;
        int cur=0;
        vector<int>totals;
        for(int i=0;i<words.size();i++){
            if(tot + words[i].length() + sent.size() <= maxWidth){
                sent.push_back(words[i]);
                tot+=words[i].length();
            }
            else {
                sentences.push_back(sent);
                totals.push_back(tot);
                sent.clear();
                sent.push_back(words[i]);
                tot=words[i].length();
            }
        }
           
        sentences.push_back(sent);
        totals.push_back(tot);

    
        
        for(int i=0;i<sentences.size();i++){
        
           if(i==sentences.size()-1){
               for(int j=0;j<sentences[i].size()-1;j++)
               {
                   sentences[i][j]+=" ";
                   totals[i]++;
               }
                while(totals[i] < maxWidth){
                    sentences[i][sentences[i].size()-1]+=" ";
                    totals[i]++;
                }
           }
           
           else {
               if(sentences[i].size()==1){
                   while(totals[i] < maxWidth){
                       sentences[i][0]+=" ";
                       totals[i]++;
                   }
               }
               else{
                   int slots=sentences[i].size()-1;
                   int minSpaces=(maxWidth-totals[i])/slots;
                   int remSpaces=(maxWidth-totals[i])%slots;
                   string sp;
                   for(int j=0;j<minSpaces;j++)
                       sp.push_back(' ');
                   for(int j=0;j<slots;j++)
                   {
                       sentences[i][j]+=sp;
                   }
                   for(int j=0;j<remSpaces;j++){
                       sentences[i][j]+=" ";
                   }
               }
               
           }
          
        }
                
        vector<string>answer;
        for(int i=0;i<sentences.size();i++){
            string tmp="";
            for(int j=0;j<sentences[i].size();j++){
                tmp+=sentences[i][j];
            }
            answer.push_back(tmp);
        }
        return answer;
    }
};