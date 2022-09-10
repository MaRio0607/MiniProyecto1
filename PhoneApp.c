#include<stdio.h>
#include<windows.h>

void main(){
    FILE *fp;
    fp=fopen("info.txt","a+");
    system("cls");
    printf("\t============Agragar Contacto===============");
    printf("\n\tNombre: ");
    char nombre[20];
    scanf("%s",nombre);
    printf("\n\tGenero: " );
    char gen[20];
    scanf("%s",gen);
        printf("\n\tNumero: ");
    char num[20];
    scanf("%s",num);
    printf("\n\tEmail: " );
    char email[20];
    scanf("%s",email);
    fprintf(fp,"%s %s %s %s\n",nombre,gen,num,email);
    fclose(fp);
    printf("\n\tPresione alguna tecla para continuar");
    getch();
    main();
}