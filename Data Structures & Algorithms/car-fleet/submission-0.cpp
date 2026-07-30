class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // sort both speed and position in decreasing order
        int n = position.size();
        vector<pair<int, int>> cars(n);
        for(int i=0; i<n; i++){
            cars[i] = {position[i], speed[i]};
        }

        sort(cars.begin(), cars.end(), greater<pair<int, int>>());
        stack<float> st; 
        for(int i=0; i<cars.size(); i++){
            // Find how long it will take to reach destination, use that to group fleets. If it will take longer than the fleet before, it will form its own fleet.
            float distanceLeft = target - cars[i].first;
            float timeNeeded = cars[i].second / distanceLeft;
            if(st.empty()) st.push(timeNeeded);
            else {
                if(timeNeeded < st.top()) st.push(timeNeeded);
            }
        }
        return st.size();
    }
};