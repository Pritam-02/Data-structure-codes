#include <stdio.h>
#include <stdlib.h>

// Define a structure for a term in the polynomial
typedef struct Node {
    int coeff;
    int expo;
    struct Node *next;
} Node;

// Function to create a new term
Node *createNode(int coefficient, int exponent) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->coeff = coefficient;
    newNode->expo = exponent;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term into the polynomial
Node* insert(Node* head, int coeff, int expo) {
    Node* temp;
    Node* newP = malloc(sizeof(Node));
    newP->coeff = coeff;
    newP->expo = expo;
    newP->next = NULL;

    if (head == NULL || expo > head->expo) {
        newP->next = head;
        head = newP;
    } else {
        temp = head;
        while (temp->next != NULL && temp->next->expo >= expo) {
            temp = temp->next;
        }
        newP->next = temp->next;
        temp->next = newP;
    }
    return head;
}

// Function to display a polynomial
void displayPoly(Node *head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->expo);
        temp = temp->next;
        if (temp != NULL) {
            printf(" + ");
        } else {
            printf("\n");
        }
    }
}

// Function to add two polynomials
void addPoly(Node* head1, Node* head2, Node** result) {
    Node *ptr1 = head1, *ptr2 = head2;

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->expo == ptr2->expo) {
            *result = insert(*result, ptr1->coeff + ptr2->coeff, ptr1->expo);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        } else if (ptr1->expo > ptr2->expo) {
            *result = insert(*result, ptr1->coeff, ptr1->expo);
            ptr1 = ptr1->next;
        } else {
            *result = insert(*result, ptr2->coeff, ptr2->expo);
            ptr2 = ptr2->next;
        }
    }

    while (ptr1 != NULL) {
        *result = insert(*result, ptr1->coeff, ptr1->expo);
        ptr1 = ptr1->next;
    }

    while (ptr2 != NULL) {
        *result = insert(*result, ptr2->coeff, ptr2->expo);
        ptr2 = ptr2->next;
    }
}

// Function to subtract two polynomials
void subtractPoly(Node* head1, Node* head2, Node** result) {
    Node *ptr1 = head1, *ptr2 = head2;

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->expo == ptr2->expo) {
            *result = insert(*result, ptr1->coeff - ptr2->coeff, ptr1->expo);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        } else if (ptr1->expo > ptr2->expo) {
            *result = insert(*result, ptr1->coeff, ptr1->expo);
            ptr1 = ptr1->next;
        } else {
            *result = insert(*result, -ptr2->coeff, ptr2->expo);
            ptr2 = ptr2->next;
        }
    }

    while (ptr1 != NULL) {
        *result = insert(*result, ptr1->coeff, ptr1->expo);
        ptr1 = ptr1->next;
    }

    while (ptr2 != NULL) {
        *result = insert(*result, -ptr2->coeff, ptr2->expo);
        ptr2 = ptr2->next;
    }
}


//Function to multiply two polynomials
void multPoly(Node* head1, Node* head2, Node** result) {
    if (head1 == NULL || head2 == NULL) {
        printf("Zero polynomial\n");
        return;
    }

    Node *ptr1 = head1, *ptr2 = head2;
    Node *tempResult = NULL;

    // Multiply each term of the first polynomial with each term of the second
    while (ptr1 != NULL) {
        ptr2 = head2;
        while (ptr2 != NULL) {
            int coeffProduct = ptr1->coeff * ptr2->coeff;
            int expoSum = ptr1->expo + ptr2->expo;
            tempResult = insert(tempResult, coeffProduct, expoSum);
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }

    // Simplify the resulting polynomial (combine terms with the same exponent)
    Node* temp = tempResult;
    while (temp != NULL && temp->next != NULL) {
        Node* current = temp;
        while (current->next != NULL) {
            if (temp->expo == current->next->expo) {
                temp->coeff += current->next->coeff;
                Node* duplicate = current->next;
                current->next = current->next->next;
                free(duplicate);
            } else {
                current = current->next;
            }
        }
        temp = temp->next;
    }

    // Assign the simplified result to the result pointer
    *result = tempResult;
}




// Function to differentiate a polynomial
void differentiatePoly(Node* head, Node** result) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->expo > 0) {
            *result = insert(*result, temp->coeff * temp->expo, temp->expo - 1);
        }
        temp = temp->next;
    }
}

// Function to free a polynomial
void freePolynomial(Node *poly) {
    while (poly != NULL) {
        Node *temp = poly;
        poly = poly->next;
        free(temp);
    }
}

int main() {
    Node *A = NULL, *B = NULL, *C = NULL;
    int choice, coeff, expo;

    printf("Enter terms for Polynomial A (enter coefficient 0 to stop):\n");
    do {
        printf("Coefficient: ");
        scanf("%d", &coeff);
        if (coeff == 0) break;
        printf("Exponent: ");
        scanf("%d", &expo);
        A = insert(A, coeff, expo);
    } while (1);

    printf("Enter terms for Polynomial B (enter coefficient 0 to stop):\n");
    do {
        printf("Coefficient: ");
        scanf("%d", &coeff);
        if (coeff == 0) break;
        printf("Exponent: ");
        scanf("%d", &expo);
        B = insert(B, coeff, expo);
    } while (1);

    do {
        printf("\nChoose an operation:\n");
        printf("1. Add Polynomials\n");
        printf("2. Subtract Polynomial B from A\n");
        printf("3. Multiplecation Polynomial\n");
        printf("4. Differentiate Polynomial A\n");
        printf("5. Exit....\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                C = NULL;
                addPoly(A, B, &C);
                printf("Resultant Polynomial: ");
                displayPoly(C);
                freePolynomial(C);
                break;
            case 2:
                C = NULL;
                subtractPoly(A, B, &C);
                printf("Resultant Polynomial: ");
                displayPoly(C);
                freePolynomial(C);
                break;
            case 3:
                C = NULL;
                multPoly(A, B, &C);
                printf("Resultant Polynomial: ");
                displayPoly(C);
                freePolynomial(C);
                break;

            case 4:
                C = NULL;
                differentiatePoly(A, &C);
                printf("Differentiated Polynomial: ");
                displayPoly(C);
                freePolynomial(C);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    freePolynomial(A);
    freePolynomial(B);
    return 0;
}