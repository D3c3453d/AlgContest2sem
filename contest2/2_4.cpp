/*
На числовой прямой окрасили N отрезков.
Известны координаты левого и правого концов каждого отрезка [Li, Ri]. Найти сумму длин частей числовой прямой, окрашенных ровно в один слой.
N ≤ 10000. Li, Ri — целые числа в диапазоне [0, 10^9].

Формат ввода:
В первой строке записано количество отрезков.
В каждой последующей строке через пробел записаны координаты левого и правого концов отрезка.

Формат вывода:
Выведите целое число — длину окрашенной в один слой части.

Пример:
Ввод:
3
1 4
7 8
2 5

Вывод:
3

*/

#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;



int main(){
    vector<pair<int, int>> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int time_in, time_out;
        cin >> time_in >> time_out;
        arr.emplace_back(time_in, -1);
        arr.emplace_back(time_out, +1);
    }
    sort(arr.begin(), arr.end());
    int level = 0;
    int c = 0;
    int prev = arr[0].first;
    for (auto i: arr){
        if (level == 1)c+=i.first - prev;
        level -= i.second;
        prev = i.first;
    }
    cout << c;
}

