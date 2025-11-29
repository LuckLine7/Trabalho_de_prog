#include "conta.h"
#include <time.h>
#include <stdio.h>
#include <string.h>

Conta titular;

int depositar (long long valor) {

    if (valor <= 0) {
        printf("\n Valor inválido. Digite um Valor maior que 0. \n");
        return ERRO_VALOR_INVALIDO;
    }

    titular.saldo_corrente+= valor;
    printf("\n Depósito realizado com sucesso. \n");

    time_t now = time(NULL);
    struct tm *cur_time = localtime(&now);
    char buffer[100];
    int quando = strftime(buffer, 100, "%Y-%m-%d %H:%M:%S", cur_time);

    titular.log[titular.nlog].tipo = DEP;
    titular.log[titular.nlog].valor = valor;
    titular.log[titular.nlog].saldo_corrente_apos = titular.saldo_corrente;
    titular.log[titular.nlog].saldo_poupanca_apos = titular.saldo_poupanca;
    strcpy(titular.log[titular.nlog].quando, buffer);
    titular.nlog++;
    
    return OK;
}

int sacar(long long valor) {

    if (valor <= 0) {
        printf("\n Valor inválido. Digite um Valor maior que 0. \n");
        return ERRO_VALOR_INVALIDO;
    }

    if (valor > titular.saldo_corrente) {
        printf("\n Saldo insuficiente. \n");
        return ERRO_SALDO_INSUFICIENTE;
    }
    
    titular.saldo_corrente-= valor;

    time_t now = time(NULL);
    struct tm *cur_time = localtime(&now);
    char buffer[100];
    int quando = strftime(buffer, 100, "%Y-%m-%d %H:%M:%S", cur_time);

    titular.log[titular.nlog].tipo = SAQ;
    titular.log[titular.nlog].valor = valor;
    titular.log[titular.nlog].saldo_corrente_apos = titular.saldo_corrente;
    titular.log[titular.nlog].saldo_poupanca_apos = titular.saldo_poupanca;
    strcpy(titular.log[titular.nlog].quando, buffer);
    titular.nlog++;
    printf("\n Saque realizado com sucesso. \n");

    return OK;
}

int aplicar_poupanca(long long valor) {

    if (valor <= 0) {
        printf("\n Valor inválido. Digite um Valor maior que 0. \n");
        return ERRO_VALOR_INVALIDO;
    }

    if (valor > titular.saldo_corrente) {
        printf("\n Saldo insuficiente. \n");
        return ERRO_SALDO_INSUFICIENTE;
    }

    titular.saldo_corrente-= valor;
    titular.saldo_poupanca+= valor;

    time_t now = time(NULL);
    struct tm *cur_time = localtime(&now);
    char buffer[100];
    int quando = strftime(buffer, 100, "%Y-%m-%d %H:%M:%S", cur_time);

    titular.log[titular.nlog].tipo = APLI;
    titular.log[titular.nlog].valor = valor;
    titular.log[titular.nlog].saldo_corrente_apos = titular.saldo_corrente;
    titular.log[titular.nlog].saldo_poupanca_apos = titular.saldo_poupanca;
    strcpy(titular.log[titular.nlog].quando, buffer);
    titular.nlog++;

    printf("\n Valor aplicado com sucesso. \n");

    return OK;    
}

int resgatar_poupanca(long long valor) {

    if (valor <= 0) {
        printf("\n Valor inválido. Digite um Valor maior que 0. \n");
        return ERRO_VALOR_INVALIDO;
    }

    if (valor > titular.saldo_poupanca) {
        printf(" \n Saldo insuficiente. \n");
        return ERRO_SALDO_INSUFICIENTE;
    }

    titular.saldo_poupanca-= valor;
    titular.saldo_corrente+= valor;

    time_t now = time(NULL);
    struct tm *cur_time = localtime(&now);
    char buffer[100];
    int quando = strftime(buffer, 100, "%Y-%m-%d %H:%M:%S", cur_time);

    titular.log[titular.nlog].tipo = RESG;
    titular.log[titular.nlog].valor = valor;
    titular.log[titular.nlog].saldo_corrente_apos = titular.saldo_corrente;
    titular.log[titular.nlog].saldo_poupanca_apos = titular.saldo_poupanca;
    strcpy(titular.log[titular.nlog].quando, buffer);
    titular.nlog++;
    printf("\n Resgate realizado. \n"); 

    return OK;
}

void conta_init(void) { 
    titular.saldo_corrente = 0;
    titular.saldo_poupanca = 0;
    titular.nlog = 0;
}

long long saldo_corrente(void) { 
    return titular.saldo_corrente;
}

long long saldo_poupanca(void) { 
    return titular.saldo_poupanca;
}

    
const char* nomeTransacao(TipoTransacao t) {
    switch (t) {
        case DEP:  return "DEPÓSITO";
        case SAQ:  return "SAQUE";
        case APLI: return "APLICAÇÃO";
        case RESG: return "RESGATE";
    }
}

void extrato_imprimir(void) {
     printf("\n------ EXTRATO ------\n");
    for (int i = 0; i < titular.nlog; ++i) {
        Transacao t = titular.log[i];
        printf("[%s] %s de %lld\n", t.quando, nomeTransacao(t.tipo), t.valor);

        long long reais_corr = t.saldo_corrente_apos / 100;
        long long centavos_corr = t.saldo_corrente_apos % 100;

        long long reais_poup = t.saldo_poupanca_apos / 100;
        long long centavos_poup = t.saldo_poupanca_apos % 100;

        printf("Saldo corrente: R$%lld,%02lld | Saldo poupança: R$%lld,%02lld\n\n", reais_corr, centavos_corr, reais_poup, centavos_poup);
    }
}