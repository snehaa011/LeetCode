class Solution {
    stack<char> st;
    void calc(string &s, string temp, int &score, int &num){
        while (!st.empty()) st.pop();
        for (int i=0; i<s.length(); i++){
            if (s[i]==temp[1]){
                if (!st.empty() && st.top()==temp[0]){
                    score+=num;
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }else{
                st.push(s[i]);
            }
        }
        
    }
public:
    int maximumGain(string s, int x, int y) {
        int score=0;
        if (x>y){ 
            calc(s,"ab",score,x);
            s="";
            while (!st.empty()){
                s+=st.top();
                st.pop();
            }
            reverse(s.begin(), s.end());
            calc(s,"ba", score, y);
        }else{
            calc(s,"ba", score, y);
            s="";
            while (!st.empty()){
                s+=st.top();
                st.pop();
            }
            reverse(s.begin(), s.end());
            calc(s,"ab", score, x);
        }
        return score;
    }
};

//T(n) = O(n)
//S(n) = O(n)
