//
//  main.cpp
//  DLL_reverse
//
//  Created by CodeBreaker on 22/12/24.
//
/*
 Swap First and Last ( ** Interview Question)
 Implement a member function called swapFirstLast() that swaps the values of the first and last nodes in the list.

 If the length of the list is less than 2, the function should not perform any operation.

 Input:
 The function is a member of the DoublyLinkedList class, which has a head and a tail pointer, as well as a length attribute.



 Output:
 No explicit output is returned. However, the function should modify the doubly linked list such that the values of the first and last nodes are swapped.



 Constraints:
 The doubly linked list may be empty, have only one node, or have two or more nodes.



 Example:

 Consider the following doubly linked list:

 Head: 1
 Tail: 5
 Length: 5
  
 Doubly Linked List:
 1 <-> 2 <-> 3 <-> 4 <-> 5


 After calling swapFirstLast(), the list should be:

 Head: 5
 Tail: 1
 Length: 5
  
 Doubly Linked List:
 5 <-> 2 <-> 3 <-> 4 <-> 1


 Note that the pointers to the nodes themselves are not swapped - only their values are exchanged.
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
        //   | - This is the reverse method.                       |
        //   | - It reverses the entire doubly linked list.        |
        //   | - Return type: void                                 |
        //   |                                                     |
        //   | Tips:                                               |
        //   | - Create two pointers: current and temp.            |
        //   | - Loop through the list swapping next and prev      |
        //   |   for each node.                                    |
        //   | - After loop, swap head and tail pointers.          |
        //   | - Check output from Test.cpp in "User logs".        |
        //   +=====================================================+
        void reverse()
        {
            if(length<2) return;
            Node *C = head; // C current node
            Node *A = head; // After curren node
            
            while(A!=NULL)
            {
                A=C->next;
                C->next=C->prev;
                C->prev=A;
                C=A;
            }
            
            Node *tailtmp = tail;
            tail=head;
            head=tailtmp;
        }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Doubly linked linst reverse!\n";
    DoublyLinkedList *DLL = new DoublyLinkedList(1);
    DLL->append(2);
//    DLL->append(3);
//    DLL->append(4);
//    DLL->append(5);
//    DLL->append(6);
//    DLL->append(7);
    DLL->printList();
    DLL->reverse();
    DLL->printList();
    return 0;
}
