#include<iostream>
#include<list>
#include<string>
using namespace std;

#define INT_MAX 99999

struct Aresta{
	int origem;
	int destino;
	int peso;
};

// criando struct que permite alocar varias informacoes das habilidades em uma unica estrutura
struct Habilidade{
    int codigo;
    string nome;
    double poder;
};

int prim(list<Aresta> grafo[], int vertices, int origem){
    bool visitado[vertices];
    int pai[vertices], distancia[vertices], atual;
    for(int i=0; i<vertices; i++){
        visitado[i] = false;
        pai[i] = -1;
        distancia[i] = INT_MAX;
    }
    atual = origem;
    distancia[atual] = 0;
    while(!visitado[atual]){
        visitado[atual] = true;
        list<Aresta>::iterator it;
        for(it = grafo[atual].begin(); it != grafo[atual].end(); it++){
            int d = it->destino, p = it->peso;
            if(!visitado[d] && p < distancia[d]){
                distancia[d] = p;
                pai[d] = atual;
            }
        }
        int menor_distancia = INT_MAX;
        for(int i=0; i<vertices; i++){
            if(!visitado[i] && distancia[i] < menor_distancia){
                menor_distancia = distancia[i];
                atual = i;
            }
        }
    }
    int peso_mst = 0;
    for(int i=0; i<vertices; i++){
        peso_mst += distancia[i];
    }
    return peso_mst;
}

int main(){
	int H;
	cin >> H;
	
	Habilidade habilidade[H];
	list<Aresta> grafo[H];
	
	int i = 0;
	while(i < H){
	    habilidade[i].codigo = i;
	    cin >> habilidade[i].nome >> habilidade[i].poder;
	    i++;
	}
	
	int U;
	cin >> U;
	
	i = 0;
	int origem, destino, peso;
	while(i < U){
	    cin >> origem >> destino >> peso;
	    grafo[origem].push_back({origem, destino, peso});
	    grafo[destino].push_back({destino, origem, peso});
	    i++;
	}
	
	int custo_minimo = prim(grafo, H, 0); // definindo 0 como o no inicial da mst
	cout << custo_minimo << endl;
	
	return 0;
}
