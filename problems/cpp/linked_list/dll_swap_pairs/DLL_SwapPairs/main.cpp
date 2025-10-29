//
//  main.cpp
//  DLL_SwapPairs
//
//  Created by CodeBreaker on 23/12/24.
/*
 Implement a member function called swapPairs() that swaps the values of every two adjacent nodes in the list.

 Note: This DoublyLinkedList does not have a tail pointer which will make the implementation easier.



 Input:
 The function is a member of the DoublyLinkedList class, which has a head and a tail pointer, as well as a length attribute.



 Output:
 No explicit output is returned. However, the function should modify the doubly linked list such that the values of every two adjacent nodes are swapped.



 Constraints:
 The doubly linked list may be empty, have only one node, or have two or more nodes.



 Example:

 Consider the following doubly linked list:

 Head: 1
 Tail: 6
 Length: 6
  
 Doubly Linked List:
 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6


 After calling swapPairs(), the list should be:

 Head: 2
 Tail: 5
 Length: 6
  
 Doubly Linked List:
 2 <-> 1 <-> 4 <-> 3 <-> 6 <-> 5






 Consider the following doubly linked list:

 Head: 1
 Tail: 5
 Length: 5
  
 Doubly Linked List:
 1 <-> 2 <-> 3 <-> 4 <-> 5


 After calling swapPairs(), the list should be:

 Head: 2
 Tail: 4
 Length: 5
  
 Doubly Linked List:
 2 <-> 1 <-> 4 <-> 3 <-> 5


 Note that the pointers to the nodes themselves are updated to achieve the swapping of adjacent nodes.  Do not update the values of the nodes.
 */

#include <iostream>
using namespace std;

class Node {
    public:
        int value;
        Node* next;
        Node* prev;
    
        Node(int value) {
            this->value = value;
            next = nullptr;
            prev = nullptr;
        }
};

class DoublyLinkedList {
    private:
        Node* head;
        Node* tail;
        int length;
    
    public:
        DoublyLinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }
    
        ~DoublyLinkedList() {
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
                cout << "empty" << endl;
                return;
            }
            while (temp->next != nullptr) {
                cout << temp->value << " <-> ";
                temp = temp->next;
            }
            cout << temp->value << endl;
        }
    
        Node* getHead() {
            return head;
        }
    
        Node* getTail() {
            return tail;
        }
    
        int getLength() {
            return length;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            length++;
        }

        //   +=====================================================+
        //   |                 WRITE YOUR CODE HERE                |
        //   | Description:                                        |
        //   | - The swapPairs function swaps adjacent pairs       |
        //   |   of nodes in a doubly linked list.                 |
        //   | - Return type: void                                 |
        //   |                                                     |
        //   | Tips:                                               |
        //   | - Utilizes a dummyNode to simplify edge cases.      |
        //   | - Uses pointers to navigate and swap nodes.         |
        //   | - Pay close attention to the 'next' and 'prev'      |
        //   |   pointers of the nodes.                            |
        //   | - Works in-place; doesn't create new nodes.         |
        //   | - Always checks if the list is empty or has only    |
        //   |   one node.                                         |
        //   | - Check output from Test.cpp in "User logs".        |
        //   +=====================================================+
    void swapPairsActual() {
                Node dummyNode(0);
                dummyNode.next = head;
                Node* previousNode = &dummyNode;
            
                while (head != nullptr && head->next != nullptr) {
                    Node* firstNode = head;
                    Node* secondNode = head->next;
            
                    previousNode->next = secondNode;
                    firstNode->next = secondNode->next;
                    secondNode->next = firstNode;
            
                    secondNode->prev = previousNode;
                    firstNode->prev = secondNode;
                    if (firstNode->next != nullptr) {
                        firstNode->next->prev = firstNode;
                    }
            
                    head = firstNode->next;
                    previousNode = firstNode;
                }
            
                head = dummyNode.next;
                if (head) head->prev = nullptr;
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
            if(A->next!=NULL)
            {
                A->next->prev = C;
            }

            
            A->next = C;
            A->prev=C->prev;
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
    std::cout << "Hello, Doubly linked list swappairs\n";
    DoublyLinkedList *DLL = new DoublyLinkedList(1);
    DLL->append(2);
    DLL->append(3);
    DLL->append(4);
    DLL->append(5);
//    DLL->append(6);
    DLL->printList();
    DLL->swapPairs();
    cout<<endl;
    cout<<"tail : "<<DLL->getTail()->value<<endl;
    DLL->printList();
    return 0;
}
