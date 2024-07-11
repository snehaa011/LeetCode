class Solution {
public:
    string reverseParentheses(string s) {
       stack<char> st;
       for (int i=0; i<s.length(); i++){
        if (s[i]==')'){
            string temp="";
            while (!st.empty() && st.top()!='('){
                temp+=st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
            for (auto j:temp){
                st.push(j);
            }
        }
        else{
            st.push(s[i]);
        }
       }
       string res="";
       while (!st.empty()){
            res+=st.top();
            st.pop();
       } 
       reverse(res.begin(), res.end());
       return res;
    }
};

//T(n) = O(n)
//S(n) = O(n)
