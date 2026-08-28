class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        vector<int> pre(size, 0);
        vector<int> post(size, 0);

        pre[0] = height[0];
        post[size - 1] = height[size - 1];

        for(int i = 1; i < size; i++){
            pre[i] = max(pre[i - 1], height[i - 1]);
            post[size - i - 1] = max(post[size - i], height[size - i]);
        }
        
        int water = 0;

        for(int i = 1; i < size; i++){
            if(pre[i] > height[i] && post[i] > height[i]){
                water += min(pre[i], post[i])  - height[i];
            }
        }

        return water;
    }
};
