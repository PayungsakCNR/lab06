#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct song{
  char title[128];
  double duration;
};
typedef struct song Song;

struct listnode{
  Song s;
  struct listnode *next;
};
typedef struct listnode LN;

void insert(LN **hptr, Song *sp);
LN *find_tail(LN *head);
double sum_duration(LN *head);
void free_list(LN **hptr);

int main(){
    Song buf;
    LN *head = NULL;
    int i=1;
    while(i <= 5){
        printf("S%02d: ",i);
        scanf(" %s %lf",buf.title, &buf.duration);
        insert(&head, &buf);
        i++;
    }
    printf("=%.2f", sum_duration(head));
    free_list(&head);
    return 0;
    
}

void insert(LN **hptr, Song *sp){
    LN *new_node = NULL;
    LN *tail = find_tail(*hptr);
    new_node = (LN *)malloc(sizeof(LN));
    strcpy(new_node->s.title, sp->title);
    new_node->s.duration = sp->duration;
    new_node->next = NULL;
    if(tail == NULL){
        *hptr = new_node;
    }
    else{
        tail->next = new_node;
    }
}

LN *find_tail(LN *head){
    LN *tail;
    if(head == NULL){
        return NULL;
    }
    tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    return tail;
}

double sum_duration(LN *head){
    LN *cur;
    cur = head;
    double total = 0.0;
    while(cur != NULL){
        total += cur->s.duration;
        cur = cur->next;
    }
    return total;
}
/*
void *free_list(LN *head){
    LN *tail;
    if(head == NULL)
      return NULL;
    tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    free(tail);
    return tail;
}
*/
void free_list(LN **hptr){
    LN *cur=*hptr,*tmp;
    while(cur != NULL){
        tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    *hptr = NULL;
}