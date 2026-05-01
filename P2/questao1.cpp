#include<iostream>
#include<list>
#include<string>
using namespace std;

#define INT_MAX 99999

struct Aresta{
	int orig;
	int dest;
	int tamanho;
};

void dijkstra(list<Aresta> adj[], int vertices, int start){
    bool intree[vertices];
    int distance[vertices], parent[vertices];
	for(int i=0; i<vertices; i++){
		intree[i] = false;
		distance[i] = INT_MAX;
		parent[i] = -1;
	}
    distance[start] = 0;
    int v = start;
    while(intree[v] == false){
        intree[v] = true;
        list<Aresta>::iterator p;
        for(p = adj[v].begin();p != adj[v].end(); p++){
            int dest = p->dest;
            int weigth =p->tamanho;
			if(distance[dest] > distance[v] + weigth && intree[dest]==false){
                distance[dest] = distance[v] + weigth;
                parent[dest] = v;
			}
		}
        v = 0;
        int dist = INT_MAX;
        for(int i=0; i<vertices; i++){
            if(intree[i]==false && dist>distance[i]){
                dist = distance[i];
                v = i;
			}
		}
	}
	
	// loop que verifica se a distancia da origem ate o nó "i" é maior que quinze, se for ele sera printado
	int aux = 0; // variavel de contagem para controle se ha ou nao regioes alagadas
	for(int i = 0; i < vertices; i++){
	    if(distance[i] > 15){
	        cout << i << endl;
	        aux++;
	    }
	}
	if(aux == 0){
	    cout << "Nenhuma região alagada" << endl;
	}
}

int main(){
    int R, C, orig, dest, peso;
    cin >> R;
	cin >> C;
	list<Aresta> grafo[R];
	int i = 0;
	while(i < C){
	    cin >> orig >> dest >> peso;
	    grafo[orig].push_back({orig, dest, peso});
	    grafo[dest].push_back({dest, orig, peso});
	    i++;
	}
	
	int B;
	cin >> B;
	
	dijkstra(grafo, R, B);
	return 0;
}