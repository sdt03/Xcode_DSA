#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct appointment {
    char name[50];
    int time;
    struct appointment* next;
} Appointment;

typedef struct queue {
    Appointment* front;
    Appointment* rear;
} Queue;

Appointment* create_appointment(char name[], int time) {
    Appointment* new_appointment = (Appointment*) malloc(sizeof(Appointment));
    strcpy(new_appointment->name, name);
    new_appointment->time = time;
    new_appointment->next = NULL;
    return new_appointment;
}

void enqueue(Queue* q, char name[], int time) {
    Appointment* new_appointment = create_appointment(name, time);
    if (q->front == NULL) {
        q->front = new_appointment;
        q->rear = new_appointment;
    } else {
        q->rear->next = new_appointment;
        q->rear = new_appointment;
    }
    printf("Appointment for %s at %d added to the queue.\n", name, time);
}

void dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
    } else {
        Appointment* temp = q->front;
        q->front = q->front->next;
        if (q->front == NULL) {
            q->rear = NULL;
        }
        printf("Appointment for %s at %d removed from the queue.\n", temp->name, temp->time);
        free(temp);
    }
}

void print_queue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
    } else {
        printf("Appointment Queue:\n");
        Appointment* current_appointment = q->front;
        while (current_appointment != NULL) {
            printf("%s at %d\n", current_appointment->name, current_appointment->time);
            current_appointment = current_appointment->next;
        }
    }
}

int main() {
    Queue appointment_queue = {NULL, NULL};
    int choice, time;
    char name[50];
    
    do {
        printf("\nAppointment Management System\n");
        printf("1. Add Appointment\n");
        printf("2. Remove Appointment\n");
        printf("3. View Appointments\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter patient name: ");
                scanf("%s", name);
                printf("Enter appointment time: ");
                scanf("%d", &time);
                enqueue(&appointment_queue, name, time);
                break;
            case 2:
                dequeue(&appointment_queue);
                break;
            case 3:
                print_queue(&appointment_queue);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct patient {
    char name[50];
    int age;
    int id;
    struct patient *next;
} Patient;

Patient *p = NULL;

void add_patient() {
    Patient *new_patient = malloc(sizeof(Patient));
    printf("Enter name: ");
    scanf("%s", new_patient->name);
    printf("Enter age: ");
    scanf("%d", &new_patient->age);
    printf("Enter ID: ");
    scanf("%d", &new_patient->id);
    new_patient->next = NULL;
    
    if (p == NULL) {
        p = new_patient;
    } else {
        Patient *current = p;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_patient;
    }
    printf("Patient added successfully!\n");
}

void list_patients() {
    if (p == NULL) {
        printf("No patients found.\n");
    } else {
        Patient *current = p;
        printf("ID\tName\tAge\n");
        while (current != NULL) {
            printf("%d\t%s\t%d\n", current->id, current->name, current->age);
            current = current->next;
        }
    }
}

int main() {
    int choice;
    do {
        printf("Patient Management System\n");
        printf("------------------------\n");
        printf("1. Add Patient\n");
        printf("2. List Patients\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_patient();
                break;
            case 2:
                list_patients();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
    
    return 0;
}

