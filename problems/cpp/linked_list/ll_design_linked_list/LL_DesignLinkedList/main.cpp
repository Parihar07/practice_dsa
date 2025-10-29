//
//  main.cpp
//  LL_DesignLinkedList
//
//  Created by CodeBreaker on 03/12/24.
//
/*
 Design Linked list
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given a matrix A of size Nx3 representing operations. Your task is to design the linked list based on these operations.

 There are four types of operations:

 0 x -1: Add a node of value x before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
 1 x -1: Append a node of value x to the last element of the linked list.
 2 x index: Add a node of value x before the indexth node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
 3 index -1: Delete the indexth node in the linked list, if the index is valid.
 A[i][0] represents the type of operation.

 A[i][1], A[i][2] represents the corresponding elements with respect to type of operation.

 Note: Indexing is 0 based.


 Problem Constraints
 1 <= Number of operations <= 1000
 1 <= All node values <= 109


 Input Format
 The only argument given is matrix A.


 Output Format
 Return the pointer to the starting of the linked list.


 Example Input
 Input 1:
     A = [   [0, 1, -1]
             [1, 2, -1]
             [2, 3, 1]   ]
 Input 2:
     A = [   [0, 1, -1]
             [1, 2, -1]
             [2, 3, 1]
             [0, 4, -1]
             [3, 1, -1]
             [3, 2, -1]  ]


 Example Output
 Output 1:
     1->3->2->NULL
  
 Output 2:
     4->3->NULL
 */
#include <iostream>
#include<vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int v):val(v),next(NULL){}
};
class LinkedList{
private:
    ListNode *head;
    int size;
public:
    LinkedList():head(NULL),size(0){ }
    void insert_node(int pos, int val);
    void delete_node(int pos);
    void print_LL();
    int getSize(){ return size; };
    ListNode *getHead(){ return head; };
    void actUpon(int cmd, int val, int pos);
};

LinkedList LL;

void LinkedList::insert_node(int pos, int val)
{
    ListNode *nwNode = new ListNode(val);
    if(pos==1)
    {
        if(head ==NULL)
        {
            head = nwNode;
        } else {
            nwNode->next = head;
            head = nwNode;
        }
    } else {
        ListNode *tmpNode = head;
        ListNode *prev = NULL;
        int cnt=1;
        while(tmpNode!=NULL)
        {
            cnt+=1;
            prev = tmpNode;
            tmpNode=tmpNode->next;
            if(cnt==pos) break;
        }
        if(tmpNode==NULL)
        {
            prev->next = nwNode;
        } else {
            prev->next = nwNode;
            nwNode->next = tmpNode;
        }
    }
    size+=1;
}

void LinkedList::delete_node(int pos)
{
    if(head == NULL) return;
    ListNode *tmpNode = head;
    ListNode *prev = NULL;
    int cnt=1;
    if(pos == 1)
    {
        head=head->next;
        delete tmpNode;
        size-=1;
    } else {
        while(tmpNode!=NULL)
        {
            cnt+=1;
            prev=tmpNode;
            tmpNode=tmpNode->next;
            if(cnt==pos) break;
        }
        if(tmpNode!=NULL)
        {
            prev->next= tmpNode->next;
            delete tmpNode;
            size-=1;
        }
    }
    
    if(size==0) head = NULL; //handling dangling pointer
}

//int LinkedList::getSize()
//{
//    return size;
//}
void LinkedList::print_LL()
{
    ListNode *tmpNode = head;
    while(tmpNode!=NULL)
    {
        cout<<tmpNode->val;
        tmpNode=tmpNode->next;
        if(tmpNode!=NULL) cout<<" ";
    }
    cout<<endl;
}

void LinkedList::actUpon(int cmd, int val, int pos)
{
    switch (cmd) {
        case 0:
            insert_node(1, val);
            break;
        case 1:
            insert_node(getSize()+1, val); // 0 Based indexing hecning adding 1
            break;
        case 2:
            insert_node(pos+1, val); // 0 Based indexing hecning adding 1
            break;
        case 3:
            delete_node(val+1);
            break;
        default:
            cout<<"unknown command !!!!!!";
            break;
    }
}

ListNode* solve(vector<vector<int> > &A) {
    LinkedList LL;
    size_t N = A.size();
    for(int q=0;q<N;q++)
    {
        LL.actUpon(A[q][0], A[q][1],A[q][2]);
    }
    return LL.getHead();
}

//Output 3 -> 20 -> 11 -> 13 -> 15 -> 7 -> 15 -> 1 -> 14 -> 8 -> 9 -> 17 -> 17 -> 11 -> 4 -> 4 -> 7 -> 10 -> 20 -> 3 -> 8 -> 1 -> 5 -> 19 -> 4 -> 19 -> 4 -> 15 -> 4 -> 11 -> 16 -> 4 -> 7 -> 11

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Design linked list!\n";
//    LinkedList LL;
//    LL.insert_node(1, 11);
//    LL.insert_node(2, 12);
//    LL.insert_node(3, 113);
//    LL.insert_node(4, 671);
//    LL.insert_node(5, 17);
//    LL.insert_node(10, 40);
//    LL.print_LL();
//    LL.delete_node(1);
//    LL.delete_node(1);
//    LL.delete_node(1);
//    LL.delete_node(1);
//    LL.delete_node(1);
//    LL.delete_node(1);
//    cout<<"size : "<<LL.getSize()<<endl;;
//    LL.print_LL();
//    cout<<"size : "<<LL.getSize()<<endl;;
//    vector<vector<int>> A{{0,1,-1},{1,2,-1},{2,3,1}};
    vector<vector<int>> A{{0,13,-1},{2,10,0},{2,7,0},{2,4,3},{1,20,-1},{0,4,-1},{0,15,-1},{2,9,3},{3,5,-1},{0,11,-1},{3,1,-1},{1,20,-1},{1,8,-1},{3,5,-1},{1,14,-1},{2,4,1},{0,9,-1},{0,13,-1},{1,5,-1},{3,8,-1},{2,5,0},{3,7,-1},{0,14,-1},{1,19,-1},{2,3,10},{1,3,-1},{1,18,-1},{0,13,-1},{3,16,-1},{3,0,-1},{1,4,-1},{2,1,13},{0,5,-1},{2,17,5},{2,17,3},{2,7,21},{3,15,-1},{0,15,-1},{1,19,-1},{1,4,-1},{0,7,-1},{1,4,-1},{3,5,-1},{1,11,-1},{2,15,24},{2,17,8},{2,15,18},{3,2,-1},{3,17,-1},{3,21,-1},{0,15,-1},{0,13,-1},{0,11,-1},{3,7,-1},{1,16,-1},{1,4,-1},{1,7,-1},{0,20,-1},{1,11,-1},{2,1,6},{2,8,9},{0,3,-1},{3,25,-1},{3,9,-1}}/*{{0,1,-1},{1,2,-1},{2,3,1},{0,4,-1},{3,1,-1},{3,2,-1}}*/;
    ListNode *ans = solve(A);
    while(ans!=NULL)
    {
        cout<<ans->val<<" ";
        ans=ans->next;
    }
    cout<<endl;
    return 0;
}
