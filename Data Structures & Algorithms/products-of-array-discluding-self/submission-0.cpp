class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> pre (size, 1);
        vector<int> post (size, 1);
        vector<int> ans (size, 1);


        pre[0] = nums[0];
        post[size-1] = nums[size-1];

        for(int i=1;i<size;i++){
            pre[i] = pre[i - 1] * nums[i];
            post[size - i - 1] =  post[size - i] * nums[size - i - 1];
        }

        for (int i=0; i<size;i++){
            if(i == 0){
                ans[i] = post[i+1];  
            }
            else if(i == size - 1){
                ans[i] = pre[i-1];
            }
            else{
                ans[i] = pre[i-1] * post[i+1];
            }
        }

        return ans;

    }
};
