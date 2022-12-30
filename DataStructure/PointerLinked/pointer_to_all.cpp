#include <iostream>

using namespace std;

struct Phone{
    int serial_num;
    char *phone_number;
    char *host;
    char *ip;
};

void callPhone1(Phone p){
    cout << "params size : " << sizeof(p) << endl;
    cout << "serial num : " << p.serial_num << endl;
    cout << "phone_number : " << p.phone_number << endl;
    cout << "host : " << p.host << endl;
    cout << "ip : " << p.ip << endl << endl;
}
// pass to pointer 방식 : 인자로 넘긴 포인터 주소를 복사해 새로 할당, 즉 함수내 파라미터 포인터가 인자값을 가르킴
void callPhone2(Phone *p){
    cout << "params size : " << sizeof(p) << endl;
    cout << p << endl;
    cout << p->serial_num << endl;
    cout << p->phone_number << endl;
    cout << p->host << endl;
    cout << p->ip << endl << endl;
}

// pass to reference 방식 : 인자의 주소와 파라미터의 주소가 같음
void callPhone3(Phone &p){
    cout << "params size : " << sizeof(p) << endl;
    cout << &p << endl;
    cout << p.serial_num << endl;
    cout << p.phone_number << endl;
    cout << p.host << endl;
    cout << p.ip << endl << endl;
    p.serial_num = 2;
}

void callPhone4(Phone *p){
    cout << "params size : " << sizeof(p) << endl;
    cout << p << endl;
}

int main(){
    Phone p1;
    p1.serial_num = 1234921;
    char pn[20] = "010-4111-5077";
    char h[20] ="seungho";
    char ip[20] = "127.0.0.1";
    p1.phone_number = pn;
    p1.host = h;
    p1.ip = ip;
    callPhone1(p1);
    callPhone2(&p1);
    cout << &p1 << endl;
    callPhone3(p1);
    callPhone1(p1);
    callPhone2(&p1);
    return 0;
}


