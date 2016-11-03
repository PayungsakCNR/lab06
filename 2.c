#include <stdio.h>
#include <stdlib.h>
struct song{
  char title[128];
  double duration;
};
typedef struct song Song;

struct listnode{
  Song *sp;
  struct listnode *next;
};
typedef struct listnode LN;

Song *input_song();
void insert(LN **hptr, Song *sp);
LN *find_tail(LN *head);
double sum_duration(LN *head);
void free_list(LN **hptr);

int main(){
  Song *sp;
  LN *head = NULL;
  int i;
  for(i = 0; i < 5; i++){
      printf("S%02d: ",i+1);
      sp = input_song();  //malloc, scanf Song in this function
      insert(&head, sp);
  }
  printf("=%.2f",sum_duration(head));
  free_list(&head);
  printf("=%.2f",sum_duration(head));
  return 0;
}

Song *input_song(){
    Song *cur_s;
    cur_s = (Song*)malloc(sizeof(Song));
    scanf("%s %lf", cur_s->title, &cur_s->duration);
    return cur_s;
}

void insert(LN **hptr, Song *sp){
    LN *new_node, *tail;
    new_node = (LN*)malloc(sizeof(LN));
    new_node->sp = sp;
    new_node->next = NULL;
    tail = find_tail(*hptr);
    if(tail == NULL)
        *hptr = new_node;
    else
        tail->next=new_node;
}

LN *find_tail(LN *head){
    LN *tail = head;
    if(tail == NULL)
        return NULL;
    while(tail->next != NULL){
        tail = tail->next;
    }
    return tail;
}

double sum_duration(LN *head){
    LN *cur = head;
    double total = 0.0;
    while(cur != NULL){
        total += cur->sp->duration;
        cur = cur->next;
    }
    return total;
}

void free_list(LN **hptr){
    LN *cur = *hptr, *tmp;
    while(cur != NULL){
        tmp = cur;
        cur = cur->next;
        //free(tmp->sp);
        free(tmp);
    }
    *hptr = NULL;
}