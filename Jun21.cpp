class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        long long csat=0;
        for (int i=0; i<n; i++){
            if (!grumpy[i]) csat+=customers[i];
        }
        int i=0;
        long long msat=csat;
        while(i<minutes){
            if (grumpy[i]) csat+=customers[i];
            i++;
        }
        if (csat>msat) msat=csat;
        while(i<n){
            if (grumpy[i-minutes]) csat-=customers[i-minutes];
            if (grumpy[i]) csat+=customers[i];
            if (csat>msat) msat=csat;
            i++;
        }
        return msat;
    }
};

//T(n) = O(n)
//S(n) = O(1)
