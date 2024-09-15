/*
    Nama        : Irwan Rivandy Siagian
    NIM         : 2702427024
    Deskripsi   : Tugas Personal 1 Struktur Data
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct karyawan
{
    int employeeID;
    char nama[30];
    char tempatLahir[30];
    char jabatan[50];
    struct karyawan *next;
};

struct karyawan *createKaryawan(int id, char *nama, char *tempatLahir, char *jabatan)
{
    struct karyawan *newNode = (struct karyawan *)malloc(sizeof(struct karyawan));

    newNode->employeeID = id;
    strcpy(newNode->nama, nama);
    strcpy(newNode->tempatLahir, tempatLahir);
    strcpy(newNode->jabatan, jabatan);
    newNode->next = NULL;

    return newNode;
}

int checkID(struct karyawan *head, int id)
{
    struct karyawan *temp = head;
    while (temp != NULL)
    {
        if (temp->employeeID == id)
        {
            printf("Employee With Id %d Already Registered \n", id);
            system("PAUSE");
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void insertData(struct karyawan **head, int *count)
{
    int id, flag = 0;
    char nama[30], tempatLahir[30], jabatan[50];

    do
    {
        system("CLS");
        printf("Enter employee ID (5 digits): ");
        scanf("%d", &id);
        flag = checkID(*head, id);
    } while ((id < 10000 || id >= 100000) || flag == 1);
    printf("Enter employee name: ");
    scanf(" %[^\n]%*c", nama);
    printf("Enter place of birth: ");
    scanf(" %[^\n]%*c", tempatLahir);
    printf("Enter position (jabatan): ");
    scanf(" %[^\n]%*c", jabatan);

    struct karyawan *newNode = createKaryawan(id, nama, tempatLahir, jabatan);

    if (*head == NULL)
    {
        *head = newNode;
        printf("Employee added successfully.\n");
        system("PAUSE");
        ++*count;
        return;
    }

    struct karyawan *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    ++*count;
    printf("Employee added successfully.\n");
    system("PAUSE");
}

void deleteKaryawan(struct karyawan **head, int id, int *count)
{
    struct karyawan *temp = *head;
    struct karyawan *prev = NULL;

    if (temp == NULL)
    {
        printf("List is empty.\n");
        system("PAUSE");
        return;
    }

    if (temp != NULL && temp->employeeID == id)
    {
        *head = temp->next;
        free(temp);
        --*count;
        printf("Employee with ID %d deleted successfully.\n", id);
        system("PAUSE");
        return;
    }
    while (temp != NULL && temp->employeeID != id)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Employee not found.\n");
        system("PAUSE");
        return;
    }

    prev->next = temp->next;

    free(temp);
    --*count;
    printf("Employee with ID %d deleted successfully.\n", id);
    system("PAUSE");
}

void sortListByAsc(struct karyawan **head)
{
    struct karyawan *temp = *head;
    struct karyawan *temp2 = NULL;
    int id, tempID;
    char nama[30], tempNama[30];
    char tempatLahir[30], tempTempatLahir[30];
    char jabatan[50], tempJabatan[50];

    while (temp != NULL)
    {
        temp2 = temp->next;
        while (temp2 != NULL)
        {
            if (temp->employeeID > temp2->employeeID)
            {
                tempID = temp->employeeID;
                temp->employeeID = temp2->employeeID;
                temp2->employeeID = tempID;

                strcpy(tempNama, temp->nama);
                strcpy(temp->nama, temp2->nama);
                strcpy(temp2->nama, tempNama);

                strcpy(tempTempatLahir, temp->tempatLahir);
                strcpy(temp->tempatLahir, temp2->tempatLahir);
                strcpy(temp2->tempatLahir, tempTempatLahir);

                strcpy(tempJabatan, temp->jabatan);
                strcpy(temp->jabatan, temp2->jabatan);
                strcpy(temp2->jabatan, tempJabatan);
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
}

void sortListByDesc(struct karyawan **head)
{
    struct karyawan *temp = *head;
    struct karyawan *temp2 = NULL;
    int id, tempID;
    char nama[30], tempNama[30];
    char tempatLahir[30], tempTempatLahir[30];
    char jabatan[50], tempJabatan[50];

    while (temp != NULL)
    {
        temp2 = temp->next;
        while (temp2 != NULL)
        {
            if (temp->employeeID < temp2->employeeID)
            {
                tempID = temp->employeeID;
                temp->employeeID = temp2->employeeID;
                temp2->employeeID = tempID;

                strcpy(tempNama, temp->nama);
                strcpy(temp->nama, temp2->nama);
                strcpy(temp2->nama, tempNama);

                strcpy(tempTempatLahir, temp->tempatLahir);
                strcpy(temp->tempatLahir, temp2->tempatLahir);
                strcpy(temp2->tempatLahir, tempTempatLahir);

                strcpy(tempJabatan, temp->jabatan);
                strcpy(temp->jabatan, temp2->jabatan);
                strcpy(temp2->jabatan, tempJabatan);
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
}

void printList(struct karyawan *node)
{
    if (node == NULL)
    {
        printf("List is empty.\n");
        system("PAUSE");
        return;
    }

    int choice;
    system("CLS");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        sortListByAsc(&node);
        printf("List Karyawan ASC By Employee Id:\n");
        break;
    case 2:
        sortListByDesc(&node);
        printf("List Karyawan DESC By Employee Id:\n");
        break;
    default:
        printf("Invalid choice.\n");
        system("PAUSE");
        return;
    }

    while (node != NULL)
    {
        printf("ID: %d", node->employeeID);
        printf("\nNama: %s\nTempat Lahir: %s\nJabatan: %s\n", node->nama, node->tempatLahir, node->jabatan);
        node = node->next;
        printf("---------------\n");
    }
    system("PAUSE");
}

int main()
{
    struct karyawan *head = NULL;
    int choice;
    int id, karyawanCount = 0;

    while (1)
    {
        system("CLS");
        printf("\nMenu:\n");
        printf("1. Insert karyawan\n");
        printf("2. Delete karyawan by ID\n");
        printf("3. Display karyawan By ASC/DESC\n");
        printf("4. Clear all employees\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (karyawanCount > 5)
            {
                printf("Maximum 5 employees can be registered.\n");
                system("PAUSE");
                break;
            }
            insertData(&head, &karyawanCount);
            break;
        case 2:
            do
            {
                printf("Enter employee ID (5 digits): ");
                scanf("%d", &id);
            } while (id < 10000 && id >= 100000);
            deleteKaryawan(&head, id, &karyawanCount);
            break;
        case 3:
            printList(head);
            break;
        case 4:
            system("CLS");
            char choice2;
            printf("Are you sure you want to clear all employees? (Y/N): ");
            scanf("%c", &choice2);
            if (choice == 'Y' || choice == 'y')
            {
                while (head != NULL)
                {
                    struct karyawan *temp = head;
                    head = head->next;
                    free(temp);
                }
                karyawanCount = 0;
                printf("All employees cleared.\n");
                system("PAUSE");
            }
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
