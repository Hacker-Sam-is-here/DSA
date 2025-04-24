#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for a BST node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a node into the BST
Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    
    return root;
}

// Search for a value in the BST
Node* search(Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    
    if (value < root->data) {
        return search(root->left, value);
    }
    return search(root->right, value);
}

// Find minimum value node in BST
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Delete a node from BST
Node* deleteNode(Node* root, int value) {
    if (root == NULL) {
        return root;
    }
    
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        
        // Node with two children
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Inorder traversal of BST
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postOrder(struct Node* root){
    if(root!=NULL){            
       postOrder(root->left);
       postOrder(root->right);
       printf("%d ",root->data);
    }
 }

// Main function to test the BST operations
int main() {
    Node* root = NULL;
    
    // Insert nodes
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal of the BST: ");
    inorder(root);
    printf("\n");

    // Search for a value
    int search_value = 40;
    Node* found = search(root, search_value);
    if (found != NULL) {
        printf("%d found in the BST\n", search_value);
    } else {
        printf("%d not found in the BST\n", search_value);
    }

    // Delete a node
    int delete_value = 30;
    root = deleteNode(root, delete_value);
    printf("Inorder traversal after deleting %d: ", delete_value);
    inorder(root);
    printf("\n");

    return 0;
}