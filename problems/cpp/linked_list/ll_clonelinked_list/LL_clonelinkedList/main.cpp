//
//  main.cpp
//  LL_clonelinkedList
//
//  Created by CodeBreaker on 29/01/25.
//
/*
 Copy List
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 You are given a linked list A
 Each node in the linked list contains two pointers: a next pointer and a random pointer
 The next pointer points to the next node in the list
 The random pointer can point to any node in the list, or it can be NULL
 Your task is to create a deep copy of the linked list A
 The copied list should be a completely separate linked list from the original list, but with the same node values and random pointer connections as the original list
 You should create a new linked list B, where each node in B has the same value as the corresponding node in A
 The next and random pointers of each node in B should point to the corresponding nodes in B (rather than A)


 Problem Constraints
 0 <= |A| <= 106


 Input Format
 The first argument of input contains a pointer to the head of linked list A.


 Output Format
 Return a pointer to the head of the required linked list.


 Example Input
 Given list
    1 -> 2 -> 3
 with random pointers going from
   1 -> 3
   2 -> 1
   3 -> 1
   


 Example Output
    1 -> 2 -> 3
 with random pointers going from
   1 -> 3
   2 -> 1
   3 -> 1
   


 Example Explanation
 You should return a deep copy of the list. The returned answer should not contain the same node as the original list, but a copy of them. The pointers in the returned list should not link to any node in the original input list.
 */
#include <iostream>
#include "sll.h"

/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* copyRandomList(RandomListNode* A) {
    auto tmp = A;
    while(tmp!=NULL)
    {
        auto nn = new RandomListNode(tmp->label);
        nn->next = tmp->next;
        tmp->next = nn;
        tmp=tmp->next->next;
    }
    tmp = A;
    while(tmp!=NULL)
    {
        if(tmp->next!=NULL && tmp->random!=NULL)
        {
            tmp->next->random = tmp->random->next;
        }
        tmp=tmp->next->next;
    }
    auto h2 = A->next;
    auto h1 = A;
    auto t1=h1, t2=h2;
    while(t2!=NULL)
    {
        t1->next = t2->next;
        if(t2->next!=NULL)
        {
            t2->next= t2->next->next;
        }
        t1=t1->next;
        t2=t2->next;
    }
    return h2;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Cloning linked list !\n";
    CloneSingleLL csll;
    csll.createDummyLinkedList();
    cout<<csll<<endl;
    csll.pointRandoms();
    auto head = csll.get_head();
    auto h2 = copyRandomList(head);
    auto t = h2;
    while(t!=NULL)
    {
        cout<<t->label;
        t=t->next;
        if(t!=NULL) cout<<"->";
    }
    cout<<endl;
    t=h2;
    while(t)
    {
        if(t->random!=NULL){
            cout<<t->label<<"->"<<t->random->label<<" ";
        }
        t=t->next;
    }
    cout<<endl;
    cout<<endl;
    return 0;
}
