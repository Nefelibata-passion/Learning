// 线段树是基于分治思想的二叉树，用来维护区间信息（区间和，区间最值，区间GCD等）
// 可以在logn的时间内执行区间修改和区间查询。
// 线段树中每个叶子节点存储元素本身，非叶子节点存储区间内元素的统计值

/*重点：
->  节点数组tr[]存{l, r, 统计值, 懒标记}
->  pushup函数从下向上计算统计值
->  pushdown函数从上向下计算统计值和懒标记
->  建树、修改、查询均从根节点进入
->  递归建树，时间O(n)
->  区间修改，区间查询O(logn)
*/
#include <iostream>

#define lc p << 1      // 节点编号
#define rc p << 1 | 1  // 节点编号
#define N 500005

using namespace std;

int n, w[N];

void build(int p, int l, int r);
void update(int p, int x, int k);
int query(int p, int x, int y);
void pushup(int p);
void pushdown(int p);
void update(int p, int x, int y, int k);

// 1.节点数组 tr[]
// 包含三个变量l,r,sum
struct node {
    int l, r, sum,
        add;  // 左/右区间的端点， sum存区间和， 懒惰标记(类似于记账本)
} tr[N * 4];

// 2.递归建树
// 父节点编号为p
// 左孩子编号为2*p，右孩子编号为2*p+1
void build(int p, int l, int r) {
    tr[p] = {l, r, w[l], 0};
    if (l == r)
        return;          // 是叶子节点则返回
    int m = l + r >> 1;  // 不是叶子节点则裂开
    build(lc, l, m);
    build(rc, m + 1, r);
    tr[p].sum = tr[lc].sum + tr[rc].sum;
}

// 3.点修改
// 从根节点进入，递归找到叶子节点[x,x]，把该节点的值增加k。
// 然后从下往上更新其祖先节点上的统计值
void update(int p, int x, int k) {       // 点修改
    if (tr[p].l == x && tr[p].r == x) {  // 叶子则修改
        tr[p].sum += k;
        return;
    }
    int m = tr[p].l + tr[p].r >> 1;  // 非叶子则裂开
    if (x <= m)
        update(lc, x, k);
    if (x > m)
        update(rc, x, k);
    tr[p].sum = tr[lc].sum + tr[rc].sum;
}

// 4.区间查询
// 拆分与拼凑的思想。eg:查询区间[4,9]可以拆分成[4,5][6,8]和[9,9]
// 通过合并这三个区间的答案求得查询答案。
// 从根节点进入，递归执行以下过程：
// 1.若查询区间[x,y]完全覆盖当前节点区间，则立即回溯，并返回该节点得sum值。
// 2.若左子节点与[x,y]有重叠，则递归访问左子树
// 3.若右子节点与[x,y]有重叠，则递归访问右子树
int query(int p, int x, int y) {       // 区间查询
    if (x <= tr[p].l && tr[p].r <= y)  // 覆盖则返回
        return tr[p].sum;
    int m = tr[p].l + tr[p].r >> 1;  // 不覆盖则裂开
    int sum = 0;
    pushdown(p);
    if (x <= m)
        sum += query(lc, x, y);
    if (y > m)
        sum += query(rc, x, y);
    return sum;
}

// 5.区间修改
// eg:对区间[4,9]内的每个数加上5.如果修改区间[x,y]所覆盖的每个叶子节点，时间将是O(n)的。
// 做懒惰修改，当[x,y]完全覆盖节点区间[a,b]时，先修改该区间的sum值，再打上一个“懒标记”，
// 然后立即返回。等下次需要时，再下传“懒标记”。
// 这样，可以把每次修改和查询的时间都控制到O(logn)
void pushup(int p) {  // 向上更新
    tr[p].sum = tr[lc].sum + tr[rc].sum;
}

void pushdown(int p) {  // 向下更新
    if (tr[p].add) {
        tr[lc].sum += tr[p].add * (tr[lc].r - tr[lc].l + 1);
        tr[rc].sum += tr[p].add * (tr[rc].r - tr[rc].l + 1);
        tr[lc].add += tr[p].add;
        tr[rc].add += tr[p].add;
        tr[p].add = 0;
    }
}

void update(int p, int x, int y, int k) {
    if (x <= tr[p].l && tr[p].r <= y) {  // 覆盖则修改
        tr[p].sum += (tr[p].r - tr[p].l + 1) * k;
        tr[p].add += k;
        return;
    }
    int m = tr[p].l + tr[p].r >> 1;  // 不覆盖则裂开
    pushdown(p);
    if (x <= m)
        update(lc, x, y, k);
    if (y > m)
        update(rc, x, y, k);
    pushup(p);
}