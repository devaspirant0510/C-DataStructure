#include <iostream>
#include "List.hpp"

using namespace std;


void test(){
    LinkedList<int> list;
    int input;
    while(1){
        cout <<"리스트 프로그램" << endl;
        cout <<"1: 삽입, 2:삭제, 3:수정, 4: 인덱스값, 5: 값찾기, 6 : 출력, 0:종료"<< endl;
        cin >> input;
        if(input==1){
            int index,value;
            cout << "삽입할 위치를 입력하세요 : ";
            cin >> index;
            cout <<"삽입할 값을 입력하세요 : ";
            cin >> value;
            list.insert_list(index,value);
        }
        if(input==2){
            int index;
            cout << "삭제할 위치를 입력하세요 : ";
            cin >> index;
            int result = list.remove_list(index);
            cout << "remove value : " << result << endl;
        }
        if(input==4){
            int index;
            cout <<"get index : ";
            cin>>index;
            cout << " you find get value is " << list.get_list(index) <<  endl;
        }
        if(input==6){
            list.print_list();
        }
        

    }
}


int main(){
    test();
    return 0;
}
