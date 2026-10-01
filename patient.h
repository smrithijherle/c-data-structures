#ifndef PATIENT_H
#define PATIENT_H

#define MAX_NAME 100

struct Patient {
    char name[MAX_NAME];
    int severity;
    struct Patient *next;
};

struct Patient *createPatient(const char *name, int severity);

void admitPatient(struct Patient **head, const char *name, int severity);

void treatNextPatient(struct Patient **head);

void displayWaitingList(struct Patient *head);

void freeList(struct Patient **head);

#endif
