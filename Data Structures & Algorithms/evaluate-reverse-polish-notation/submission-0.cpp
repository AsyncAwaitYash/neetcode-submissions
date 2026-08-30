class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string c : tokens) {

            if (c == "/" || c == "*" || c == "+" || c == "-") {

                int num2 = st.top();
                st.pop();

                int num1 = st.top();
                st.pop();

                if (c == "/")
                    st.push(num1 / num2);
                else if (c == "*")
                    st.push(num1 * num2);
                else if (c == "+")
                    st.push(num1 + num2);
                else
                    st.push(num1 - num2);

            } else {
                st.push(stoi(c));
            }
        }

        return st.top();
    }
};