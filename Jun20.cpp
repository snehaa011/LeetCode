//highest minimum magnetic force between m balls placed at any position given in position array
// we have to maximize the distance between the balls so we get max magnetic force (out of all mag forces between diff balls in that arrangement we have to choose minimum)

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int l=1, r=position[position.size()-1]-position[0];
        while (l<=r){
            int mid=l+((r-l)/2);
            int prev=position[0], count=1;
            for (int i=1; i<position.size(); i++){
                if (position[i]-prev>=mid){
                    prev=position[i];
                    count++;
                }
            }
            if (count>=m){       //if possible to place m balls at mid dist, check for higher dist as we want max dist
                l=mid+1;
            }else{
                r=mid-1;        //else, check for lower distances
            }
            
        }
        return r;
    }
};
