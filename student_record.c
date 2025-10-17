#include <stdio.h>
#include <string.h>

#define MAX 50

typedef struct {
    int roll;
    char name[40];
    float marks;
} Student;

Student arr[MAX];
int n = 0;

void addStudent() {
    if (n >= MAX) { printf("Storage full.\n"); return; }
    printf("Enter roll: "); scanf("%d", &arr[n].roll);
    printf("Enter name: "); scanf(" %[^\n]", arr[n].name);
    printf("Enter marks: "); scanf("%f", &arr[n].marks);
    n++;
    printf("Added.\n");
}

void displayAll() {
    if (n == 0) { printf("No records.\n"); return; }
    printf("\nRoll\tName\t\tMarks\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%-15s\t%.2f\n", arr[i].roll, arr[i].name, arr[i].marks);
}

void searchByRoll() {
    int r; printf("Enter roll to search: "); scanf("%d", &r);
    for (int i = 0; i < n; i++) {
        if (arr[i].roll == r) {
            printf("Found: %d, %s, %.2f\n", arr[i].roll, arr[i].name, arr[i].marks);
            return;
        }
    }
    printf("Not found.\n");
}

void deleteByRoll() {
    int r; printf("Enter roll to delete: "); scanf("%d", &r);
    for (int i = 0; i < n; i++) {
        if (arr[i].roll == r) {
            for (int j = i; j < n-1; j++) arr[j] = arr[j+1];
            n--;
            printf("Deleted.\n");
            return;
        }
    }
    printf("Not found.\n");
}

void sortByMarks() { /* bubble sort descending */
    if (n < 2) { printf("Not enough records to sort.\n"); return; }
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if (arr[j].marks < arr[j+1].marks) {
                Student t = arr[j]; arr[j] = arr[j+1]; arr[j+1] = t;
            }
        }
    }
    printf("Sorted by marks (high -> low).\n");
}

int main() {
    int ch;
    printf("Simple Student Record System\n");
    do {
        printf("\n1.Add 2.Display 3.Search 4.Delete 5.Sort 6.Exit\nChoice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: searchByRoll(); break;
            case 4: deleteByRoll(); break;
            case 5: sortByMarks(); break;
            case 6: printf("Exiting.\n"); break;
            default: printf("Invalid.\n");
        }
    } while (ch != 6);
    return 0;
}
