//
//  main.cpp
//  LL_reverselistKgroups
//
//  Created by CodeBreaker on 17/01/25.
//
/*
 
 Question
 Help with Problem Solving
 Submissions
 Discussions
 Current Possible Score: 100
 Your Score: 0
 Max Score:
 100
 Q6. Linked-List
 Unsolved
 feature icon
 Get your doubts resolved blazing fast with Chat GPT Help
 Check Chat GPT
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Design and implement a Linked List data structure.
 A node in a linked list should have the following attributes - an integer value and a pointer to the next node.

 It should support the following operations:
 insert_node(position, value) - To insert the input value at the given position in the linked list.
 delete_node(position) - Delete the value at the given position from the linked list.
 print_ll() - Print the entire linked list, such that each element is followed by a single space (no trailing spaces).
 Note:
 If an input position does not satisfy the constraint, no action is required.
 Each print query has to be executed in a new line.


 Problem Constraints
 1 <= value <= 105
 1 <= position <= n where, n is the size of the linked-list.


 Input Format
 First line contains an integer denoting number of cases, let's say t. Next t line denotes the cases.


 Output Format
 When there is a case of print_ll(), Print the entire linked list, such that each element is followed by a single space.

 There should not be any trailing space.

 NOTE: You don't need to return anything.


 Example Input
 Input 1:
 5
 i 1 23
 i 2 24
 p
 d 1
 p
 Input 2:
 3
 i 1 54
 d 10
 p


 Example Output
 Output 1:
 23 24
 24
 Output 2:
 54


 Example Explanation
 Explanation 1:
 After first two cases linked list contains two elements 23 and 24.
 At third case print: 23 24.
 At fourth case delete value at first position, only one element left 24.
 At fifth case print: 24.
 Explanation 2:
 After the first case,  linked list contains: 54

 At second case delete value at 10th position,
 Since the position is higher than the length of the linkedlist.
 It does not satisfy the constraint, So no action is required.

 At third case print: 54.
 */
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
    std::cout << "Hello, Designing Linked List!\n";
    insert_node(1, 13);
    insert_node(2, 14);
    insert_node(3, 15);
    insert_node(4, 16);
    insert_node(5, 17);
    insert_node(6, 18);
    insert_node(7, 19);
    insert_node(8, 20);
    print_ll();
    LL.reverseKgroups(3);
    print_ll();
    return 0;
}

