#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    //variables declaration   
    FILE *fp;             
    int lineCounter = 0;  
    int wordCount = 0;      
    int wordCount2 = 0; 
    int * wordCounter2 = malloc(sizeof(int)*2);     
    char *token;   
    char * line = malloc(sizeof(char)*101);              
    //open the file passed in the command line for reading     
    fp = fopen (argv[1],"r"); 
       
    while(!feof(fp)) {
        //read the file and store it in the variable named line, 
        fgets(line, 100, fp);         
        token = strtok(line," ");         
        while(token!= NULL) {
            wordCount+=1;            
            wordCount2+=1;           
            token = strtok(NULL," ");   
        }
        wordCounter2 = realloc(wordCounter2,sizeof(char)*(lineCounter+2));  
        wordCounter2[lineCounter] = wordCount2;    //store word count2 in the line counter array
        wordCount2 = 0;      //assign wordCount2 to 0
        lineCounter+=1;     //increment the variable lineCounter
    }
    
    if (lineCounter == 1 || wordCount == 1) {
        //print the number of words and number of lines found in the file 
        printf("%d word on %d line\n", wordCount, lineCounter);   
    }
    else if(lineCounter > 1 && wordCount > 1) {       
        //print the number of words and number of lines found in the file 
        printf("%d words on %d lines\n", wordCount, lineCounter);   
    }

    for (int i = 0; i < lineCounter; i++) {
        //print the number of words in each line 
        printf("%d ",wordCounter2[i]);     
    }
    //print a new line 
    printf("\n");     
    //close the file 
    fclose(fp);  

    return 0;        
}