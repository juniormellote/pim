#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    bool login;
    char user[25], password[50];

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