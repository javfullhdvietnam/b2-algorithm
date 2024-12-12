#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

struct Car{
    int data_passenger;
    char id[100];
    struct Car* prev;
    struct Car* next;
};

struct Car* CreateTrain(struct Car* head){
    int n,capacity=20,i;
    int data_passenger[]={11,23,9,4,0,1,5,7,4};
    char* id[]={"t01","t02","t03","t04","t05","t06","t07","t08","t09"};
    struct Car* tail =NULL;
    
    n = sizeof(data_passenger)/sizeof(data_passenger[0]);
    for(i=0;i<n;i++)
    {
        if(data_passenger[i]==0){
            continue;
        }
        if(data_passenger[i]>capacity){
            printf("\nCar %s is overload with %d passengers ",id[i],data_passenger[i]);
            continue;
        }
        struct Car* newCar = (struct Car*)malloc(sizeof(struct Car));
        newCar->data_passenger=data_passenger[i];
        strcpy(newCar->id,id[i]);
        newCar ->prev = NULL;
        newCar->next = NULL;
        if(head==NULL){
            head = newCar;
            tail = newCar;
        }

        else
        {
            tail->next=newCar;
            newCar->prev=tail;
            tail = newCar;
        }
    }

    return head;

}

void insertTrainEnd(struct Car** head,int data_passenger,char* id){
    struct Car*temp = (struct Car*)malloc(sizeof(struct Car));
    struct Car* ptr;
    temp->prev=NULL;
    temp->data_passenger=data_passenger;
    strcpy(temp->id,id);
    temp->next=NULL;

    if (*head == NULL) {
        *head = temp;
        return;
    }
    ptr = *head;
    while (ptr->next!=NULL)
    {
        ptr=ptr->next;
        
    }
        ptr->next=temp;
        temp->prev=ptr;
    // return head;
}


void displayTrain(struct Car* head)
{
    struct Car* ptr = head;
    while (ptr!=NULL)
    {
       printf("\n %s passengers %d",ptr->id,ptr->data_passenger);
       ptr=ptr->next;
    }
    
}

int main(){
    struct Car* head = NULL;
    struct Car* ptr;
    head = CreateTrain(head);
    
    printf("\ninformation of car: ");
    displayTrain(head);
    insertTrainEnd(&head,12,"t10");
    printf("\n after add new car in train: ");
    displayTrain(head);
}