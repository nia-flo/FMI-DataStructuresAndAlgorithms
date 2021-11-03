# Delete a node

Delete the node at a given position in a linked list and return a reference to the head node. The head is at position 0. The list may be empty after you delete the node. In that case, return a null value. 

### Example

llist = 0 -> 1 -> 2 -> 3 <br>
position = 2

After removing the node at position 2, llist = 0 -> 1 -> 3

### Function Description

Complete the *deleteNode* function in the editor below.

*deleteNode* has the following parameters:
- SinglyLinkedListNode pointer llist: a reference to the head node in the list
- int position: the position of the node to remove

### Returns
- SinglyLinkedListNode pointer: a reference to the head of the modified list 

### Input Format

The first line of input contains an integer n, the number of elements in the linked list.
Each of the next n lines contains an integer, the node data values in order.
The last line contains an integer, position, the position of the node to delete. 

### Constraints

1 <= n <= 1000 <br>
1 <= list[i] <= 1000, where list[i] is the i-th element of the linked list.

### Sample Input

8 <br>
20 <br>
6 <br>
2 <br>
19 <br>
7 <br>
4 <br>
15 <br>
9 <br>
3

### Sample Output

20 6 2 7 4 15 9

### Explanation

The original list is 20 -> 6 -> 2 -> 19 -> 7 -> 4 -> 15 -> 9. After deleting the node at position 3, the list is 20 -> 6 -> 2 -> 7 -> 4 -> 15 -> 9.
