#include <iostream>

using namespace std;

// classe No
class No
{
private:
	int dado;
	No* prox;
public:
	No(int dado) // construtor
	{
		this->dado = dado;
		this->prox = NULL;
	}

	int getDado() // obtém o valor
	{
		return dado;
	}

	No*getProx() // obtém o próximo No
	{
		return prox;
	}

	void setProx(No* p) // seta o próximo No
	{
		prox = p;
	}
};



// classe Lista
class Lista
{
private:
	No* inicio; // primeiro elemento
	No* final; // último elemento
	int tam;
public:
	Lista()
	{
		// se não passar elemento, então inicio e final são NULL
		inicio = NULL;
		final = NULL;
		tam = 0;
	}
	
	Lista(int dado)
	{
		// se passar elemento, então cria novo No
		inicio = new No(dado);
		final = inicio;
		tam = 1;
	}

	void exibir() // mostra todos os elementos da lista
	{
		cout << "\nImprimindo todos os elementos...\n";
		No* c = inicio;

		if(vazia())
			cout << "A lista NAO possui elementos!!\n";
		else
		{
			while(c) // percorre a lista
			{
				cout <<"    " <<c->getDado();
				c = c->getProx();
			}
			cout << endl;
		}
	}

	bool vazia() // verifica se a lista está vazia
	{
		return (inicio == NULL);
	}

	// insere no início (semelhante a push_front da list)
	void inserir_inicio(int dado)
	{
		No* novo_no = new No(dado);

		if(vazia())
		{
			inicio = novo_no;
			final = novo_no;
		}
		else
		{
			novo_no->setProx(inicio);
			inicio = novo_no;
		}
	}

	// insere no final (semelhante a push_back da list)
	void inserir_final(int dado)
	{
		No* novo_no = new No(dado);

		if(vazia())
		{
			inicio = novo_no;
			final = novo_no;
		}
		else
		{
			final->setProx(novo_no);
			final = novo_no;
		}
	}

	// retorna o tamanho da lista
	int tamanho()
	{
		if(vazia()) // se for vazia, entã retorna 0
			return 0;

		No* c = inicio;
		int tam = 0;
		
		// percorre a lista
		do
		{
			c = c->getProx();
			tam++;
		}
		while(c);
		
		return tam;
	}

	// verifica se um elemento existe na lista
	bool existe(int v)
	{
		No* c = inicio;
		
		while(c)
		{
			if(c->getDado() == v)
				return true;
			c = c->getProx();
		}
		return false;
	}

	// remove da lista, remoção do final (semelhante a pop_back da list)
	void removerfinal()
	{
		if(!vazia())
		{
			// se houver só 1 elemento
			if(inicio->getProx() == NULL)
				inicio = NULL;
			else if(inicio->getProx()->getProx() == NULL) // 2 elementos
				inicio->setProx(NULL);
			else // > 2 elementos
			{
				No* ant_ant = inicio;
				No* ant = inicio->getProx();
				No* corrente = inicio->getProx()->getProx();

				while(corrente)
				{
					No* aux = ant;
					ant = corrente;
					ant_ant = aux;
					corrente = corrente->getProx();
				}
				delete ant_ant->getProx(); // libera memória
				ant_ant->setProx(NULL); // seta o prox como NULL
				final = ant_ant; // atualiza a final
			}
		}
	}

	void removerinicio (){

		if(inicio->getProx() == NULL)
				inicio = NULL;
		else if (inicio -> getProx() -> getProx() == NULL)
			inicio->setProx(NULL);
		else
		{
			No* ant = inicio;
			No* corrente = inicio->getProx();
			inicio = corrente;
			delete ant;
			
		}

		




    }
};


class pilha
{

	private:
	Lista* lista; 


	public:
	pilha (){ //construtor
		lista = new Lista();

	}
	pilha (int dado){

		lista = new Lista(dado);

	}

	void inserir_inicio(int dado){

		lista -> inserir_inicio(dado);

	}

	void removerinicio(){

		lista -> removerinicio();
	}
	
	void exibir(){
		lista ->exibir();
	}

	bool existe (int v){
		lista -> existe(v);
	}

	int tamanho(){
		lista -> tamanho();
	}


};

class fila
{

	private:
	Lista* lista; 


	public:
	fila (){ //construtor
		lista = new Lista();

	}
	fila (int dado){

		lista = new Lista(dado);

	}

	void inserir_final(int dado){

		lista -> inserir_final(dado);

	}

	void removerinicio(){

		lista -> removerinicio();
	}
	
	void exibir(){
		lista ->exibir();
	}

	bool existe (int v){
		lista -> existe(v);
	}

	int tamanho(){
		lista -> tamanho();
	}


};

int main(int argc, char *argv[])
{
	
	fila* Fila = new fila(10);
	
	
	Fila -> inserir_final(21);
	Fila -> inserir_final(11);
	Fila -> inserir_final(20);
	Fila -> inserir_final(64);
	Fila -> inserir_final(17);
	Fila -> inserir_final(13);
	Fila -> inserir_final(51);
	Fila -> inserir_final(25);
	Fila -> inserir_final(78);

	Fila ->exibir();

	Fila->removerinicio();
	


	Fila -> exibir();
	


	
	return 0;
}