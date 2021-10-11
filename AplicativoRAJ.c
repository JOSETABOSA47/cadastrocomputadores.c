/*
JOSÉ TABOSA BRAGA SOBRINHO - 2019021600
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h> 
#include <locale.h>
#define SIZE 600
 
void encontrar_ip(char buf[500], char ip_retorno[30]) {
    int idx = 0;
    while(buf[idx] != ';') {
        idx++;
    }
 
    idx++;
 
    int i = 0;
 
    while(buf[idx] != ';') {
        ip_retorno[i] = buf[idx];
        idx++;
        i++;
    }
}
 
int main (){
 
    char menu, listar, sair, quant, i;
    setlocale(LC_ALL, "Portuguese");
        // criando a variável ponteiro para o arquivo
    FILE *pont_arq;
    FILE *pont_arq1;
    FILE *pont_arq2;
    char alterar[600];
    char consultar[250];
    char gerarbackup[600];
    char line[250];
    char *charptr;
    char cabecario[30];
    char nomeComp[600];
    char IP[600];
    char SO[600];
    char versaoSO[600];
    char responMaqui[600];
    char setor[600];
 
 
    char *computador1[600];
    char *ip1[600];
    char *os1[600];
    char *osversion1[600];
    char *responsavel1[600];
    char *area1[600];	
  //abrindo o arquivo
 
pont_arq = fopen("bancoAplicativo.txt", "a");
//pont_arq1 = fopen("bancoAplicativo1.bkp", "a");
 
// fechando arquivo
// fclose(pont_arq);
//testando se o arquivo foi realmente criado
if(pont_arq == NULL)
{
printf("Erro na abertura do arquivo!");
return 1;
}
 
fclose(pont_arq);
while(menu!=7){
 
        system("cls");
        system("color F9");
 		printf("\t\n ________________________________________");
 		printf("\t\n|                                        |");
        printf("\t\t\n|        BEM-VINDOS AO SISTEMA RAJ       |");
        printf("\t\n|________________________________________|");
        printf(" \t\t\n");
        
        printf("\n    1 – Cadastrar um novo computador    ");
        printf("\n    2 - Consultar um computador         ");
        printf("\n    3 – Alterar um computador           ");
        printf("\n    4 – Excluir um computador           ");
        printf("\n    5 – Listar todos os computadores    ");
        printf("\n    6 – Gerar backup                    ");
        printf("\n    7 - Sair                            ");
        printf("\t\t\n\n________________________________________");
        printf(" \t\t\n");
        printf("\nQual opcao voce deseja acessar? ");
        scanf("%d", &menu);
 		
        switch(menu){
            system("cls");
 
            case 1:
                system("cls");
                //printf("\nQuantos cadastros deseja realizar? ");
                //scanf("%d", &quant);
            pont_arq = fopen("bancoAplicativo.txt", "a");
 
            for(i=1;i<=menu;i++){
                printf(" ________________________________________\n");
				printf("|                                        |\n");
				printf("|          INICIANDO CADASTRO            |\n");
				printf("|________________________________________|\n");
                printf("\n Nome do Computador : ");
                scanf("%s", &nomeComp);
                fprintf(pont_arq, "%s;", nomeComp);
                printf("\n IP : ");
                scanf("%s", &IP);
                fprintf(pont_arq, "%s;", IP);
                printf("\n SO : ");
                scanf("%s", &SO);
                fprintf(pont_arq, "%s;", SO);
                printf("\n Versao do SO : ");
                scanf("%s", &versaoSO);
                fprintf(pont_arq, "%s;", versaoSO);
                printf("\n Responsavel : ");
                scanf("%s", &responMaqui);
                fprintf(pont_arq, "%s;", responMaqui);
                printf("\n Setor : ");
                scanf("%s", &setor);
                fprintf(pont_arq, "%s", setor);
                fprintf(pont_arq,"\n");
                system("pause");
                system("cls");
            fclose(pont_arq);
            }
            break;
 
            case 2:
                system("cls");
            pont_arq = fopen("bancoAplicativo.txt", "r");
 
                printf("\n Digite o IP: ");
                scanf("%s", consultar);
                system("cls");
 
            while(fgets(line, 250, pont_arq) != NULL){		
                char *computador  = strtok(line, ";");
                char *ip          = strtok(NULL, ";");
                char *os          = strtok(NULL, ";");
                char *osversion   = strtok(NULL, ";");
                char *responsavel = strtok(NULL, ";");
                char *area        = strtok(NULL, ";");
 
            if(!strcmp(consultar, ip)){
            	printf(" ________________________________________\n");
				printf("|                                        |\n");
				printf("|      SEGUE COMPUTADOR SOLICITADO!      |\n");
				printf("|________________________________________|\n");
            	//printf("|                                        \n");
    			printf("|                                        \n"); 
                printf("|     Nome do Computador : %s", computador);
                printf("\n|     IP :                 %s", ip);
                printf("\n|     SO :                 %s", os);
                printf("\n|     Versao do SO :       %s", osversion);
                printf("\n|     Responsavel :        %s",responsavel);
                printf("\n|     Setor :              %s", area);
                printf("|________________________________________");
                printf("\n\n");
                system("pause");
                system("cls");
            }
 
            }
 
            fclose(pont_arq);
            break;
 
            case 3:
            system("cls");
            pont_arq = fopen("bancoAplicativo.txt", "r");
            printf("\nDigite o IP: ");
            char ip_buf[30], receber_ip[30];
            scanf("%s", ip_buf);
            system("cls");
 
            // aqui fica o arquivo inteiro
            char file_buf[1000][500];
 
            int alterar = 0, achou = 0, counter = 0;
 
            while(fgets(file_buf[counter], 500, pont_arq) != NULL) {
                encontrar_ip(file_buf[counter], receber_ip);
                if(strcmp(receber_ip, ip_buf) == 0) {
                    alterar = counter;
                    achou = 1;
                }
                counter++;
                memset(receber_ip, 0, 30);
            }                                   
 
            char buf[300];
 
            int cnt = 6;
 
            if(achou != 1) {
                for(i = 0; i < cnt; i++) {
                    scanf("%s", buf);
                    if(i >= 0 && i < 5) {
                        fprintf(pont_arq, "%s;", buf);
                    } else if(i == 5) {
                        fprintf(pont_arq, "%s\n", buf);
                    }
                }
            } else {
                memset(file_buf[alterar], 0, 495);
 
                printf("\nDigite o nome do Computador : "); scanf("%s", buf);
                strcat(file_buf[alterar], strcat(buf, ";"));
                printf("\nDigite o IP : "); scanf("%s", buf);
                strcat(file_buf[alterar], strcat(buf, ";"));
                printf("\nDigite o SO : "); scanf("%s", buf);
                strcat(file_buf[alterar], strcat(buf, ";"));
                printf("\nDigite a Versao do SO : "); scanf("%s", buf);
                strcat(file_buf[alterar], strcat(buf, ";"));
                printf("\nDigite o nome do Responsavel : "); scanf("%s", buf);
                strcat(file_buf[alterar], strcat(buf, ";"));
                printf("\nDigite o Setor : "); scanf("%s", buf);
                strcat(file_buf[alterar], strcat(buf, "\n"));
                printf("\n");
 
                fclose(pont_arq);
 
                remove("bancoAplicativo.txt");
 
                pont_arq = fopen("bancoAplicativo.txt", "w");
 
                for(i = 0; i < counter; i++) {
                    fprintf(pont_arq, "%s", file_buf[i]);
                }
            }
 
            fclose(pont_arq);
            system("pause");
 
            break;
 
            case 4:  {
                system("cls");
                pont_arq = fopen("bancoAplicativo.txt", "r");
                printf("\nDigite o IP: ");
                char ip_buf[30], receber_ip[30];
                scanf("%s", ip_buf);
				system("cls");
                // aqui fica o arquivo inteiro
                char file_buf[1000][500];
 
                int alterar = 0, achou = 0, counter = 0;
 
                while(fgets(file_buf[counter], 500, pont_arq) != NULL) {
                    encontrar_ip(file_buf[counter], receber_ip);
                    if(strcmp(receber_ip, ip_buf) == 0) {
                        alterar = counter;
                        achou   = 1;
                    }
                    counter++;
                    memset(receber_ip, 0, 30);
                }
 
                if(achou == 0) {
                    printf("O ip nao foi encontrado\n");
                    fclose(pont_arq);
                    system("pause");
                    break;
                }
 
                fclose(pont_arq);
 
                remove("bancoAplicativo.txt");
 
                pont_arq = fopen("bancoAplicativo.txt", "w");
 
                for(i = 0; i < counter; i++) {
                    if(i != alterar) {
                        fprintf(pont_arq, "%s", file_buf[i]);
                    }
                }
                printf(" ________________________________________\n");
				printf("|                                        |\n");
				printf("|  COMPUTADOR FOI REMOVIDO COM SUCESSO!  |\n");
				printf("|________________________________________|");
 				printf("\n\n");
                fclose(pont_arq);
                system("pause");
 
                break;
            }
 
            case 5:
            system("cls");
            pont_arq = fopen("bancoAplicativo.txt", "r");	
            
            printf(" ________________________________________\n");
			printf("|                                        |\n");
			printf("|         LISTA DE COMPUTADORES          |\n");
			printf("|________________________________________|");
 
            while(fgets(line, 250, pont_arq) != NULL){		
                char *computador  = strtok(line, ";");
                char *ip          = strtok(NULL, ";");
                char *os          = strtok(NULL, ";");
                char *osversion   = strtok(NULL, ";");
                char *responsavel = strtok(NULL, ";");
                char *area        = strtok(NULL, ";");
				
				
				printf("\n");
    			printf(" ________________________________________\n");
    			printf("|                                        \n"); 
                printf("|      Nome do Computador : %s\n", computador);
                printf("|      IP :                 %s\n", ip);
                printf("|      SO :                 %s\n", os);
                printf("|      Versao do SO :       %s\n", osversion);
                printf("|      Responsavel :        %s\n",responsavel);
                printf("|      Setor :              %s", area);
                printf("|                                        \n");
                printf("|________________________________________");
                printf("\n");
                
            }
            printf("\n");
            system("pause");
            break;
            
            case 6:
    			system("cls");
    		    pont_arq = fopen("bancoAplicativo.txt", "r");
    		    
    		    pont_arq1 = fopen("gerarbackup.bkp", "w");
    		    
    			while(fgets(gerarbackup, 1000, pont_arq) != NULL)
    			fputs(gerarbackup, pont_arq1);
    			printf("\n");
    			printf(" ________________________________________");
    			printf("\n|                                        |");
    			printf("\t\n|      BACKUP REALIZADO COM SUCESSO!     |");
    			printf("\t\n|________________________________________|");
    			printf("\n\n");
    		    fclose(pont_arq);
    		    fclose(pont_arq1);
    		    system("pause");
        		system("cls");
    		    
    		break;
    		
    		case 7:
			break;	
    			
    		
    		default:{
    			system("cls");
    			printf("\n ________________________________________");
    			printf("\n|                                        |");
    			printf("\n|            VALOR INVÁLIDO!             |");
    			printf("\t\n|________________________________________|\n");
    			printf("\n");
    			system("pause");
        		system("cls");
				break;
			}
 
    	}
    } 
    return 0;
}
