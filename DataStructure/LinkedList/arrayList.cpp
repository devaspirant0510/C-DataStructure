#include <iostream>
#define MAX 10

using namespace std;

int myList[MAX];
int length = 0;

int get_size(int *);
void insert_arr(int, int, int *);
void remove_arr(int, int *);
int get_entry(int, int *);
int find_entry(int, int *);
int is_full();
int is_empty();
void print_list(int *);
void list_test();

int main()
{
    list_test();
    return 0;
}
void list_test()
{
    while (true)
    {
        cout << "list program : " << endl;
        cout << "add : 1, remove :2, find: :3, get_entry:4, print: 5, exit :6" << endl;
        cout << endl
             << endl;

        int user_input;
        cin >> user_input;
        switch (user_input)
        {
        case 1:
        {
            int input_value, index_value;
            cout << "input value :...";
            cin >> input_value;
            cout << "index number to index (-1 is list`s last index to insert ) : ";
            cin >> index_value;
            if(index_value==-1){
               // insert_arr(length,)

            }else{
            insert_arr(index_value, input_value, myList);
            }
            break;
        }
        case 2:
        {
            int index_value;
            cout << "input to remove index value : ";
            cin >> index_value;
            remove_arr(index_value, myList);
            break;
        }
        case 3:
        {
            int find_value;
            cout << "input to find value";
            cin >> find_value;
            cout << "you find value result is " << (string)(find_entry(find_value, myList)==1?"true":"false");
            break;
        }
        case 4:
        {
            int index_value;
            cout << "input to get entry value : ";
            cin >> index_value;
            cout << "value is :" <<get_entry(index_value, myList)<<endl;
            break;
        }
        case 5:
        {
            print_list(myList);
            break;
        }
        case 6:
        {
            cout << " bye bye " << endl;
            return;
        }
        default:
            break;
        }
    }
}

int get_size(int *arr)
{
    return length;
}
int is_full()
{
    return MAX == length;
}

void insert_arr(int index, int val, int *arr)
{
    if (is_full() || length == MAX - 1)
    {
        cout << "list is full" << endl;
        return;
    }
    if (length < index)
    {
        cout << "The index to be inserted into the list cannot be greater than the length of the list." << endl;
        return;
    }
    if (index < 0)
    {
        cout << "index is not smaller than zero" << endl;
        return;
    }
    length++;
    for (int i = length; i >= index; i--)
    {
        int temp = myList[i + 1];
        myList[i + 1] = myList[i];
        myList[i] = temp;
    }
    myList[index] = val;
    cout << " result is : ";
    cout << endl;
}
void remove_arr(int index, int *list)
{
    if (length < index)
    {
        cout << "The index to be inserted into the list cannot be greater than the length of the list." << endl;
        return;
    }
    if (index < 0)
    {
        cout << "index is not smaller than zero" << endl;
        return;
    }
    for (int i = index; i < length; i++)
    {
        int temp = list[i + 1];
        list[i + 1] = list[i];
        list[i] = temp;
        print_list(list);
    }
    length--;
    cout << " result is : ";
    print_list(list);
    cout << endl;
}
int get_entry(int index, int *list)
{
    return list[index];
}
int find_entry(int find_value, int *list)
{
    for (int i = 0; i < length; i++)
    {
        if (list[i] == find_value)
        {
            return 1;
        }
    }
    return 0;
}
void print_list(int *list)
{
    cout << " | ";
    for (int i = 0; i < length; i++)
    {
        cout << list[i] << " | ";
    }
    cout << endl;
}
