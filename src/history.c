#include "stdio.h"
#include "stdlib.h"
#include "history.h"
#include "malloc.h"
#include "tokenizer.h"

List* init_history(){
  List *history = (List*)malloc(sizeof(List*)*100);
  return history;
}

void add_history(List *list, char *str){

  int strLen = 0;
  int i = 0;
  while(str[i] != '0'){
    i++;
    strLen++;
  }

  Item *item =(Item*)malloc(sizeof(Item*)*100);
  item->str = copy_str(str, strLen);

  if(list->root != NULL){
    Item *temp = list->root;
    item->id = 1;

      while(temp->next != NULL){
	item->id++;
	temp = temp->next;
      }

    temp->next = item;
    item->id++;
  }
  else{
    item->id = 1;
    list->root = item;
  }
}

char *get_history(List *list, int id){

  if(list == NULL && list->root == NULL)
    return 0;

  Item *temp = list->root;
  while(temp != NULL){

    if(temp->id == id)
      return temp->str;
    
    temp = temp->next;
  }
  return 0;
}

void print_history(List *list){
  Item *temp = list->root;

  while(temp != NULL){
    printf("* %d: %s", temp->id, temp->str);
    temp  =temp->next;
  }
}

void free_history(List *list){
  Item *temp= list->root;

  while(temp->next != NULL){
    free(temp->str);
    free(temp);
    temp = temp->next;

  }
  free(list);
  free(temp);
}



