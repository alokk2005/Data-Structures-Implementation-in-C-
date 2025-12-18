#include <iostream>
#include <queue>
using namespace std;

/* ---------- LINKED LIST ---------- */
struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertLL(int val) {
    Node* temp = new Node();
    temp->data = val;
    temp->next = head;
    head = temp;
}

void deleteLL(int val) {
    Node *temp = head, *prev = NULL;
    while (temp && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) {
        cout << "Value not found\n";
        return;
    }
    if (!prev) head = temp->next;
    else prev->next = temp->next;
    delete temp;
    cout << "Value deleted successfully\n";
}

void displayLL() {
    if (!head) {
        cout << "Linked List is empty\n";
        return;
    }
    cout << "Linked List: ";
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

/* ---------- STACK ---------- */
#define MAX 100
int stack[MAX], top = -1;

void push(int x) {
    if (top == MAX - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    stack[++top] = x;
    cout << "Value pushed successfully\n";
}

void pop() {
    if (top == -1) {
        cout << "Stack Underflow\n";
        return;
    }
    cout << "Popped value: " << stack[top] << endl;
    top--;
}

void displayStack() {
    if (top == -1) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack elements: ";
    for (int i = top; i >= 0; i--)
        cout << stack[i] << " ";
    cout << endl;
}

/* ---------- QUEUE ---------- */
int q[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) {
        cout << "Queue Overflow\n";
        return;
    }
    if (front == -1) front = 0;
    q[++rear] = x;
    cout << "Value enqueued successfully\n";
}

void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue Underflow\n";
        return;
    }
    cout << "Dequeued value: " << q[front] << endl;
    front++;
}

void displayQueue() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty\n";
        return;
    }
    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++)
        cout << q[i] << " ";
    cout << endl;
}

/* ---------- BINARY SEARCH TREE ---------- */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) {
        TreeNode* node = new TreeNode();
        node->val = val;
        node->left = node->right = NULL;
        cout << "Value inserted in BST\n";
        return node;
    }
    if (val < root->val)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);
    return root;
}

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

/* ---------- MAIN MENU ---------- */
int main() {
    int choice, val;
    TreeNode* bstRoot = NULL;

    do {
        cout << "\n----- MAIN MENU -----\n";
        cout << "1. Linked List\n";
        cout << "2. Stack\n";
        cout << "3. Queue\n";
        cout << "4. Binary Search Tree\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\n1. Insert\n2. Delete\n3. Display\nEnter choice: ";
            cin >> choice;
            if (choice == 1) {
                cout << "Enter value to insert: ";
                cin >> val;
                insertLL(val);
            } else if (choice == 2) {
                cout << "Enter value to delete: ";
                cin >> val;
                deleteLL(val);
            } else if (choice == 3) {
                displayLL();
            }
            break;

        case 2:
            cout << "\n1. Push\n2. Pop\n3. Display\nEnter choice: ";
            cin >> choice;
            if (choice == 1) {
                cout << "Enter value to push: ";
                cin >> val;
                push(val);
            } else if (choice == 2) {
                cout << "Enter value to pop\n";
                pop();
            } else if (choice == 3) {
                displayStack();
            }
            break;

        case 3:
            cout << "\n1. Enqueue\n2. Dequeue\n3. Display\nEnter choice: ";
            cin >> choice;
            if (choice == 1) {
                cout << "Enter value to enqueue: ";
                cin >> val;
                enqueue(val);
            } else if (choice == 2) {
                cout << "Enter value to dequeue\n";
                dequeue();
            } else if (choice == 3) {
                displayQueue();
            }
            break;

        case 4:
            cout << "\n1. Insert\n2. Inorder Traversal\nEnter choice: ";
            cin >> choice;
            if (choice == 1) {
                cout << "Enter value to insert in BST: ";
                cin >> val;
                bstRoot = insertBST(bstRoot, val);
            } else if (choice == 2) {
                cout << "BST Inorder Traversal: ";
                inorder(bstRoot);
                cout << endl;
            }
            break;

        case 5:
            cout << "Exiting program...\n";
            break;
        }
    } while (choice != 5);

    return 0;
}
