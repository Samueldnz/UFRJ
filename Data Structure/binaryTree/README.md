# Binary Search Tree

This program implements a binary search tree in C. The binary search tree is a data structure that allows efficient searching, insertion, and deletion of nodes with logarithmic time complexity.

## Getting Started

To run the program, follow these steps:

1. Clone the repository or download the source code files.
2. Compile the code using a C compiler.
3. Run the compiled executable with the following command: ./binaryTree.exe < "input.txt"

### Important

Input.txt is a file that has many key values, you can either create it yourself or write code to do it for you. However, there are two rules: the first line must have how many nodes there will be in the Binary Tree, and the following lines must contain the key values ​​for each node, only one value per line.

## Functionality

The program provides the following functionality:

- Adding a new node to the binary search tree.
- Deleting a node from the binary search tree.
- Searching for a node in the binary search tree.
- Displaying the elements of the binary search tree in ascending order.

## Usage

Upon running the program, the user is prompted to enter the number of keys to add and the desired height of the binary search tree. Then, the user can perform the following actions:

1. Add a new node: The user can enter a new key value, and the program adds a new node with the given key to the binary search tree.
2. Delete a node: The user can enter a key value to delete a node with that key from the binary search tree.
3. Search for a node: The user can enter a key value to search for a node with that key in the binary search tree. If found, the program displays the details of the node.
4. Display the binary tree: The program prints the elements of the binary search tree in ascending order.
5. Exit: The program terminates.

## Data Structure

The binary search tree is implemented using a structure called `Node`, which contains the following fields:

- `valueKey`: The key value of the node.
- `leftSubTree`: Pointer to the left subtree of the node.
- `rightSubTree`: Pointer to the right subtree of the node.

## Functions

The program includes the following functions:

- `addNode`: Adds a node with a given key to the binary search tree.
- `deleteNode`: Deletes a node with a given key from the binary search tree.
- `searchNode`: Searches for a node with a given key in the binary search tree.
- `createNode`: Creates a new node with the given key.
- `printTreeInOrder`: Prints the elements of the binary search tree in ascending order.
- `findMinimumValueNode`: Finds the node with the minimum value in the binary search tree.
- `displayNode`: Displays the details of a node in the binary search tree.

## License

This project is licensed under the [MIT License](LICENSE).
