#include <stdio.h>
#include <stdlib.h>

// Structure of a term
struct node {
    float coef;
    int expo;
    struct node* link;
};

// Insert a node in decreasing order of exponents
struct node* insertNode(struct node* head, float co, int ex) {
    struct node* temp;
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->coef = co;
    newNode->expo = ex;
    newNode->link = NULL;

    if (head == NULL || ex > head->expo) {
        newNode->link = head;
        head = newNode;
    } else {
        temp = head;
        while (temp->link != NULL && temp->link->expo > ex) {
            temp = temp->link;
        }
        newNode->link = temp->link;
        temp->link = newNode;
    }
    return head;
}

// Create a polynomial
struct node* createNode(struct node* head) {
    int n, i, ex;
    float co;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the coefficient for term %d: ", i + 1);
        scanf("%f", &co);
        printf("Enter the exponent for term %d: ", i + 1);
        scanf("%d", &ex);
        head = insertNode(head, co, ex);
    }
    return head;
}

// Print a polynomial
void printPoly(struct node* head) {
    if (head == NULL) {
        printf("The polynomial is empty!\n");
    } else {
        struct node* temp = head;
        while (temp != NULL) {
            printf("(%.2fx^%d)", temp->coef, temp->expo);
            temp = temp->link;
            if (temp != NULL) {
                printf(" + ");
            } else {
                printf("\n");
            }
        }
    }
}

// Free the memory allocated for a polynomial
void freePoly(struct node* head) {
    struct node* temp;
    while (head != NULL) {
        temp = head;
        head = head->link;
        free(temp);
    }
}

// Add two polynomials
void addPoly(struct node* head1, struct node* head2) {
    struct node *ptr1 = head1, *ptr2 = head2;
    struct node* head3 = NULL;

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->expo == ptr2->expo) {
            head3 = insertNode(head3, ptr1->coef + ptr2->coef, ptr1->expo);
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        } else if (ptr1->expo > ptr2->expo) {
            head3 = insertNode(head3, ptr1->coef, ptr1->expo);
            ptr1 = ptr1->link;
        } else {
            head3 = insertNode(head3, ptr2->coef, ptr2->expo);
            ptr2 = ptr2->link;
        }
    }

    while (ptr1 != NULL) {
        head3 = insertNode(head3, ptr1->coef, ptr1->expo);
        ptr1 = ptr1->link;
    }
    while (ptr2 != NULL) {
        head3 = insertNode(head3, ptr2->coef, ptr2->expo);
        ptr2 = ptr2->link;
    }

    printf("\nAddition : ");
    printPoly(head3);
    freePoly(head3);  // Free memory after printing
}

// Subtract two polynomials
void subPoly(struct node* head1, struct node* head2) {
    struct node *ptr1 = head1, *ptr2 = head2;
    struct node* head3 = NULL;

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->expo == ptr2->expo) {
            head3 = insertNode(head3, ptr1->coef - ptr2->coef, ptr1->expo);
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        } else if (ptr1->expo > ptr2->expo) {
            head3 = insertNode(head3, ptr1->coef, ptr1->expo);
            ptr1 = ptr1->link;
        } else {
            head3 = insertNode(head3, -ptr2->coef, ptr2->expo);
            ptr2 = ptr2->link;
        }
    }

    while (ptr1 != NULL) {
        head3 = insertNode(head3, ptr1->coef, ptr1->expo);
        ptr1 = ptr1->link;
    }
    while (ptr2 != NULL) {
        head3 = insertNode(head3, -ptr2->coef, ptr2->expo);
        ptr2 = ptr2->link;
    }

    printf("\nSubtraction : ");
    printPoly(head3);
    freePoly(head3);
}

// Differentiate a polynomial
void derivation(struct node* head) {
    struct node* head2 = NULL;
    struct node* ptr = head;

    while (ptr != NULL) {
        if (ptr->expo != 0) {  // Skip constants
            head2 = insertNode(head2, ptr->coef * ptr->expo, ptr->expo - 1);
        }
        ptr = ptr->link;
    }

    printf("After differentiation: ");
    printPoly(head2);
    freePoly(head2);
}

int main() {
    struct node* head1 = NULL;
    struct node* head2 = NULL;

    printf("\t--Enter the 1st polynomial--\t\n");
    head1 = createNode(head1);
    printf("\t--Enter the 2nd polynomial--\t\n");
    head2 = createNode(head2);

    printf("\n1st Polynomial : ");
    printPoly(head1);
    printf("\n2nd Polynomial : ");
    printPoly(head2);

    addPoly(head1, head2);
    subPoly(head1, head2);

    printf("\n1st Polynomial Differentiation: ");
    derivation(head1);
    printf("\n2nd Polynomial Differentiation: ");
    derivation(head2);

    // Free the polynomials
    freePoly(head1);
    freePoly(head2);

    return 0;
}

