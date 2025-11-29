#include <stdio.h>
#include "conta.h"


int main (void) {       

      int opcao = 0;
      conta_init();
      
      Transacao historico_titular;
      historico_titular.valor = 0;

    printf("\n Bem-Vindo ao VoidBank! \n");

while(opcao != 7){

    printf("\n ---MENU VoidBank--- \n"
            "Operações disponíveis: \n"
            "(1) DEPÓSITO-CONTA CORRENTE \n"
            "(2) SAQUE-SEM CHEQUE ESPECIAL \n"
            "(3) APLICAÇÃO NA POUPANÇA \n"
            "(4) RESGATE DA POUPANÇA \n"
            "(5) CONSULTAR SALDOS-CONTA POUPANÇA E CORRENTE \n"
            "(6) CONSULTAR EXTRATO \n"
            "(7) SAIR \n");

    printf("Insira a opção desejada: ");
    scanf("%d", &opcao);

    switch(opcao){

            case 1:
            printf("\n Qual valor deseja Depositar? \n R$ ");
            scanf("%lld" ,&historico_titular.valor);
            depositar(historico_titular.valor);

            if (titular.nlog == 100) {
                  printf("\n [ALERTA] Capacidade de registros atingida (100 transações). \n" 
                    "\n O serviço do VoidBank sairá do ar agora. \n");

                    return ERRO_CAPACIDADE_LOG ;

            }
            break;

            case 2:
            printf("\n Qual valor deseja Sacar? \n R$ ");
            scanf("%lld" ,&historico_titular.valor);
            sacar(historico_titular.valor);

             if (titular.nlog == 100) {
                  printf("\n [ALERTA] Capacidade de registros atingida (100 transações). \n" 
                    "\n O serviço do VoidBank sairá do ar agora. \n");

                    return ERRO_CAPACIDADE_LOG ;

            }
            break; 

            case 3:
            printf("\n Qual valor deseja Aplicar Na Poupança? \n R$ ");
            scanf("%lld" ,&historico_titular.valor);
            aplicar_poupanca(historico_titular.valor);

             if (titular.nlog == 100) {
                  printf("\n [ALERTA] Capacidade de registros atingida (100 transações). \n" 
                    "\n O serviço do VoidBank sairá do ar agora. \n");

                    return ERRO_CAPACIDADE_LOG;

            }
            break; 

            case 4:
            printf("\n Qual valor deseja Resgatar Da Poupança? \nR$ ");
            scanf("%lld" ,&historico_titular.valor);
            resgatar_poupanca(historico_titular.valor);

             if (titular.nlog == 100) {
                  printf("\n [ALERTA] Capacidade de registros atingida (100 transações). \n" 
                    "\n O serviço do VoidBank sairá do ar agora. \n");

                    return ERRO_CAPACIDADE_LOG ;

            }
            break; 

            case 5:

                  long long corr = saldo_corrente();
                  long long poup = saldo_poupanca();

                  printf("\n Seu saldo corrente é de R$ %lld,%02lld\n",
                  corr / 100, corr % 100);

                  printf(" Seu saldo poupança é de R$ %lld,%02lld\n",
                  poup / 100, poup % 100);
            break; 

            case 6:
            extrato_imprimir();
            break;

            case 7:
            printf("\n ---SAINDO--- \n");
            break;

            default:
            printf("\n Opção inválida. \n Insira a opção desejada novamente! \n");
            break;

      } 
}
return 0;
} 