#include <iostream>

#define MAX_DEGREE 100

using namespace std;

struct expression{
    int degree;
    float coef[MAX_DEGREE];
};
class Polynomial{
    private:
        expression exp;
    public:
        void input();
        void print();

};
void Polynomial::input(){
    int n;
    int el;
    cin >> n;
    this->exp.degree = n;
    for(int i=0; i<n; i++){
        cin >> el;
        this->exp.coef[i] = el;
    }
}
void Polynomial::print(){
    cout << "n: " << exp.degree;
    for (int i=0; i<exp.degree; i++){
        cout << exp.coef[i];
    }
}