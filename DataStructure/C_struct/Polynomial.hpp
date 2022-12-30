#include <iostream>

#define MAX_DEGREE 100

using namespace std;

struct expression{
    int degree;
    float coef[MAX_DEGREE];
};

class Polynomial{
    private:
        expression* exp=nullptr;
    public:
        Polynomial();
        Polynomial(expression*);
        ~Polynomial();
        expression* input();
        void print();
        void op_machine();
        friend Polynomial operator+(Polynomial a,Polynomial b);
        friend Polynomial operator*(Polynomial a,Polynomial b);
        friend ostream& operator<<(ostream&,Polynomial);

};

Polynomial::Polynomial(expression* exp){
    this->exp = exp;

}

Polynomial::Polynomial(){
}

Polynomial::~Polynomial(){
    // cout << "destroy"<< endl;
    // exp = NULL;
}
void Polynomial::op_machine(){
    char input_data;
    while(1){
        cin >> input

    }
}


ostream& operator<<(ostream& out,Polynomial poly){
    poly.print();
    return out;
}
Polynomial operator*(Polynomial a,Polynomial b){
    Polynomial res;
    expression* res_exp = new expression;
    res.exp = res_exp;
    if (a.exp->degree>b.exp->degree){
        res.exp->degree = a.exp->degree+b.exp->degree;
        int size = res.exp->degree; 
        int s = 0;
        for(int i=0; i<a.exp->degree; i++){
            for(int j=0; j<b.exp->degree; j++){
                res.exp->coef[size-((a.exp->degree-i)+(b.exp->degree-i))] +=a.exp->coef[i]*b.exp->coef[i];
            }
        }
    }else{
        res = b;
        for (int i=0; i<b.exp->degree; i++){
            res.exp->coef[i+(b.exp->degree-a.exp->degree)]*=a.exp->coef[i];
        }
    }
    return res;
}

Polynomial operator+(Polynomial a,Polynomial b){
    Polynomial res;
    expression* res_exp = new expression;
    res.exp = res_exp;
    // a 의 차수가 더 클경우
    if (a.exp->degree>b.exp->degree){
        res = a;
        for (int i=0; i<b.exp->degree; i++){
            // a 차수 - b 차수 => 연산되는 차수
            res.exp->coef[i+(a.exp->degree-b.exp->degree)]+=b.exp->coef[i];
        }
    }else{
        res = b;
        for (int i=0; i<b.exp->degree; i++){
            res.exp->coef[i+(b.exp->degree-a.exp->degree)]+=a.exp->coef[i];
        }

    }
    delete res_exp;
    return res;
    // if(a.exp->degree<b.exp->degree){
    //     Polynomial tmp;
    //     tmp = a;
    //     a=b;
    //     b=tmp;
    // }
    // int size=a.exp->degree;
    // Polynomial result;
    // expression *setting = new expression;
    // setting->degree = size;
    // result.exp = setting;
    // int s = 0;
    // int p=0;
    // for(int i=size; i>0; i--){
    //     cout << result.exp->coef[s] << " " << a.exp->coef[s] << " "<<b.exp->coef[s]<< endl;
    //     if(i<=b.exp->degree){
    //         result.exp->coef[s] = a.exp->coef[s]+b.exp->coef[p];
    //         p++;
    //     }else{
    //         result.exp->coef[s] = a.exp->coef[s];
    //     }
    //     s+=1;
    // }
    // return result;
}
void Polynomial::input(){
    expression* exp = new expression;
    int n;
    int el;
    cin >> n;
    exp->degree = n;
    for(int i=0; i<n; i++){
        cin >> el;
        exp->coef[i] = el;
    }
    this->exp = exp;
}
void Polynomial::print(){
    if(exp==NULL){
        return;
    }
    int n = exp->degree;
    cout << "n: " << exp->degree<< endl;
    
    for (int i=0; i<exp->degree; i++){
        if(exp->coef[i]==1){
            cout << "x^"<< n-i << " + ";
        }else{
            cout << exp->coef[i]<< "x^"<< n-i << " + ";
        }
    }
    cout << endl;
}