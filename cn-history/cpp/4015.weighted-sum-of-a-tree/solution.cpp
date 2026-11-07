class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int node = 1; node < n; ++node) {
            children[parent[node]].push_back(node);
        }
        vector<int> depth(n);
        
        queue<int> q;

        depth[0] = 1;
        
        q.push(0);

        int height = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            height = max(height, depth[node]);

            for (int child : children[node]) {
                depth[child] = depth[node] + 1;
                q.push(child);
            }
        }
        long long ans = 0;

        for (int node = 0; node < n; ++node) {
            ans += 1LL * nums[node]
                   * (height - depth[node] + 1);
        }

        return ans;
    }
};
