#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char NAME[10];

typedef struct Node {
    NAME name;
    struct Node* next;

#define N(v) v->name
#define NEXT(v) v->next
#define HAS_NEXT(v) (v->next != NULL)
} Node;

void
init_node(Node* n, NAME name)
{
    n->next = NULL;
    memcpy(N(n), name, sizeof(NAME));
}

#define INC(v) v = NEXT(v)

void
insert_node(Node* head, int n, Node* node)
{
    Node* p;
    for (p = head; n-- && p; INC(p));

    Node* pn = NEXT(p);
    NEXT(p) = node;
    NEXT(node) = pn;
}

void
remove_node(Node* head, NAME name)
{
    Node* p;
    Node* pn;
    for (p = head, pn = NEXT(head);
         pn && strcmp(N(pn), name);
         INC(p), INC(pn));

    if (!pn) {
        return;
    }

    NEXT(p) = NEXT(pn);
    free(pn);
}

void
print_linked_list(Node* head)
{
    for (Node* p = NEXT(head); p; INC(p)) {
        printf("%s\n", N(p));
    }
}

void
do_(Node* head)
{
    int op;
    scanf("%d", &op);

    if (op == 1) {
        NAME name;
        memset(name, 0, sizeof(NAME));

        int pos;
        scanf("%s %d", name, &pos);

        Node* node = (Node*) malloc(sizeof(Node));
        init_node(node, name);

        insert_node(head, pos, node);
    } else {
        NAME name;
        scanf("%s", name);

        remove_node(head, name);
    }

}

int
main()
{
    int n;
    scanf("%d", &n);

    while (n--) {
        int nn;
        scanf("%d", &nn);

        NAME EMPTY;
        EMPTY[0] = '\0';

        Node head;
        init_node(&head, EMPTY);

        while (nn--) {
            do_(&head);
        }

        print_linked_list(&head);
    }

    return 0;
}
