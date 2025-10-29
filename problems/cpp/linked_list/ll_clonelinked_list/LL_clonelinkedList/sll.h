#ifndef H_SINGLY_LINKED_LIST_RANDOM
#define H_SINGLY_LINKED_LIST_RANDOM
//
//  sll.h
//  LL_clonelinkedList
//
//  Created by CodeBreaker on 29/01/25.
//

#include<ostream>
using namespace std;
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class CloneSingleLL{
private:
    RandomListNode *head;
public:
    CloneSingleLL():head(NULL){}
    void createDummyLinkedList()
    {
        auto n1 = new RandomListNode(1);
        auto n2 = new RandomListNode(2);
        auto n3 = new RandomListNode(3);
        auto n4 = new RandomListNode(4);
        auto n5 = new RandomListNode(5);
        auto n6 = new RandomListNode(6);
        auto n7 = new RandomListNode(7);
        auto n8 = new RandomListNode(8);
        auto n9 = new RandomListNode(9);
        head = n1;
        n1->next=n2;n2->next=n3;n3->next=n4;n4->next=n5;
        n5->next=n6;n6->next=n7;n7->next=n8;n8->next=n9;
        
        //random refernces
        
        n1->random = n3;
        n3->random = n9;
        n2->random = n2;
        n4->random = n7;
        n9->random = n1;
        n5->random = n1;
    }
    void printLL()
    {
        RandomListNode *t = head;
        while(t)
        {
            cout<<t->label;
            t=t->next;
            if(t!=NULL) cout<<" ";
        }
    }
    void pointRandoms()
    {
        RandomListNode *t = head;
        while(t)
        {
            if(t->random!=NULL){
                cout<<t->label<<"->"<<t->random->label<<" ";
            }
            t=t->next;
        }
        cout<<endl;
    }
    RandomListNode *get_head(){return head;}
    friend ostream &operator<<(ostream &os, CloneSingleLL &csll)
    {
        csll.printLL();
        return os;
    }
};

#endif //SINGLY_LINKED_LIST_RANDOM
