/*
ВНИМАНИЕ! Для решения данной задачи нужно использовать структуру данных стек!
Пара слов называется стековой анаграмой, если одно слово можно получить из другого, 
проведя последовательность стековых операций с его буквами(взять очередную букву исходного слова и поместить ее в стек; 
взять букву из стека и добавить ее в конец выходного слова). 
Для заданной пары слов требуется определить, можно ли выполнить последовательность стековых операций, переводящую первое слово во второе. 
Все буквы в слове различные. Длина анаграммы ≤ 10000.

Формат ввода:
Пара слов, являющихся анаграммой.

Формат вывода:
YES, если последовательность стековых операций существует и NO в противном случае.

Пример 1:
Ввод:
STOL SLOT
Вывод:
YES

Пример 2:
Ввод:
ABC CAB
Вывод:
NO
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

class Stack{
    vector<char> st;
public:
    int top(){
        if (st.size() == 0)return -1;
        return st[st.size()-1];
    }
    int pop(){
        int t = top();
        st.pop_back();
        return t;
    }
    void push(int t){
        st.push_back(t);
    }
    void print(){
        cout << "|";
        for (auto i = st.begin(); i < st.end(); ++i)
            cout << *i << " ";
        cout << "|\n";
    }
    bool empty(){
        if (st.size()==0)return true;
        return false;
    }
};

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


int main(){
    Stack st;
    string one, two;
    cin >> two;
    cin >> one;
    int j = 0;
    int i = 0;
    for (; i < one.size(); ++i){
        //step();
        if (one[i] == two[j]){
            j++;
        }
        else {
            if (!st.empty() && one[i] == st.top()) {
                st.pop();
                continue;
            }
            while (j<two.size() && one[i] != two[j]) {
                st.push(two[j]);
                j++;
            }
            if (one[i] == two[j]){
                j++;
            }
        }

    }
    if (i==one.size() && st.empty())cout <<"YES";
    else cout <<"NO";
}

