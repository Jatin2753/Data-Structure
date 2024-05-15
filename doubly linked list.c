#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist {
    struct linkedlist *prev;
    int info;
    struct linkedlist *next;
} node;

void insert_beg(node **, node **, int);
void traversing(node *);
void reverse_traversing(node *);
void insert_end(node **, node **, int);
node* searching(node *, int);
void insert_afer_elem(node *, node **, int, int);
void insert_before_elem(node **, node *, int, int);
void delete_at_beg(node **, node **);
void delete_at_end(node **, node **);
void delete_after_elem(node *, node **, int);
void delete_before_elem(node **, node *, int);

int main() {
    node *head = NULL, *tail = NULL;
    int c, val, val1;
    while (1) {
        printf("\n");
        printf("1. insert at beginning\n");
        printf("2. insert at end\n");
        printf("3. insert after element\n");
        printf("4. insert before element\n");
        printf("5. delete at beginning\n");
        printf("6. delete at end\n");
        printf("7. delete after element\n");
        printf("8. delete before element\n");
        printf("9. traversing\n");
        printf("10. reverse traversing\n");
        printf("11. searching\n");
        printf("12. Exit\n");
        printf("Enter choice for operations: ");
        scanf("%d", &c);
        switch (c) {
            case 1:
                printf("enter value : ");
                scanf("%d", &val);
                insert_beg(&head, &tail, val);
                break;
            case 2:
                printf("enter value : ");
                scanf("%d", &val);
                insert_end(&head, &tail, val);
                break;
            case 3:
                printf("enter before value : ");
                scanf("%d", &val);
                printf("enter value : ");
                scanf("%d", &val1);
                insert_afer_elem(head, &tail, val, val1);
                break;
            case 4:
                printf("enter after value : ");
                scanf("%d", &val);
                printf("enter value : ");
                scanf("%d", &val1);
                insert_before_elem(&head, tail, val, val1);
                break;
            case 5:
                delete_at_beg(&head, &tail);
                break;
            case 6:
                delete_at_end(&head, &tail);
                break;
            case 7:
                printf("enter value : ");
                scanf("%d", &val);
                delete_after_elem(head, &tail, val);
                break;
            case 8:
                printf("enter value : ");
                scanf("%d", &val);
                delete_before_elem(&head, tail, val);
                break;
            case 9:
                traversing(head);
                break;
            case 10:
                reverse_traversing(tail);
                break;
            case 11:
                printf("enter value : ");
                scanf("%d", &val);
                printf("the value is available at : %p\n", searching(head, val));
                break;
            case 12:
                exit(0);
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}

void insert_beg(node **head1, node **tail1, int val) {
    node *temp;
    temp = (node *)malloc(sizeof(node));
    if (temp == NULL) {
        printf("memory doesn't allocated\n");
        return;
    }
    temp->info = val;
    temp->prev = NULL;
    if (*head1 == NULL) {
        temp->next = NULL;
        *head1 = temp;
        *tail1 = temp;
    } else {
        temp->next = (*head1);
        (*head1)->prev = temp;
        *head1 = temp;
    }
}

void traversing(node *head1) {
    while (head1 != NULL) {
        printf("%d->", head1->info);
        head1 = head1->next;
    }
    printf("\n");
}

void reverse_traversing(node *tail) {
    while (tail != NULL) {
        printf("%d->", tail->info);
        tail = tail->prev;
    }
    printf("\n");
}

void insert_end(node **head1, node **tail1, int val) {
    node *temp;
    temp = (node *)malloc(sizeof(node));
    if (temp == NULL) {
        printf("memory doesn't allocated\n");
        return;
    }
    temp->info = val;
    temp->next = NULL;
    temp->prev = *tail1;
    if (*tail1 == NULL) {
        *head1 = temp;
    } else {
        (*tail1)->next = temp;
    }
    *tail1 = temp;
}

node* searching(node *head, int val) {
    while (head != NULL) {
        if (head->info == val) {
            return head;
        }
        head = head->next;
    }
    return NULL; 
}

void insert_afer_elem(node *head, node **tail1, int val, int val1) {
    node *temp, *loc;
    temp = (node *)malloc(sizeof(node));
    loc = searching(head, val);
    if (temp == NULL) {
        printf("memory doesn't allocated\n");
        return;
    }
    if (loc != NULL) {
        temp->info = val1;
        temp->next = loc->next;
        temp->prev = loc;
        if (loc->next != NULL)
            (loc->next)->prev = temp;
        loc->next = temp;
        if (temp->next == NULL)
            *tail1 = temp;
    } else {
        printf("Value %d not found in the list.\n", val);
    }
}

void insert_before_elem(node **head1, node *tail, int val, int val1) {
    node *temp, *loc;
    temp = (node *)malloc(sizeof(node));
    loc = searching(*head1, val);
    if (temp == NULL) {
        printf("Memory not allocated\n");
        return;
    }
    if (loc != NULL) {
        temp->info = val1;
        temp->next = loc;
        temp->prev = loc->prev;
        if (loc->prev != NULL)
            (loc->prev)->next = temp;
        else
            *head1 = temp;
        loc->prev = temp;
    } else {
        printf("Value %d not found in the list.\n", val);
    }
}

void delete_at_beg(node **head1, node **tail1) {
    if (*head1 == NULL) {
        printf("List is empty.\n");
        return;
    }
    node *temp = *head1;
    if ((*head1)->next == NULL) {
        *head1 = NULL;
        *tail1 = NULL;
    } else {
        *head1 = (*head1)->next;
        (*head1)->prev = NULL;
    }
    free(temp);
}

void delete_at_end(node **head1, node **tail1) {
    if (*tail1 == NULL) {
        printf("List is empty.\n");
        return;
    }
    node *temp = *tail1;
    if ((*tail1)->prev == NULL) {
        *head1 = NULL;
        *tail1 = NULL;
    } else {
        *tail1 = (*tail1)->prev;
        (*tail1)->next = NULL;
    }
    free(temp);
}

void delete_after_elem(node *head, node **tail1, int val) {
    node *loc = searching(head, val);
    if (loc == NULL || loc->next == NULL) {
        printf("Element not found or it's the last element.\n");
        return;
    }
    node *temp = loc->next;
    loc->next = temp->next;
    if (temp->next != NULL)
        (temp->next)->prev = loc;
    if (temp == *tail1)
        *tail1 = loc;
    free(temp);
}

void delete_before_elem(node **head1, node *tail, int val) {
    node *loc = searching(*head1, val);
    if (loc == NULL || loc->prev == NULL) {
        printf("Element not found or it's the first element.\n");
        return;
    }
    node *temp = loc->prev;
    if (temp == *head1)
        *head1 = loc;
    else
        (temp->prev)->next = loc;
    loc->prev = temp->prev;
    free(temp);
}



