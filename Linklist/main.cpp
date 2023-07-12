
#include <iostream>
#include <vector>
#include "LinkList.h"
#include "DoublyLinkList.h"
using namespace std;

int maxSubarraySum(const std::vector<int>& nums) {
    int currentSum = nums[0];
    int maxSum = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        // Calculate the maximum sum including the current element
        currentSum = std::max(nums[i], currentSum + nums[i]);

        // Update the maximum sum if the current sum is greater
        maxSum = std::max(maxSum, currentSum);
    }

    return maxSum;
}
void moveZeroes(vector<int>& nums) {
    // 
    int counter = 0;
    cout << "[";
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            cout << nums[i] << ",";
        }
        else {
            counter++;
        }
    }
    for (int j = 0; j < counter; j++) {
        cout << 0;
        if (j != counter - 1) {
            cout << ",";
        }
    }
    cout << "]";


}
int main() {
    std::vector<int> nums = { 0,1,0,3,12 };
    LinkedList list;
    
    // Add nodes to the list
    list.addNodeToHead(10);
    list.addNodeToHead(20);
    list.addNodeToTail(30);
    list.addNode(40, 3);
    list.addNode(50, 4);
    list.addNode(530,5);

    list.removeValue(20);
    // Print the list
    cout << "Linked List: ";
    list.printList();
    cout << endl;

    // Get item at position
    cout << "Item at position 2: " << list.getItem(2) << endl;
    cout << "Item at position 4: " << list.getItem(4) << endl;
    cout << endl;

    // Remove nodes from the list
    cout << "Removed Head: " << list.removeHead() << endl;
    cout << "Removed Tail: " << list.removeTail() << endl;
    cout << "Removed At position 2: " << list.removeAt(2) << endl;

    // Print the updated list
    cout << "Linked List after removal: ";
    list.printList();
    cout << endl;

    // Double linked list
    cout << "Double link list started ";
    DoublyLinkedList dLL;
    dLL.addNodeToTail(19);
    dLL.addNodeToTail(29);
    dLL.printList();
    
    return 0;
}