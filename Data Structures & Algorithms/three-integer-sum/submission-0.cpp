class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> vec = nums;

        sort(vec.begin(), vec.end());

        vector<vector<int>> ans;

        for(int i = 0; i < vec.size(); i++){

            if(i > 0 && vec[i] == vec[i-1])
                continue;

            if(vec[i] > 0){
                break;
            }

            vector<pair<int, int>> res = 
                twoSum(vec, i+1, vec.size() - 1, -vec[i]);

            for(auto it: res){
                ans.push_back({vec[i], it.first, it.second});
            }
        }

        return ans;
    }

    vector<pair<int, int>> twoSum(vector<int>& vec, int start, int end, int target){

        vector<pair<int,int>> res;

        while(start < end){
            int curr = vec[start] + vec[end];

            if(curr < target){
                start++;
            }
            else if(curr > target){
                end--;
            }
            else{
                res.push_back({vec[start], vec[end]});

                int leftval = vec[start];
                int rightval = vec[end];
                
                while(start < end && vec[start] == leftval){
                    start++;
                }
                while(start < end && vec[end] == rightval){
                    end--;
                }
            }
        }

        return res;
    }
};
