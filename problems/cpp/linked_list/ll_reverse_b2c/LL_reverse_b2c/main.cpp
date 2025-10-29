//
//  main.cpp
//  LL_reverse_b2c
//
//  Created by CodeBreaker on 17/01/25.
//

#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int v): val(v),next(NULL){}
};

class LinkedList{
    Node *head;
    Node *tail;
    int size;
    Node *reverseK(Node *h, int k);
public:
    LinkedList(int v)
    {
        head = new Node(v);
        tail = head;
        size = 1;
    }
    LinkedList():head(NULL),tail(NULL),size(0){}
    void insert_node(int pos, int v);
    void delete_node(int pos);
    void prepend(int v);
    void append(int v);
    friend ostream &operator<<(ostream &os, const LinkedList &obj);
    void reverseKgroups(int k);
    void reverseB2C(int B, int C);
    
};

void LinkedList::insert_node(int pos, int v)
{
//    if(head==NULL) return;
    
    if(pos==1)
    {
        prepend(v);
        return;
    }
    if(pos==size)
    {
        append(v);
        return;
    }
    if(pos>size+1 || pos<1) return;
    int cnt=1;Node* tmp=head, *prev=NULL;
    while(tmp!=NULL && cnt!=pos)
    {
        prev=tmp;
        tmp=tmp->next;cnt+=1;
    }
    Node *nwNode = new Node(v);
    nwNode->next=tmp;
    prev->next=nwNode;
    size+=1;
}
void LinkedList::delete_node(int pos)
{
    if(head==NULL) return;
    if(pos>size || pos<1) return;
    Node *tmp = head, *prev=NULL;
    if(pos==1)
    {
        head=head->next;
        delete(tmp);
        tmp=NULL;
        size-=1;
        return;
    }
    int cnt=1;
    while(tmp!=NULL && cnt!=pos)
    {
        prev=tmp;
        tmp=tmp->next;
        cnt+=1;
    }
    prev->next=tmp->next;
    delete(tmp);
    tmp=NULL;
    size-=1;
}
ostream &operator<<(ostream &os, const LinkedList &obj)
{
    if(obj.head==NULL){
        os<<"Empty List\n";
        return os;
    }
    Node *tmp = obj.head;
    while(tmp)
    {
        os<<tmp->val;
        tmp=tmp->next;
        if(tmp) os<<"->";
    }
    os<<endl;
    return os;
}
void LinkedList::prepend(int v)
{
    Node* nwNode = new Node(v);
    if(head==NULL)
    {
        head = nwNode;
        tail = head;
        size+=1;
        return;
    }
    nwNode->next=head;
    head=nwNode;
    size+=1;
}
void LinkedList::append(int v)
{
    Node *nwNode = new Node(v);
    
    if(head==NULL)
    {
        head = nwNode;
        tail = head;
        size+=1;
        return;
    }
    
    tail->next=nwNode;
    tail=tail->next;
    size+=1;
}

Node* LinkedList::reverseK(Node *h, int k)
{
    if(h==NULL) return NULL;
    Node* prev=NULL, *fwd=h, *th = h, *curr=h;
    int i=0;
    while(curr!=NULL && i<k)
    {
        fwd=fwd->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
        i++;
    } //MLA071623340
    Node* sh = reverseK(curr, k);
    th->next = sh;
    return prev;
}

void LinkedList::reverseKgroups(int k)
{
    head = reverseK(head, 3);
}

void LinkedList::reverseB2C(int B, int C)
{
    Node *prev=NULL,*curr=NULL,*fwd=NULL;
    Node *S=NULL,*E=NULL;
    Node *P1=NULL;
    int i=0;
    curr=head;
    while(curr!=NULL)
    {
        i+=1;
        if(i==B)
        {
            P1=prev;
            S=curr;
        }
        if(i==C)
        {
            E=curr;
        }
        prev=curr;
        curr=curr->next;
    }
    if(E!=NULL) E=E->next;
    prev=NULL;
    curr=S;
    fwd=S;
    while(curr!=E)
    {
        fwd=fwd->next;
        curr->next=prev;
        prev=curr;
        curr=fwd;
    }
    if(P1!=NULL)
    {
        P1->next = prev;
    } else {
        head = prev;
    }
    S->next=curr;
}
LinkedList LL;

void insert_node(int position, int value) {
    // @params position, integer
    // @params value, integer
    LL.insert_node(position, value);
}

void delete_node(int position) {
    // @params position, integer
    LL.delete_node(position);
}

void print_ll() {
    // Output each element followed by a space
    cout<<LL<<endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Reversing form B to C!\n";
    insert_node(1, 13);
    insert_node(2, 14);
    insert_node(3, 15);
    insert_node(4, 16);
    insert_node(5, 17);
    insert_node(6, 18);
    insert_node(7, 19);
    insert_node(8, 20);
    print_ll();
    LL.reverseB2C(3, 10);
    print_ll();
    return 0;
}
