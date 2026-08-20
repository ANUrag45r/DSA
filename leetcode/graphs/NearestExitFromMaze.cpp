class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

        int i = entrance[0];
        int j = entrance[1];

        int n = maze.size();
        int m = maze[0].size();

        queue<pair<pair<int, int>, int>> q;

        q.push({{i, j}, 0});

        maze[i][j] = '+';

        while (!q.empty()) {

            int r = q.front().first.first;

            int c = q.front().first.second;

            int d = q.front().second;

            q.pop();

            int delr[] = {-1, 0, 1, 0};
            int delc[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++) {

                int nr = r + delr[i];
                int nc = c + delc[i];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < m &&
                    maze[nr][nc] == '.') {

                    if ((nr == 0 || nr == n - 1 ||
                         nc == 0 || nc == m - 1)) {

                        return d + 1;
                    }

                    maze[nr][nc] = '+';

                    q.push({{nr, nc}, d + 1});
                }
            }
        }

        return -1;
    }
};