/*
На склад привезли много пустых ящиков. Все ящики пронумерованы по порядку поступления от 0.
Известно, что их все можно сложить один в один (то есть так, что каждый следующий помещается в предыдущий). 
Один ящик можно вложить в другой, если его можно перевернуть так, что размеры одного ящика по всем осям станут строго меньше размеров другого ящика по соответствующим осям.
Требуется определить, в какой последовательности они будут вложены друг в друга. Вывести номера ящиков.
Максимальное кол-во 10000.

Пример:
Ввод:
3
2 3 5
1 1 1
10 4 10

Вывод:
1 0 2

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct A{
    int max, mid, min;
    int ind;
    bool operator<( A r) const{
        if (max < r.max)return true;
        if (max > r.max)return false;
        if (mid < r.mid)return true;
        if (mid > r.mid)return false;
        return min < r.min;
    }
};

int max(int a, int b){
    if (a > b)return a;
    return b;
}



std::istream& operator>> (std::istream &in, A &p)
{
    int a, b, c;
    in >> a >> b >> c;
    p.max = max(a, max(b, c));
    p.min = -max(-a, max(-b, -c));
    p.mid = a+b+c - p.min - p.max;
    return in;
}

int main(){
    int n;
    cin >> n;
    vector<A> arr(n);
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
        arr[i].ind = i;
    }
    sort(arr.begin(), arr.end());
    for (auto i: arr){
        cout << i.ind << " ";
    }
}