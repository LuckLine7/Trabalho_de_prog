#include <stdio.h>
//DUVIDAS---CASO 5 //char destino
//CASO 6-Reescrever o %lld como um valor em Reais (Está em centavos).

int main (void) {

      int opcao = 0;

    printf("\nBem-Vindo ao VoidBank!\n");

while(opcao != 8){

    printf("\n---MENU VoidBank---\n
            Operações disponíveis:\n
            (1) DEPÓSITO-CONTA CORRENTE\n
            (2) SAQUE-SEM CHEQUE ESPECIAL\n
            (3) APLICAÇÃO NA POUPANÇA\n
            (4) RESGATE DA POUPANÇA\n
            (5) REALIZAR PIX\n     
            (6) CONSULTAR SALDOS-CONTA POUPANÇA E CORRENTE\n
            (7) CONSULTAR EXTRATO\n
            (8) SAIR\n");

    printf("Insira a opção desejada: ");
    scanf("%d", &opcao);

    switch(opcao){

            case 1:
            printf("\nQual valor deseja Depositar?\nR$ ");
            scanf("%lld" ,&valor);
            depositar(valor);
            break;

            case 2:
            printf("\nQual valor deseja Sacar?\nR$ ");
            scanf("%lld" ,&valor);
            sacar(valor);
            break; 

            case 3:
            printf("\nQual valor deseja Aplicar Na Poupança?\nR$ ");
            scanf("%lld" ,&valor);
            aplicar_poupanca(valor);
            break; 

            case 4:
            printf("\nQual valor deseja Resgatar Da Poupança?\nR$ ");
            scanf("%lld" ,&valor);
            resgatar_poupanca(valor);
            break; 

            case 5:
            printf("\nQual valor ?\nR$ ");
            scanf("%lld" ,&valor);
            fazer_pix(valor);
            break;//duvida(char destino?)

            case 6:
            printf("\nSeu Saldo na Conta Poupança é de R$(%lld\100),(%lld % 100) e na Conta Corrente 
            é de R$%(%lld\100),(%lld % 100)\n" ,saldo_poupanca(),saldo_corrente());
            break;//duvida

            case 7:
            extrato_imprimir();
            break;

            case 8:
            printf("---SAINDO---");
            break;

            default:
            printf("\nOpção inválida.\nInsira a opção desejada novamente!\n");

      }//encerra o switch
}//encerra o while
return 0;
} 


/*void conta_init(void); \\inicializar a conta logo no início da aplicação. 

int  depositar(long long valor); \\ depositar na conta
int  sacar(long long valor); \\ sacar da conta
int  aplicar_poupanca(long long valor); \\ passar dinheiro da conta para a poupança
int  resgatar_poupanca(long long valor); \\passar dinheiro da poupança para a conta
int  fazer_pix(const char destino[], long long valor); \\tirar dinheiro da conta e transferir para a chave pix
void render_poupanca(double rendimento_mensal); \\ colocar na conta o rendimento mensal da poupança
int  receber_pix(long long valor); \\ creditar um pix recebido na conta

long long saldo_corrente(void); \\ retorna o valor do saldo
long long saldo_poupanca(void); \\ retorna o valor da poupança

void extrato_imprimir(void); \\imprime as transações realizadas e o saldo final.

      Operações disponíveis
1. Depositar (conta corrente)
2. Sacar (sem cheque especial)
3. Aplicar na poupança
4. Resgatar da poupança
5. Fazer PIX (registrar conta/chave de destino)
6. Consultar saldos
7. Extrato (listar transações com data/hora)
8. Sair
9. Rendimento mensal da poupança
10.Receber pix*/