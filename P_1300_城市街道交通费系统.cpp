#include<bits/stdc++.h>
using namespace std;
// 思路：dijkstra优先队列 + 方向维度
//在dijkstra里枚举了上下左右的移动，还枚举了方向的变化
const int N = 40;
char g[N][N];
int h, w;
const int di[] = { -1, 1, 0, 0 };
const int dj[] = { 0, 0, -1, 1 };
// turn[dir][i][j]表示dir方向向周围转的3个方向及每个方向的花费
int turn[4][4][2];
int dis[N][N][4];
bool visit[N][N][4];
const int north = 0, south = 1, west = 2, east = 3;
struct Node
{
   //（i，j)表示当前坐标点，dir表示当前方向，是4个常量之一，dis表示当前到这个坐标点的距离
    int i, j, dir, dis;
    Node(int x, int y, int dr, int ds)
    : i(x), j(y), dir(dr), dis(ds)
    { }
};
bool operator<(const Node& lhs, const Node& rhs)
{
    return lhs.dis > rhs.dis;
}
priority_queue<Node> heap;
inline int turnLeft(int dir)
{
    switch (dir)
    {
        case north:
        {
            return west;
            break;
        }
        case south:
        {
            return east;
            break;
        }
        case west:
        {
            return south;
            break;
        }
        case east:
        {
            return north;
            break;
        }
    }
    return -1;
}

inline int turnRight(int dir)
{
    return turnLeft(dir) ^ 1;
}

inline int turnBack(int dir)
{
    return dir ^ 1;
}

inline bool inArea(int i, int j)
{
    return i >= 0 && i < h && j >= 0 && j < w;
}

void dijkstra(int si, int sj, int sdir)
{
    bool flag = false;
    // for (int rot = 0; rot < 4; ++rot) // rotate
    // {
    //     if (rot == 3 && flag)
    //     {
    //         break;
    //     }
    //     int newDir = turn[sdir][rot][0];
    //     int weight = turn[sdir][rot][1];
    //     dis[si][sj][newDir] = weight;
    //     flag |= (inArea(si + di[newDir], sj + dj[newDir]) &&
    //      g[si + di[newDir]][sj + dj[newDir]] != '.');
    //     heap.push(Node(si, sj, newDir, weight));
    // }
    dis[si][sj][sdir] = 0;
    heap.push(Node(si, sj, sdir, 0));
    // printf("befor !heap.empty()\n");
    while (!heap.empty())
    {
        Node node = heap.top();
        heap.pop();
        // printf("pop the node (%d, %d)\n", node.i, node.j);
        if (visit[node.i][node.j][node.dir])
        {
            continue;
        }
        visit[node.i][node.j][node.dir] = true;
        for (int move = 0; move < 4; ++move)
        {
            flag = false;
            int newI = node.i + di[move];
            int newJ = node.j + dj[move];
            if (!inArea(newI, newJ))
            {
                continue;
            }
            for (int rot = 0; rot < 4; ++rot)
            {
                if (rot == 3 && flag)
                {
                    continue;
                }            
                int newDir = turn[node.dir][rot][0];
                int weight = turn[node.dir][rot][1]; 
                flag |= (inArea(newI + di[newDir], newJ + dj[newDir]) && g[newI + di[newDir]][newJ + dj[newDir]] != '.');
                if (!visit[newI][newJ][newDir] && dis[node.i][node.j][node.dir] + weight < dis[newI][newJ][newDir])
                {
                    dis[newI][newJ][newDir] = dis[node.i][node.j][node.dir] + weight; 
                    heap.push(Node(newI, newJ, newDir, dis[newI][newJ][newDir]));
                }
            }
        }
    }
}

int main()
{
    memset(dis, 0x3f, sizeof(dis));
    scanf("%d%d", &h, &w);
    int si = -1, sj = -1, ei = -1, ej = -1, sdir = -1;
    for (int dir = 0; dir < 4; ++dir)
    {
        turn[dir][0][0] = dir;
        turn[dir][0][1] = 0;
        turn[dir][1][0] = turnLeft(dir);
        turn[dir][1][1] = 1;
        turn[dir][2][0] = turnLeft(dir) ^ 1;
        turn[dir][2][1] = 5;
        turn[dir][3][0] = dir ^ 1;
        turn[dir][3][1] = 10;
    }
    for (int i = 0; i < h; ++i)
    {
        scanf("%s", g[i]);
        for (int j = 0; j < w; ++j)
        {
            switch (g[i][j])
            {
                case 'N': { si = i; sj = j; sdir = north; break; }
                case 'S': { si = i; sj = j; sdir = south; break; } 
                case 'W': { si = i; sj = j; sdir = west; break; }
                case 'E': { si = i; sj = j; sdir = east; break; }
                case 'F': { ei = i; ej = j; break; }
            }
        }
    }
    // printf("=====1\n");
    dijkstra(si, sj, sdir);
    // printf("=====2\n");
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++)
            cout<<dis[i][j][west]<<dis[i][j][south]<<dis[i][j][north]<<dis[i][j][east]<<" ";
        cout<<'\n';
    }
    printf("%d\n", *min_element(dis[ei][ej], dis[ei][ej] + 4));
}
