#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


struct Ponto {
	int x, y;
};

float distancia_quadrada(Ponto p1, Ponto p2){
	return (p1.y-p2.y)*(p1.y-p2.y) + (p1.x-p2.x)*(p1.x-p2.x);
}

int main(){
	
	Ponto pontos[100];

	int n;
	cin >> n;

	for (int i=0; i<n; i++) {
		cin >> pontos[i].x >> pontos[i].y;
	}
	
    Ponto usuario;
    cin >> usuario.x >> usuario.y;

    Ponto melhor = pontos[0];
    int menorDist = distancia_quadrada(pontos[0], usuario);

    for (int i = 1; i < n; i++) {

        int dist = distancia_quadrada(pontos[i], usuario);

        if (dist < menorDist) {
            menorDist = dist;
            melhor = pontos[i];
        }
        else if (dist == menorDist) {

            if (pontos[i].x < melhor.x || (pontos[i].x == melhor.x && pontos[i].y < melhor.y)) {
                melhor = pontos[i];
            }
        }
    }

    cout << melhor.x << " " << melhor.y << endl;

    return 0;
}