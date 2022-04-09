/*
В круг выстроено N человек, пронумерованных числами от 1 до N. Будем исключать каждого k-ого до тех пор, пока не уцелеет только один человек.
Например, если N=10, k=3, то сначала умрет 3-й, потом 6-й, затем 9-й, затем 2-й, затем 7-й, потом 1-й, потом 8-й, за ним - 5-й, и потом 10-й. 
Таким образом, уцелеет 4-й.
Необходимо определить номер уцелевшего.
N, k ≤ 10000.

Пример:
Ввод:
10 3

Вывод:
4
*/

#include <iostream>
#include <vector>
#include <utility>
#include<cmath>

using namespace std;

void step(){
    char r;
    cin >> r;
}


int count (int n, int k) {
    if (n > 1)
        return (count(n-1,k)+k-1)%n+1;
    else{
        return 1;
    }
}
int main(){
    int n, k;
    cin>>n>>k;
    cout<<count(n,k);
}