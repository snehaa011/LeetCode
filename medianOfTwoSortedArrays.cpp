//BRUTE FORCE
class Solution {
public:
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector <int> merged(nums1.size() + nums2.size());
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), merged.begin());
        int mid=merged.size()/2;
        if (merged.size()%2==0)
        {
            return ((merged[mid-1]+merged[mid])/2.0);
        }
        return merged[mid];
    }
};

//T(n) = O((n+m)log(n+m))
//S(n) = O(n+m)

//2-POINTERS
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size(), i=0, j=0, m1=0, m2=0;
        for(int count=0; count<=(n+m)/2; count++){
            m2=m1;
            if (i!=n && j!=m){
                if (nums1[i]>nums2[j]){
                    m1=nums2[j++];
                }else{
                    m1=nums1[i++];
                }
            }
            else if (i<n){
                m1=nums1[i++];
            }
            else{
                m1=nums2[j++];
            }
        }
        if ((n+m)%2==0) return (m1+m2)/2.0;
        return m1;
    }
};

//T(n) = O(n+m)
//S(n)=O(1)

//BINARY SEARCH
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size();
        if (n1>n2){
            return findMedianSortedArrays(nums2,nums1);
        }
        int n=n1+n2;
        int left=(n1+n2+1)/2;
        int low=0, high=n1;

        while (low<=high){
            int mid1=(low+high)/2;
            int mid2=left-mid1;

            int l1=INT_MIN , l2=INT_MIN, r2=INT_MAX, r1=INT_MAX;

            if (mid1<n1){
                r1=nums1[mid1];
            }
            if (mid2<n2){
                r2=nums2[mid2];
            }
            if (mid1-1>=0){
                l1=nums1[mid1-1];
            }
            if (mid2-1>=0){
                l2=nums2[mid2-1];
            }

            if (l1<=r2 && l2<=r1){
                if (n%2==1) return max(l1,l2);
                else return ((max(l1,l2)+min(r1,r2))/2.0);
            }
            else if (l1>r2){
                high=mid1-1; //consider lesser elements from nums1;
            }else{
                low=mid1+1; //consider more elements from nums1;
            }
        }
        return 0;
    }
};

//T(n) = O(log(n+m))
//S(n) = O(1)

