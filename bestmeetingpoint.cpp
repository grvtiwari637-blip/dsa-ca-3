
class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> rows, cols;

        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }

        sort(cols.begin(), cols.end());

        int rowMedian = rows[rows.size() / 2];
        int colMedian = cols[cols.size() / 2];

        int distance = 0;

        for (int r : rows)
            distance += abs(r - rowMedian);

        for (int c : cols)
            distance += abs(c - colMedian);

        return distance;
    }
};
