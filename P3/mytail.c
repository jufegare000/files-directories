#include <stdio.h> 
#include <stdlib.h>


int main(int argc, char *argv[])
{
    char *prmNumber=argv[1];
    char *fileName=argv[2];

    char * line = NULL;
    size_t len = 0;

    FILE *fp;
    int pos=-1;
    int line_count=1;
    char *c;

    if(prmNumber==NULL || fileName==NULL){
        perror("Error: argumentos inválidos");
        return (-1);
    }
    int linesNumber=atoi(prmNumber);
    if(linesNumber>=0){
        perror("Error: numero de lineas inválido (debe ser un número negativo)");
        return (-1);
    }
    linesNumber=linesNumber*-1;
   
    fp = fopen(fileName, "r");
    fseek(fp, pos, SEEK_END);
    while (pos) {
        fseek(fp, pos, SEEK_END); 
        *c=(char)fgetc(fp);
        if (*c == '\n') {
            if (line_count++ == linesNumber) {
                break;
            }
        }
        pos--;
    }

     while ((getline(&line, &len, fp)) != -1) {
        printf("line: %s", line);
    }

    printf("\n");

    return 0;
}

