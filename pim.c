#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<locale.h>

#define TRUE  1
#define FALSE 0
typedef int bool;


bool doLogin(char user[], char password[]){
    FILE *users;
    bool loginSuccess = FALSE;
    char userFile[25], passwordFile[50];

    users = fopen("users.txt", "r");
    if(users == NULL) {
        printf("Erro ao abrir arquivo !\n");
        exit(0); 
    }
    do {
        if(feof(users)) {
            break;
        }
        fscanf(users, "%s %s", userFile, passwordFile);

        if((strcmp(user, userFile) == 0) && (strcmp(password, passwordFile) == 0)) {
            loginSuccess = TRUE;
            break;
        }

    } while(1);
    
    printf("\n");
    printf("%i \n", loginSuccess);

    fclose(users);
    return loginSuccess;
}

int main(){
    setlocale(LC_ALL,"");//comando para acentuaçao 
    bool login;
    char user[25], password[50];
    printf("        IIIII    II  IIIII  IIIII  IIIII  IIIII   II  IIIII         \n");
printf("        II  III  II  IIIII  IIIII  IIIII  II II   II  IIIII\n");
printf("        II  III  II     I      I   II II  IIIII   II  II II\n");
printf("        IIIII    II   I      I     IIIII  IIII    II  IIIII\n");
printf("        II       II  IIIII  IIIII  II II  IIIII   II  II II\n");
printf("        II       II  IIIII  IIIII  II II  II  II  II  II II\n");
    

    // fazer menu aqui
    printf("Faça seu login... \n");
    printf("Usuário: ");
    scanf("%s", user);

    printf("Senha: ");
    scanf("%s", password);

    if(doLogin(user, password) == TRUE) {
        printf("VOCÊ ESTÁ LOGADO \n");
        //continuar fluxo e fazer menu a partir daqui
    } else {
        printf("SENHA INCORRETA \n");
    }

    return(0);
}
