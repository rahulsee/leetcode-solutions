// https://leetcode.com/problems/design-skiplist

class Node:
    def __init__(self, val):
        self.val=val
        self.right=None
        self.left=None
        self.down=None
    
class Skiplist:

    def __init__(self):
        self.skiplist=[]
        for i in range(16):
            s1=Node(-1)
            s2=Node(20007)
            s1.right=s2
            s2.left=s1
            self.skiplist.append(s1);
        for i in range(0,15):
            self.skiplist[i].down=self.skiplist[i+1]
            self.skiplist[i].right.down=self.skiplist[i+1].right

    def search(self, target: int) -> bool:
        start_node=self.skiplist[0]
        while start_node is not None:
            if start_node.right.val < target:
                start_node=start_node.right
            elif start_node.right.val > target:
                start_node=start_node.down
            else:
                return True
        return False
                

    def add(self, num: int) -> None:
        start_node=self.skiplist[0]
        prev_pointer_list=[]
        while start_node is not None:
            if start_node.right.val < num:
                start_node=start_node.right
            else:
                prev_pointer_list.append(start_node)
                start_node=start_node.down
        
        l=len(prev_pointer_list)
        prev_y=None
        for i in range(l-1, -1, -1):
            x=prev_pointer_list[i]
            z=x.right
            y=Node(num)
            y.left=x
            y.right=z
            x.right=y
            y.down=prev_y
            z.left=y
            prev_y=y
            toss=random.randint(0,2)
            if toss==0:
                break
        
        
    def erase(self, num: int) -> bool:
        start_node=self.skiplist[0]
        pointer_list=[]
        while start_node is not None:
            if start_node.right.val < num:
                start_node=start_node.right
            else:
                if start_node.right.val == num:
                    pointer_list.append(start_node.right)
                start_node=start_node.down

        l=len(pointer_list)
        for i in range(l-1, -1, -1):
            x=pointer_list[i]
            p=x.left
            n=x.right
            p.right=n
            n.left=p
        
        return len(pointer_list)>0

# Your Skiplist object will be instantiated and called as such:
# obj = Skiplist()
# param_1 = obj.search(target)
# obj.add(num)
# param_3 = obj.erase(num)