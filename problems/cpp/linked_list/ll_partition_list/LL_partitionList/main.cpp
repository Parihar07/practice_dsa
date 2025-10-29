//
//  main.cpp
//  LL_partitionList
//
//  Created by CodeBreaker on 20/12/24.
//
/*
 Implement the partitionList member function for the LinkedList class, which partitions the list such that all nodes with values less than x come before nodes with values greater than or equal to x.

 Note:  This linked list class does NOT have a tail which will make this method easier to implement.

 The original relative order of the nodes should be preserved.



 Function Signature:

 void partitionList(int x)



 Details:

 The function partitionList takes an integer x as a parameter and modifies the current linked list in place according to the specified criteria. If the linked list is empty (i.e., head is null), the function should return immediately without making any changes.



 Example 1:

 Input:

 Linked List: 3 -> 8 -> 5 -> 10 -> 2 -> 1 x: 5

 Process:

 Values less than 5: 3, 2, 1

 Values greater than or equal to 5: 8, 5, 10

 Output:

 Linked List: 3 -> 2 -> 1 -> 8 -> 5 -> 10





 Example 2:
 Input:

 Linked List: 1 -> 4 -> 3 -> 2 -> 5 -> 2 x: 3

 Process:

 Values less than 3: 1, 2, 2

 Values greater than or equal to 3: 4, 3, 5

 Output:

 Linked List: 1 -> 2 -> 2 -> 4 -> 3 -> 5





 Tips:

 While traversing the linked list, maintain two separate chains: one for values less than x and one for values greater than or equal to x.

 Use dummy nodes to simplify the handling of the heads of these chains.

 After processing the entire list, connect the two chains to get the desired arrangement.



 Note:

 The solution must maintain the relative order of nodes. For instance, in the first example, even though 8 appears before 5 in the original list, the partitioned list must still have 8 before 5 as their relative order remains unchanged.

 Note:

 You must solve the problem WITHOUT MODIFYING THE VALUES in the list's nodes (i.e., only the nodes' next pointers may be changed.)
 */
#include <iostream>
#include<vector>
using namespace std;

class Node {
    public:
        int value;
        Node* next;
        Node(int value) {
            this->value = value;
            next = nullptr;
        }
};

class LinkedList {
    private:
        Node* head;
        int length;
        
    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            length = 1;
        }

        ~LinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        void printList() {
            Node* temp = head;
            if (temp == nullptr) {
                cout << "empty";
            } else {
                while (temp != nullptr) {
                    cout << temp->value;
                    temp = temp->next;
                    if (temp != nullptr) {
                        cout << " -> ";
                    }
                }
            }
            cout << endl;
        }

        Node* getHead() {
            return head;
        }

        int getLength() {
            return length;
        }
        
        void makeEmpty() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
            length = 0;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
            } else {
                Node* currentNode = head;
                while (currentNode->next != nullptr) {
                    currentNode = currentNode->next;
                }
                currentNode->next = newNode;
            }
            length++;
        }

        //   +======================================================+
        //   |                 WRITE YOUR CODE HERE                 |
        //   | Description:                                         |
        //   | - Partition list around value x                      |
        //   | - Return type: void                                  |
        //   |                                                      |
        //   | Tips:                                                |
        //   | - Create two dummy nodes for two new lists           |
        //   | - One list for nodes less than x                     |
        //   | - Another list for nodes greater or equal to x       |
        //   | - Loop through original list                         |
        //   | - Assign nodes to new lists based on value           |
        //   | - Merge the two new lists                            |
        //   | - Update the original list's head                    |
        //   +======================================================+
    void partitionList(int x)
    {
        vector<Node *> listNodeFirst, listNodeSecond;
        Node *tmp = head;
        if(head == NULL) return;
        while(tmp)
        {
            if(tmp->value < x)
            {
                listNodeFirst.push_back(tmp);
            } else {
                listNodeSecond.push_back(tmp);
            }
            tmp=tmp->next;
        }
        
        
        for(int i=0;i<listNodeSecond.size();i++)
        {
            listNodeFirst.push_back(listNodeSecond[i]);
        }
        
        for(int i=0;i<listNodeFirst.size()-1;i++)
        {
            listNodeFirst[i]->next=listNodeFirst[i+1];
        }
        listNodeFirst[listNodeFirst.size()-1]->next=NULL;
        
        head = listNodeFirst[0];
    }
    void partitionListActual(int x) {
                if (head == nullptr) return;
     
                Node dummy1(0);
                Node dummy2(0);
                Node* prev1 = &dummy1;
                Node* prev2 = &dummy2;
                Node* current = head;
     
                while (current != nullptr) {
                    if (current->value < x) {
                        prev1->next = current;
                        prev1 = current;
                    } else {
                        prev2->next = current;
                        prev2 = current;
                    }
                    current = current->next;
                }
     
                prev2->next = nullptr;
                prev1->next = dummy2.next;
                head = dummy1.next;
            }
    void swapPairs()
    {
        Node *C=head;
        head=head->next;
        Node* prev=NULL;
        Node *A=NULL;
        while(C!=NULL && C->next!=NULL)
        {
            A=C->next;
            C->next = A->next;
            A->next = C;
            if(prev!=NULL)
            {
                prev->next=A;
            }
            prev=C;
            C=C->next;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Linked list partiotion list!\n";
    
    LinkedList *LL = new LinkedList(3);
    LL->append(8);
    LL->append(5);
    LL->append(10);
    LL->append(2);
    LL->append(1);
    LL->append(11);
    LL->printList();
    LL->swapPairs();
    LL->printList();
    return 0;
}
