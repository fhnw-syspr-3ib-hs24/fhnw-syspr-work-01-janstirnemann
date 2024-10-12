#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

    struct node {
        char label[32];
        struct node * left; // Man darf auf etwas zeigen, dass noch nicht fertig definiert ist
        struct node * right;
    };


int main(void) {
    struct node lr = {"left right", NULL, NULL};
    struct node ll = {"left left", NULL, NULL};
    struct node l = {"left", &ll, &lr};
    struct node r = {"right", NULL, NULL};
    struct node n = {"root", &l, &r}; // Stack
    struct node* root = &n;

    // Man kann es auch so definieren

    //struct node n;   // STACK
    //n.label = "root";
    //n.left= NULL;
    //n.right = NULL;

        // In java Node n = new Node();
    //struct node * n = malloc(sizeof(struct node));   // HEAP , dynamischer Speicher
        // In java n.label = "root";
    //n->label = root;
    //n->left= NULL;
    //n->right = NULL;
    
    assert(n.left == &l);

    printf("%s\n", n.label);
    printf("%s\n", (*(n.left)).label);
    // printf("%s\n", (n.left)->label);
    printf("%s\n", ll.label);
    printf("%s\n", lr.label);
    printf("%s\n", r.label);


    // speicher von den Blättern richtig root wieder freigeben mit free()
    return 0;
}
