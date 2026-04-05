#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
struct Node {
    int flightID;
    char flightName[50];
    int gateNumber;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int id, char name[], int gate) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->flightID = id;
    strcpy(newNode->flightName, name);
    newNode->gateNumber = gate;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert (CREATE)
struct Node* insert(struct Node* root, int id, char name[], int gate) {
    if (root == NULL)
        return createNode(id, name, gate);

    if (id < root->flightID)
        root->left = insert(root->left, id, name, gate);
    else if (id > root->flightID)
        root->right = insert(root->right, id, name, gate);
    else
        printf("Flight ID already exists!\n");

    return root;
}

// Inorder Traversal (READ)
void display(struct Node* root) {
    if (root != NULL) {
        display(root->left);
        printf("Flight ID: %d | Name: %s | Gate: %d\n",
               root->flightID, root->flightName, root->gateNumber);
        display(root->right);
    }
}

// Search node
struct Node* search(struct Node* root, int id) {
    if (root == NULL || root->flightID == id)
        return root;

    if (id < root->flightID)
        return search(root->left, id);
    else
        return search(root->right, id);
}

// Update (UPDATE)
void update(struct Node* root, int id) {
    struct Node* temp = search(root, id);

    if (temp == NULL) {
        printf("Flight not found!\n");
        return;
    }

    printf("Enter new Gate Number: ");
    scanf("%d", &temp->gateNumber);

    printf("Gate updated successfully!\n");
}

// Find minimum node (for delete)
struct Node* findMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Delete node (DELETE)
struct Node* deleteNode(struct Node* root, int id) {
    if (root == NULL)
        return root;

    if (id < root->flightID)
        root->left = deleteNode(root->left, id);
    else if (id > root->flightID)
        root->right = deleteNode(root->right, id);
    else {
        // Node with one or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        struct Node* temp = findMin(root->right);
        root->flightID = temp->flightID;
        strcpy(root->flightName, temp->flightName);
        root->gateNumber = temp->gateNumber;

        root->right = deleteNode(root->right, temp->flightID);
    }
    return root;
}

// Main Menu
int main() {
    struct Node* root = NULL;
    int choice, id, gate;
    char name[50];

    while (1) {
        printf("\n--- Airport Gate Management ---\n");
        printf("1. Add Flight (Create)\n");
        printf("2. Display Flights (Read)\n");
        printf("3. Update Gate\n");
        printf("4. Delete Flight\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter Flight ID: ");
            scanf("%d", &id);
            printf("Enter Flight Name: ");
            scanf("%s", name);
            printf("Enter Gate Number: ");
            scanf("%d", &gate);
            root = insert(root, id, name, gate);
            break;

        case 2:
            printf("\nFlight Allocations:\n");
            display(root);
            break;

        case 3:
            printf("Enter Flight ID to update: ");
            scanf("%d", &id);
            update(root, id);
            break;

        case 4:
            printf("Enter Flight ID to delete: ");
            scanf("%d", &id);
            root = deleteNode(root, id);
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }
}