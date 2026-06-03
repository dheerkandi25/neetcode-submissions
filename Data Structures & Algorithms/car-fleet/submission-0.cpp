class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> cars;

        for (int i = 0; i < position.size(); i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        sort(cars.rbegin(), cars.rend());

        int fleets = 0;
        double fleetTime = 0;

        for (auto car : cars) {
            double currTime = car.second;

            if (currTime > fleetTime) {
                fleets++;
                fleetTime = currTime;
            }
        }

        return fleets;
    }
};
