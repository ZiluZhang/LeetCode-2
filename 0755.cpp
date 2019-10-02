class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        int n = heights.size();
        for (int i = 0; i < V; i++) {
            int idx = K;
            while (idx > 0 && heights[idx-1] <= heights[idx]) idx--;
            if (heights[idx] < heights[K]) {
                while (idx+1 < K && heights[idx+1] == heights[idx]) idx++;
                heights[idx]++;
                continue;
            }
            idx = K;
            while (idx < n-1 && heights[idx+1] <= heights[idx]) idx++;
            if (heights[idx] < heights[K]) {
                while (idx-1 > K && heights[idx-1] == heights[idx]) idx--;
                heights[idx]++;
                continue;
            }
            heights[K]++;
        }
        return heights;
    }
};