#include<stdio.h>
#include<string.h>

#define null 0

int size = 0;

void insert();
void del();
int search(char lab[]);
void modify();
void display();

struct symbtab {
    char label[10];
    int addr;
    struct symtab *next;
};

struct symbtab *first, *last;

void main() {
    int op;
    int y;
    char la[10];

    do {
        printf("\n Symbol table implementation\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Delete\n");
        printf("4. Search\n");
        printf("5. Modify\n");
        printf("6. End\n");
        printf("Enter your option :");
        scanf("%d", &op);

        switch(op) {
            case 1:
                insert();
                display();
                break;
            case 2:
                display();
                break;
            case 3:
                del();
                display();
                break;
            case 4:
                printf("Enter the label to be searched: ");
                scanf("%s", la);
                y = search(la);
                if (y == 1) {
                    printf("The label is already in the symbol table");
                } else {
                    printf("The label is not found in the symbol table");
                }
                break;
            case 5:
                modify();
                display();
                break;
            case 6:
            printf("\nLab NO:12\n");	
			printf("Name:Rajip Maharjan\n");
			printf("Roll no:14");
                break;
        }
    } while(op < 6);
}

void insert() {
    int n;
    char l[10];
    printf("Enter the label: ");
    scanf("%s", l);
    n = search(l);
    if (n == 1) {
        printf("The label already exists. Duplicate can't be inserted.\n");
    } else {
        struct symbtab *p;
        p = malloc(sizeof(struct symbtab));
        strcpy(p->label, l);
        printf("Enter the address: ");
        scanf("%d", &p->addr);
        p->next = null;
        if (size == 0) {
            first = p;
            last = p;
        } else {
            last->next = p;
            last = p;
        }
        size++;
    }
}

void display() {
    int i;
    struct symbtab *p;
    p = first;
    printf("Label\t Address\n");
    for (i = 0; i < size; i++) {
        printf("%s\t%d\n", p->label, p->addr);
        p = p->next;
    }
}

int search(char lab[]) {
    int i, flag = 0;
    struct symbtab *p;
    p = first;
    for (i = 0; i < size; i++) {
        if (strcmp(p->label, lab) == 0) {
            flag = 1;
        }
        p = p->next;
    }
    return flag;
}

void modify() {
    char l[10], nl[10];
    int add, choice, i, s;
    struct symbtab *p;
    p = first;

    printf("What do you want to modify?\n");
    printf("1. Only the label\n");
    printf("2. Only the address of a particular label\n");
    printf("3. Both the label and address\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter the old label: ");
            scanf("%s", l);
            printf("Enter the new label: ");
            scanf("%s", nl);
            s = search(l);
            if (s == 0) {
                printf("No such label\n");
            } else {
                for (i = 0; i < size; i++) {
                    if (strcmp(p->label, l) == 0) {
                        strcpy(p->label, nl);
                    }
                    p = p->next;
                }
            }
            break;

        case 2:
            printf("Enter the label whose address is to be modified: ");
            scanf("%s", l);
            printf("Enter the new address: ");
            scanf("%d", &add);
            s = search(l);
            if (s == 0) {
                printf("No such label\n");
            } else {
                for (i = 0; i < size; i++) {
                    if (strcmp(p->label, l) == 0) {
                        p->addr = add;
                    }
                    p = p->next;
                }
            }
            break;

        case 3:
            printf("Enter the old label: ");
            scanf("%s", l);
            printf("Enter the new label: ");
            scanf("%s", nl);
            printf("Enter the new address: ");
            scanf("%d", &add);
            s = search(l);
            if (s == 0) {
                printf("No such label\n");
            } else {
                for (i = 0; i < size; i++) {
                    if (strcmp(p->label, l) == 0) {
                        strcpy(p->label, nl);
                        p->addr = add;
                    }
                    p = p->next;
                }
            }
            break;
    }
}

void del() {
    int a;
    char l[10];
    struct symbtab *p, *q;
    p = first;

    printf("Enter the label to be deleted: ");
    scanf("%s", l);
    a = search(l);
    if (a == 0) {
        printf("Label not found\n");
    } else {
        if (strcmp(first->label, l) == 0) {
            first = first->next;
        } else if (strcmp(last->label, l) == 0) {
            q = p->next;
            while (strcmp(q->label, l) != 0) {
                p = p->next;
                q = q->next;
            }
            p->next = null;
            last = p;
        } else {
            q = p->next;
            while (strcmp(q->label, l) != 0) {
                p = p->next;
                q = q->next;
            }
            p->next = q->next;
        }
        size--;
    }
}

