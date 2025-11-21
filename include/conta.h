#ifndef CONTA_H
#define CONTA_H

#define MAX_TRANS 100

/*
    COISAS A FAZER:
    1- Todas as funções.
    2- Avaliar conta_init (Como vai funcionar).
    3- Verificar biblioteca de time.
    4- Como funcionará o histórico de transações.
    5- TALVEZ--> Colocar um "if" nas funções que verifica se é a centésima transação.
    6- Corrigir inputs de entrada? Quais?
    7- Onde entra ponteiros nisso?


*/

typedef enum { DEP, SAQ, APLI, RESG, PIX, REND, PIXR } TipoTransacao;

typedef struct {
    TipoTransacao tipo;
    long long valor;
	long long saldo_corrente_apos;
	long long saldo_poupanca_apos;
    char destino[128];
    char quando[20];
} Transacao;

typedef struct {
    long long saldo_corrente;
    long long saldo_poupanca;
    Transacao log[MAX_TRANS];
    int nlog;
} Conta;

enum {
    OK = 0,
    ERRO_VALOR_INVALIDO = 1,
    ERRO_SALDO_INSUFICIENTE = 2,
    ERRO_CAPACIDADE_LOG = 3
};

void conta_init(void); //inicializar a conta logo no início da aplicação. 

int  depositar(long long valor); // depositar na conta
int  sacar(long long valor); // sacar da conta
int  aplicar_poupanca(long long valor); //passar dinheiro da conta para a poupança
int  resgatar_poupanca(long long valor); //passar dinheiro da poupança para a conta
int  fazer_pix(const char destino[], long long valor); //tirar dinheiro da conta e transferir para a chave pix
void render_poupanca(double rendimento_mensal); // colocar na conta o rendimento mensal da poupança
int  receber_pix(long long valor); // creditar um pix recebido na conta

long long saldo_corrente(void); // retorna o valor do saldo
long long saldo_poupanca(void); // retorna o valor da poupança

void extrato_imprimir(void); //imprime as transações realizadas e o saldo final.

//--------------------------------------------FUNÇÕES-----------------------------------------------

depositar (long long valor) {

    if (valor <= 0) {
        printf("\n Valor inválido. Digite um Valor maior que 0. \n");
        return ERRO_VALOR_INVALIDO;
    }

    saldo_corrente+= valor;
    printf("\n Depósito realizado com sucesso. \n");

    return OK;
}

sacar(long long valor) {

    if (valor <= 0) {
        printf("\n Valor inválido. Digite um Valor maior que 0. \n");
        return ERRO_VALOR_INVALIDO;
    }

    if (valor > saldo_corrente) {
        printf("\n Saldo insuficiente. \n");
        return ERRO_SALDO_INSUFICIENTE;
    }

    saldo_corrente-= valor;
    printf("\n Saque realizado com sucesso. \n")

    return OK;
}

int  aplicar_poupanca(long long valor) {

    if (valor <= 0) {
        printf("\n Valor inválido. Digite um Valor maior que 0. \n");
        return ERRO_VALOR_INVALIDO;
    }

    saldo_poupanca+= valor;
    printf("\n Valor aplicado com sucesso. \n")

    return OK;    
}

resgatar_poupanca(long long valor) {

    if (valor <= 0) {
        printf("\n Valor inválido. Digite um Valor maior que 0. \n");
        return ERRO_VALOR_INVALIDO;
    }

    if (valor > saldo_poupanca) {
        printf(" \n Saldo insuficiente. \n");
        return ERRO_SALDO_INSUFICIENTE;
    }

    saldo_poupanca-= valor;
    printf("\n Resgate realizado. \n") 

    return OK;
}

int  receber_pix(long long valor) {

    saldo_corrente+= valor;

    return OK;
}

#endif // CONTA_H