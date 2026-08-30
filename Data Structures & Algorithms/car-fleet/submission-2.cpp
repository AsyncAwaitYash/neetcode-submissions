class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        map<int, double, greater<int>> posWiseTime;

        for(int i = 0; i< pos.size(); i++){
            double cnt = (double)(target - pos[i]) / speed[i];
            posWiseTime[pos[i]] = cnt;
        }

        int fleets = 0;
        double previousVal = -1;
        for(auto [key, val]: posWiseTime){
            // same fleet case
            if(val > previousVal){
                fleets++;
                previousVal = val;  
            }

        }

        return fleets;
    }
};
