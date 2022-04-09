/*
Вывести квадраты натуральных чисел от 1 до n, используя только O(n) операций сложения и вычитания(умножением пользоваться нельзя). n ≤ 1000.

Пример:
Ввод:
5

Вывод:
1 4 9 16 25
*/

#include <iostream>
#include <vector>
#include <utility>
#include<cmath>

using namespace std;



int main() {
    int n;
    cin >> n;
    int d = 1;
    int a = 0;
    for (int i = 0; i < n; ++ i){
        a += d;
        cout << a<< " ";
        d += 2;
    }
    return 0;
#include <iostream>
#include <vector>
#include <utility>
#include<cmath>

using namespace std;



int main() {
    int n;
    cin >> n;
    int d = 1;
    int a = 0;
    for (int i = 0; i < n; ++ i){
        a += d;
        cout << a<< " ";
        d += 2;
    }
    return 0;
}