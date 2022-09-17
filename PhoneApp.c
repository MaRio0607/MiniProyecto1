#include<stdio.h>
#include<windows.h>

void nuevo_num(){
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
        printf("\n\tNumero2: ");
    char num2[20];
    scanf("%s",num2);
    printf("\n\tEmail: " );
    char email[20];
    scanf("%s",email);
    printf("\n\tEmail2: " );
    char email2[20];
    scanf("%s",email2);
    fprintf(fp,"%s %s %d %d %s %s\n",nombre,gen,num,num2,email,email2);
    fclose(fp);
    printf("\n\tPresione alguna tecla para continuar");
    getch();
    main();
}

void borrar_num(){
    FILE *fp,*fp1;
    fp=fopen("info.txt","r+");
    fp1=fopen("temp.txt","w");
    system("cls");
    printf("\t============Borrar Contacto===============");
    printf("\n\t Nombre que desea borrar: ");
    char nombre[20];
        scanf("%s",nombre);
    char nombreSe[20],gen[20],email[20],email2[20];
    int num,num2;
        while(fscanf(fp,"%s %s %d %d %s %s",nombreSe,gen,num,num2,email,email2)!=EOF){
            if(strcmp(nombre,nombreSe)==0){
                continue;
            }
            fprintf(fp1,"%s %s %d %d %s %s\n",nombreSe,gen,num,num2,email,email2);
        }
    fclose(fp);
    fclose(fp1);
    fp=fopen("info.txt","w");
    fp1=fopen("temp.txt","r");
        while(fscanf(fp1,"%s %s %d %d %s %s",nombreSe,gen,num,num2,email,email2)!=EOF){
            fprintf(fp,"%s %s %d %d %s %s",nombreSe,gen,num,num2,email,email2);
        }
    fclose(fp);
    fclose(fp1);
    remove("temp.txt");
    printf("\n\tPresione alguna tecla para continuar");
    getch();
    main();
}

void buscar_num(){
    FILE *fp;
    fp=fopen("info.txt","r");
    system("cls");
    printf("\t============Buscar Contacto===============");
    printf("\n\t Nombre que desea Buscar: ");
    char name[20];
    scanf("%s",name);
    char nombreSe[20],gen[20],email[20],email2[20];    
    int num,num2;
    while(fscanf(fp,"%s %s %d %d %s %s",nombreSe,gen,num,num2,email,email2)!=EOF){
        if(strcmp(name,nombreSe)==0){
            printf("\n\tNombre:  %s\n",nombreSe);
            printf("\n\tGenero:  %s\n",gen);
            printf("\n\tNumero:  %d\n",num);
            printf("\n\tEmail:  %s\n",email);
              printf("\n\tNumero2:  %d\n",num2);
            printf("\n\tEmail2:  %s\n",email2);
        }
    }
    fclose(fp);
    printf("\n\tPresione alguna tecla para continuar");
    getch();
    main();
}

void main(){
    
    system("cls");
    printf("\t============Telefono De Consola===============\n");
    printf("\t 1. Agregar Contacto\n");
    printf("\t 2. Buscar Contacto\n");
    printf("\t 3. Borrar Contacto\n");
    printf("\t 4. Salir\n");
    printf("Elija una opcion: ");
    int select;
    scanf("%d",&select);
    switch (select){
        case 1:
            nuevo_num();
            break;
        case 2:
            buscar_num();
            break;
        case 3:
            borrar_num();
            break;
        default:
            main();
    }

}