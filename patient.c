#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patient.h"

struct Patient *createPatient(const char *name, int severity)
{
    struct Patient *newPatient;

    newPatient = (struct Patient *)malloc(sizeof(struct Patient));

    if (newPatient == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    strcpy(newPatient->name, name);
    newPatient->severity = severity;
    newPatient->next = NULL;

    return newPatient;
}

void admitPatient(struct Patient **head, const char *name, int severity)
{
    struct Patient *newPatient;
    struct Patient *current;

    if (severity < 1 || severity > 3)
    {
        printf("Invalid severity!\n");
        printf("1 = Critical, 2 = Urgent, 3 = Stable\n");
        return;
    }

    newPatient = createPatient(name, severity);

    if (*head == NULL || severity < (*head)->severity)
    {
        newPatient->next = *head;
        *head = newPatient;
        return;
    }

    current = *head;

    while (current->next != NULL &&
           current->next->severity <= severity)
    {
        current = current->next;
    }

    newPatient->next = current->next;
    current->next = newPatient;
}

void treatNextPatient(struct Patient **head)
{
    struct Patient *temp;

    if (*head == NULL)
    {
        printf("\nNo patients are waiting.\n");
        return;
    }

    temp = *head;

    printf("\nTreating patient: %s\n", temp->name);
    printf("Severity: %d\n", temp->severity);

    *head = (*head)->next;

    free(temp);
}

void displayWaitingList(struct Patient *head)
{
    int position = 1;

    if (head == NULL)
    {
        printf("\nWaiting list is empty.\n");
        return;
    }

    printf("\n========== WAITING LIST ==========\n");

    while (head != NULL)
    {
        printf("%d. %s - Severity %d",
               position,
               head->name,
               head->severity);

        if (head->severity == 1)
            printf(" (Critical)");
        else if (head->severity == 2)
            printf(" (Urgent)");
        else
            printf(" (Stable)");

        printf("\n");

        head = head->next;
        position++;
    }

    printf("==================================\n");
}

void freeList(struct Patient **head)
{
    struct Patient *temp;

    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}
