﻿/*
Даны два строго возрастающих массива целых чисел A[0..n) и B[0..m) и число k. Найти количество таких пар индексов (i, j), что A[i] + B[j] = k. 
Время работы O(n + m). n, m ≤ 100000.
Указание: Обходите массив B от конца к началу.

Формат ввода:
В первой и второй строке вводятся количество элементов и сами элементы массива A.
В третьей и четвертой строке вводятся количество элементов и сами элементы массива B.
В пятой строке — число k.

Формат вывода:
Выведите требуемое количество пар.

Пример:
Ввод:
4
-5 0 3 18
5
-10 -2 4 7 12
7

Вывод:
3
*/

#include <iostream>
#include <vector>
#include <utility>
#include<cmath>

using namespace std;




int main()
{
    int n;
    cin >> n;
    int n1 = n;
    vector<int> v1(n);
    for (int i = 0; i < n; ++i){
        cin >> v1[i];
    }
    cin >> n;
    vector<int> v2(n);
    for (int i = 0; i < n; ++i){
        cin >> v2[i];
    }
    int k, ans = 0;
    cin >> k;
    int cur_j = 0;
    for (int i = n-1; i>=0;--i){
        for (; cur_j < n1 && v1[cur_j] + v2[i] <= k;++cur_j){
            if (v1[cur_j] + v2[i] == k){
                ++ans;
            }
        }
    }
    cout << ans;
    return 0;
}