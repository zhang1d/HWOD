/*
描述：
对于给出的 n 个整数组成的数组 {a1, a2, …, an}，根据输入要求，按升序或降序排列后输出。

输入描述：
第一行输入一个整数 n（1 ≤ n ≤ 10^3），代表数组中的元素个数。
第二行输入 n 个整数 a1, a2, …, an（0 ≤ ai ≤ 10^5），代表数组中的元素。
第三行输入一个整数 op（0 ≤ op ≤ 1），代表排序方式，其中：
op = 0 表示按升序，op = 1 表示按降序。
*/

#include <iostream>
#include<vector>
#include<algorithm>
int main()
{
    int n ;

    std::cin>>n;
    std::vector<int> arr(n);
    for(int i = 0;i<n;i++){
        std::cin>>arr[i];

    }
    int op;

    std::cin>>op;
    std::sort(arr.begin(),arr.end(),[op](int a,int b){
        if (op)
        {
           return a>b;
        }
        return a<b;
        
    });
    for(int x :arr){
        std::cout << x <<" ";
    }

    return 0;
}

