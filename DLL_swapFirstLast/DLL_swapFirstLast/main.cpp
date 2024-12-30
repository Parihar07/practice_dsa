//
//  main.cpp
//  DLL_swapFirstLast
//
//  Created by CodeBreaker on 22/12/24.
//

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
        //   | - This is the swapFirstLast function.               |
        //   | - It swaps the values of the first and last nodes   |
        //   |   in the doubly linked list.                        |
        //   | - Return type: void                                 |
        //   |                                                     |
        //   | Tips:                                               |
        //   | - Check if the list has less than 2 nodes. If so,   |
        //   |   just return; nothing to swap.                     |
        //   | - Use a temporary variable to store the value of    |
        //   |   the head node.                                    |
        //   | - Assign the value of the tail node to the head     |
        //   |   node.                                             |
        //   | - Assign the stored head node value to the tail.    |
        //   | - Check output from Test.cpp in "User logs".        |
        //   +=====================================================+
        void swapFirstLast()
        {
            if(length<2) return;
            Node *tmp =head;
            
            if(length!=2)
            {
                Node *prevTail = tail->prev;
                Node *afterHead = head->next;
                            
                prevTail->next = head;
                head->prev = prevTail;
                head->next = NULL;
                
                afterHead->prev = tail;
                tail->next = afterHead;
                tail->prev = NULL;
                
                head=tail;
                tail = tmp;
            } else {
                head=tail;
                tail = tmp;
                head->prev = NULL;
                head->next = tail;
                tail->next = NULL;
                tail->prev = head;
            }
        }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Doubly linked list swap frist last!\n";
    
    DoublyLinkedList *DLL = new DoublyLinkedList(1);
    DLL->append(2);
//    DLL->append(3);
//    DLL->append(4);
//    DLL->append(5);
//    DLL->append(6);
//    DLL->append(7);
//    DLL->append(8);
    DLL->printList();
    DLL->swapFirstLast();
    DLL->printList();
    return 0;
}
