class Solution {
    bool isboq(int d, int k, int m, vector<int> arr){
        int bm=0, count=0;
        for (int i=0; i<arr.size(); i++){
            if (arr[i]<=d) count++;
            else count=0;
            if (count==k){
                bm++;
                count=0;
            }
            if (bm>=m) return true;
        }
        return false;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (bloomDay.size()<(long)m*k) return -1;
        int r=*max_element(bloomDay.begin(), bloomDay.end());
        int l=1;
        while (l<r){
            int mid=(l+r)/2;
            if (isboq(mid, k, m, bloomDay)) r=mid;
            else l=mid+1;
        }
        return l;
    }
};
