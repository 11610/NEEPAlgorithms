/**
* kruskal算法：采用了边贪心的策略
**/

struct edge {
    int u, v; //边的两个端点编号
    int cost; //边权
} E[MAXE]; //最多有MAXE条边

bool cmp(edge a, edge b) {
    return a.cost < b.cost;
}

//伪代码
int kruskal() {
    令最小生成树的边权之和为ans、最小生成树当前边数Num_Edge;
    将所有边按边权从小到大排序;
    for (从小到大枚举所有边) {
        if (当前测试边的两个端点在不同的连通块中) {
            将该测试边加入最小生成树中;
            ans += 测试边的边权;
            最小生成树的当期边数Num_Edge加1;
            当边数Num_Edge等于顶点数减1时结束循环;
        }
    }
    return ans;
}

//代码实现
int father[N]; //并查集数组
//并查集查询函数
int findFather(int x) {
    ...
}
//kruskal函数返回最小生成树的边权之和，n为顶点个数，m为图的边数
int kruskal(int n, int m) {
    //ans为所求边权之和，Num_Edge为当前生成树的边数
    int ans = 0, Num_Edge = 0;
    //假设题目中顶点范围是[1,n]
    for (int i = 1; i <= n; i++)
        father[i] = i; //并查集初始化
    sort(E, E + m, cmp); //将所有边权按从小到大排序
    //枚举所有边
    for (int i = 0; i < m; i++) {
        //查询测试边两个端点所在集合的根结点
        int faU = findFather(E[i].u);
        int faV = findFather(E[i].v);
        //如果不在一个集合中
        if (faU != faV) {
            father[faU] = faV; //合并集合（即把测试边加入最小生成树中）
            ans += E[i].cost; //边权之和加入测试边的边权
            Num_Edge++; //当前生成树的边数加1
            if (Num_Edge == n - 1)
                break; //边数等于顶点数减1时结束算法
        }
    }
    if (Num_Edge != n - 1)
        return -1; //无法连通时返回-1
    else
        return ans; //返回最小生成树的边权之和
}
