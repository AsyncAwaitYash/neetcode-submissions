class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        unordered_map<char, char> closeToOpen = {
            {'}', '{'},
            {']', '['},
            {')', '('}
        };

        for(char c: s){
            if(closeToOpen.contains(c)){
                if(!st.empty() && closeToOpen[c] == st.top()){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else{
                st.push(c);
            }            
        }

        return st.empty();
    }
};
