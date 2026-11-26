
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

// Create a new node
struct node* createNode(int value)
{
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = NULL;

    return newnode;
}

// Create the doubly linked list
void createList()
{
    struct node *newnode, *temp;
    int value, choice = 1;

    while (choice == 1)
    {
        printf("Enter data: ");
        scanf("%d", &value);

        newnode = createNode(value);

        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newnode;
            newnode->prev = temp;
        }

        printf("Do you want to continue? (1/0): ");
        scanf("%d", &choice);
    }
}

// Insert a node to the left of a specified value
void insertLeft(int key, int value)
{
    struct node *temp, *newnode;

    temp = head;

    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Node not found\n");
        return;
    }

    newnode = createNode(value);

    newnode->next = temp;
    newnode->prev = temp->prev;

    if (temp->prev != NULL)
    {
        temp->prev->next = newnode;
    }
    else
    {
        head = newnode;
    }

    temp->prev = newnode;

    printf("Node inserted successfully\n");
}

// Delete a node based on its value
void deleteNode(int key)
{
    struct node *temp;

    temp = head;

    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Node not found\n");
        return;
    }

    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    else
    {
        head = temp->next;
    }

    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    free(temp);

    printf("Node deleted successfully\n");
}

// Display the list
void display()
{
    struct node *temp;

    temp = head;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Doubly Linked List: ");

    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    int key, value;

    printf("Create Doubly Linked List\n");
    createList();

    display();

    printf("\nEnter the node value before which to insert: ");
    scanf("%d", &key);

    printf("Enter new value: ");
    scanf("%d", &value);

    insertLeft(key, value);
    display();

    printf("\nEnter the value to delete: ");
    scanf("%d", &key);

    deleteNode(key);
    display();

    return 0;
}

