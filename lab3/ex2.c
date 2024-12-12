#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_length 150

typedef struct{
    char web_title[MAX_length][150];
    char web_url[MAX_length][150];
    int top;
}Stack;
void init(Stack* stack){
    stack->top = -1;
}
int isFull(Stack* stack){
    return stack->top == MAX_length-1;
}
int isEmpty(Stack* stack){
    return stack->top == -1;
}

void push(Stack* stack,const char* title,const char* url){
    if(isFull(stack)){
        printf("Stack underflow\n");
        return;
    }
    stack->top++; 
    strcpy(stack->web_title[stack->top],title);
    strcpy(stack->web_url[stack->top],url);
}

void pop(Stack* stack,char*title,char*url){
    if(isEmpty(stack)){
        printf("Stack underflow\n");
        return;
    }
    strcpy(title,stack->web_title[stack->top]);
    strcpy(url, stack->web_url[stack->top]);
    stack->top--;
}
void display(Stack* stack){
    if(isEmpty(stack)){
        printf("website is empty    ");
        return;
    }
    printf("\nWebsite accessed ");
    for (int i = stack->top; i>=0 ; i--)
    {
        printf("\nTitle: %s URL: %s",stack->web_title[i],stack->web_url[i]);
    }
    
}
int main(){
    Stack current,backward, forward;
    init(&backward);
    init(&forward);
    init(&current);
    
    strcpy(current.web_title[0],"hackercardlord");
    strcpy(current.web_url[0],"http://hackercardlord.io.vn/");

    current.top =0;
    display(&current);

    int choice=1;
    char title[MAX_length];
    char url[MAX_length];
        printf("\nMenu:\n");
        printf("1. Visit a new page\n");
        printf("2. Backward\n");
        printf("3. Forward\n");
        printf("4. Exit\n");
    do{
      
    if(choice == 1){
            if(current.top != -1){
                push(&backward,current.web_title[0],current.web_url[0]);
            }
            strcpy(current.web_title[0],"FaceBook");
            strcpy(current.web_url[0],"https://web.facebook.com/nqdoan13");
            current.top = 0;
            init(&forward);
            printf("visiting new website -> ");
            display(&current);
    }
    else if(choice == 2){
        if(isEmpty(&backward)){
            printf("No backward history \n");
        }
        else{
            push(&forward,current.web_title[0], current.web_url[0]);
            pop(&backward,title,url);
            strcpy(current.web_title[0],title);
            strcpy(current.web_url[0],url);
            current.top = 0;
            printf("\nbackward to ->");
            display(&current);

        }
    }
    else if(choice == 3){
        if(isEmpty(&forward)){
            printf("no forward history \n");
        }
        else{
            push(&backward,current.web_title[0],current.web_url[0]);
            pop(&forward,title,url);
            strcpy(current.web_title[0],title);
            strcpy(current.web_url[0],url);
            current.top = 0;
            printf("\nfordward to -> ");
            display(&current);
        }

    }
    else if(choice == 4){
        printf("\nexit brower ");
    }
    choice++;
    }while (choice<=4);
    return 0;
    
}
