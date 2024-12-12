#include <stdio.h>
#include <stdlib.h>

struct Digit{
    int data;
    struct Digit* next;
};
struct Digit* ListNum(struct Digit*head){
    int n,i;
    int data[] = {3,-5,12,8,9,21,42};
    n= sizeof(data)/sizeof(data[0]);
    struct Digit* temp =NULL;

    for(i=0;i<n;i++){
    struct Digit* newdigit = (struct Digit*)malloc(sizeof(struct Digit));
        newdigit->data=data[i];
        newdigit->next=NULL;
        if (head == NULL)
        {
            head = newdigit;
        }
        else
        {
            temp->next=newdigit;
        }
        temp=newdigit;
        
        
    }
    return head;

}

void addNumberposition(struct Digit *head,int data,int position){
    struct Digit *ptr = head; 
    struct Digit *ptr2 = malloc(sizeof(struct Digit));
    ptr2 -> data = data;
    ptr2 -> next = NULL;
    position--;
    while (position!=1)
    {
        ptr = ptr ->next;
        position--;
    }
    ptr2->next=ptr->next;
    ptr->next=ptr2;
    
}

void delelingNumber(struct Digit** head, int position){
    struct Digit *current =*head;
    struct Digit *previous = *head;
    if(position ==1){
        *head = current->next;
        free(current);
        current =NULL;
    }
    else{
        while (position !=1)
        {
           previous = current;
           current =current ->next;
           position--;
        }
        previous->next=current->next;
        free(current);
        current=NULL;
        
    }
    
}

void display(struct Digit* digit){
    while (digit !=NULL)
    {
        printf(" %d ",digit->data);
        digit = digit->next;
    }
    
}


int sumNumber(struct Digit* head){
    int sum = 0;
    struct Digit* current = head;
    while (current!=NULL)
    {
        sum +=current->data;
        current=current->next;
    }

    return sum;
    
}

int main(){
    struct Digit* head =NULL;
    head = ListNum(head);
    printf("Linked list number ares: ");
    display(head);
    int data=38;
    int position =2;

    addNumberposition(head,data,position);
    printf("\nlinked list add number in position %d: ",position);
    display(head);
    int del_position = 5;
    delelingNumber(&head,del_position);
    printf("\nafter deleting number %d: ",del_position);
    display(head);
    int total_number = sumNumber(head);
    printf("\nsum of number = %d",total_number);
}