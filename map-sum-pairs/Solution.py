// https://leetcode.com/problems/map-sum-pairs

class Trie:
    def __init__(self, eos):
        self.count=0
        self.children=dict()
        self.eos=True
        self.val=0

    def add_child(self, ch):
        self.children[ch]=Trie(eos=True)
            
class MapSum:
    def __init__(self):
        self.trie=Trie(eos=True)
    
    def find(self, key):
        x=self.trie
        for ch in key:
            if ch in x.children:
                x=x.children[ch]
            else:
                x.eos=False
                x.children[ch]=Trie(eos=True)
                x=x.children[ch]
        return x.eos, x.val

    def insert(self, key: str, val: int) -> None:
        res, key_val=self.find(key)
        print(f"Found {key}? res={res} count={key_val}")
        x=self.trie
        for ch in key:
            if ch in x.children:
                x=x.children[ch]
            else:
                x.eos=False
                x.children[ch]=Trie(eos=True)
                x=x.children[ch]
            if res==True:
                x.count=x.count-key_val+val
            else:
                x.count=x.count+val
        x.eos=True
        x.val=val
        print(f"Count now is {x.count}")

    def sum(self, prefix: str) -> int:
        x=self.trie
        ans=0
        for ch in prefix:
            if ch in x.children:
                x=x.children[ch]
                print(x.count)
                ans=x.count
            else:
                return 0
        return ans


# Your MapSum object will be instantiated and called as such:
# obj = MapSum()
# obj.insert(key,val)
# param_2 = obj.sum(prefix)