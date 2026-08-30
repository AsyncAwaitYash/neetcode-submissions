class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        vector<pair<int, double>> posWiseTime;

        for(int i = 0; i< pos.size(); i++){
            double cnt = (double)(target - pos[i]) / speed[i];
            posWiseTime.push_back({pos[i], cnt});
        }

        sort(posWiseTime.rbegin(), posWiseTime.rend());

        int fleets = 0;
        double previousVal = -1;
        for(auto [pos, time]: posWiseTime){
            // same fleet case
            if(time > previousVal){
                fleets++;
                previousVal = time;  
            }
        }

        return fleets;
    }
};
