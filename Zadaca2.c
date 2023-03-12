#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void vnesi(struct Node **head_ref, int new_data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void pecati(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void brisi(struct Node **head_ref, int key) {
    struct Node *temp = *head_ref, *prev;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void sortOpagjanje(struct Node **head_ref) {
    struct Node *i, *j;
    int temp;

    for (i = *head_ref; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data < j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void sortRastenje(struct Node **head_ref) {
    struct Node *i, *j;
    int temp;

    for (i = *head_ref; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

int main() {
    struct Node *head = NULL;

    vnesi(&head, 1);
    vnesi(&head, 2);
    vnesi(&head, 3);
    vnesi(&head, 4);
    vnesi(&head, 5);

    printf("Nesortirana lista: ");
    pecati(head);

    sortOpagjanje(&head);
    printf("Sortirana lista vo opagjacki redosled: ");
    pecati(head);

    sortRastenje(&head);
    printf("Sortirana lista vo rastechki redosled: ");
    pecati(head);

    brisi(&head, 3);
    printf("Lista po brisenje na elementot so vrednost 3: ");
    pecati(head);

    return 0;
}
