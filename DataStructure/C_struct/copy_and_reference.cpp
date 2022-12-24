#include <iostream>
#include <cstring>

using namespace std;

void print_arr(int*,int);
int main(){
    int v_a = 2023;
    int v_b;
    v_b = v_a;
    cout << "va : " << v_a << "\t vb : " << v_b << endl;
    cout << "if change value 'v_a' to 2024... (it works v_a = 2024;)" << endl;
    v_a = 2024;
    cout << "va : " << v_a << "\t vb : " << v_b << endl;
    cout << endl;

    int r_arr_1[4] = {3,2,5,15};
    int r_arr_2[4];
    int* pt_r_arr1 = r_arr_1;
    int* pt_r_arr2 = r_arr_2; 

    // refrence copy issue
    pt_r_arr2 = pt_r_arr1;
    cout << "rar1 : " << pt_r_arr1 << "\t value: ";
    print_arr(pt_r_arr1,4);
    cout << "rar2 : " << pt_r_arr2 <<"\t value: " ;
    print_arr(pt_r_arr2,4);
    cout << "both value are sucessful copies but both value refrence same address" << endl;
    cout << "In this case, if you change the value of v_a, the value of v_b is also changed because they refer to the same address." << endl;
    r_arr_1[2] = 365;
    cout << "rar1 : " << pt_r_arr1 << "\t value: ";
    print_arr(pt_r_arr1,4);
    cout << "rar2 : " << pt_r_arr2 <<"\t value: " ;
    print_arr(pt_r_arr2,4);
    cout << endl;

    // solution
    // case 1;
    int s1_arr1[4] = {1,2,3,4};
    int s1_arr2[4];
    for (int i=0; i<4; i++){
        s1_arr2[i] = s1_arr1[i];
    }
    cout << "s1_arr1 adr : " << s1_arr1 << "\t value : ";
    print_arr(s1_arr1,4);
    cout << "s1_arr2 adr : " << s1_arr2 << "\t value : ";
    print_arr(s1_arr2,4);
    cout << "both value has different address reference, therefore if you changed value copied value not "<< endl;
    cout << "So even if you change the values ​​in the array, the copied values ​​will not be affected." << endl;
    s1_arr1[1] = 12;
    cout << "s1_arr1 adr : " << s1_arr1 << "\t value : ";
    print_arr(s1_arr1,4);
    cout << "s1_arr2 adr : " << s1_arr2 << "\t value : ";
    print_arr(s1_arr2,4);
    cout << endl;

    // case2
    cout << " use memcpy function in cstring header(in C string.h)" << endl;
    cout << "memcpy( copied value, value, value size(in byte))" << endl;
    int s2_arr1[4] = {1,2,3,4};
    int s2_arr2[4];
    memcpy(s2_arr2,s2_arr1,sizeof(int)*4);
    cout << "s2_arr1 adr : " << s2_arr1 << "\t value : ";
    print_arr(s2_arr1,4);
    cout << "s2_arr2 adr : " << s2_arr2 << "\t value : ";
    print_arr(s2_arr2,4);
    s2_arr1[3] = 999;
    cout << "s2_arr1 adr : " << s2_arr1 << "\t value : ";
    print_arr(s2_arr1,4);
    cout << "s2_arr2 adr : " << s2_arr2 << "\t value : ";
    print_arr(s2_arr2,4);




    return 0;
}
void print_arr(int *arr,int size){
    for (int i=0; i<size;i++){
        cout << *(arr+i) << " ";
    }
    cout << endl;
}