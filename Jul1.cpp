class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int num=0, l=0, r=0;
        while (r<arr.size()){
            if (arr[r]%2){
                r++;
                num++;
            }else{
                r++;
                l=r;
                num=0;
            }
            if (num>=3) return true;
        }
        return num>=3;
    }
};
