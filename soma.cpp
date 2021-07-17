#include <iostream>
using namespace std;

class no{
    private:
        int dado;
        no *proximo;
    public:
    //construtor
        no (int dado){
            this -> dado = dado;
            proximo = NULL;
        }
    // recebendo
        int getDado(){
            return dado;
        }

        no* getProximo(){
            return proximo;
        }
        
        void setProximo(no* novo)
        {
            proximo = novo;
        }

        no*  operator+ (no* noaux)
        {
            if (this -> proximo != NULL){
                cout << "operacao invalida" << endl;
                return NULL;
            }
            
            return this -> proximo = noaux;
        }

};


int main()
{

    no *a = new no (3);
    no *b = new no (4);

    a ->operator+(b);
    //a + b;
    //*a + b;
    cout << "a soma deu certo se aparecer : 4 vejamos : "<< a->getProximo()->getDado() << endl;

    return 0;
}
