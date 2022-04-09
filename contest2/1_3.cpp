/*
Задано N точек на плоскости. Указать (N-1)-звенную несамопересекающуюся замкнутую ломаную, проходящую через все эти точки.
Предполагается, что никакие три точки не лежат на одной прямой.
Стройте ломаную от точки, имеющей наименьшую координату x. 
Если таких точек несколько, то используйте точку с наименьшей координатой y. 
Точки на ломаной расположите в порядке убывания углов лучей от начальной точки до всех остальных точек.
Для сортировки точек реализуйте алгоритм сортировки вставками.

Формат ввода:
В первой строке записано единственное число — число точек N. N ≤ 10000. 
В последующих N строках записаны координаты точек xi, yi. Все координаты целочисленные xi, yi ≤ 100000.

Формат вывода:
Точки в требуемом порядке.

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
1 1
1 0

*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct A{
    int x, y;
    int ind;
    double a;
    bool operator<( A r) const{
        if (x > r.x)return false;
        if (x < r.x)return true;
        return y < r.y;
    }
    void angle(A& r){
        if (r.x == x && r.y == y){
            a = -1;
            return;
        }
        if (r.x == x){
            a = 999999;
            return;
        }
        a = atan(double(r.y - y)/(r.x - x));
    }
};



int max(int a, int b){
    if (a > b)return a;
    return b;
}

std::ostream& operator<< (std::ostream &out, const A &point)
{
    out << point.x << " " << point.y;

    return out;
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
    cin>>arr[0];
    auto min_a = arr.begin();
    for (int i = 1; i < n; ++i){
        cin >> arr[i];
        arr[i].ind = i;
        if (arr[i] < *min_a)min_a = arr.begin() + i;
    }
    for (int i = 0; i < n; ++i){
        arr[i].angle(*min_a);
    }
    swap(*arr.begin(), *min_a);
    for(int i = 1; i < n; i++)
        for(int j = i; j > 1 && (arr[j-1].a < arr[j].a); j--)
            swap(arr[j-1],arr[j]);
    for (auto i : arr){
        cout << i << endl;
    }
}