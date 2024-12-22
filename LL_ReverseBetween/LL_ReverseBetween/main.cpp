//
//  main.cpp
//  LL_ReverseBetween
//
//  Created by CodeBreaker on 21/12/24.
//

#include <iostream>
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
    
        void deleteFirst() {
            if (length == 0) return;
            Node* temp = head;
            if (length == 1) {
                head = nullptr;
            } else {
                head = head->next;
            }
            delete temp;
            length--;
        }
    
        //   +======================================================+
        //   |                 WRITE YOUR CODE HERE                 |
        //   | Description:                                         |
        //   | - Reverse nodes between positions m and n            |
        //   | - Return type: void                                  |
        //   |                                                      |
        //   | Tips:                                                |
        //   | - Create a dummy node and set its next to head       |
        //   | - Use 'prev' pointer to go to m-th node              |
        //   | - Use 'current' pointer for m+1 to n nodes           |
        //   | - Loop to reverse m+1 to n nodes                     |
        //   | - Update original list's head                        |
        //   | - Free dummy node memory                             |
        //   +======================================================+
    void reverseBetween(int m, int n)
    {
        Node *tmp = head, *prev=NULL;
        int cnt=0;
        if(m>length || n>length) return;
        if(tmp==NULL) return;
        while(cnt<m)
        {
            prev=tmp;
            tmp=tmp->next;
            cnt++;
        }
        Node *C=tmp, *A=C->next, *B=NULL;
        while(cnt<=n)
        {
            A=C->next;
            C->next = B;
            B=C;
            C=A;
            cnt++;
        }
        if(m!=0)
        {
            prev->next = B;
        } else {
            head = B;
        }
        tmp->next=A;
    }
    
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Linked list bweteen indicies!\n";
    LinkedList *LL = new LinkedList(1);
    LL->append(2);
    LL->append(3);
    LL->append(4);
    LL->append(5);
    LL->append(6);
    LL->append(7);
    LL->append(8);
    LL->printList();
    LL->reverseBetween(0, 7);
    LL->printList();
    return 0;
}
