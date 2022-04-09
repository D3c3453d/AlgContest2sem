/*
В базе данных хранится N записей, вида (Name, a1, a2, … , ak) — во всех записях одинаковое число параметров. 
На вход задачи подаётся приоритет полей — перестановка на числах 1,...,k — записи нужно вывести в соответствии с этим приоритетом. 
В случае, если приоритет полей таков: 3 4 2 1, то это следует воспринимать так: надо читать как: приоритет значений из 3 колонки самый высокий, 
приоритет значений из колонки 4 ниже, приоритет значений из колонки 2 ещё ниже, а приоритет значений из колонки 1 самый низкий.

Формат ввода:
N (1⩽N⩽1000) k (1⩽k;⩽10) p1 p2 ... pk (перестановка на k числах, разделитель пробел) N строк вида Name a1 a2 ... ak (разделитель — пробел)

Формат вывода:
N строк с именами согласно приоритету

Пример:
Ввод:
3
3
2 1 3
A 1 2 3
B 2 1 3
C 3 1 2

Вывод:
A
C
B

*/

#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

vector<int> priority;

struct A{
    string name;
    vector<int> data;
    A(){}
    A(string name, int k):name(std::move(name)){
        data.resize(k);
    }
    A( int k){
        data.resize(k);
    }
    bool operator>( A& r) const{

        for (auto i: priority){
            if (data[i-1] > r.data[i-1])return true;
            if (data[i-1] < r.data[i-1])return false;
        }
        return false;
    }

};



int max(int a, int b){
    if (a > b)return a;
    return b;
}

std::ostream& operator<< (std::ostream &out, const A &point)
{
    out << point.name ;
    return out;
}

std::istream& operator>> (std::istream &in, A &p)
{
    in >> p.name;
    for (int & i : p.data){
        cin >> i;
    }
    return in;
}



int main(){
    int n, k;
    cin >> n >> k;
    priority.resize(k);
    for (auto i = priority.begin(); i != priority.end(); ++ i){
        cin >> *i;
    }
    vector<A> arr(n, A {k});
    for (auto i = arr.begin(); i != arr.end(); ++ i){
        cin >> *i;
    }
    sort(arr.begin(), arr.end(), []( A& a,  A& b){ return a > b;});
    for (auto i: arr){
        cout <<  i << endl;
    }
}