/*
¬ычислить площадь выпуклого n-угольника, заданного координатами своих вершин. 
¬начале вводитс€ количество вершин, затем последовательно целочисленные координаты всех вершин в пор€дке обхода по часовой стрелке.
n < 1000, координаты < 10000.
”казание: ƒл€ вычислени€ площади n-угольника можно посчитать сумму ориентированных площадей трапеций под каждой стороной многоугольника.

ѕример:
¬вод:
3
1 0
0 1
2 2

¬ывод:
1.5
*/

#include <iostream>
#include <vector>
#include <utility>
#include<cmath>

using namespace std;

struct Point{
    double x = 0, y = 0;
    Point(double x, double y):x(x), y(y){};
};


double s(Point a, Point b){
    return (a.y/2 + b.y/2)*(b.x - a.x);
}


int main()
{
    int n;
    cin >> n;
    vector<Point> arr;
    for (int i = 0; i < n; ++ i){
        double x, y;
        cin >> x >> y;
        arr.push_back(Point(x, y));
    }
    double S=0;
    for (int i = 1; i < n; ++ i){
        S += s(arr[i-1], arr[i]);
    }
    S+=s(arr[n-1], arr[0]);
    cout << S;
    return 0;
}#include <iostream>
#include <vector>
#include <utility>
#include<cmath>

using namespace std;

struct Point{
    double x = 0, y = 0;
    Point(double x, double y):x(x), y(y){};
};


double s(Point a, Point b){
    return (a.y/2 + b.y/2)*(b.x - a.x);
}


int main()
{
    int n;
    cin >> n;
    vector<Point> arr;
    for (int i = 0; i < n; ++ i){
        double x, y;
        cin >> x >> y;
        arr.push_back(Point(x, y));
    }
    double S=0;
    for (int i = 1; i < n; ++ i){
        S += s(arr[i-1], arr[i]);
    }
    S+=s(arr[n-1], arr[0]);
    cout << S;
    return 0;
}