#include <stdio.h>
#include <string.h>
FILE *fp;
void first(FILE *fp);
void alnum(FILE *fp);
void space(FILE *fp);
void afterequals(FILE *fp);
void secondspace(FILE *fp);

int main() { 
        fp = fopen("ex.txt", "r");
        if (fp == NULL) { printf("Error! Could not open file."); }
        first(fp);
       }

void first(FILE *fp) {
     int c;
        if ((c = fgetc(fp)) == EOF) {
         fclose(fp);
         exit(0);
        }

        if (c == '\n') { first(fp); }
        
        if (!isalpha(c)) {                      //checking to see if first is not a character
                 while (c != '\n'){
                    c = fgetc(fp);
                    putchar(c);
                }
                
                printf(" Bad. Not a character.\n");              //if it's not a character, print bad 
                first(fp);
        }
        
        else {  
                putchar(c);
                alnum(fp);                      //if it is a character, jump to alnum
        }
}

void alnum(FILE *fp) {                                                                           //checking the next character pointer

        int c = fgetc(fp);                                                                       //grab second index
        if (c == 32) {                                                                           //if c is equal to a space
                putchar(c);
                space(fp);
        }

        else if (c == 41) {                                                                     // c is equal to closing  
                putchar(c);
                alnum(fp);

        }
        else if (!isalnum(c)) {
              while (c != '\n'){
                  putchar(c);
                    c = fgetc(fp);
                }
                printf(" Bad. Double operand.\n");
                first(fp);
        }

        else {  
                putchar(c);
                alnum(fp);                                                                      //if it is good, print out good 
        }


}

void space(FILE *fp) {                                                                          //checking what to do after a space

        int c = fgetc(fp);
        if (c == 61) {                                                                          //if there is an equal
                putchar(c);
                afterequals(fp);                                                                //jump to alnum to see check for space
        }

                else if (c == 37 || c == 42 || c == 43 || c == 45 || c == 47) {
                        putchar(c);
                        alnum(fp);
                }

                else if (c == 41) {                                                             // c is equal to closing parenthesis 
                        putchar(c);
                        alnum(fp);
                }

                else if (c==40) {                                                               // c is equal to open parenthesis 
                        putchar(c);
                        first(fp);
                }

                else if (c == 59) {                                                             //reached semicolon
                        putchar(c);
                        c = fgetc(fp);
                                while(c != '\n'){ c = fgetc(fp); }
                        printf(" Good\n");
                        first(fp);           
                }

                else if (isalpha(c)) {
                        putchar(c);
                        alnum(fp);
                }

                else if (c!=59) {
                        while (c != '\n'){
                                putchar(c);
                                c = fgetc(fp);
                        }
                        printf(" Bad. Missing semicolon or improper op.\n");
                        first(fp);
                }

                        else {
                                while (c != '\n'){
                                        putchar(c);
                                        c = fgetc(fp);
                                }
                                printf(" Bad. Invalid operand.\n");
                                first(fp);
                        }
}


void afterequals(FILE *ptr) {
        int c = fgetc(fp);

        if (c != 32) {
                while (c != '\n'){
                    putchar(c);
                    c = fgetc(fp);
                }
                printf(" Bad. Double operands.\n");
                first(fp);
        }

        else {
                putchar(c);
                secondspace(fp);
        }
}

void secondspace(FILE *ptr) {
        int c = fgetc(fp);

        if (!isalpha(c)) {
                while (c != '\n'){
                    putchar(c);
                    c = fgetc(fp);
                }
                printf(" Bad. Consecutive operands.\n");
                first(fp);
               
        }

        else {
                putchar(c); 
                alnum(fp);
        }
}

