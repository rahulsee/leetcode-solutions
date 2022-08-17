// https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum

#define MAXN 50000
#define MAXN 50000
struct node {
	int suffix;
	int prefix;
	int count;
};

int n;
node t1[4*MAXN], t2[4*MAXN];
int a[MAXN];
int leftval, rightval;

int compute_pref(int l, int r, int ub){
	int cnt=0;
	for(int i=l;i<=r;i++){
		if(a[i]<=ub){
			cnt++;
			continue;
		}
		else
			break;
	}
	return cnt;
}


int compute_suff(int l, int r, int ub){
	int cnt=0;
	for(int i=r;i>=l;i--){
		if(a[i]<=ub){
			cnt++;
			continue;
		}
		else
			break;
	}
	return cnt;
}


void build(node t[], int v, int tl, int tr, int ub) {
    if (tl == tr) {
        t[v].suffix = (a[tl]<=ub);
        t[v].prefix = (a[tl]<=ub);
        t[v].count =  (a[tl]<=ub);
     } 
     else {
        int tm = (tl + tr) / 2;
        build(t, v*2+1, tl, tm, ub);
        build(t, v*2+2, tm+1, tr, ub);
        int x=t[v*2+1].suffix;
        int y=t[v*2+2].prefix;
        t[v].count=t[2*v+1].count+t[2*v+2].count + x*y;
        t[v].suffix=compute_suff(tl,tr,ub);
        t[v].prefix=compute_pref(tl,tr,ub);
    }
}


class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n=nums.size();
        for(int i=0;i<n;i++)
            a[i]=nums[i];
        leftval=left;
        rightval=right;
        build(t1, 0, 0, n-1, rightval);
        build(t2, 0, 0, n-1, leftval-1);
        return t1[0].count-t2[0].count;
    }
};