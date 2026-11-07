class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones,
                     vector<int>& target) {
        int answer = -1;
        int minimumDistance = INT_MAX;

        for (int index = 0; index < drones.size(); ++index) {
            int distance =
                abs(drones[index][0] - target[0]) +
                abs(drones[index][1] - target[1]);

            if (distance <= drones[index][2] &&
                distance < minimumDistance) {
                minimumDistance = distance;
                answer = index;
            }
        }

        return answer;
    }
};
