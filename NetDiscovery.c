#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define MAX_SUBDOMAIN_LENGTH 50

int main(int argc, char *argv[]){

    //Definição de Variaveis
    char *urlAlvo;
    urlAlvo = argv[1];
    struct hostent *host;

    char *resultado;
    FILE *saida; 
    FILE *discovery = fopen(argv[2], "r");

    char txt[MAX_SUBDOMAIN_LENGTH];

    if (argc < 3 || discovery == NULL){
        printf(" _   _  _____  _____  _____   _   _____   _____  _____    _   _  _____  ____   _   _ \n");
        printf("| \\ | || ____||_   _||  __ \\ | | |  ___| / ____|/ ___ \\ | |  | || ____||  _ \\ | | | |\n");
        printf("|  \\| || |___   | |  | |  | || | | |___ | |    / /   \\ \\| |  | || |___ | |_| | \\ V / \n");
        printf("| |\\  ||  ___|  | |  | |  | || | |___  \\| |    | |   | || |  | ||  ___||    /   | |  \n");
        printf("| | \\ || |___   | |  | |__| || |  ___| || |____\\ \\__/ / | |__| || |___ | |\\\\    | |  \n");
        printf("|_|  \\||_____|  |_|  |_____/ |_| |____/  \\_____|\\____/   \\____/ |_____||_| \\\\   |_|  v1.0\n");

        printf("\n====================================NetDiscovery - BaianoGeek================================\n");
        printf("=====================Modo de Uso: ./NetDiscovery alvo.com.br NetDiscovery.txt===============\n");
        return 0;
    }else{
        printf(" _   _  _____  _____  _____   _   _____   _____  _____    _   _  _____  ____   _   _ \n");
        printf("| \\ | || ____||_   _||  __ \\ | | |  ___| / ____|/ ___ \\ | |  | || ____||  _ \\ | | | |\n");
        printf("|  \\| || |___   | |  | |  | || | | |___ | |    / /   \\ \\| |  | || |___ | |_| | \\ V / \n");
        printf("| |\\  ||  ___|  | |  | |  | || | |___  \\| |    | |   | || |  | ||  ___||    /   | |  \n");
        printf("| | \\ || |___   | |  | |__| || |  ___| || |____\\ \\__/ / | |__| || |___ | |\\\\    | |  \n");
        printf("|_|  \\||_____|  |_|  |_____/ |_| |____/  \\_____|\\____/   \\____/ |_____||_| \\\\   |_|  v1.0\n");

        printf("\n==================================NetDiscovery - BaianoGeek================================\n\n");

       char resposta;
        printf("Deseja criar um arquivo com a saída? (s/n): ");
        scanf(" %c", &resposta);

        if (resposta == 's' || resposta == 'S') {
            char *nomeArquivoSaida = argv[1];
            saida = fopen(nomeArquivoSaida, "w");
            if (saida == NULL) {
                printf("Erro ao criar o arquivo de saída.\n");
                fclose(discovery);
                return 1;
            }
        } else {
            saida = stdout;
        }
        

        while (fscanf(discovery, "%s", txt) != EOF) {
            char resultado[MAX_SUBDOMAIN_LENGTH + strlen(urlAlvo) + 2];
            snprintf(resultado, sizeof(resultado), "%s.%s", txt, urlAlvo);

            host = gethostbyname(resultado);

            if(host != NULL){
                printf("Subdominio: %s\t\t IP: %s\n", resultado, inet_ntoa(*((struct in_addr *)host->h_addr)));
                fprintf(saida, "%s \n", inet_ntoa(*((struct in_addr *)host->h_addr)));
            }
        }

    }
    if (saida != stdout) {
        fclose(saida);
    }
    fclose(discovery);
    return 0;

}
