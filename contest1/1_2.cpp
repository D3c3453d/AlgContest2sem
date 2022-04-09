/*
Вывести разложение натурального числа n на простые множители. 
Простые множители должны быть упорядочены по возрастанию и разделены пробелами. 2 ≤ n ≤ 10^6.

Пример:
Ввод:
75

Вывод:
3 5 5
*/

#include <iostream>
#include <vector>
#include <utility>
#include<cmath>

using namespace std;

int min(pair <int, int> arr){
    if (arr.first < arr.second)return arr.first;
    return arr.second;
}

int main() {
    int n;
    cin >> n;
    if (n<4){
        cout << n;
        return 0;
    }
    int t = n;
    int i = 2;
    while (t!=1) {
        if (t % i == 0) {
            while (t % i == 0) {
                t /= i;
                cout << i << " ";
            }
        }
        ++i;
    }
    return 0;
}
