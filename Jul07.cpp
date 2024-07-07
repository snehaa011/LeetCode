class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int sum=0, todrink=numBottles, empty=0;
        while (todrink){
            sum+=todrink;
            todrink=numBottles/numExchange;
            empty=numBottles%numExchange;
            numBottles=todrink+empty;
        }
        return sum;
    }
};

//T(n) = O(n)
//S(n) = O(1)
