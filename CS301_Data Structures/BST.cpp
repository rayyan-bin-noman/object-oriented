// Binary Search Tree (BST) Implementation in C++
#include <iostream>
using namespace std;

// Global variable to keep track of total nodes in the tree
int nodeCount = 0;

// Node class: represents a single node in BST
class Node
{
public:
    int data;       // Value stored in the node
    Node* left;     // Pointer to left child
    Node* right;    // Pointer to right child

    // Constructor to initialize a node
    Node(int val)
    {
        data = val;
        left = right = NULL;   // Initially, children are NULL
    }
};

// BST class: contains all operations on the BST
class BST
{
public:
    Node* root;     // Root node of the tree

    // Constructor to initialize an empty tree
    BST()
    {
        root = NULL;
    }

    //================= INSERT NODE =================
    void insert()
    {
        int val;
        cout << "\nPlease insert value: ";
        cin >> val;

        Node* newnode = new Node(val);  // Create a new node with input value

        // If tree is empty, new node becomes root
        if (root == NULL)
        {
            root = newnode;
            cout << "\nNew node successfully inserted on the root";
        }
        else
        {
            Node* pre = NULL;     // Pointer to track parent node
            Node* temp = root;    // Pointer to traverse tree

            // Traverse tree to find correct position
            while (temp != NULL)
            {
                if (val < temp->data)       // Go to left subtree
                {
                    pre = temp;
                    temp = temp->left;

                    if (temp == NULL)      // Found position on left
                    {
                        pre->left = newnode;
                        cout << "\nNew node successfully inserted on the left";
                    }
                }
                else if (val > temp->data)  // Go to right subtree
                {
                    pre = temp;
                    temp = temp->right;

                    if (temp == NULL)      // Found position on right
                    {
                        pre->right = newnode;
                        cout << "\nNew node successfully inserted on the right";
                    }
                }
                else    // Duplicate value found, cannot insert
                {
                    delete newnode;
                    cout << "\nDuplicate value found & removed";
                    return;
                }
            }
        }
        nodeCount++;    // Increment total node count
    }

    //================= SEARCH NODE =================
    void search()
    {
        if (root == NULL)
        {
            cout << "\nTree is empty...";
            return;
        }

        Node* temp = root;      // Start traversal from root
        int val;
        cout << "\nPlease enter value to search: ";
        cin >> val;

        while (temp != NULL)
        {
            if (val == temp->data)     // Value found
            {
                cout << "\nValue " << val << " found in the tree";
                return;
            }
            else if (val < temp->data) // Search in left subtree
            {
                temp = temp->left;
            }
            else                        // Search in right subtree
            {
                temp = temp->right;
            }
        }

        // Value not found after traversal
        cout << "\nValue " << val << " not found in the tree";
    }

    //================= DELETE NODE HELPERS =================
    Node* findMin(Node* node)    // Find minimum value node in a subtree
    {
        while (node && node->left != NULL)      // Go to leftmost node
            node = node->left;                  // Keep moving left
        return node;
    }

    Node* deleteNode(Node* node, int key)  // Recursive function to delete a node
    {
        if (node == NULL) return NULL;

        if (key < node->data)               // Go to left subtree
            node->left = deleteNode(node->left, key);       // Recursive call on left child
        else if (key > node->data)          // Go to right subtree
            node->right = deleteNode(node->right, key);     // Recursive call on right child
        else
        {
            // Case 1: Node has no children
            if (node->left == NULL && node->right == NULL)      // Leaf node
            {
                delete node;
                return NULL;
            }
            // Case 2: Node has one child
            else if (node->left == NULL)            // Only right child
            {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == NULL)           // Only left child  
            {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            // Case 3: Node has two children
            Node* temp = findMin(node->right);    // Find inorder successor
            node->data = temp->data;              // Replace value
            node->right = deleteNode(node->right, temp->data);  // Delete successor
        }
        return node;
    }

    //================= DELETE NODE =================
    void deleteValue()
    {
        if (root == NULL)
        {
            cout << "\nTree is empty...";
            return;
        }

        int val;
        cout << "\nEnter value to delete: ";
        cin >> val;

        if (!searchForUpdate(root, val))   // Check if value exists before deletion
        {
            cout << "\nValue " << val << " not found. Delete failed.\n";
            return;
        }

        root = deleteNode(root, val);     // Delete node safely
        cout << "\nValue deleted successfully.\n";
    }

    //================= UPDATE NODE =================
    void update()
    {
        if (root == NULL)
        {
            cout << "\nTree is empty...";
            return;
        }

        int oldVal, newVal;
        cout << "\nEnter the value you want to update: ";
        cin >> oldVal;

        if (!searchForUpdate(root, oldVal))   // Check if old value exists
        {
            cout << "\nValue " << oldVal << " not found. Update failed.\n";
            return;
        }

        cout << "Enter the new value: ";
        cin >> newVal;

        // Safe update: delete old value → insert new value
        root = deleteNode(root, oldVal);
        insertNewValue(newVal);

        cout << "\nValue updated successfully without breaking BST property.\n";
    }

    // Helper function: check if a value exists in the tree
    bool searchForUpdate(Node* node, int key)
    {
        if (node == NULL) return false;
        if (key == node->data) return true;
        if (key < node->data) return searchForUpdate(node->left, key);
        else return searchForUpdate(node->right, key);
    }

    // Helper function: insert new value (used by update)
    void insertNewValue(int val)
    {
        Node* newnode = new Node(val);      // Create a new node with input value

        if (root == NULL)
        {
            root = newnode;
            return;
        }

        Node* pre = NULL;
        Node* temp = root;

        while (temp != NULL)
        {
            if (val < temp->data)
            {
                pre = temp;
                temp = temp->left;
                if (temp == NULL)
                    pre->left = newnode;
            }
            else if (val > temp->data)
            {
                pre = temp;
                temp = temp->right;
                if (temp == NULL)
                    pre->right = newnode;
            }
            else
            {
                delete newnode;
                return;
            }
        }
    }

    //================= COUNT NODES =================
    void count()
    {
        cout << "\nTotal number of nodes in the tree: " << nodeCount;
    }

    //================= TRAVERSALS =================
    // Inorder Traversal: Left → Node → Right (LNR)
    void InOrderTraversal(Node* temp)
    {
        if (temp == NULL) return;
        InOrderTraversal(temp->left);           // Visit left subtree up to leaf
        cout << temp->data << " ";              // Visit node
        InOrderTraversal(temp->right);          // Visit right subtree up to leaf
    }

    // Preorder Traversal: Node → Left → Right (NLR)
    void PreOrderTraversal(Node* temp)
    {
        if (temp == NULL) return;
        cout << temp->data << " ";              // Visit node   
        PreOrderTraversal(temp->left);          // Visit left subtree up to leaf
        PreOrderTraversal(temp->right);         // Visit right subtree up to leaf
    }

    // Postorder Traversal: Left → Right → Node (LRN)
    void PostOrderTraversal(Node* temp)
    {
        if (temp == NULL) return;
        PostOrderTraversal(temp->left);             // Visit left subtree up to leaf
        PostOrderTraversal(temp->right);            // Visit right subtree up to leaf
        cout << temp->data << " ";                   // Visit node  
    }
};

//================= MAIN FUNCTION =================
int main()
{
    BST tree;

    while (true)
    {
        int choice;
        cout << "\n\n***** Binary Search Tree Menu ***** ";
        cout << "\n1: Insert Record";
        cout << "\n2: Search Record";
        cout << "\n3: Update Record";
        cout << "\n4: Delete Record";
        cout << "\n5: Count Nodes";
        cout << "\n6: Inorder Traversal";
        cout << "\n7: Preorder Traversal";
        cout << "\n8: Postorder Traversal";
        cout << "\n9: Exit";
        cout << "\n\nPlease Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: tree.insert(); break;
        case 2: tree.search(); break;
        case 3: tree.update(); break;
        case 4: tree.deleteValue(); break;
        case 5: tree.count(); break;
        case 6: tree.InOrderTraversal(tree.root); break;
        case 7: tree.PreOrderTraversal(tree.root); break;
        case 8: tree.PostOrderTraversal(tree.root); break;
        case 9: exit(0);
        default: cout << "\nInvalid choice.....Please try again"; break;
        }
    }

    return 0;
}
