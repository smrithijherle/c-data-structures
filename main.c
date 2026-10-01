#include <stdio.h>
#include <string.h>
#include "patient.h"

int main()
{
    struct Patient *head = NULL;

    int choice;
    int severity;
    char name[MAX_NAME];

    while (1)
    {
        printf("\n========== ER PATIENT SYSTEM ==========\n");
        printf("1. Admit Patient\n");
        printf("2. Treat Next Patient\n");
        printf("3. Display Waiting List\n");
        printf("4. Exit\n");
        printf("=======================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1:
                printf("\nEnter patient name: ");
                fgets(name, MAX_NAME, stdin);

                name[strcspn(name, "\n")] = '\0';

                printf("Enter severity:\n");
                printf("1 = Critical\n");
                printf("2 = Urgent\n");
                printf("3 = Stable\n");
                printf("Enter severity: ");
                scanf("%d", &severity);

                admitPatient(&head, name, severity);

                printf("Patient admitted successfully.\n");
                break;

            case 2:
                treatNextPatient(&head);
                break;

            case 3:
                displayWaitingList(head);
                break;

            case 4:
                freeList(&head);
                printf("\nProgram ended.\n");
                return 0;

            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}
