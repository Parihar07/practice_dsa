//
//  main.cpp
//  LL_insertdeleteprint
//
//  Created by CodeBreaker on 02/12/24.
//
/*
 Linked-List
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


class Node{
public:
    int val;
    Node *nxt;
    Node(int v):val(v),nxt(NULL){}
};

class LinkedList{
    Node *head;
public:
    LinkedList(){
        head=NULL;
    }
    void insert_node(int position, int value);
    void delete_node(int position);
    void print_ll();
};

void LinkedList::insert_node(int position, int value) {
    // @params position, integer
    // @params value, integer
    Node *newNode = new Node(value);
    Node *tmpNode = head;
    Node *posNode=NULL;
    int cnt=0;
    if(position == 1)
    {
        if(head == NULL)
        {
            head = newNode;
        } else {
            newNode->nxt=head;
            head = newNode;
        }
    } else {
        tmpNode=head;
        cnt=1;
        while(tmpNode!=NULL)
        {
            posNode=tmpNode;
            tmpNode=tmpNode->nxt;
            cnt++;
            if(cnt==position) break;
        }
        posNode->nxt=newNode;
        newNode->nxt = tmpNode;
    }
}

void LinkedList::delete_node(int position) {
    // @params position, integer
}


void LinkedList::print_ll() {
    // Output each element followed by a space
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Linked list world!\n";
    return 0;
}
