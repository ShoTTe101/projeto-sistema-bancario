#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>

//opções das funções
int op;
int opConta;
int opLogin;

//informações do usuário
char nome[256];
char email[256];
char senha[256];

float saldo;
float saque;
float deposito;

//auxiliares em comum das funções de transferência
float transfere_valorBanco;
float transfere_valorPessoa;

//informações da outra conta da transferência
char outroNome[256];
char outroEmail[256];

//contador para o extrato
int cont;

//função principal
int main(){
	setlocale(LC_ALL, ""); //adicionar acentos	
	menu();
	return 0;
}

void menu(){
	printf("\t        WYTH\n");
	printf("\t====================\n");
    printf("\t  O banco que está\n\t  sempre com você!\n");
    printf("\t====================\n\n");
    printf("\t--------------------\n");
    printf("\t  Logar na conta [1]\n");
    printf("\tRegistre-se agora [2]\n");
    printf("\t--------------------\n");
    printf("\n\t  Opção desejada: ");
    scanf("%d", &op);
    switch(op){
    	case 1:
    		login();
    	break;
    	case 2:
    		criar_conta();
    	break;
		default:
			printf("\n\t   Opção Inválida!");
		break;	
	}
}

//funções auxiliares
void criar_conta(){
	system("cls");
	printf("   -------------------------------------------\n");
	printf("   Digite o nome de usuário que você deseja\n   Caso seja composto, utilize (_): ");
	scanf("%s", nome);
	printf("   Digite o seu e-mail: ");
	scanf("%s", email);
	printf("   Digite sua senha: ");
	scanf("%s", senha); 
	printf("   -------------------------------------------\n");
	printf("\t\t    Parabéns!\n");
	printf("\tSua conta foi criada com sucesso!\n");
	printf("   -------------------------------------------\n");
	printf("\t Digite [1] para voltar ao menu: ");
	scanf("%d", &op);
	if(op == 1){
		system("cls");	
		menu();
	}else{
		do{
			printf("Opção Inválida!\n");
			printf("Digite [1] para voltar ao menu: ");
			scanf("%d", &op);
		}while(op != 1);
		system("cls");
		menu();	
	}		
}

void login(){
	//primeiras auxiliares
	char verificaNome[256];
	char verificaEmail[256];
	char verificaSenha[256];
	
	//segundas auxiliares
	int comparaNome;
	int comparaEmail;
	int comparaSenha;
	
	system("cls");
	printf("   --------------------------\n");
	printf("   Digite seu usuário: ");
	scanf("%s", verificaNome);
	printf("   Digite seu e-mail: ");
	scanf("%s", verificaEmail);
	printf("   Digite sua senha: ");
	scanf("%s", verificaSenha);
	printf("   --------------------------\n");
	comparaNome = strcmp(verificaNome, nome);    
	comparaEmail = strcmp(verificaEmail, email); //strcmp - comparação de string (vetor de char)
	comparaSenha = strcmp(verificaSenha, senha); 
	if(comparaNome, comparaEmail, comparaSenha == 0){
		system("pause");
		conta();
	}else{
		printf("   Credenciais Incorretas!\n");
		printf("   --------------------------\n");
		system("pause");
		system("cls");	
		menu();
	}
}
	
void conta(){
	system("cls");
	printf("   ==========================================================\n");
	printf("\t\t\t    Olá, %s!", nome);
	printf("\n\t\t      Saldo atual: %.2fR$\n", saldo);
	printf("   ==========================================================\n");
	printf("   ----------------------------------------------------------\n");
	printf("\t\t      Opções disponíveis:\n");
	printf("   Depósito [1] | Saque [2] | Transferência [3] | Extrato [4]\n");
	printf("   ----------------------------------------------------------\n");
	printf("\t\t    Digite a opção desejada: ");
	scanf("%d", &opConta);
	switch(opConta){
		case 1:
			depositar();
		break;
		case 2:
			sacar();
		break;
		case 3:
			transferencia();
		break;
		case 4:
			extrato();
		break;
		default:
			printf("Opção Inválida!\n");
			system("pause");
			conta();
		break;		
	}
}

void depositar(){
	system("cls");
	printf("   ----------------------------------------------\n");
	printf("   Digite o valor que você deseja depositar: "); 
	scanf("%f", &deposito);
	if(deposito > 0){
		saldo = saldo + deposito;
		printf("   ----------------------------------------------\n");
		printf("\t  O seu novo saldo é de %.2fR$\n", saldo);
		printf("   ----------------------------------------------\n");
		printf("     Operação de depósito registrada no extrato\n");
		printf("   ----------------------------------------------\n");
		system("pause");
		conta();
	}else{
		printf("   ----------------------------------------------\n");
		printf("                  Opção Inválida!\n");
		printf("   ----------------------------------------------\n");
		system("pause");
		conta();	
	}
	
}

void sacar(){
	system("cls");
	printf("   ------------------------------------------------------------------------------------\n");
	printf("   Digite o valor que você deseja sacar (não utilize ponto a partir dos milhares): "); //programa não reconhece o ponto para separar as casas e acaba dando erro
	scanf("%f", &saque);
	if(deposito > 0){
		saldo = saldo - saque;
		printf("   ------------------------------------------------------------------------------------\n");
		printf("\t\t\t       O seu novo saldo é de %.2fR$\n", saldo);
		printf("   ------------------------------------------------------------------------------------\n");
		printf("\t\t\t  Operação de saque registrada no extrato\n");
		printf("   ------------------------------------------------------------------------------------\n");
		system("pause");
		conta();
	}else{
		printf("   ------------------------------------------------------------------------------------\n");
		printf("   Opção Inválida!\n");
		system("pause");
		conta();
	}
}

void transferencia(){
	system("cls");
	printf("   ==========================================================\n");
	printf("   Para transferir seu dinheiro para outro banco, digite [1]\n");
	printf("   Para transferir seu dinheiro para outra pessoa, digite [2]\n");
	printf("   ==========================================================\n");
	printf("\t\t    Digite a opção desejada: ");
	scanf ("%d", &op);
	switch(op){
		case 1:
			outro_banco();
		break;
		case 2:
			outra_pessoa();
		break;
		default:
			printf("Opção Inválida!\n");
			system("pause");
			conta();
		break;		
	}	
}

void outro_banco(){
	int op_outroBanco; //auxiliar da transferência para outro banco
	
	system("cls");
	printf("   ================================================\n");
	printf("\t\t  Opções disponíveis:\n");
	printf("     Inter [1] | Next [2] | Will [3] | Nubank [4]\n");
	printf("   ================================================\n");
	printf("\t       Digite a opção desejada: ");
	scanf ("%d", &op_outroBanco);
	switch(op_outroBanco){
		case 1:
			printf("   -----------------------------------------------\n");
			printf("   Digite o valor que você deseja transferir: ");
			scanf("%f", &transfere_valorBanco);
			printf("   A transferência de %.2fR$ para o banco\n   Inter foi bem sucedida!\n", transfere_valorBanco);
			printf("   -----------------------------------------------\n");
			printf("   Operação de transferência registrada no extrato\n");
			printf("   -----------------------------------------------\n");
			saldo = saldo - transfere_valorBanco;
			system("pause");
			conta();
		break;
		case 2:
			printf("   -----------------------------------------------\n");
			printf("   Digite o valor que você deseja transferir: ");
			scanf("%f", &transfere_valorBanco);
			printf("   A transferência de %.2fR$ para o banco\n   Next foi bem sucedida!\n", transfere_valorBanco);
			printf("   -----------------------------------------------\n");
			printf("   Operação de transferência registrada no extrato\n");
			printf("   -----------------------------------------------\n");
			saldo = saldo - transfere_valorBanco;
			system("pause");
			conta();
		break;
		case 3:
			printf("   -----------------------------------------------\n");
			printf("   Digite o valor que você deseja transferir: ");
			scanf("%f", &transfere_valorBanco);
			printf("   A transferência de %.2fR$ para o banco\n   Will foi bem sucedida!\n", transfere_valorBanco);
			printf("   -----------------------------------------------\n");
			printf("   Operação de transferência registrada no extrato\n");
			printf("   -----------------------------------------------\n");
			saldo = saldo - transfere_valorBanco;
			system("pause");
			conta();	
		break;
		case 4:
			printf("   -----------------------------------------------\n");
			printf("   Digite o valor que você deseja transferir: ");
			scanf("%f", &transfere_valorBanco);
			printf("   A transferência de %.2fR$ para o banco\n   Nubank foi bem sucedida!\n", transfere_valorBanco);
			printf("   -----------------------------------------------\n");
			printf("   Operação de transferência registrada no extrato\n");
			printf("   -----------------------------------------------\n");
			saldo = saldo - transfere_valorBanco;
			system("pause");
			conta();
			break;
		default:
			printf("Opção Inválida!\n");
			system("pause");
			conta();
		break;				
	}
}

void outra_pessoa(){	
	int op_outraPessoa;
	
	system("cls");
	printf("   ====================================================================\n");
	printf("   Digite o nome da pessoa para qual você deseja transferir: ");
	scanf("%s", outroNome);
	printf("   Digite o email da pessoa para qual você deseja transferir: ");
	scanf("%s", outroEmail);
	printf("   ====================================================================\n");
	printf("\t\t\t   Opções disponíveis:\n");
	printf("\t\tInter [1] | Next [2] | Will [3] | Nubank [4]\n");
	printf("   ====================================================================\n");
	printf("\t\t\t Digite a opção desejada: ");
	scanf ("%d", &op_outraPessoa);
	switch(op_outraPessoa){
		case 1:
			printf("   --------------------------------------------------------------------\n");
			printf("   Digite o valor que você deseja transferir: ");
			scanf("%f", &transfere_valorPessoa);
			printf("   A transferência de %.2fR$, para %s, do banco Wyth para o banco\n   Inter foi bem sucedida!\n", transfere_valorPessoa, outroNome);
			printf("   --------------------------------------------------------------------\n");
			printf("\t\tOperação de transferência registrada no extrato\n");
			printf("   --------------------------------------------------------------------\n");
			saldo = saldo - transfere_valorPessoa;
			system("pause");
			conta();
			break;
		case 2:
			printf("   --------------------------------------------------------------------\n");
			printf("   Digite o valor que você deseja transferir: ");
			scanf("%f", &transfere_valorPessoa);
			printf("   A transferência de %.2fR$, para %s, do banco Wyth para o banco\n   Next foi bem sucedida!\n", transfere_valorPessoa, outroNome);
			printf("   --------------------------------------------------------------------\n");
			printf("\t\tOperação de transferência registrada no extrato\n");
			printf("   --------------------------------------------------------------------\n");
			saldo = saldo - transfere_valorPessoa;
			system("pause");
			conta();
			break;
		case 3:
			printf("   --------------------------------------------------------------------\n");
			printf("   Digite o valor que você deseja transferir: ");
			scanf("%f", &transfere_valorPessoa);
			printf("   A transferência de %.2fR$, para %s, do banco Wyth para o banco\n   Will foi bem sucedida!\n", transfere_valorPessoa, outroNome);
			printf("   --------------------------------------------------------------------\n");
			printf("\t\tOperação de transferência registrada no extrato\n");
			printf("   --------------------------------------------------------------------\n");
			saldo = saldo - transfere_valorPessoa;
			system("pause");
			conta();
			break;
		case 4:
			printf("   --------------------------------------------------------------------\n");
			printf("   Digite o valor que você deseja transferir: ");
			scanf("%f", &transfere_valorPessoa);
			printf("   A transferência de %.2fR$, para %s, do banco Wyth para o banco\n   Nubank foi bem sucedida!\n", transfere_valorPessoa, outroNome);
			printf("   --------------------------------------------------------------------\n");
			printf("\t\tOperação de transferência registrada no extrato\n");
			printf("   --------------------------------------------------------------------\n");
			saldo = saldo - transfere_valorPessoa;
			system("pause");
			conta();
			break;
		default:
			printf("Opção Inválida!\n");
			system("pause");
			conta();
			break;				
	}
}

void extrato(){	
	system("cls");
	if(deposito > 0){
		printf("   ========================================\n");
		printf("\t\t   Crédito\n");
		printf("   ========================================\n");
		printf("   ----------------------------------------\n");
		printf("   Nome do usuário: %s\n", nome);
		printf("   E-mail do usuário: %s\n", email);
		printf("   Foram depositados %.2fR$ à sua conta!\n", deposito);
		printf("   ----------------------------------------\n");
	} 
	if(saque > 0){
		printf("   ========================================\n");
		printf("\t\t    Débito\n");
		printf("   ========================================\n");
		printf("   ----------------------------------------\n");
		printf("   Nome do usuário: %s\n", nome);
		printf("   E-mail do usuário: %s\n", email);
		printf("   Foram sacados %.2fR$ à sua conta!\n", saque);
		printf("   ----------------------------------------\n");
	} 
	if(transfere_valorBanco > 0){
		printf("   ========================================\n");
		printf("\t\tTransferência\n");
		printf("   ========================================\n");
		printf("   ----------------------------------------\n");
		printf("   Nome do usuário: %s\n", nome);
		printf("   E-mail do usuário: %s\n", email);
		printf("   Foram transferidos %.2fR$ da sua conta\n   para o banco de sua escolha!\n", transfere_valorBanco);
		printf("   ----------------------------------------\n");
	} 
	if(transfere_valorPessoa > 0){
		printf("   ========================================\n");
		printf("\t\tTransferência\n");
		printf("   ========================================\n");
		printf("   ----------------------------------------\n");
		printf("   Nome do usuário: %s\n", nome);
		printf("   E-mail do usuário: %s\n", email);
		printf("   Foram transferidos %.2fR$, para %s,\n   do banco de sua escolha!\n", transfere_valorPessoa, outroNome);
		printf("   ----------------------------------------\n");
	}
	printf("   Digite [1] para voltar à conta: ");
	scanf("%d", &op);
	if(op == 1){
		conta();
	}else{
		printf("Opção Inválida!");
		system("pause");
	}
}