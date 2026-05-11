#include<iostream>
using namespace std;

struct Rocha{
    string nome;
    string tipo;
};

struct node{
  Rocha data;
  struct node * left;
  struct node * right;
};

void insert(node * & current, Rocha data){
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

node * find_less_save_right(node * & current) {
  if(current->left != NULL) {
    return find_less_save_right(current->left);
  } else {
    node * copy = current;
    current = current->right;
    return copy;
  }
}

bool remove(node * & current, Rocha data){
  if(current == NULL){
    return false;
  } else if(data.nome == current->data.nome && data.tipo == current->data.tipo){
    node * temp = current;
    if (current->right == NULL) {
      current = current->left;
    } else if (current->left == NULL) {
      current = current->right;
    } else {
      temp = find_less_save_right(current->right);
      current->data = temp->data;
    }
    delete(temp);
    return true;
  } else {
    if(data.nome < current->data.nome){
      return remove(current->left, data);
    } else {
      return remove(current->right, data);
    }
  }
}

int main(){
    node * root = NULL;
    Rocha data;
    string nome, tipo, nome_procurado;
    int op;

    while(true){
        cin >> op;
        if(op == 1){
            getline(cin >> ws, nome);
            getline(cin >> ws, tipo);
            data = {nome, tipo};
            insert(root, data);
        }
        else if(op == 2){
            getline(cin >> ws, nome_procurado);
            node * result = search(root, nome_procurado);
            if(result == NULL){
                cout << "Rocha nao encontrada" << endl;   
            }
            else{
                cout << "Nome: " << result -> data.nome << endl;
                cout << "Tipo: " << result -> data.tipo << endl;
            }
        }
        else if(op == 3){
            getline(cin >> ws, nome);
            getline(cin >> ws, tipo);
            data = {nome, tipo};
            bool result = remove(root, data);
            if(result) cout << "Rocha removida com sucesso" << endl;
            else cout << "Rocha nao encontrada para remocao" << endl;
        }
        
        else if(op == 0) break;
        
        else{
            cout << "Operacao invalida" << endl;
        }
    }
    return 0;
}