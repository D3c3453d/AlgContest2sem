/*
Найти, на сколько нулей оканчивается n! = 1 * 2 * 3 * … * n. n ≤ 1000.

Пример:
Ввод:
25

Вывод:
6
*/

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int min(pair <int, int> arr){
    if (arr.first < arr.second)return arr.first;
    return arr.second;
}

int main() {
    int k_2 = 0, k_5=0;
    int s_1= 0, s_2 = 0;
    int n = 25;
    cin >> n;
    vector<pair<int, int>> din{make_pair(0, 0), make_pair(0, 0), make_pair(1, 0)};
    for (int i = 3; i <= n; ++i){
        if (i%2 == 0){
            k_2 = din[i/2].first+1;
        }
        if (i%5 == 0){
            k_5 = din[i/5].second+1;
        }
        din.push_back(make_pair(k_2, k_5));
        s_1+=k_2;
        s_2+=k_5;
        k_2=0;
        k_5=0;
    }
    cout << min(make_pair(s_1, s_2));
    return 0;
}