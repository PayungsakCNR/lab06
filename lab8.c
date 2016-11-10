#include <stdio.h>
#include <stdlib.h>
struct listnode{
   int data;
   struct listnode *next;
};

typedef struct listnode LN;
typedef LN *LNP;

typedef struct{
   int size;
   LNP head;
} Stack;


void push(Stack *sptr, int v);
int pop(Stack *sptr);
void cal(Stack *sptr, char operator);
void free_list(LN **hptr);
int main(){
   Stack stack = {0, NULL}; //head
   char s[128]; char *tmp;
   printf("Enter: "); 
   gets(s);
   tmp = s;
   while(*tmp != '\0'){
      if(*tmp >= '0' && *tmp <= '9')
         push(&stack, *tmp - '0');
      else if(*tmp == '+' || *tmp == '-' || *tmp == '*')
         cal(&stack, *tmp);
         tmp++;
   }
   printf("= %d", stack.head->data);
   return 0;
}

void push(Stack *sptr, int v){
   LNP tmp;
   tmp = (LNP)malloc(sizeof(LN));
   tmp->data = v;
   tmp->next = sptr->head;
   sptr->head = tmp;
   (sptr->size)++;
}

int pop(Stack *sptr){
   int v;
   LNP tmp;
   tmp = sptr->head;
   v = tmp->data;
   sptr->head = tmp->next;
   free(tmp);
   (sptr->size)--;
   return v;
}

void cal(Stack *sptr, char operator){
   int a, b;
   a = pop(sptr);
   b = pop(sptr);
   if(operator == '+')
      push(sptr, a+b);
   else if(operator == '-')
      push(sptr, b-a);
   else if(operator == '*')
      push(sptr, a*b);
}
void free_list(LN **hptr){
   LN *cur=*hptr,*tmp;
    while(cur != NULL){
        tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    *hptr=NULL;
}
