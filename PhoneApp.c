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
    printf("\n\tEmail: " );
    char email[20];
    scanf("%s",email);
    fprintf(fp,"%s %s %d %s\n",nombre,gen,num,email);
    fclose(fp);
    printf("\n\tPresione alguna tecla para continuar");
    getch();
    Application();
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
    char nombreSe[20],gen[20],num[20],email[20];
        while(fscanf(fp,"%s %s %d %s",nombreSe,gen,num,email)!=EOF){
            if(strcmp(nombre,nombreSe)==0){
                continue;
            }
            fprintf(fp1,"%s %s %d %s\n",nombreSe,gen,num,email);
        }
    fclose(fp);
    fclose(fp1);
    fp=fopen("info.txt","w");
    fp1=fopen("temp.txt","r");
        while(fscanf(fp1,"%s %s %d %s",nombreSe,gen,num,email)!=EOF){
            fprintf(fp,"%s %s %d %s\n",nombreSe,gen,num,email);
        }
    fclose(fp);
    fclose(fp1);
    remove("temp.txt");
    printf("\n\tPresione alguna tecla para continuar");
    getch();
    Application();
}

void buscar_num(){
    FILE *fp;
    fp=fopen("info.txt","r");
    system("cls");
    printf("\t============Buscar Contacto===============");
    printf("\n\t Nombre que desea Buscar: ");
    char name[20];
    scanf("%s",name);
    char nombreSe[20],gen[20],num[20],email[20];
    while(fscanf(fp,"%s %s %d %s",nombreSe,gen,num,email)!=EOF){
        if(strcmp(name,nombreSe)==0){
            printf("\n\tNombre:  %s\n",nombreSe);
            printf("\n\tGenero:  %s\n",gen);
            printf("\n\tNumero:  %d\n",num);
            printf("\n\tEmail:  %s\n",email);
        }
    }
    fclose(fp);
    printf("\n\tPresione alguna tecla para continuar");
    getch();
    Application();
}

void Application(){
    system("cls");
    printf("\n\t============Telefono De Consola===============\n");
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
            Application();
    }
}

void Login(){
    FILE *fp;
    fp=fopen("password.txt","r");
    system("cls");
    printf("\t============Inicio de Sesion===============");
    printf("\n\tIngrese Usuario: ");
    char usuario[20];
    scanf("%s",usuario);
    // printf("\n\tIngrese Contras: ");
    // char contra[20];
    // scanf("%s",contra);
    char usSE[20],contraSE[20];
    while(fscanf(fp,"%s",usSE)!=EOF){
        if(strcmp(usuario,usSE)==0 ){  
            fclose(fp);
            printf("\n\tPresione alguna tecla para ir a la applicacion");
            getch();
            Application();
        
        }else{
            fclose(fp);
            printf("\n\tINCORRECTO Presione alguna tecla para continuar");
            getch();
            main();
        }
    }

}

void Register(){
FILE *fp;
    fp=fopen("password.txt","a+");
    system("cls");
    printf("\t============Nuevo Usuario===============");
    printf("\n\tUsuario: ");
    char Usuario[20];
    scanf("%s",Usuario);
    printf("\n\tContra: " );
    char Contra[20];
    scanf("%s",Contra);
    fprintf(fp,"%s %s\n",Usuario,Contra);
    fclose(fp);
    printf("\n\tPresione alguna tecla para continuar");
    getch();
    main();
}

void main(){
        system("cls");
    printf("\t============Desea registrarse o iniciar sesion===============\n");
    printf("\t 1. Iniciar Sesion\n");
    printf("\t 2. Resgistrar Usuario\n");
    printf("Elija una opcion: ");
    int select;
    scanf("%d",&select);
    switch (select){
        case 1:
            Login();
            break;
        case 2:
            Register();
            break;
        default:
            main();
    }
}