const int INF = 999999;
int  map[MAXN][MAXN]; //map[i,j]为初始输入的i到j的距离，未知的map[i,j]=INF;
int  dis[MAXN];
char vst[MAXN];
// 参数n表示结点数，s表示源点
int SPFA(int n, int s)
{
	// pri是队列头结点，end是队列尾结点
    int i, pri, end, p, t;
    memset(vst, 0, sizeof(vst));
    for(int i=0; i<MAXN; ++i)
        Q[i] = 0;
    for (i=0; i<n; i++)
        dis[i] = INF;
    dis[s] = 0;
    vst[s] = 1;
    Q[0] = s; pri = 0; end = 1;
    while (pri < end)
    {
        p = Q[pri];
        for (i=0; i<n; ++i)
        {
			//更新dis
            if (dis[p]+map[p][i] < dis[i])
            {
                dis[i] = dis[p]+map[p][i];
                if (!vst[i])     //未在队列中
                {
                    Q[end++] = i;
                    vst[i] = 1;
                }
            }
        }
        vst[p] = 0;   // 置出队的点为未标记
        pri++;
    }
    return 1;
}
