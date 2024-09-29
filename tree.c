#include <stdio.h>
#include <stdlib.h>

    struct node {
        char label[32];
        struct node * left;
        struct node * right;
    };


int main(void) {
    struct node lr = {"left right", NULL, NULL};
    struct node ll = {"left left", NULL, NULL};
    struct node l = {"left", &ll, &lr};
    struct node r = {"right", NULL, NULL};
    struct node n = {"root", &l, &r};
    struct node* root = &n;
    
    printf("%s\n", n.label);
    printf("%s\n", l.label);
    printf("%s\n", ll.label);
    printf("%s\n", lr.label);
    printf("%s\n", r.label);
    return 0;
}
