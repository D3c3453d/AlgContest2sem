/*
Даны два массива целых чисел одинаковой длины A[0..n-1] и B[0..n-1]. 
Необходимо найти первую пару индексов i0 и j0, i0 ≤ j0, такую что A[i0] + B[j0] = max {A[i] + B[j], где 0 <= i < n, 0 <= j < n, i <= j}.
Время работы - O(n). n ≤ 100000.

Пример:
Ввод:
4
4 -8 6 0
-10 3 1 1

Вывод:
0 1
*/

#include <iostream>
#include <vector>
#include <utility>
#include<cmath>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    vector<int> v1(n), v2(n);
    for (int i = 0; i < n; ++i) {
        cin >>v1[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> v2[i];
    }
    int max = 0;
    vector<int> maxs(n);
    int max_ind = 0;
    for (int i = 0; i < n; ++i) {
        if (v1[i] > max) {
            max = v1[i];
            max_ind = i;
        }
        maxs[i] = max_ind;
    }
    int a = 0, b = 0;
    max = 0;
    for (int i = 0; i < n; ++i) {
        max_ind = v2[i] + v1[maxs[i]];
        if (max_ind > max) {
            max = max_ind;
            a = maxs[i];
            b = i;
        }
    }

    std::cout << a << " " << b << std::endl;
    return 0;
}#include <iostream>
#include <vector>
#include <utility>
#include<cmath>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    vector<int> v1(n), v2(n);
    for (int i = 0; i < n; ++i) {
        cin >>v1[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> v2[i];
    }
    int max = 0;
    vector<int> maxs(n);
    int max_ind = 0;
    for (int i = 0; i < n; ++i) {
        if (v1[i] > max) {
            max = v1[i];
            max_ind = i;
        }
        maxs[i] = max_ind;
    }
    int a = 0, b = 0;
    max = 0;
    for (int i = 0; i < n; ++i) {
        max_ind = v2[i] + v1[maxs[i]];
        if (max_ind > max) {
            max = max_ind;
            a = maxs[i];
            b = i;
        }
    }

    std::cout << a << " " << b << std::endl;
    return 0;
}