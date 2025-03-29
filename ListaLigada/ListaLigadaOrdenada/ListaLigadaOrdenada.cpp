#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

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
	novo->valor = valor;

	if (primeiro == NULL|| primeiro->valor > valor) 
	{
		novo->prox = primeiro;
		primeiro = novo;
	}
	else
	{
NO* atual = primeiro;
        NO* anterior = NULL;
        while (atual != NULL && atual->valor < valor) {
            anterior = atual;
            atual = atual->prox;
        }
        
        if (anterior != NULL && anterior->valor == valor) {
            free(novo);
            cout << "Elemento ja existe na lista!\n";
            return;
        }
        novo->prox = atual;
        anterior->prox = novo;
    }
}

void excluirElemento()
{
    int valor;
    cout << "Digite o elemento a excluir: ";
    cin >> valor;

    if (primeiro == NULL) {
        cout << "Lista vazia!\n";
        return;
    }

    if (primeiro->valor == valor) {
        NO* temp = primeiro;
        primeiro = primeiro->prox;
        free(temp);
        cout << "Elemento removido!\n";
        return;
    }

    NO* atual = primeiro;
    NO* anterior = NULL;
    while (atual != NULL && atual->valor < valor) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL || atual->valor != valor) {
        cout << "Elemento nao encontrado!\n";
        return;
    }

    anterior->prox = atual->prox;
    free(atual);
    cout << "Elemento removido!\n";
}

void buscarElemento()
{
 int valor;
    cout << "Digite o elemento a buscar: ";
    cin >> valor;
    
    NO* aux = primeiro;
    while (aux != NULL && aux->valor <= valor) {
        if (aux->valor == valor) {
            cout << "Elemento encontrado!\n";
            return;
        }
        aux = aux->prox;
    }
    cout << "Elemento nao encontrado!\n";
}

