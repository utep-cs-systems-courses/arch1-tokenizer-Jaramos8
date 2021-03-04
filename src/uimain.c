#include "stdio.h"
#include "stdlib.h"
#include "tokenizer.h"
#include "history.h"
#include "malloc.h"

int main()
{
  
  char input[100];
  char sentence[100];
  char identifier[100];
  List *history = init_history();
  int exit = 0;
  
  printf("\n");
  printf(" Enter 's' to enter sentence / 'h' for History / 'x' to Exit]");

  while(exit == 0 ){

   fgets(input, 100, stdin);

   if(*input == 'x'){
    exit = 1;
   
  }
  
  else if(*input == 'h'){
    printf("Enter 'a' for the complete history / ID number '!#' for specific history entry  ");
    fgets(identifier,100,stdin);

    if(*identifier == 'a'){
      print_history(history);
    }
    else{

      int id = atoi(identifier);
      char *entry = get_history(history, id);
      if (entry != NULL){

	printf("%d: ", id);
	printf(get_history(history,id));
	
      }
    }
    

  }

  else if (*input == 's'){
    printf("Enter Sentence:");
    fgets(sentence, 100,stdin);
    
  printf("%s\n",sentence);
  
  char **tokens = tokenize(sentence);
  printf("Tokens: \n");
  print_tokens(tokens);
  add_history(history,sentence);
  free_tokens(tokens);
  }
  }
 
  return 0;
}
