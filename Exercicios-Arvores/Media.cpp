#include <iostream>
#include <iomanip>
using namespace std;

struct node{
  int data;
  struct node * left;
  struct node * right;
};

void insert(node * & current, int data){
  if(current == NULL){
    current = new node;
    current->data = data;
    current->left = NULL;
    current->right = NULL;
  } else if(data < current->data){
    insert(current->left, data);
  } else {
    insert(current->right, data);
  }
}

int soma_nos(node * current){
    int soma = 0;

    if(current != NULL){
        if(current->left != NULL){
            soma += soma_nos(current->left);
        }

        soma += current->data;

        if(current->right != NULL){
            soma += soma_nos(current->right);
        }
    }
    return soma;
}

float media(node * root, int N){
    int soma = soma_nos(root);

    return (float)soma / N;
}

int main(){
    int num, N;
    node * root = NULL;

    N = 0;

    cin >> num;

    while(num != -1){
        insert(root, num);
        N++;
        cin >> num;
    }
    
    cout << fixed << setprecision(2);
    cout << "Media: " << media(root, N) << endl;

    return 0;
}