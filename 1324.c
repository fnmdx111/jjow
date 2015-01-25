#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Point
{
    double x, y;
} Point;
#define PX(p) (p->x)
#define PY(p) (p->y)

typedef struct Shape
{
    int type;

    Point* c;
    double r;

    Point* tl;
    Point* br;
} Shape;
#define CEN(s) (s->c)
#define RAD(s) (s->r)
#define TL(s) (s->tl)
#define BR(s) (s->br)
#define TYPE(s) (s->type)
#define T_RECT 1
#define T_CIRC 2
#define IS_RECT(s) (TYPE(s) == T_RECT)
#define IS_CIRC(s) (TYPE(s) == T_CIRC)

typedef struct Node
{
    Shape* shape;
    struct Node* next;
} Node;
#define N(node) (node->next)
#define HAS_NEXT(node) N(node)
#define S(node) (node->shape)
#define HAS_SHAPE(node) S(node)
#define ITER(head, n) for (Node* n = head; n; n = N(n))

void
init_node(Node* pn)
{
    memset(pn, 0, sizeof(Node));
}

void
append(Node** p_tail, Shape* shape)
{
    Node* tail = *p_tail;

    Node* new = (Node*) malloc(sizeof(Node));
    S(new) = NULL;
    N(new) = NULL;

    S(new) = shape;
    N(tail) = new;
    *p_tail = new;
}

void
append_rectangle(Node** p_tail)
{
    Node* tail = *p_tail;
    Shape* shape = (Shape*) malloc(sizeof(Shape));
    memset(shape, 0, sizeof(Shape));

    TL(shape) = (Point*) malloc(sizeof(Point));
    BR(shape) = (Point*) malloc(sizeof(Point));

    scanf("%lf %lf %lf %lf",
          &PX(TL(shape)), &PY(TL(shape)),
          &PX(BR(shape)), &PY(BR(shape)));

    TYPE(shape) = T_RECT;

    append(p_tail, shape);
}

void
append_circle(Node** p_tail)
{
    Node* tail = *p_tail;
    Shape* shape = (Shape*) malloc(sizeof(Shape));
    memset(shape, 0, sizeof(Shape));

    CEN(shape) = (Point*) malloc(sizeof(Point));

    scanf("%lf %lf %lf",
          &PX(CEN(shape)), &PY(CEN(shape)),
          &RAD(shape));

    TYPE(shape) = T_CIRC;

    append(p_tail, shape);
}

int
main()
{
    Node* head;
    head = (Node*) malloc(sizeof(Node));
    init_node(head);

    Node* tail = head;

    char what;
    while (1) {
        scanf("%c", &what);

        if (what == 'r') {
            append_rectangle(&tail);
        } else if (what == 'c') {
            append_circle(&tail);
        } else if (what == '*') {
            break;
        }

        getchar();
    }

    int counter = 0;
    while (++counter) {
        double a, b;
        scanf("%lf %lf", &a, &b);

#define D_EQ(a, b) (abs(a - b) <= 0.0000001)
        if (D_EQ(a, 9999.9) && D_EQ(b, 9999.9)) {
            break;
        } else {
            int i = 0;
            int k = -1;
            ITER(N(head), p) {
                ++i;
                if (IS_RECT(S(p))) {
                    if (a <= PX(BR(S(p)))
                     && PX(TL(S(p))) <= a
                     && b <= PY(BR(S(p)))
                     && PY(TL(S(p))) <= b) {
                        k = i;
                        printf("Point %d is contained in figure %d\n",
                               counter, k);
                    }
                }

                if (IS_CIRC(S(p))) {
#define s (PX(CEN(S(p))) - a)
#define t (PY(CEN(S(p))) - b)
                    if (sqrt(s * s + t * t) <= RAD(S(p))) {
                        k = i;
                        printf("Point %d is contained in figure %d\n",
                               counter, k);
                    }
                }
            }

            if (k < 0) {
                printf("Point %d is not contained in any figure\n",
                       counter);
                break;
            }
        }
    }

    free(head);

    return 0;
}
