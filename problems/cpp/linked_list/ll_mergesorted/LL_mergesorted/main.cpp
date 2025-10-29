//
//  main.cpp
//  LL_mergesorted
//
//  Created by CodeBreaker on 14/01/25.
//


/*
 Merge Two Sorted Lists
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Merge two sorted linked lists, A and B, and return it as a new list.
 The new list should be made by splicing together the nodes of the first two lists and should also be sorted.


 Problem Constraints
 0 <= |A|, |B| <= 105


 Input Format
 The first argument of input contains a pointer to the head of linked list A.
 The second argument of input contains a pointer to the head of linked list B.


 Output Format
 Return a pointer to the head of the merged linked list.


 Example Input
 Input 1:
  A = 5 -> 8 -> 20
  B = 4 -> 11 -> 15
 Input 2:
  A = 1 -> 2 -> 3
  B = Null


 Example Output
 Output 1:
  4 -> 5 -> 8 -> 11 -> 15 -> 20
 Output 2:
  1 -> 2 -> 3


 Example Explanation
 Explanation 1:
  Merging A and B will result in 4 -> 5 -> 8 -> 11 -> 15 -> 20
 Explanation 2:
  We don't need to merge as B is empty.
 */


#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
    Node() = default;
};

class LinkedList{
private:
    Node *head;
    Node *tail;
    int size;
public:
    LinkedList(int v){
        head = new Node(v);
        tail = head;
        size=1;
    }
    LinkedList():head(NULL),tail(NULL),size(0){};
    friend ostream &operator<<(ostream &os, const LinkedList &obj);
    void prepend(int v);
    void append(int v);
    void deleteFirst();
    void deleteLast();
    bool insert(int pos, int v);
    bool delelteNode(int pos);
    void mergeSorted(LinkedList &LL2);
    int getSize();
    
};

//LinkedList& mergeSorted(LinkedList &LL1, LinkedList &LL2);

ostream& operator<<(ostream &os, const LinkedList &obj)
{
    if(obj.head == NULL) {
        os<<"empty list\n";
    } else {
        Node *tmp = obj.head;
        while(tmp)
        {
            os<<tmp->val;
            tmp=tmp->next;
            if(tmp) os<<"->";
        }
        os<<endl;
    }
    return os;
}
void LinkedList::prepend(int v)
{
    Node *nwNode = new Node(v);
    if(head == NULL)
    {
        head = nwNode;
        tail = head;
    }
    else {
        nwNode->next = head;
        head = nwNode;
    }
    size+=1;
}

void LinkedList::append(int v)
{
    Node *nwNode = new Node(v);
    if(head==NULL){
        prepend(v);
    } else {
        tail->next=nwNode;
        tail=tail->next;
        size+=1;
    }
}

void LinkedList::deleteFirst()
{
    if(head==NULL) return;
    Node *tmp = head;
    if(size==1)
    {
        head = NULL;
        tail = NULL;
    } else {
        head=head->next;
    }
    delete(tmp);tmp=NULL;
    size-=1;
}

void LinkedList::deleteLast()
{
    if(head==NULL) return;
    Node* tmp = head;
    if(size == 1)
    {
        head = NULL;
        tail = NULL;
        delete(tmp);
        tmp=NULL;
    } else {
        while(tmp->next != tail)
        {
            tmp=tmp->next;
        }
        tmp->next = NULL;
        delete(tail);
        tail=NULL;
        tail=tmp;
    }
    size-=1;
}
bool LinkedList::insert(int pos, int v)
{
    if(pos>size || head==NULL) return NULL;
    if(pos==0)
    {
        prepend(v);
        return true;
    }
    if(pos==size)
    {
        append(v);
        return true;
    }
    Node *tmp = head, *prev=NULL;
    int cnt=1;
    while(tmp)
    {
        prev=tmp;
        tmp=tmp->next;
        if(cnt==pos) break; cnt+=1;
    }
    Node *nwNode = new Node(v);
    prev->next = nwNode;
    nwNode->next = tmp;
    return true;
}
void LinkedList::mergeSorted(LinkedList &LL2)
{
    
    Node *A = this->head;
    Node *B = LL2.head;
    if(this->head == NULL ) return;
    if(LL2.head == NULL ) return;
    Node *h1=NULL,*h2=NULL, *t=NULL;
    if(A->val < B->val)
    {
        h1=A; h2=B;
    } else {
        h1=B; h2=A;
    }
    t=h1;
    h1=h1->next;
    while(h1!=NULL && h2!=NULL)
    {
        if(h1->val<h2->val)
        {
            t->next = h1;
            h1=h1->next;
        } else {
            t->next = h2;
            h2 = h2->next;
        }
        t=t->next;
    }
    if(h1==NULL) t->next=h2;
    if(h2==NULL) t->next=h1;
    return;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Merge sorted linked list!\n";
    LinkedList LL1, LL2;
    LL1.append(10);
    LL2.append(11);
    LL1.append(12);
    LL2.append(13);
    LL1.append(14);
    cout<<LL1<<endl;
    cout<<LL2<<endl;
    LL1.mergeSorted(LL2);
    cout<<LL1;
    return 0;
}
