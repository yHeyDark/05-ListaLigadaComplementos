#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;
NO* ultimo = NULL;
// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------

int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista j� possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	ultimo = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	NO* repetido = posicaoElemento(novo->valor);
	if (repetido != NULL) {
		cout << "Elemento ja existe na lista \n";
		free(novo);
		return;
	}
	if (primeiro == NULL)
	{
		primeiro = novo;
		ultimo = novo;
	}
	else
	{
		// procura o final da lista
		ultimo->prox = novo;
		ultimo = novo;
	}
}

void excluirElemento()
{
	NO* atual = primeiro;
	NO* anterior = NULL;
	cout << "Digite o elemento a ser excluido: ";
	int numero;
	cin >> numero;
	NO* posicao = posicaoElemento(numero);
	if (posicao == NULL) {
		cout << "Elemento nao existe na lista" << endl;
		return;
	}
	else {
		// funcao para excluir o elemento
		if (posicao == primeiro) {
			primeiro = primeiro->prox;
			free(posicao);
			cout << "Elemento excluido" << endl;
			return;
		}
		else {
			while (numero != NULL) {
				if (numero == atual->valor) {
					if (numero == ultimo->valor) {
						anterior->prox = NULL;
						ultimo = anterior;
					}
					else
					{
						anterior->prox = atual->prox;
					}
					cout << "elemento excluido" << endl;
					free(atual);
					break;
				}
				anterior = atual;
				atual = atual->prox;
			}
				
		}
	}
}

void buscarElemento()
{

}

NO* posicaoElemento(int numero)
{
	NO* aux = primeiro;
	while (aux != NULL) {
		if (aux->valor == numero)
		{
			break;
		}
		aux = aux->prox;
	}
	return aux;
}

