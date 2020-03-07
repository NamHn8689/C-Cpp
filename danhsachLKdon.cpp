#include <iostream>
#include <stdio.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
};
typedef Node *List;
void Create(List &l)
{
    l = NULL;
}
//chen vao dau list
void addHead(List &l, int x)
{
    Node *q = new Node;
    q->data = x;
    q->next = l;
    l = q;
}
//chen vao cuoi
void addTail(List &l, int x)
{
    Node *q = new Node; //tao 1 node co 1 phan tu data = x
    q->data = x;
    q->next = NULL;
    if (l == NULL)
        l = q;
    else
    {
        Node *p = new Node;
        p = l;
        while (p->next != NULL)
            p = p->next;
        p->next = q;
    }
}
//chen vao giua sau vt k
void addMid(List &l, int x, int k)
{
    //chen node vao sau vt k
    Node *q = new Node; //khoi tao 1 node moi
    q->data = x;
    q->next = NULL;

    Node *p = l;
    int i = 0;
    while (p != NULL)
    {
        if (i == k)
            break;
        i++;
        p = p->next;
    }
    q->next = p->next;
    p->next = q;
}
void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
void sort(List &l)
{
    List p = l;
    List q = p->next;
    while (p->next != NULL)
    {
        q = p->next;
        while (q != NULL)
        {
            if (p->data > q->data)
                swap(p->data, q->data);
            q = q->next;
        }
        p = p->next;
    }
}
void delAt(List &l, int k)
{ //xoa phan tu có data = k;
    List p = l;
    List pre = new Node;
    pre ->next = p;
    while (p != NULL)
    {
        if (p->data == k)
        {
            pre->next = p->next;
            delete p;
            return;
        }
        pre = p;
        p = p->next;
    }
}
void print(List l)
{
    List p = l;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
int main()
{
    List l;
    Create(l);
    addTail(l, 1);
    addTail(l, 2);
    addTail(l, 15);
    addTail(l, 9);
    addTail(l, 4);
    addMid(l, 5, 1);
    sort(l);
    delAt(l, 9);
    print(l);
    return 0;
}