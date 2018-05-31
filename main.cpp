#include <iostream>
#include <vector>

#include "myvector.h"
#include "Timer.h"

class Test{
    std::string as;
    std::string mmm;
    std::vector<int> nDarbai;
    double egzam;
};

using namespace std;
int main() {
    double spent = 0;

    cout << "|Duomenu kiekis                    |PVector     |std::vector     |" <<  endl;
    cout << "|----------------------------------|-----------------|----------------|" <<  endl;
    cout << "| n = 10000 |";
    for (int j = 0; j < 10; ++j) {
        Timer t{};
        Vector<Test> v2;
        for (int i = 1; i <= 10000; ++i)
            v2.push_back(Test());
        spent += t.getTime();
    }
    cout << " " << spent/10 << " s. |";
    spent = 0;
    for (int j = 0; j < 10; ++j) {
        Timer t{};
        std::vector<int> v2;
        for (int i = 1; i <= 10000; ++i)
            v2.push_back(i);
        spent += t.getTime();
    }
    cout << " " << spent/10 << " s. |" << endl;
    cout << "| n = 100000 |";
    spent = 0;
    for (int j = 0; j < 10; ++j) {
        Timer t{};
        Vector<int> v2;
        for (int i = 1; i <= 100000; ++i)
            v2.push_back(i);
        spent += t.getTime();
    }
    cout << " " << spent/10 << " s. |";
    spent = 0;
    for (int j = 0; j < 10; ++j) {
        Timer t{};
        std::vector<int> v2;
        for (int i = 1; i <= 100000; ++i)
            v2.push_back(i);
        spent += t.getTime();
    }
    cout << " " << spent/10 << " s. |" << endl;
    cout << "| n = 1000000 |";
    spent = 0;
    for (int j = 0; j < 10; ++j) {
        Timer t{};
        Vector<int> v2;
        for (int i = 1; i <= 1000000; ++i)
            v2.push_back(i);
        spent += t.getTime();
    }
    cout << " " << spent/10 << " s. |";
    spent = 0;
    for (int j = 0; j < 10; ++j) {
        Timer t{};
        std::vector<int> v2;
        for (int i = 1; i <= 1000000; ++i)
            v2.push_back(i);
        spent += t.getTime();
    }
    cout << " " << spent/10 << " s. |" << endl;
    cout << "| n = 10000000 |";
    spent = 0;
    for (int j = 0; j < 10; ++j) {
        Timer t{};
        Vector<int> v2;
        for (int i = 1; i <= 10000000; ++i)
            v2.push_back(i);
        spent += t.getTime();
    }
    cout << " " << spent/10 << " s. |";
    spent = 0;
    for (int j = 0; j < 10; ++j) {
        Timer t{};
        std::vector<int> v2;
        for (int i = 1; i <= 10000000; ++i)
            v2.push_back(i);
        spent += t.getTime();
    }
    cout << " " << spent/10 << " s. |" << endl;
    cout << "| n = 100000000 |";
    spent = 0;
    for (int j = 0; j < 10; ++j) {
        Timer t{};
        Vector<int> v2;
        for (int i = 1; i <= 100000000; ++i)
            v2.push_back(i);
        spent += t.getTime();
    }
    cout << " " << spent/10 << " s. |";
    spent = 0;
    for (int j = 0; j < 10; ++j) {
        Timer t{};
        std::vector<int> v2;
        for (int i = 1; i <= 100000000; ++i)
            v2.push_back(i);
        spent += t.getTime();
    }
    cout << " " << spent/10 << " s. |" << endl;


    cout << "return'as" << endl;
    return 0;
}