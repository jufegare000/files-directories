/*

Stat: Escriba su propia versión del comando stat (consulte sobre lo que hace este), la cual simplemente invoca la llamada del sistema stat() en un archivo o directorio. Imprima el tamaño del archivo, el número de bloques asignado, contador de referencias (links), etc. ¿Qué significa el contador de referencias (link count) de un directorio?, ¿cómo cambia el número de entradas en el directorio? Interfaces útiles: stat(), naturalmente.

*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    /*
        Dependiendo de la opción que ingrese el usario se ejecutarán las funciones
        correspondientes de stat()
    */
    char *nameFile = argv[1];
    int opt = (int)atoi(argv[2]);

    struct stat elstatpa;
    int status = stat(nameFile, &elstatpa);

    if (status == 0)
    {

        switch (opt)
        {
        case 1: // lenght of file
            printf("Tamano del archivo: %ld bytes \n", elstatpa.st_size);
            break;
        case 2:
            printf("Tamano de bloque: %ld \n", elstatpa.st_blksize);
            break;
        case 3:
            printf("Contador de referencia: %ld \n", elstatpa.st_nlink);
            break;
        case 4:
            printf("Id de dispositivo: %ld \n", elstatpa.st_dev);
            break;

        case 5:
            printf("Numero de Inode: %ld \n", elstatpa.st_ino);
            break;

        case 6:
            printf("Numero de hard links: %ld \n", elstatpa.st_nlink);
            break;
        case 7:
            printf("User Id del propietario: %d \n", elstatpa.st_uid);
            break;
        case 8:
            printf("Group Id del propietario: %d \n", elstatpa.st_gid);
            break;
        case 9:
            printf("Device id: %ld \n", elstatpa.st_rdev);
            break;
        case 10:
            printf("Numero de bloques de 512B asignados: %ld \n", elstatpa.st_blocks);
            break;
        }
    }
    else
    {
        printf("Error al leer archivo, asegurese de escribir bien el nombre y pasar el número del argumento:"
               "1 Para tamano de archivo \n"
               "2 Para tamano de bloque \n"
               "3 Para contador de referencia \n"
               "4 Para Id del dispositivo \n"
               "5 Para número de Inode \n"
               "6 Para Numero de hard links \n"
               "7 Para User Id del propietario \n"
               "8 Para Group Id del propietario \n"
               "9 Device id \n"
               "10 Numero de bloques de 512B asignados \n");
        return -1;
    }
    return 0;
}

/*

               "1 Para tamano de archivo \n"
               "2 Para tamano de bloque \n"
               "3 Para contador de referencia \n"
               "4 Para Id del dispositivo \n"
               "5 Para número de Inode \n"
               "6 Para Numero de hard links \n"
               "7 Para User Id del propietario \n"
               "8 Para Group Id del propietario \n"
               "9 Device id \n"
               "10 Numero de bloques de 512B asignados \n");
*/