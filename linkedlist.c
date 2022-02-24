#include <stdio.h>
#include <stdlib.h>

/// Linked List implementation (thanks to Jacob Sorter-sensei)
/* Ideas:
    A linked list is a bunch of items that are connected to one another. Accessing one item gives you not only the item itself, but also a pointer to
    where the next item can be found.

    A node is a structure, containing the "item" and also a pointer to where the next item in the linked list is.

    > The head of the linked list is where the linked list starts, it is the first node in the linked list.
    > The tail of the linked list is where the linked list ends, it is the last node in the linked list. We know this because the pointer to the next
    node says NULL...

*/


struct node
{
    char *str;  // dynamically allocated!!!
    struct node *next;
};
typedef struct node node_t;




// Takes a linked list and iteratively prints all strings in nodes throughout the linked list.
void printlist(node_t *head);

// Creates and returns a pointer to a new node.
node_t *create_new_node(char *dyn_str);

// Takes `node_to_insert` and makes `node_to_insert` point to `head`, effectively making `node_to_insert` the new head of the linked list.
node_t *insert_at_head(node_t **head, node_t *node_to_insert);

// Finds the end of the linked list for you and then inserts `node_to_insert` at the very end of the linked list, making it the new tail of the list.
node_t *insert_at_tail(node_t **head, node_t *node_to_insert);

// Takes `insert_after_this` and makes it point to `newnode`,
void insert_after_node(node_t *newnode, node_t *insert_after_this);

void insert_after_index(node_t *newnode, node_t *head, size_t index);
node_t *find_node(node_t *head, char *find_str);


void printlist(node_t *head)
{
    node_t *temporary = head;

    while (temporary)
    {
        printf("%s\n", temporary->str);

        temporary = temporary->next;
    }
    //printf("\n");
}

node_t *create_new_node(char *dyn_str)
{
    node_t *returnptr = calloc(1, sizeof(node_t));
    returnptr->str = dyn_str;
    returnptr->next = NULL;

    return returnptr;
}

node_t *insert_at_head(node_t **head, node_t *node_to_insert)
{
    node_to_insert->next = *head;
    *head = node_to_insert;  // this return value should now be assigned to the head pointer, cause now this is the first item of the linked list
    return node_to_insert;
}

node_t *insert_at_tail(node_t **head, node_t *node_to_insert)
{
    // Safety Net: If there is no head (for example a new linked list) it may be NULL. This can end up getting dereferenced.
    if (*head == NULL)
        return insert_at_head(head, node_to_insert);

    node_t *temp = *head;

    while (temp)
    {
        if (temp->next)
            temp = temp->next;
        else
            break;
    }

    temp->next = node_to_insert;
    node_to_insert->next = NULL;

    return node_to_insert;
}

void insert_after_node(node_t *newnode, node_t *insert_after_this)
{
    newnode->next = insert_after_this->next;
    insert_after_this->next = newnode;
}

void insert_after_index(node_t *newnode, node_t *head, size_t index)
{
    node_t *temp = head;
    for (size_t i = 0; i < index; i++)
    {
        if (temp->next == NULL)
            break;

        temp = temp->next;
    }

    node_t *temp2 = temp->next;
    temp->next = newnode;
    newnode->next = temp2;
}

node_t *find_node(node_t *head, char *find_str)
{
    node_t *tmp = head;

    while (tmp)
    {
        if (strcmp(find_str, tmp->str) == 0)
            return tmp;

        tmp = tmp->next;
    }

    return NULL;
}
