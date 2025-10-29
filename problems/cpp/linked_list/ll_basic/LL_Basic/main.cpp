//
//  main.cpp
//  LL_Basic
//
//  Created by CodeBreaker on 02/12/24.
//

#include <iostream>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int v):val(v),next(NULL){}
    Node():val(0),next(NULL){}
};

class LinkedList{
private:
    Node *head;
    int size;
public:
    void insert_node(int position, int value);
    void delete_node(int position);
    void print_ll();
    LinkedList():head(NULL),size(0){}
    int getSize(){return size;};
};

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
    LL.print_ll();
}

void LinkedList::insert_node(int position, int value) {
    // @params position, integer
    // @params value, integer
    Node *newNode = new Node(value);
    if(position == 1)
    {
        if(head==NULL)
        {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    } else {
        int cnt=1;
        Node *tmpNode=head, *prevNode=NULL;
        while(tmpNode!=NULL)
        {
            cnt+=1;
            prevNode=tmpNode;
            tmpNode=tmpNode->next;
            if(cnt==position) break;
        }
        prevNode->next = newNode;
        newNode->next = tmpNode;
    }
    size+=1;
}

void LinkedList::delete_node(int position) {
    // @params position, integer
    if(head==NULL) return;
    Node* tmpNode=head, *prevNode=NULL;
    int cnt=1;
    if(cnt==position)
    {
        head = tmpNode->next;
        delete(tmpNode);
        size-=1;
    } else {
        while(tmpNode!=NULL)
        {
            cnt+=1;
            prevNode=tmpNode;
            tmpNode=tmpNode->next;
            if(cnt==position) break;
        }
        if(tmpNode!=NULL)
        {
            prevNode->next= tmpNode->next;
            delete(tmpNode);
            tmpNode=NULL;
            size-=1;
        }
    }
    if(size==0) head =NULL;
}

void LinkedList::print_ll() {
    // Output each element followed by a space
    if(head==NULL) return;
    Node* tmpNode=head;
    while(tmpNode!=NULL)
    {
        cout<<tmpNode->val;
        tmpNode=tmpNode->next;
        if(tmpNode!=NULL) cout<<" ";
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Linked list!\n";
//    LinkedList LL;
    insert_node(1, 10);
    insert_node(2, 20);
    insert_node(3, 16);
    insert_node(4, 60);
    print_ll();cout<<endl;
    delete_node(1); //third node
    print_ll();cout<<endl;
    delete_node(7); //invalid node
    print_ll();cout<<endl;
    insert_node(8, 65);
    print_ll();cout<<endl;
    int ip=0;
    cin>>ip;
    while(ip>0)
    {
        char choice;
        int pos=0, val=0;
        cin>>choice;
        if(choice=='i')
        {
            cin>>pos>>val;
            insert_node(pos, val);
        }
        
        if(choice=='p')
        {
            print_ll();
        }
        if(choice=='d')
        {
            cin>>pos;
            delete_node(pos);
        }
       
        ip--;
    }
//    cout<<"Size of Linked List : " << LL.getSize() <<endl;
    return 0;
}
