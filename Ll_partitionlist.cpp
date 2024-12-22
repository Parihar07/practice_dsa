//
//  Ll_partitionlist.cpp
//  LL_partitionList
//
//  Created by CodeBreaker on 20/12/24.
//

#include "Ll_partitionlist.hpp"
//
//  testcases.cpp
//  LL_partitionList
//
//  Created by CodeBreaker on 20/12/24.
//

#include <iostream>
#include "../practice_dsa/LL_partitionList/LL_partitionList/main.cpp"

using namespace std;


//  +=====================================================+
//  |                                                     |
//  |          THE TEST CODE BELOW WILL PRINT             |
//  |              OUTPUT TO "USER LOGS"                  |
//  |                                                     |
//  |  Use the output to test and troubleshoot your code  |
//  |                                                     |
//  +=====================================================+


static void test() {
    // Helper function to check pass/fail
    auto checkTestResult = [](bool condition) {
        cout << (condition ? "PASS" : "FAIL") << endl;
    };

    // Test: PartitionEmptyList
    {
        cout << "\n------ Test: PartitionEmptyList ------\n";
        
        LinkedList list(1);
        list.makeEmpty();
        
        cout << "BEFORE:    ";
        list.printList();
        
        cout << "partitionList(3)\n";
        cout << "EXPECTED:  empty\n";
        
        list.partitionList(3);
        
        cout << "ACTUAL:    ";
        list.printList();
        
        Node* head = list.getHead();
        checkTestResult(head == nullptr);
    }

    // Test: PartitionSingleElement
    {
        cout << "\n------ Test: PartitionSingleElement ------\n";
        
        LinkedList list(1);
        
        cout << "BEFORE:    ";
        list.printList();
        
        cout << "partitionList(3)\n";
        cout << "EXPECTED:  1\n";
        
        list.partitionList(3);
        
        cout << "ACTUAL:    ";
        list.printList();
        
        Node* head = list.getHead();
        checkTestResult(head && head->value == 1);
    }

    // Test: PartitionAllLessThanX
    {
        cout << "\n------ Test: PartitionAllLessThanX ------\n";
        
        LinkedList list(1);
        list.append(2);
        list.append(3);
        
        cout << "BEFORE:    ";
        list.printList();
        
        cout << "partitionList(4)\n";
        cout << "EXPECTED:  1 -> 2 -> 3\n";
        
        list.partitionList(4);
        
        cout << "ACTUAL:    ";
        list.printList();
        
        Node* head = list.getHead();
        checkTestResult(head && head->value == 1);
    }

    // Test: PartitionMixedNumbers
    {
        cout << "\n------ Test: PartitionMixedNumbers ------\n";
        
        LinkedList list(1);
        list.append(4);
        list.append(3);
        list.append(2);
        list.append(5);
        list.append(2);
        
        cout << "BEFORE:    ";
        list.printList();
        
        cout << "partitionList(3)\n";
        cout << "EXPECTED:  1 -> 2 -> 2 -> 4 -> 3 -> 5\n";
        
        list.partitionList(3);
        
        cout << "ACTUAL:    ";
        list.printList();
        
        // Check if the list is partitioned correctly
        Node* current = list.getHead();
        bool isPartitioned = true;
        bool crossedPartitionValue = false;
        
        while (current && current->next) {
            if (current->value >= 3) {
                crossedPartitionValue = true;
            }
            if (crossedPartitionValue && current->value < 3) {
                isPartitioned = false;
                break;
            }
            current = current->next;
        }

        
        checkTestResult(isPartitioned);
    }
}




