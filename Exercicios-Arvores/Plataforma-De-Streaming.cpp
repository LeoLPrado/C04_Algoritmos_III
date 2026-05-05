#include<iostream>
using namespace std;

struct filme{
    string nome;
    string genero;
    int duracao;
    int classificacao;
    int ano;
};

struct node{
  filme data;
  struct node * left;
  struct node * right;
};

void insert(node * & current, filme data){
    if(current == NULL){
        current = new node;
        current -> data = data;
        current -> left = NULL;
        current -> right = NULL;
    } 
    else if(data.nome < current -> data.nome){
        insert(current -> left, data);
    }
    else{
        insert(current -> right, data);
    }
}

node * search(node * current, string data){
    if(current == NULL){
        return NULL;
    } 
    else if(data == current -> data.nome){
        return current;
    } 
    else{
        if(data < current -> data.nome){
          return search(current -> left, data);
        } 
        else{
            return search(current -> right, data);
        }
    }
}

int main(){
    node * root = NULL;
    int ano, classificacao, duracao;
    filme data;
    string nome, genero, nome_procurado;
    int op;

    while(true){
        cin >> op;
        if(op == 1){
            getline(cin >> ws, nome);
            getline(cin >> ws, genero);
            cin >> duracao;
            cin >> classificacao;
            cin >> ano;
            data = {nome, genero, duracao, classificacao, ano};
            insert(root, data);
        }
        else if(op == 2){
            getline(cin >> ws, nome_procurado);
            node * result = search(root, nome_procurado);
            if(result == NULL){
                cout << "Filme nao encontrado" << endl;   
            }
            else{
                cout << "Nome: " << result -> data.nome << endl;
                cout << "Genero: " << result -> data.genero << endl;
                cout << "Duracao: " << result -> data.duracao << " mins" << endl;
                cout << "Classificacao: " << result -> data.classificacao <<endl;
                cout << "Ano: " << result -> data.ano <<endl;
            }
        }
        else if(op == 0){
            break;
        }
        else{
            cout << "Operacao invalida" << endl;
        }
    }
    return 0;
}