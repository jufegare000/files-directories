#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>

char* concat(const char *s1, const char *s2);

int main(int argc, char *argv[])
{
    DIR *d;
    struct dirent *dir;

    char *param1=argv[1];
    char *dirName;
    int show_file_inf=0;
    if(strcmp(param1,"-l")==0){
        show_file_inf=1;
        dirName=argv[2];
    }
    else{
        dirName=argv[1];
    }

    if(dirName==NULL){
        perror("Error: Parametros inválidos");
        return (-1);
    }

    printf("directorio: %s\n", dirName);
    printf("show file info?: %d\n", show_file_inf);
    
    if(strcmp(dirName,".")==0){
        dirName="./";
    }

    if(strcmp(dirName,"..")==0){
        dirName="../";
    }

    d = opendir(dirName);
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            if(show_file_inf==1){
                char* file_name=concat(dirName,dir->d_name);
                struct stat elstatpa;
                int status = stat(file_name, &elstatpa);
                struct passwd *pw = getpwuid(elstatpa.st_uid);
                struct group  *gr = getgrgid(elstatpa.st_gid);
                printf("directorio %s\n", file_name);
               
                 printf("\n-------------\n");
                 printf("%s\n", dir->d_name);
                 printf("owner:%s\n", pw->pw_name);
                 printf("grupo:%s\n", gr->gr_name);
                 printf("File Permissions:");
                 printf("\t USR:");
                 printf( (S_ISDIR(elstatpa.st_mode)) ? "d" : "-");
                 printf( (elstatpa.st_mode & S_IRUSR) ? "r" : "-");
                 printf( (elstatpa.st_mode & S_IWUSR) ? "w" : "-");
                 printf( (elstatpa.st_mode & S_IXUSR) ? "x" : "-");
                 printf("\t GRP:");
                 printf( (elstatpa.st_mode & S_IRGRP) ? "r" : "-");
                 printf( (elstatpa.st_mode & S_IWGRP) ? "w" : "-");
                 printf( (elstatpa.st_mode & S_IXGRP) ? "x" : "-");
                 printf("\t OTH:");
                 printf( (elstatpa.st_mode & S_IROTH) ? "r" : "-");
                 printf( (elstatpa.st_mode & S_IWOTH) ? "w" : "-");
                 printf( (elstatpa.st_mode & S_IXOTH) ? "x" : "-");
                 printf("\n-------------\n");
               
            }
            else{
                printf("%s\n", dir->d_name);
            }
        }
        closedir(d);
    }
    return(0);
}

char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}