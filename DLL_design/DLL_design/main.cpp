//
//  main.cpp
//  DLL_design
//
//  Created by CodeBreaker on 22/12/24.
//

#include <iostream>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int v):val(v),next(NULL),prev(NULL){}
};

class DoubliLinkedList{
private:
    Node *head;
    Node *tail;
    int length;
public:
    DoubliLinkedList(int v)
    {
        Node *nwNode = new Node(v);
        head = nwNode;
        tail = nwNode;
        length = 1;
    }
    ~DoubliLinkedList()
    {
        if(head!=NULL)
        {
            Node *tmp;
            while(head)
            {
                tmp = head;
                head=head->next;
                delete tmp;
            }
        }
        head = NULL;
        tail = NULL;
    }
    void append(int v);
    void deleteLast();
    void prepend(int v);
    void deleteFirst();
    Node *get(int ind);
    bool set(int ind, int v);
    bool insert(int ind, int v);
    void deleteNode(int ind);
    void printDLL();
    
};

void DoubliLinkedList::append(int v)
{
    Node *nwNode = new Node(v);
    if(length==0)
    {
        head=nwNode;
        tail=nwNode;
    } else {
        tail->next=nwNode;
        nwNode->prev = tail;
        tail = nwNode;
    }
    length+=1;
}

void DoubliLinkedList::deleteLast()
{
    Node *tmp = tail;
    if(length==0)
    {
        head=NULL;
        tail=NULL;
    } else {
        tail=tail->prev;
        tail->next=NULL;
    }
    delete(tmp);
    length-=1;
}

void DoubliLinkedList::prepend(int v)
{
    Node *nwNode = new Node(v);
    if(length==0)
    {
        head = nwNode;
        tail = nwNode;
    } else {
        nwNode->next=head;
        head->prev=nwNode;
        head=nwNode;
    }
    length+=1;
}

void DoubliLinkedList::deleteFirst()
{
    if(length==0) return;
    if(length==1)
    {
        head=NULL;
        tail=NULL;
    } else {
        Node *tmp = head;
        head=head->next;
        head->prev=NULL;
        delete(tmp);
    }
    length-=1;
}
Node* DoubliLinkedList::get(int ind)
{
    if(ind<0 || ind>=length) return NULL;
    int mid = length/2;
    Node *tmp=NULL;
    if(ind<=mid)
    {
        tmp=head;
        for(int i=0;i<ind;i++)
        {
            tmp=tmp->next;
        }
    } else {
        tmp =tail;
        for(int i= length;i>=ind;i--)
        {
            tmp=tmp->prev;
        }
    }
    return tmp;
}
bool DoubliLinkedList::set(int ind, int v)
{
    if(ind<0||ind>length) return false;
    Node *tmp=get(ind);
    if(tmp!=NULL)
    {
        tmp->val=v;
        return true;
    }
    return false;
}
bool DoubliLinkedList::insert(int ind, int v)
{
    if(ind<0||ind>length) return false;
    if(ind==0)
    {
        prepend(v);
        return true;
    }
    if(ind == length)
    {
        append(v);
        return true;
    }
    Node *tmp = get(ind);
    Node *nwNode = new Node(v);
    nwNode->next = tmp;
    nwNode->prev = tmp->prev;
    tmp->prev->next = nwNode;
    tmp->prev = nwNode;
    length+=1;
    return true;
}
void DoubliLinkedList::deleteNode(int ind)
{
    if(ind<0||ind>length) return;
    if(ind==0) return deleteFirst();
    if(ind==length-1) return deleteLast();
    Node *tmp=get(ind);
    tmp->next->prev=tmp->prev;
    tmp->prev->next=tmp->next;
    length-=1;
}

void DoubliLinkedList::printDLL()
{
    Node* tmp=head;
    if(tmp==NULL)
    {
        cout<<"empty\n";
    } else {
        while(tmp!=NULL)
        {
            cout<<tmp->val;
            tmp=tmp->next;
            if(tmp!=NULL) cout<<"->";
        }
    }
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Doubly linked list!\n";
    DoubliLinkedList *DLL = new DoubliLinkedList(1);
    DLL->append(2);
    DLL->append(3);
    DLL->append(4);
    DLL->append(5);
    DLL->append(6);
    DLL->append(7);
    DLL->append(8);
    DLL->printDLL();
    
    cout<<DLL->get(4)->val<<endl;
    cout<<DLL->get(0)->val<<endl;
    cout<<DLL->get(7)->val<<endl;
    //cout<<DLL->get(8)->val<<endl; //wrong index
    DLL->insert(3, 12);
    DLL->insert(9, 19);
    DLL->printDLL();
    
    return 0;
}
