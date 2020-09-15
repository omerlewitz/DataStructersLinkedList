#include <iostream>

using namespace std;

struct Node
{
    int _data;
    struct Node *_next;
};
//================================
void print_list(const struct Node *head);
struct Node *build_sorted_list();

//================================

int main ()
{
     struct Node *head=NULL;
     head=build_sorted_list();
     print_list(head);
}
struct Node *build_sorted_list(){
     struct Node *head =NULL,
                 *temp,
                 *rear,
                 *front;

    int num;

    cin >> num;
    while(num !=0)
    {
        temp = new(std::nothrow) struct Node;
        if(temp==NULL)
        {
            cerr << "Cannot allocate memory\n";
            exit(EXIT_FAILURE);
        }
        temp->_data = num;

        //First element
        if(head==NULL){
        temp ->_next = head;
        head = temp;
        }
        else if(num <= head->_data){
        temp ->_next = head;
        head = temp;
        }
        else{
            rear=head;
            front =rear->_next;
            while(front!=NULL && front->_data <=num){
                rear=front;
                front=front->_next;
            }
            rear->_next=temp;
            temp->_next=front;
        }

        cin >> num;
    }
    return head;
}
//============================
void print_list(const struct Node *head)
{

    while(head!= NULL)
    {
        cout << head->_data << " ";
        head = head->_next;
    }
    cout<<endl;
}
