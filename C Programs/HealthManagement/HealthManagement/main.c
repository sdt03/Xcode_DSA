#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct patient {
    char name[50];
    int age;
    int id;
    struct patient* next;
} Patient;

typedef struct appointment {
    char patient_name[50];
    int patient_age;
    int appointment_time;
    float billing;
    struct appointment* next;
} Appointment;

typedef struct billing {
    char patient_name[50];
    int patient_age;
    float total_bill;
    struct billing* next;
} Billing;


Patient* create_patient(char name[], int age, int id) {
    Patient* new_patient = (Patient*) malloc(sizeof(Patient));
    strcpy(new_patient->name, name);
    new_patient->age = age;
    new_patient->id = id;
    new_patient->next = NULL;
    return new_patient;
}

void add_patient(Patient** head, char name[], int age, int id) {
    Patient* new_patient = create_patient(name, age, id);
    if (*head == NULL) {
        *head = new_patient;
    } else {
        Patient* current_patient = *head;
        while (current_patient->next != NULL) {
            current_patient = current_patient->next;
        }
        current_patient->next = new_patient;
    }
}

void print_patients(Patient* head) {
    if (head == NULL) {
        printf("No patients in the list.\n");
    } else {
        printf("Patient List:\n");
        while (head != NULL) {
            printf("ID: %d | Name: %s | Age: %d\n", head->id, head->name, head->age);
            head = head->next;
        }
    }
}

typedef struct appointment_queue {
    Appointment* front;
    Appointment* rear;
} AppointmentQueue;

Appointment* create_appointment(char patient_name[], int patient_age, int appointment_time) {
    Appointment* new_appointment = (Appointment*) malloc(sizeof(Appointment));
    strcpy(new_appointment->patient_name, patient_name);
    new_appointment->patient_age = patient_age;
    new_appointment->appointment_time = appointment_time;
    new_appointment->next = NULL;
    return new_appointment;
}

void enqueue(AppointmentQueue* queue, char patient_name[], int patient_age, int appointment_time) {
    Appointment* new_appointment = create_appointment(patient_name, patient_age, appointment_time);
    if (queue->front == NULL) {
        queue->front = new_appointment;
    } else {
        queue->rear->next = new_appointment;
    }
    queue->rear = new_appointment;
}

void dequeue(AppointmentQueue* queue) {
    if (queue->front == NULL) {
        printf("No appointments in the queue.\n");
    } else {
        Appointment* temp = queue->front;
        queue->front = temp->next;
        printf("Patient Name: %s | Age: %d | Appointment Time: %d\n", temp->patient_name, temp->patient_age, temp->appointment_time);
        free(temp);
    }
}

void print_queue(AppointmentQueue* queue) {
    if (queue->front == NULL) {
        printf("No appointments in the queue.\n");
    } else {
        Appointment* current_appointment = queue->front;
        printf("Appointment Queue:\n");
        while (current_appointment != NULL) {
            printf("Patient Name: %s | Age: %d | Appointment Time: %d\n", current_appointment->patient_name, current_appointment->patient_age, current_appointment->appointment_time);
            current_appointment = current_appointment->next;
        }
    }
}

Billing* create_billing(char patient_name[], int patient_age, float total_bill) {
    Billing* new_billing = (Billing*) malloc(sizeof(Billing));
    strcpy(new_billing->patient_name, patient_name);
    new_billing->patient_age = patient_age;
    new_billing->total_bill = total_bill;
    new_billing->next = NULL;
    return new_billing;
}

void add_billing(Billing** head, char patient_name[], int patient_age, float total_bill) {
    Billing* new_billing = create_billing(patient_name, patient_age, total_bill);
    if (*head == NULL) {
        *head = new_billing;
    } else {
        Billing* current_billing = *head;
        while (current_billing->next != NULL) {
            current_billing = current_billing->next;
        }
        current_billing->next = new_billing;
    }
}

void print_billing(Billing* head) {
    if (head == NULL) {
        printf("No billing information.\n");
    } else {
        Billing* current_billing = head;
        printf("Billing Information:\n");
        while (current_billing != NULL) {
            printf("Patient Name: %s | Age: %d | Total Bill: $%.2f\n", current_billing->patient_name, current_billing->patient_age, current_billing->total_bill);
            current_billing = current_billing->next;
        }
    }
}


int main() {
    Patient* head = NULL;
        
    add_patient(&head, "Shoumik Daterao", 20, 1);
    add_patient(&head, "Swarali Damle", 20, 2);
    add_patient(&head, "Gauri Choudhari", 21, 3);
        
    print_patients(head);
    
    AppointmentQueue queue;
    queue.front = NULL;
    queue.rear = NULL;
    
    
    enqueue(&queue, "Shoumik Daterao ", 25, 10);
    enqueue(&queue, "Swarali", 35, 11);
    enqueue(&queue, "Gauri", 45, 12);
    

    print_queue(&queue);
    Billing* billing_list = NULL;
    
    // Add some billing information
    add_billing(&billing_list, "J", 25, 500.00);
    add_billing(&billing_list, "Jane Doe", 35, 750.00);
    add_billing(&billing_list, "Bob Johnson", 45, 1000.00);
    

    print_billing(billing_list);
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct patient {
    char name[100];
    int age;
    int id;
    struct patient* next;
};

struct patient* create_patient(char name[], int age, int id) {
    struct patient* new_patient = (struct patient*) malloc(sizeof(struct patient));
    strcpy(new_patient->name, name);
    new_patient->age = age;
    new_patient->id = id;
    new_patient->next = NULL;
    return new_patient;
}

struct patient* add_patient(struct patient* head, char name[], int age, int id) {
    struct patient* new_patient = create_patient(name, age, id);
    if (head == NULL) {
        head = new_patient;
    } else {
        struct patient* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_patient;
    }
    printf("Patient %s added successfully.\n", name);
    return head;
}

void display_patients(struct patient* head) {
    if (head == NULL) {
        printf("No patients found.\n");
    } else {
        printf("List of patients:\n");
        struct patient* current = head;
        while (current != NULL) {
            printf("Name: %s\nAge: %d\nID: %d\n\n", current->name, current->age, current->id);
            current = current->next;
        }
    }
}

struct patient* delete_patient(struct patient* head, int id) {
    if (head == NULL) {
        printf("No patients found.\n");
    } else {
        if (head->id == id) {
            struct patient* temp = head;
            head = head->next;
            free(temp);
            printf("Patient with ID %d deleted successfully.\n", id);
        } else {
            struct patient* current = head;
            while (current->next != NULL && current->next->id != id) {
                current = current->next;
            }
            if (current->next == NULL) {
                printf("Patient with ID %d not found.\n", id);
            } else {
                struct patient* temp = current->next;
                current->next = current->next->next;
                free(temp);
                printf("Patient with ID %d deleted successfully.\n", id);
            }
        }
    }
    return head;
}

int main() {
    struct patient* head = NULL;
    int choice, age, id;
    char name[100];
    do {
        printf("\nPatient Management System\n");
        printf("1. Add patient\n");
        printf("2. Display patients\n");
        printf("3. Delete patient\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter age: ");
                scanf("%d", &age);
                printf("Enter ID: ");
                scanf("%d", &id);
                head = add_patient(head, name, age, id);
                break;
            case 2:
                display_patients(head);
                break;
            case 3:
                printf("Enter ID: ");
                scanf("%d", &id);
                head = delete_patient(head, id);
                break;
            case 4:
                printf("Exiting...\n");
