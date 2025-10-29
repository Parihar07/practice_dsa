//
//  main.cpp
//  LL_ver2
//
//  Created by CodeBreaker on 16/12/24.
//

#include <iostream>
using namespace std;
class Node {
public:
    int val;
    Node *next;
    Node(int v) : val(v), next(NULL){}
};

class LinkedList{
private:
    Node *head;
    Node *tail;
    int len;
public:
    LinkedList(int v);
    void append(int v);
    void deleteLast();
    void deleteFirst();
    void prepend(int v);
    Node *get(int ind);
    bool set(int ind, int v);
    bool insert(int ind, int v);
    void deleteNode(int ind);
    void reverse();
    Node *findMiddle();
    void printLL();
};

LinkedList::LinkedList(int v)
{
    Node *nwNode = new Node(v);
    head = nwNode;
    tail = nwNode;
    len=1;
}

void LinkedList::append(int v)
{
    Node* nwNode = new Node(v);
    if(len==0)
    {
        head = nwNode;
        tail = nwNode;
    } else {
        tail->next = nwNode;
        tail = nwNode;
    }
    len+=1;
}

void LinkedList::deleteLast()
{
    if(len==0) return;
    Node *tmp = head;
    if(len==1)
    {
        head = NULL;
        tail = NULL;
    } else {
        Node *prev = head;
        while(tmp->next!=NULL)
        {
            prev = tmp;
            tmp=tmp->next;
        }
        tail = prev;
        tail->next=NULL;
    }
    delete tmp;
    len-=1;
}

void LinkedList::deleteFirst()
{
    if(len == 0) return;
    Node *tmp = head;
    head=head->next;
    len-=1;
    if(len==0) tail = NULL;
    delete tmp;
}

void LinkedList::prepend(int v)
{
    Node *nwNode = new Node(v);
    if(len==0)
    {
        head = nwNode;
        tail = nwNode;
    } else {
        nwNode->next = head;
        head = nwNode;
    }
    len+=1;
}

Node* LinkedList::get(int ind)
{
    if(ind<0 || ind>len) return NULL;
    Node *tmp = head;
    for(int i=0;i<ind;i++)
    {
        tmp=tmp->next;
    }
    return tmp;
}

bool LinkedList::set(int ind, int v)
{
    if(ind<0 || ind >len) return false;
    Node * tmp = get(ind);
    if(tmp!=NULL)
    {
        tmp->val=v;
        return true;
    }
    return false;
}

bool LinkedList::insert(int ind, int v)
{
    if(ind <0 || ind>=len) return false;
    if(ind == 0) {
        prepend(v);
        return true;
    }
    if(ind == len)
    {
        append(v);
        return true;
    }
    Node *prev = get(ind-1);
    Node *nwNode = new Node(v);
    nwNode->next=prev->next;
    prev->next=nwNode;
    return true;
}

void LinkedList::deleteNode(int ind)
{
    if(ind<0||ind>=len) return;
    if(ind==0) return deleteFirst();
    if(ind==len-1) return deleteFirst();
    Node *prev = get(ind-1);
    Node *tmp = prev->next;
    prev->next= tmp->next;
    len-=1;
    delete tmp;
}

void LinkedList::printLL()
{
    if(len==0) return;
    Node *tmp=head;
    while(tmp!=NULL)
    {
        cout<<tmp->val<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
}
Node* LinkedList::findMiddle()
{
    if(len==0) return NULL;
    Node *mid= head;
    Node *fast=NULL;
    if(head->next!=NULL)
    {
        fast = head->next->next;
    }
    while(fast!=NULL && fast->next!=NULL)
    {
        mid=mid->next;
        fast= fast->next->next;
    }
    return mid;
}
void LinkedList::reverse()
{
    Node* tmp = head;
    head = tail;
    tail = tmp;
    Node *A=tmp->next, *B=NULL; // A- After pointer, B- Before pointer
    for(int i=0;i<len;i++)
    {
        A=tmp->next;
        tmp->next = B;
        B = tmp;
        tmp=A;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Linked list version 2.0!\n";
    
    LinkedList *LL = new LinkedList(1);
    LL->append(2);
    LL->append(3);
    LL->append(4);
//    LL->append(5);
//    LL->append(6);
//    LL->append(7);
//    LL->append(8);
//    LL->append(9);
//    LL->append(10);
    LL->printLL();
//    LL->reverse();
    LL->printLL();
    
    
    cout<<"ans : "<<LL->findMiddle()->val<<endl;
    
    return 0;
}
