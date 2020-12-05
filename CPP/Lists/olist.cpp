
#include <iostream>
 
using namespace std;
 
template <typename T>
class List
{
    struct Node
    {
        T data;
        Node *next;
        Node(T d, Node *n = 0):data(d), next(n) {}
    };
    Node *head;
public:
    List(Node *h = 0):head(h){}
    ~List();
    bool isEmpty();
    void insertAfter(Node *pre, T d);
    void removeAfter(Node *pre);
    void pushFront(T d);
    T popFront();
    void print();
    Node *search(T d);
    void removeDuplicate();
    void create(int k);
};
 
template <typename T>
List<T>::~List()
{
    while (!isEmpty())
       popFront();
}
 
template <typename T>
bool List<T>::isEmpty() 
{
    return !head;
}
 
template <typename T>
void List<T>::insertAfter(Node *pre, T d) 
{ 
    if(!pre) return;
    Node *newNode = new Node(d,0);
    newNode->next = pre->next;
    pre->next = newNode;
}
 
template <typename T>
void List<T>::removeAfter(Node *pre)
{
    if (!pre || !pre->next) return;
    Node *tmp = pre->next; 
    pre->next = pre->next->next;
    delete tmp;
}
 
template <typename T>
void List<T>:: pushFront(T d)
{
    Node *newNode = new Node(d,0);
    if(!head) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}
 
template <typename T>
T List<T>:: popFront()
{
    T data;                 
    if(!head) return data;
    Node *tmp = head;
    data = head->data;
    if(head->next) {
        head = head->next;
        delete tmp;
        return data;
    }
    delete tmp;
    head = NULL;
    return data;
}
 
template <typename T>
typename List<T>::Node* List<T>::search(T d)
{
    if(!head) return NULL;
    Node* cur = head;
    while(cur) {
        if(cur->data == d) return cur;
        cur = cur->next;
    }
    return NULL;
}
 
 
template <typename T>
void List<T>:: print()
{
    if(!head) return;
    Node *cur  = head;
    while(cur) {
        cout << cur->data << "; ";
        cur = cur->next;
    }
    cout << endl;
}
 
template <typename T>
void List<T>::create(int k)
{
    T d;
    for (int i = 1; i <= k; i++)
    {
        cout << "Enter " << i << "-i element: ";
        cin >> d;
        pushFront(d);
        
    }
}
