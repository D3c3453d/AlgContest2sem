/*
Даны четыре неотрицательных числа a, b, c и d. Сложить две рациональные дроби a/b и c/d, а их результат представить в виде несократимой дроби m/n. 
Вывести числа m и n. a, b, c, d ≤ 1000.

Пример:
Ввод:
3 10 5 18

Вывод:
26 45
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

struct Drob{
    long long ch = 0, zn = 1;
    Drob(long long ch =0, long long zn=1):ch(ch), zn(zn){
    }
    int gcd (int a, int b) {
        if (b == 0)
            return a;
        else
            return gcd (b, a % b);
    }
    void normalize(){
        int t = gcd(ch, zn);
        ch/=t;
        zn/=t;
    }
    friend std::ostream& operator<< (std::ostream &out, const Drob &p){
        out << p.ch << " " << p.zn << endl;
        return out;
    }
};

std::istream& operator>> (std::istream &in, Drob &p)
{
    in >> p.ch;
    in >> p.zn;

    return in;
}

int main() {
    Drob a, b;
    cin >> a;
    cin >> b;
    a.normalize();
    b.normalize();

    Drob c{a.zn*b.ch + a.ch*b.zn, a.zn*b.zn};
    c.normalize();

    cout << c;
    return 0;
}
