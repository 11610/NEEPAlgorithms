/**
* algorithm头文件下的常用函数
**/
#include <cstdlib>
#include <algorithm>
using namespace std;


//max()、min()和abs()
{
    int x = 1, y = -2;
    printf("%d %d\n", max(x, y), min(x, y)); // 1 -2
    printf("%d %d\n", abs(x), abs(y)); // 1 2
}


//swap()
{
    int x = 1, y = 2;
    swap(1, 2);
    printf("%d %d\n", x, y); // 2 1
}


//reverse()
{
    int a[10] = { 10, 11, 12, 13, 14, 15 };
    reverse(a, a + 4); //将a[0]-a[3]反转
    for (int i = 0; i < 6; i++)
        printf("%d ", a[i]); // 13 12 11 10 14 15
}
{
    string str = "abcdefghi";
    reverse(str.begin() + 2, str.begin() + 6); //对str[2]-str[5]反转
    for (int i = 0; i < str.length(); i++)
        printf("%c", str[i]); // abfedcghi
}


//next_permutation()
{
    int a[10] = { 1, 2, 3 };
    //a[0]-a[2]之间的序列需要求解next_permutation
    do {
        printf("%d%d%d\n", a[0], a[1], a[2]); // 123 132 213 231 312 321
    } while (next_permutation(a, a + 3));
}


//fill()
{
    int a[5] = { 1, 2, 3, 4, 5 };
    fill(a, a + 5, 233); //将a[0]-a[4]均赋值为233
    for (int i = 0; i < 5; i++)
        printf("%d ", a[i]); // 233 233 233 233 233
}


//sort()
//sort(首元素地址(必填)，尾元素地址的下一个地址(必填 )，比较函数(非必填))
{
    int a[6] = { 9, 4, 2, 5, 6, -1 };
    //将a[0]-a[3]从小到大排序
    sort(a, a + 4);
    for (int i = 0; i < 6; i++)
        printf("%d ", a[i]); // 2 4 5 9 6 -1
    printf("\n");
    //将a[0]-a[5]从小到大排序
    sort(a, a + 6);
    for (int i = 0; i < 6; i++)
        printf("%d ", a[i]); // -1 2 4 5 6 9
}
//比较函数cmp的实现
{
    bool cmp(int a, int b) {
        return a > b; //可以理解为当a>b时把a放在b前面
    }
}
//结构体数组的排序
{

    struct node {
        int x, y;
    } ssd[10];

    bool cmp(node a, node b) {
        if (a.x != b.x)
            return a.x > b.x;
        else
            return a.y < b.y;
    }

}
//容器的排序
//在STL标准容器中，只有vector、string、deque是可以使用sort的
//而set、map等用红黑树实现的容器，元素本身有序，故不允许使用sort
{

    //cmp()的元素类型取决于容器中的元素类型
    bool cmp(int a, int b) {
        return a > b;
    }

    int main() {
        vector<int> vi;
        vi.push_back(3);
        vi.push_back(1);
        vi.push_back(2);
        sort(vi.begin(), vi.end(), cmp); //对整个vector排序
        for (int i = 0; i < 3; i++)
            printf("%d ", vi[i]); // 3 2 1
    }
}


//lower_bound()和upper_bound()  O(log(last-first))
{
    int a[10] = { 1, 2, 2, 3, 3, 3, 5, 5, 5, 5 }; //注意数组下标从0开始
    //寻找-1
    int* lowerPos = lower_bound(a, a + 10, -1);
    int* upperPos = upper_bound(a, a + 10, -1);
    printf("%d %d\n", lowerPos - a, upperPos + a); // 0 0
    //寻找1
    int* lowerPos = lower_bound(a, a + 10, 1);
    int* upperPos = upper_bound(a, a + 10, 1);
    printf("%d %d\n", lowerPos - a, upperPos + a); // 0 1
    //寻找3
    int* lowerPos = lower_bound(a, a + 10, 3);
    int* upperPos = upper_bound(a, a + 10, 3);
    printf("%d %d\n", lowerPos - a, upperPos + a); // 3 6
    //寻找4
    int* lowerPos = lower_bound(a, a + 10, 4);
    int* upperPos = upper_bound(a, a + 10, 4);
    printf("%d %d\n", lowerPos - a, upperPos + a); // 6 6
    //寻找6
    int* lowerPos = lower_bound(a, a + 10, 6);
    int* upperPos = upper_bound(a, a + 10, 6);
    printf("%d %d\n", lowerPos - a, upperPos + a); // 10 10
}
{
    int a[10] = { 1, 2, 2, 3, 3, 3, 5, 5, 5, 5 };
    printf("%d %d\n", lower_bound(a, a + 10, 3) - a, upper_bound(a, a + 10, 3) - a); //寻找3
}
