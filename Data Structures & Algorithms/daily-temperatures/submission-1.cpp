class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> ans(temp.size());
        stack<int> st;

        for(int r = temp.size()-1; r >= 0; r--){ 
            while(!st.empty() && temp[st.top()] <= temp[r]){
                st.pop();
            }

            if(st.empty()){
                ans[r] = 0;
            }
            else{
                ans[r] = st.top() - r;
            }

            st.push(r);
        }

        return ans;
    }
};
