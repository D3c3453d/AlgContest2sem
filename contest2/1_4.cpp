/*
Напишите программу, печатающую набор строк в лексикографическом порядке.
Строки разделяются символом перевода строки ’∖n’. 
Если последний символ в потоке ввода ’∖n’, считать, что после него нет пустой строки. 
Известно, что либо n<100, либо n≤1000, но при этом число инверсий в данном наборе строк меньше 100. 
Максимальная длина строки 255 символов. Написать свою функцию сравнения строк. Сортировать вставками.

Пример:
Ввод:
4
caba
abba
ab
aba

Вывод:
ab
aba
abba
caba

*/

#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;




int max(int a, int b){
    if (a > b)return a;
    return b;
}



bool cmp_less (string a, string b){
    for (int i = 0; i < a.size(); ++i){
        if (i == b.size())return false;
        if (a[i] < b[i])return true;
        if (a[i] > b[i])return false;
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    for(int i = 1; i < n; i++)
        for(int j = i; j > 0 && cmp_less(arr[j], arr[j-1]); j--)
            swap(arr[j-1],arr[j]);
    for (auto i: arr){
        cout << i << endl;
    }
}