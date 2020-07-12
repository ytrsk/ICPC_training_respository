#include <bits/stdc++.h>
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};
#define x first
#define y second
int n,m;
void bfs(int x,int y,int dis[100][100],vector<string>& maze) {
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) dis[i][j] = 0x3f3f3f3f;
    dis[x][y] = 0;
    queue <pair<int,int> > q;
    q.push(make_pair(x,y));
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int i=0;i<4;i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (maze[nx][ny] == '#') continue;
            if (dis[nx][ny] > dis[cur.x][cur.y] + 1) {
                dis[nx][ny] = dis[cur.x][cur.y] + 1;
                q.push(make_pair(nx,ny));
            }
        }
    }
}
int dis[40][100][100];
int dis_t[100][100];
class Solution {
public:
    int minimalSteps(vector<string>& maze) {
        n = maze.size();
        m = maze[0].length();
        vector <pair<int,int> > O;//stone
        vector <pair<int,int> > M;//jiguan
        pair <int,int> S,T;
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (maze[i][j] == 'O') O.push_back(make_pair(i,j));
                else if (maze[i][j] == 'M') M.push_back(make_pair(i,j));
                else if (maze[i][j] == 'S') S = make_pair(i,j);
                else if (maze[i][j] == 'T') T = make_pair(i,j);
            }
        }
        for (int oo=0;oo<O.size();oo++) {
            bfs(O[oo].x,O[oo].y,dis[oo],maze);
        }
        bfs(T.x,T.y,dis_t,maze);
        if (M.size() == 0) {
            if (dis_t[S.x][S.y] == 0x3f3f3f3f) return -1;
            return dis_t[S.x][S.y];
        }
        else {
            static int f[1<<16][16];
            memset(f,0x3f,sizeof(f));
            //init
            for (int i=0;i<M.size();i++) {
                int s = 1 << i;
                for (int j=0;j<O.size();j++) {
                    f[s][i] = min(f[s][i],dis[j][S.x][S.y]+dis[j][M[i].x][M[i].y]);
                }
            }
            for (int s=1;s<(1<<M.size());s++) {
                if (__builtin_popcount(s) == 1) continue;
                for (int i=0;i<M.size();i++) if (s & (1 << i)) {
                    int last = s ^ (1 << i);
                    for (int u=0;u<M.size();u++) if (u != i && (s & (1 << i))) {
                        for (int j=0;j<O.size();j++) {
                            if (dis[j][M[u].x][M[u].y] + dis[j][M[i].x][M[i].y] > 0x3f3f3f3f) continue;
                            f[s][i] = min(f[s][i],f[last][u] + dis[j][M[u].x][M[u].y] + dis[j][M[i].x][M[i].y]);
                        }
                    }
                }
            }
            int ans = 0x3f3f3f3f;
            for (int i=0;i<M.size();i++) {
                ans = min(ans,f[(1<<M.size())-1][i] + dis_t[M[i].x][M[i].y]);
            }
            if (ans == 0x3f3f3f3f) return -1;
            return ans;
        }
    }
};