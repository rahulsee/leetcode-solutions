// https://leetcode.com/problems/find-duplicate-file-in-system

class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        ans_dict=dict()
        for p in paths:
            dir_path, *fnames = p.split(" ")
            for f in fnames:
                name, content=tuple(f.split("("))
                content = content[:-1]
                if content in ans_dict.keys():
                    ans_dict[content].append(f"{dir_path}/{name}")
                else:
                    ans_dict[content]=[f"{dir_path}/{name}"]
        ans_list=[v for (k,v) in ans_dict.items() if len(v)>1]
        return ans_list
            
        