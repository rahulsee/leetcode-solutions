// https://leetcode.com/problems/find-and-replace-pattern

class Solution:
    
    def process_string(self,word):
        mapper={}
        count=0
        for ch in word:
            if ch not in mapper.keys():
                count+=1
                mapper[ch]=str(count)
        return str(list(map(lambda x: mapper[x], word)))
    
    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        patterns=defaultdict(lambda: [])
        for word in words:
            pat = self.process_string(word)
            # print(pat)
            patterns[pat].append(word)
        
        pattern=self.process_string(pattern)
        # print(pattern)
        return patterns[pattern]
        