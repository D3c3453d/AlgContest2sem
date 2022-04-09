/*
Дан фрагмент последовательности скобок, состоящей из символов (){}[]. 
Требуется определить, возможно ли продолжить фрагмент в обе стороны, получив корректную последовательность. 
Длина исходной последовательности ≤ 800000.

Формат ввода:
Строка, содержащая символы (){}[] и, возможно, перевод строки.

Формат вывода:
Если возможно - вывести минимальную корректную последовательность, иначе - напечатать "IMPOSSIBLE".

Пример 1:
Ввод:
{}[[[[{}[]
Вывод:
{}[[[[{}[]]]]]

Пример 2:
Ввод:
{][[[[{}[]
Вывод:
IMPOSSIBLE

Пример 3:
Ввод:
]()}[](({}
Вывод:
{[]()}[](({}))
*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <map>
#include <utility>
#include<cmath>

using namespace std;

void step(){
    char r;
    cin >> r;
}

void input_vector(vector<int>& arr){
    for (int i = 0; i < arr.size(); ++i){
        cin >> arr[i];
    }
}

void print_vector(vector<int>& arr){
    for (int i = 0; i < arr.size(); ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int>::iterator bin_p(vector<int>::iterator l, vector<int>::iterator r, int x){
    while (r-l != 1){
        auto m = l + (r-l)*0.5;
        if (*m > x){
            r = m;
        } else {
            l = m;
        }
    }
    return l;
}


int main(){
    stack<char> st, to_begin;
    map<char, char>skob, re_skob;
    skob[']'] = '[';
    skob['}'] = '{';
    skob[')'] = '(';
    re_skob['['] = ']';
    re_skob['{'] = '}';
    re_skob['('] = ')';
    string inp;
    cin >> inp;
    for (char i: inp){
        auto it =skob.find(i);
        //cout << (it==skob.end());
        if (it!=skob.end()){
            if (st.empty()){
                to_begin.push(i);
                continue;
            }
            char t =st.top();
            st.pop();
            if (t!=skob[i]){
                cout << "IMPOSSIBLE";
                return 0;
            }
        }else{
            st.push(i);
        }
    }
    while (to_begin.size()){
        cout << skob[to_begin.top()];
        to_begin.pop();
    }
    cout << inp;
    while (st.size()){
        cout << re_skob[st.top()];
        st.pop();
    }
}

