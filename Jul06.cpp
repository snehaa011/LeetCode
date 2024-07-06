class Solution {
public:
    int passThePillow(int n, int time) {
        int dir=0, i=1;
        while (time--){
            if (!dir) i++;
            if (dir) i--;
            if (i==n || i==1) dir=!dir;
        }
        return i;
    }
};

//T(n) = O(n)
//S(n) = O(1)
