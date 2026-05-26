#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


struct Ponto {
	int x, y;
};

float area_triangulo(Ponto a, Ponto b, Ponto c){
	return (
		a.x * b.y - a.y * b.x + 
		a.y * c.x - a.x * c.y +
		b.x * c.y - b.y * c.x
	) / 2.0;
	
}

int main(){
	
	Ponto a;
	Ponto b; 
	Ponto c;
	
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
	
    cout << area_triangulo(a, b, c) << endl;

}