// ex3-1.cpp
#include <iostream>
using namespace std;
struct Node
{
 int data;
 Node *next;
};
void InsertNode(int);
void Display();
int DeleteNode(int);
//global variable root is used to record the head of link list
Node* root = NULL;
Node* tail = NULL;
int main()
{
    size_t i = 0;
    while (1)
    {
        cout << "Please select an option:" << endl
        << "1.Insert a node" << endl
        << "2.Delete a node" << endl
        << "3.Display the list" << endl
        << "4.End" << endl;
        cin >> i;
        int data;
        switch(i)
        {
            case 1: 
                cout << "Please enter the number:" << endl;
                cin >> data;
                InsertNode(data);
                break;
            case 2:
                cout << "Please enter the number:" << endl;
                cin >> data;
                if ( !DeleteNode(data) )
                cout << "Failed to delete node " << data << endl;
                break;
            case 3:
                Display();
                break;
            case 4:
                return 0;
            default:
                break;
        }
        cout << "tail data: " << tail->data << endl;
    }
}

void InsertNode(int data)
{
    Node *tmp = new Node;
    tmp->data = data;
    tmp->next = NULL;

    if (root == NULL)
    {
        root = tmp;
        tail = tmp;
        tmp = NULL;
        //cout << tail->data << endl;
    }
    else
    {
        tail->next = tmp;
        tail = tmp;
        //cout << "tmp-> data: " << tmp->data << endl;
        tmp = NULL; 
    }
    //delete tmp;
    //tmp = NULL;
     
}

void Display()
{
    Node *tmp = new Node; 
    tmp = root;
    while (tmp != NULL)
    {
        cout << tmp->data << "->";
        tmp = tmp->next;
    }
    cout << endl;
}

int DeleteNode(int num)
{
    Node *current = new Node;
    Node *previous  = new Node;
    current = root;
    if (num == 1)
    {
        if (root == NULL) return 0;
        root = current -> next;
        return 1; 
    }
    else
    { 
        for (int i=1; i<num; i++)
        {
            previous = current;
            current = current->next;
            if (current == NULL)
                return 0;   
        }
        previous->next = current->next;
        if (previous->next == NULL)
        {
            tail = previous; 
        } 
        return 1;
    }
}

