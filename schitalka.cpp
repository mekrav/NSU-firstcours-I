#include <stdio.h>
typedef struct Node {
    Node *next;
    int s;
}Node;

void print_loop(Node *r) {
    printf("\n");
    printf("%d ",r->s);
    Node *h = r;
    r = r->next;
    while (r->next != h->next) {
        printf("%d ", r->s);
        r = r->next;
    }
    printf("\n");
}
int main()
{   int n, m;
    Node *head, *r = new Node;
    head = r;
    scanf("%d %d",&n,&m);
    for (int i = 1; i <= n; i++) {
        r->s = i;
        if (i == n) {
            r->next = head;
            r = r->next;
        }
        else {
            r->next = new Node;
            r = r->next;
        }
    }
    int count = n;
    while (count != 1) {
        if (m != 1) {
            int st = 1;
            while(st < m-1) {
                r = r->next;
                st++;
            }
        }
        else {
            Node *h = r;
            r = r->next;
            while (r->next != h) {
                r = r->next;
            }
        }
        Node *vs = r->next;
        r->next = vs->next;
        delete(vs);
        count--;
        r = r->next;
    }
    print_loop(r);
    return 0;
}
