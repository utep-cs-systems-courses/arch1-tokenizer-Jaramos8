#include "stdio.h"
#include "malloc.h"
#include "tokenizer.h"

int space_char(char c){

  if(c == '\t' || c == ' ')
    return 1;

  else
    return 0;
}

int non_space_char(char c){

  if(c == 't' || c == ' ')
    return 0;         

  else 
    return 1;          
}

char *word_start(char *str){

  while(space_char(*str)){
    str++;
  }

  return str;
}

char *word_terminator(char *word){

  while(non_space_char(*word)){
      word++;
  }

  return word;
}

int count_words(char *str){

  int numberOfWords = 0;
  int state = 0;

  while(*str){
    if(*str== ' ' || *str == '\t'){
      state = 0;
    }
    else if(state == 0){
      state=1;
      numberOfWords++;
    }
    str++;
   }

  return numberOfWords;
}

char *copy_str(char *intStr, short len){

  char *sentence =(char*)malloc(sizeof(char)*(len+1)) ;
  
  for(int i = 0; i < len; i++)
    sentence[i] = intStr[i];
  

  sentence[len] = '\0';
  
  return sentence;

}

char **tokenize(char *str){

  int i = 0;
  char *sentence = str;
  int numberOfWords = count_words(sentence);
  char **tokens = (char**)malloc(sizeof(char*)*(numberOfWords+1));
 

  while(i < numberOfWords){

    sentence = word_start(sentence);
    char *word = copy_str(sentence, word_terminator(sentence) - sentence);
    sentence = word_terminator(sentence);

    tokens[i] = word;
    i++;
  }

  tokens[i] = '\0';
    return tokens;
  
}

void print_tokens(char **tokens){

  int i = 0;

  while(tokens[i]){

    printf("Token [%d] : %s \n", i, tokens[i]);

    i++;
  }
  
}

void free_tokens(char **tokens){

  int i = 0;
  
  while(tokens[i]){

    free(tokens[i]);
    i++;
    
  }
  free(tokens);
}

