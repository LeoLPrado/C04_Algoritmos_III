#include <iostream>

using namespace std;

// Funções para Árvore Binária de Busca ---------------------------------------

typedef int KeyType;
typedef int ValueType;

struct DataType {
	KeyType key;
	ValueType value;
};

struct Node {
	DataType data;
	Node * right;
	Node * left;
} ;


void insert(Node *& curr, DataType data){	
	if(curr == NULL){
		curr = new Node;
		curr->data = data;
		curr->right = NULL;
		curr->left = NULL;
	} else {
		if(data.value >= curr->data.value){
			insert(curr->right, data);
		} else if(data.value < curr->data.value) {
			insert(curr->left, data);
		}		
	}	
}

Node * search(Node * curr, KeyType key){
	if(curr == NULL)
		return NULL;
	if(key == curr->data.key){
		return curr;
	} else {
		if(key > curr->data.key){
			return search(curr->right, key);
		} else if(key < curr->data.key){
			return search(curr->left, key);
		}
	}
	return NULL;
}

void show_ordered(Node * curr){
	if(curr->left != NULL)
		show_ordered(curr->left);
	cout << curr->data.key << ":" << curr->data.value << endl;
	if(curr->right != NULL)
		show_ordered(curr->right);
}

Node * disconnect_lesser(Node *& curr){
	Node * aux = curr;
	if(aux->left == NULL){ 	
		curr = curr->right; 
		return aux;			
	} else {				
		return disconnect_lesser(curr->left);
	}
}


int remove(Node *& curr, KeyType key){
	if(curr == NULL){
		return 0;
	}
	Node * aux;
	if(curr->data.key == key){
		aux = curr;		
		if(curr->left == NULL){
			curr = aux->right;
		} else if(curr->right == NULL){
			curr = aux->left;
		} else {
			aux = disconnect_lesser(curr->right);
			curr->data = aux->data;
		}		
		delete aux;
		return 1;		
	} else {
		if(key > curr->data.key){
			return remove(curr->right, key);
		} else if(key < curr->data.key) {
			return remove(curr->left, key);
		}
	}
	return 0;
}


void destruct(Node *& curr){
	if(curr->left != NULL)
		destruct(curr->left);
	if(curr->right != NULL)
	   	destruct(curr->right);
	delete curr;
	curr = NULL;
	return;
}

// ----------------------------------------------------------------------------

int main(){
   int T;
   Node * root = NULL;
   int i = 0;
   DataType data;
   double espessura, peso, altura, diametro;
   
   cin >> T;
   while(i < T){
       cin >> espessura >> peso >> altura >> diametro;
       int pf = ((espessura * peso * altura) + (diametro + altura));
       data = {i, pf};
       insert(root, data);
       i++;
   }
   
   show_ordered(root);
   return 0;
}