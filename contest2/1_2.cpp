/*
Задано N точек на плоскости. Указать (N−1)-звенную несамопересекающуюся незамкнутую ломаную, проходящую через все эти точки.
Указание: стройте ломаную в порядке возрастания x-координаты. 
Если имеются две точки с одинаковой x-координатой, то расположите раньше ту точку, у которой y-координата меньше.

Пример:
Ввод:
4
0 0
1 1
1 0
0 1

Вывод:
0 0
0 1
1 0
1 1

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct A{
    int x, y;
    int ind;
    bool operator<( A r) const{
        if (x > r.x)return false;
        if (x < r.x)return true;
        return y < r.y;
    }
};

int max(int a, int b){
    if (a > b)return a;
    return b;
}



std::istream& operator>> (std::istream &in, A &p)
{
    in >> p.x >> p.y;
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
        cout << i.x << " " << i.y <<endl;
    }
}