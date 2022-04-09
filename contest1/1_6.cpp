/*
Дан массив целых чисел A[0..n). Не используя других массивов переставить элементы массива A в обратном порядке за O(n). n ≤ 10000.

Пример:
Ввод:
4
3 9 -5 2

Вывод:
2 -5 9 3
*/

#include <iostream>
#include <vector>
#include <utility>
#include<cmath>

using namespace std;



int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i <n; ++ i){
        cin >> arr[i];
    }
    for (int i = 0; i < n/2; ++i){
        swap(arr[i], arr[n-i-1]);
    }
    for (auto i:arr){
        cout << i << " ";
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <utility>
#include<cmath>

using namespace std;



int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i <n; ++ i){
        cin >> arr[i];
    }
    for (int i = 0; i < n/2; ++i){
        swap(arr[i], arr[n-i-1]);
    }
    for (auto i:arr){
        cout << i << " ";
    }
    return 0;
}
