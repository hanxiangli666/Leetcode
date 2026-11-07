class Solution {
public:
    int maximumGap(string skill, string station) {
        int workerCount = skill.size();

        if (workerCount == 1) {
            return 0;
        }

        vector<int> earliest(workerCount);
        vector<int> latest(workerCount);

        int stationIndex = 0;

        // 每名工人最早可以分配到的位置
        for (int worker = 0; worker < workerCount; ++worker) {
            while (station[stationIndex] != skill[worker]) {
                ++stationIndex;
            }

            earliest[worker] = stationIndex;
            ++stationIndex;
        }

        stationIndex = station.size() - 1;

        // 每名工人最晚可以分配到的位置
        for (int worker = workerCount - 1; worker >= 0; --worker) {
            while (station[stationIndex] != skill[worker]) {
                --stationIndex;
            }

            latest[worker] = stationIndex;
            --stationIndex;
        }

        int answer = 0;

        for (int worker = 1; worker < workerCount; ++worker) {
            int gap = latest[worker] - earliest[worker - 1];
            answer = max(answer, gap);
        }

        return answer;
    }
};
