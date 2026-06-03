#include <iostream>
#include <cmath>
using namespace std;

struct Ponto {
	int x, y;
};

float distancia(Ponto p1, Ponto p2){
	return sqrt((p1.y-p2.y)*(p1.y-p2.y) + (p1.x-p2.x)*(p1.x-p2.x));
}

int main(){
	
	int P;
	Ponto A, B, C, D;
	
	cin >> P >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
	
	int EM = distancia(A, B);
	int Diametro = distancia(C, D);
	int H = distancia(A, C);
	
	int PF = EM * P * H + Diametro + H;
	
	if(D.y > B.y) cout << "Virada" << endl;
	else cout << "Correta" << endl;
	
	cout << PF << endl;
	
	return 0;
}