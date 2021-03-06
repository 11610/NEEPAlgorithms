/**
* 快速排序（时间复杂度为O(nlogn)）
* 思路：① 调整序列中的元素，使当前序列最左端的元素在调整后满足左侧所有元素均不超过该元素、右侧所有元素均大于该元素
*       ② 对该元素的左侧和右侧分别递归进行①的调整，直到当前调整区间的长度不超过1
**/


//对区间[left,right]进行划分
int Partition(int A[], int left, int right) {
    int temp = A[left]; //将A[left]存放至临时变量temp
    //只要left与right不相遇
    while (left < right) {
        while (left < right && A[right] > temp)
            right--; //反复左移right
        A[left] = A[right]; //将A[right]挪到A[left]
        while (left < right && A[left] <= temp)
            left++; //反复右移left
        A[right] = A[left]; //将A[left]挪到A[right]
    }
    A[left] = temp; //把temp放到left与right相遇的地方
    return left; //返回相遇的下标
}

//快速排序，left与right初值为序列首尾下标（例如1与n）
void quickSort(int A[], int left, int right) {
    //当前区间的长度超过1
    if (left < right) {
        //将[left,right]按A[left]一分为二
        int pos = Partition(A, left, right);
        quickSort(A, left, pos - 1); //对左子区间递归进行快速排序
        quickSort(A, pos + 1, right); //对右子区间递归进行快速排序
    }
}
