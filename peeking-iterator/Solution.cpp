// https://leetcode.com/problems/peeking-iterator

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
    int head;
    vector<int>arr;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        head=0;
	    arr=nums;
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(head==arr.size()){
            return -1;
        }
        return arr[head];
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
         if(head==arr.size()){
            return -1;
        }
        int tmp=head;
        head++;
        return arr[tmp];
	}
	
	bool hasNext() const {
	    return head<arr.size();
	}
};