/*
Дано натуральное число N. Представить N в виде A + B, так, что НОД(A, B) максимален, 1 ≤ A ≤ B. 
Вывести A и B. Если возможно несколько ответов - вывести ответ с минимальным A. 1 < n ≤ 10 000 000.

Пример:
Ввод:
35

Вывод:
7 28
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
    int i = 2;
    for (; i < n; ++i){
        if (n%i == 0)break;
    }
    int d = n/i;
    cout << d << " " << (n - d);
    return 0;
#include <iostream>
#include <vector>
#include <utility>
#include<cmath>

using namespace std;




int main()
{
    int n;
    cin >> n;
    int i = 2;
    for (; i < n; ++i){
        if (n%i == 0)break;
    }
    int d = n/i;
    cout << d << " " << (n - d);
    return 0;
}