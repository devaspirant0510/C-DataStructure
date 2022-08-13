#include <iostream>
#include "List.hpp"

using namespace std;


void test(){
    LinkedList<int> list;
    int input;
    while(1){
        cout << "========================================================================================" << endl;
        cout <<"| 리스트 프로그램                                                                       |" << endl;
        cout <<"| 1: 삽입, 2:삭제, 3:수정, 4: 인덱스값, 5: 값찾기, 6 : 출력, 7: 크기, 8: 정렬  -1:종료  |" << endl;
        cout << "========================================================================================" << endl;
        cout << "값을 입력하세요...";
        cin >> input;
        if (input==-1){
            cout << "bye bye..." << endl;
            return;
        }
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
        if(input==3){
            int index,value;
            cout << "수정할 값의 위치를 입력하세요 : ";
            cin >> index;
            cout << "수정할 값의 입력하세요 : ";
            cin >> value;
            list.change_list(index, value);
        }
        if(input==4){
            int index;
            cout <<"get index : ";
            cin>>index;
            if(list.get_node(index)!=NULL){
                cout << " you find get value is " << list.get_node(index) <<  endl;
            }else{
                cout << "not have index value " << endl;
            }
        }
        if(input==6){
            list.print_list();
        }
        if(input==7){
            cout << "list size is " << list.get_size() << endl;
        }
        

    }
}


int main(){
    test();
    return 0;
}
