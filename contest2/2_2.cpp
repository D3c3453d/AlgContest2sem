/*
������ ����� ���������� �������������� ���� ��� ����� ������, ����� ��� ����� ��������� ������. 
��� ����� � ���� ������ ������� �� ��� ������ ���� ��� ����������� 18 ���, �� ��� �� ����������� 80 ���. 
��� ������ ����� ������� �����. ���������� �������� ������������ ���������� �������������. 
� ���� 18����� ������� ��� ����� ��������� ������� � ���������, � � ���� 80����� � � ���� ������ ��� �� �����.
���������: ������� ��� �� ������ �� 18-�����, ���� ������� � ���� 18-�����. � ���� ������� ��������� ������� � ��������� �� �� ���.

������:
����:
3
2 5 1980 13 11 2055
1 1 1982 1 1 2030
2 1 1920 2 1 2000

�����:
3

*/

#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int max(int a, int b){
    if (a > b)return a;
    return b;
}

struct Date{
    int day = 0, month = 0, year = 0;
    Date()= default;;
    Date(int day, int month, int year):day{day}, month{month}, year{year}{};
    bool operator<(Date p){
        if (year == p.year){
            if (month == p.month)return day < p.day;
            return month < p.month;
        }
        return year<p.year;
    }
    bool operator==(Date& p){
        return (year == p.year)&&(month == p.month)&&(day == p.day);
    }
    Date years_18(){
        return Date{day, month, year+18};
    }
    Date years_80(){
        return Date{day, month, year+80};
    }
};

Date min_date(Date a, Date& b){
    if (a < b)return a;
    return b;
}

struct Person{
    Date born, dead;
    Person() = default;
    bool operator<(Person& p){
        if (born == p.born){
            return dead < p.dead;
        }
        return born<p.born;
    }
};

bool cmp(pair<Date, int>& a, pair<Date, int>& b){
    if (a.first == b.first)return a.second > b.second;
    return a.first < b.first;
}



std::istream& operator>> (std::istream &in, Date &p)
{
    in >> p.day >> p.month >> p.year;
    return in;
}
std::istream& operator>> (std::istream &in, Person &p)
{
    in >> p.born >> p.dead;
    return in;
}

int main(){
    int n;
    cin >> n;
    vector<pair<Date, int>> arr;
    Date born, dead;
    for (int i = 0; i < n; ++i) {
        cin >> born;
        arr.emplace_back(born.years_18(), -1);
        cin >> dead;
        if (dead < born.years_18()){
            arr.pop_back();
            continue;
        }
        arr.emplace_back(min_date(born.years_80(), dead), +1);

    }
    sort(arr.begin(), arr.end(), cmp);
    int max_c = 1, c = 0;
    for (auto i: arr){
        c-=i.second;
        max_c = max(max_c, c);
    }
    cout << max_c;
}