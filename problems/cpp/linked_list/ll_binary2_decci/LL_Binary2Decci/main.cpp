//
//  main.cpp
//  LL_Binary2Decci
//
//  Created by CodeBreaker on 21/12/24.
//
/*
 Binary to Decimal ( ** Interview Question)
 Objective:

 You have a linked list where each node represents a binary digit (0 or 1). The goal of the binaryToDecimal function is to convert this binary number, represented by the linked list, into its decimal equivalent.



 Function Signature:

 int binaryToDecimal()



 How Binary to Decimal Conversion Works:

 In binary-to-decimal conversion, each position of a binary number corresponds to a specific power of 2, starting from the rightmost digit.

 The rightmost digit is multiplied by 2^0 (which equals 1).

 The next digit to the left is multiplied by 2^1 (which equals 2).

 The digit after that is multiplied by 2^2 (which equals 4). ... and so on.

 To find the decimal representation:

 Multiply each binary digit by its corresponding power of 2 value.

 Sum up all these products.



 Example Execution with Binary 101:

 Start with num = 0.

 Process 1 (from the head of the linked list): num = 0 * 2 + 1 = 1

 Process 0: num = 1 * 2 + 0 = 2

 Process 1: num = 2 * 2 + 1 = 5

 Return num, which is 5.



 Steps Involved in the Function:

 A variable num is initialized to 0, which will store our computed decimal number.

 Starting from the head of the linked list (the leftmost binary digit), iterate through each node until the end.

 For every node, double the current value of num (this is analogous to shifting in binary representation). Then, add the binary digit of the current node.

 Move to the next node and repeat until you've visited all nodes.

 Return the value in num, which now represents the decimal value of the binary number in the linked list.
 */
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

        //   +======================================================+
        //   |                 WRITE YOUR CODE HERE                 |
        //   | Description:                                         |
        //   | - Convert binary number in list to decimal           |
        //   | - Return type: int                                   |
        //   |                                                      |
        //   | Tips:                                                |
        //   | - Use a single pointer: 'current'                    |
        //   | - Initialize an integer 'num' to 0                   |
        //   | - Loop through the list                              |
        //   | - Use the formula: num = num * 2 + current->value    |
        //   | - Return 'num' as the decimal value                  |
        //   +======================================================+
    int binaryToDecimal()
    {
        int power=getLength()-1;
        Node *tmp=head;
        if(tmp==NULL) return -1;
        int ans=0;
        while(tmp)
        {
            ans+=(tmp->value)*1<<power;
            power-=1;
            tmp=tmp->next;
        }
        return ans;
    }
        
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Linked list binary to decimal!\n";
    LinkedList *LL = new LinkedList(1);
    LL->append(0);
    LL->append(1);
    LL->append(1);
    LL->printList();
    cout<<"Binary to decimal : "<<LL->binaryToDecimal()<<endl;
    return 0;
}
