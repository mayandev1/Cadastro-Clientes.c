#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTES 100

struct Cliente {
    char nome[100];
    char email[100];
};

void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int apresentarMenu() {
    int escolha;

    limparTela();

    printf("+==================================+\n");
    printf("|         MENU DE CADASTRO         |\n");
    printf("+==================================+\n");
    printf("| 1. Adicionar Cliente             |\n");
    printf("| 2. Visualizar Clientes           |\n");
    printf("| 3. Editar Cliente                |\n");
    printf("| 4. Excluir Cliente               |\n");
    printf("| 5. Sair                          |\n");
    printf("+==================================+\n");
    printf("Selecione sua escolha: ");
    scanf("%d", &escolha);
    getchar();

    return escolha;
}

void removerNovaLinha(char* str){
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main(){
    struct Cliente clientes[MAX_CLIENTES];
    int opcao, numClientes = 0;
    char nome[100];

    do{
        opcao = apresentarMenu();
        switch (opcao){
        case 1:
            printf("Digite o nome do cliente: ");
            fgets(clientes[numClientes].nome, 100, stdin);
            removerNovaLinha(clientes[numClientes].nome);

            printf("Digite o email do cliente: ");
            fgets(clientes[numClientes].email, 100, stdin);
            removerNovaLinha(clientes[numClientes].email);

            numClientes++;
            printf("Cliente adicionado com sucesso!\n");
            break;
        case 2:
            printf("Clientes cadastrados: \n");
            for (int i = 0; i < numClientes; i++){
                printf("Nome: %s\n", clientes[i].nome);
                printf("Email: %s\n", clientes[i].email);
            }
            break;
        case 3:
            printf("Digite o nome do cliente a ser editado: ");
            fgets(nome, 100, stdin);
            removerNovaLinha(nome);

            for (int i = 0; i < numClientes; i++){
                if (strcmp(clientes[i].nome, nome) == 0){
                    printf("Digite o novo nome do cliente: ");
                    fgets(clientes[i].nome, 100, stdin);
                    removerNovaLinha(clientes[i].nome);

                    printf("Digite o novo email do cliente: ");
                    fgets(clientes[i].email, 100, stdin);
                    removerNovaLinha(clientes[i].email);

                    printf("Cliente editado com sucesso!\n");
                    break;
                }
            }
            break;
        case 4:
            printf("Digite o nome do cliente que deseja excluir: ");
            fgets(nome, 100, stdin);
            removerNovaLinha(nome);

            for (int i = 0; i < numClientes; i++) {
                if (strcmp(clientes[i].nome, nome) == 0){
                    for (int j = i; j < numClientes - 1; j++){
                        clientes[j] = clientes[j + 1];
                    }
                    numClientes--;
                    printf("Cliente excluido com sucesso!\n");
                    break;
                }
            }
            break;
        case 5:
            printf("Encerrando o programa...\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
        }
        printf("\nPressione Enter para continuar...");
        getchar();
    } while (opcao != 5);

    return 0;
}
