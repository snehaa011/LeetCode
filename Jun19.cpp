class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (bloomDay.size()<(long)m*k) return -1;
        int r=*max_element(bloomDay.begin(), bloomDay.end());
        int l=1;
        while (l<r){
            int mid=(l+r)/2;
            int count=0, bm=m;
            for (int i=0; i<bloomDay.size(); i++){
                if (bloomDay[i]<=mid) count++;
                else count=0;
                if (count==k){
                    bm--;
                    count=0;
                }
            }
            if (bm<=0) r=mid;
            else l=mid+1;
        }
        return l;
    }
};

//T(n) = O(nlogn)
//S(n) = O(1)
