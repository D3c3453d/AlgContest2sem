/*
Дано выражение в инфиксной записи. Вычислить его, используя перевод выражения в постфиксную запись. 
Выражение не содержит отрицительных чисел. Количество операций ≤ 100.

Формат ввода:
Строка, состоящая их символов “0123456789-+/*()” 
Гарантируется, что входное выражение корректно, нет деления на 0, вычислимо в целых числах.Деление целочисленное.

Формат вывода:
Значение выражения.

Пример 1:
Ввод:
1 + 2
Вывод:
3

Пример 2:
Ввод:
200 - (123 + 34 * 2) + (48 - 2)
Вывод:
55
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <sstream>
#include <stack>
#include <cmath>

using namespace std;


void step(){
    char ch;
    cin >> ch;
}

class Stack{
    vector<char> st;
public:
    char top(){
        if (st.size() == 0)return -1;
        return st[st.size()-1];
    }
    string top_s(){
        if (st.size() == 0)return "#";
        string s = {st[st.size()-1]};
        return s;
    }
    char pop(){
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

int k = 0;





int get_len(int n){
    if (n == 0)return 0;
    return 1+get_len(n/10);
}

int priority(char a)
{
    if(a=='*' || a=='/')
        return 2;
    if(a=='+' || a=='-')
        return 1;
    return 0;
}

char get(string& line){
    if (k  == line.size())return '#';
    return line[k++];
}

int count(vector<string>& expression){
    stack<int> numbers;
    for (auto i: expression){
        if (isdigit(i[0])){
            numbers.push(stoi(i));
        }else{
            switch (i[0]) {
                case '*':{
                    int tt = numbers.top();
                    numbers.pop();
                    tt *= numbers.top();
                    numbers.pop();
                    numbers.push(tt);
                    break;}
                case '+': {
                    int tt = numbers.top();
                    numbers.pop();
                    tt += numbers.top();
                    numbers.pop();
                    numbers.push(tt);
                    break;
                }
                case '-': {
                    int tt = numbers.top();
                    numbers.pop();
                    tt -= numbers.top();
                    numbers.pop();
                    numbers.push(-tt);
                    break;
                }
                case '/': {
                    int tt = numbers.top();
                    numbers.pop();
                    tt = numbers.top()/tt;
                    numbers.pop();
                    numbers.push(tt);
                    break;
                }
            }
        }
    }
    return numbers.top();

}

int toPostfix(string& input) {
    char token;
    vector<string>output;
    Stack stack;
    for(int i = 0; i < input.length(); i++) {

        if(isdigit(input[i])) {
            string buf;
            while(isdigit(input[i])) {
                buf += input[i];
                i++;
            }
            output.push_back(buf);
        }
        token = input[i];
        if(token == '+' || token == '-' || token == '*' || token == '/') {

            if(!stack.empty() && priority(token) <= priority(stack.top())) {
                output.push_back({stack.pop()});
            }
            stack.push(token);
        }
        if(token == '(') {
            stack.push(token);
        }
        if(token == ')') {
            while( stack.top() != '(') {
                output.push_back({stack.pop()});
            }
            stack.pop();
        }
    }
    while(!stack.empty()) {
        output.push_back({stack.pop()});
    }
    return count(output);
}



int main() {
    string input_line;
    getline(cin, input_line);
    cout << toPostfix(input_line);

}
