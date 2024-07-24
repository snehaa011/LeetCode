bool cmp(pair<int,int> &a, pair<int, int> &b){
    return a.first<b.first;
}

class Solution {
public:
    vector<int> sortJumbled(vector<int>& m, vector<int>& nums) {
        vector<pair<int,int>> v;
        for (auto n:nums){
            int num=n, mpnum=0, mul=1;
            if (num==0) mpnum=m[0];
            while (num!=0){
                int d=num%10;
                mpnum+=m[d]* mul;
                mul*=10;
                num=num/10;
            }
            v.push_back({mpnum,n});
        }
        sort(v.begin(), v.end(), cmp);
        vector<int> res;
        for (auto &[mp,num]: v){
            res.push_back(num);
        }
        return res;
    }
};

//T(n) = O(nlogn + n*d)
//S(n) = O(3n)
