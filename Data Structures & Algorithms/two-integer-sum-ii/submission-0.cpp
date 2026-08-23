class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        int left = 0;
        int right = size - 1;

        while(left < right){
            if(nums[left] + nums[right] < target){
                left++;
            }
            else if(nums[left] + nums[right] > target){
                right--;
            }
            else{
                return {left + 1, right + 1};
            }
        }

        return {-1, -1};
    }
};
