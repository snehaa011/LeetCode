class Solution {
    int count(vector<int> &nums, int goal){        //return number of subarrays with sum<=goal
        if (goal<0) return 0;
        int l=0,r=0, cnt=0, sum=0;
        while (r<nums.size()){
            sum+=nums[r]%2;
            while (sum>goal){       //while sum>goal, add left pointer till u find 1 and subtract it
                sum-=nums[l]%2;
                l++;
            }
            cnt+=r-l+1;         //length of subarray is the number of subarrays with sum<=goal for nums[l..r]   
            r++;
        }
        return cnt;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return (count(nums,k)-count(nums,k-1));
    }
};

//T(n) = O(2n)
//S(n) = O(1)
