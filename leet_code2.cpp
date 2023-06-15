#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

typedef node* n;

n make_node(n a,int x)
{
    a->data = x;
    a->next = NULL;
}

void insert_begin(n &a,int x)
{
    n insert = new node();
    make_node(insert,x);
    if(a==NULL) a = insert;
    else
    {
        insert->next = a;
        a = insert;
    }
}


void process(n a)
{
    n p = a;
    while(p!=NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int cnt(n a)
{
    int count = 0;
    n p;
    p = a;
    while(p!=NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

n merge_linked_list(n a,n b)
{
    if(!a) return b; // nếu a là rỗng , trả về b và ngược lại
    if(!b) return a;

    n head = a;
    if(a->data > b->data)
    {
        head = b;
        b = b->next;
    }
    else a = a->next;

    n curr = head;
    while(a&&b)
    {
        if(a->data < b->data)
        {
            curr->next = a;
            a = a->next;
        }
        else
        {
            curr->next = b;
            b = b->next;
        }
        curr = curr->next;
    }
    if(!a) curr->next = b;
    else curr->next = a;
    return head;
}

n merge_linked_list1(n a,n b)
{
    if(!a) return b;
    if(!b) return a;
    n head = a;
    if(a->data > b->data)
    {
        head = b;
        b = b->next;
    }
    else a = a->next;
    n curr = head;
    while(a&&b)
    {
        if(a->data < b->data)
        {
            curr->next = a;
            a = a->next;
        }
        else
        {
            curr->next = b;
            b = b->next;
        }
        curr = curr->next;
    }
    if(!a) curr->next = b;
    else curr -> next = a;
    return head;
}

n merge_linked_list2(n a,n b)
{
    if(!a) return b;
    if(!b) return a;
    n head = a;
    if(a->data > b->data)
    {
        head = b;
        b = b->next;
    }
    else a = a->next;
    n curr = head;
    while(a&&b)
    {
        if(a->data < b->data)
        {
            curr->next = a;
            a = a->next;
        }
        else
        {
            curr->next = b;
            b = b->next;
        }
        curr = curr->next;
    }
    if(!a) curr->next = b;
    else curr->next = a;
    return head;
}

int main()
{
    system("cls");
    int l1[] = {1,2,4};
    int l2[] = {1,3,4};
    n a = new node();
    n b = new node();
    n result = new node();
    a = NULL;
    b = NULL;
    result = NULL;
    for(int i = 2;i>=0;i--)
    {
        insert_begin(a,l1[i]);
        insert_begin(b,l2[i]);
    }
    result = merge_linked_list2(a,b);
    process(result);
    return 0;
}