//
//  main.cpp
//  DLL_isPalindrome
//
//  Created by CodeBreaker on 22/12/24.
//
/*
 Reverse ( ** Interview Question)
 Implement a member function called reverse() that reverses the order of the nodes in the list.

 Input:
 The function is a member of the DoublyLinkedList class, which has a head and a tail pointer, as well as a length attribute.



 Output:
 No explicit output is returned. However, the function should modify the doubly linked list such that the order of the nodes is reversed.



 Constraints:
 The doubly linked list may be empty, have only one node, or have two or more nodes.



 Example:

 Consider the following doubly linked list:

 Head: 1
 Tail: 5
 Length: 5
  
 Doubly Linked List:
 1 <-> 2 <-> 3 <-> 4 <-> 5


 After calling reverse(), the list should be:

 Head: 5
 Tail: 1
 Length: 5
  
 Doubly Linked List:
 5 <-> 4 <-> 3 <-> 2 <-> 1


 Note that the list is reversed by updating the prev and next pointers of each node.
 */
#include <iostream>
#include<unordered_set>
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
        //   | - This is the isPalindrome method.                  |
        //   | - It checks if the list is a palindrome or not.     |
        //   | - Return type: bool                                 |
        //   |                                                     |
        //   | Tips:                                               |
        //   | - A list with 0 or 1 node is a palindrome.          |
        //   | - Create two pointers: forwardNode and backwardNode.|
        //   | - Loop from the start to the middle of the list.    |
        //   | - Compare forwardNode and backwardNode values.      |
        //   | - If any pair is not equal, return false.           |
        //   | - Otherwise, return true.                           |
        //   | - Check output from Test.cpp in "User logs".        |
        //   +=====================================================+
    bool isPalindrome()
    {
        if(length==1) return true;
        Node* h = head;
        Node* t = tail;
        unordered_set<Node *> S;
        cout<<"Result of set : " << (S.find(h)!=S.end()) <<endl;
        while((S.find(h)==S.end()) || (S.find(t)==S.end()))
        {
            S.insert(h); S.insert(t);
            if(h->value!=t->value) return false;
            h=h->next;
            t=t->prev;
        }
        return true;
    }

    bool isPalindromeActual() {
                if (length <= 1) return true;
            
                Node* forwardNode = head;
                Node* backwardNode = tail;
                for (int i = 0; i < length / 2; i++) {
                    if (forwardNode->value != backwardNode->value) return false;
                    forwardNode = forwardNode->next;
                    backwardNode = backwardNode->prev;
                }
                return true;
            }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, doubly linked list isplaindrome!\n";
    DoublyLinkedList *DLL = new DoublyLinkedList(1);
    DLL->append(1);
    DLL->append(1);
    DLL->append(1);
    DLL->append(0);
    DLL->append(1);
    DLL->printList();
    cout<<DLL->isPalindrome()<<endl;
    return 0;
}
