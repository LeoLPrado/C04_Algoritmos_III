#include<iostream>
using namespace std;

struct node{
  int data;
  struct node * left;
  struct node * right;
};

void insert(node * & current, int data){
    if(current == NULL){
        current = new node;
        current -> data = data;
        current -> left = NULL;
        current -> right = NULL;
      } else if( data < current -> data ){
        insert(current -> left, data);
      }
      else{
        insert(current -> right, data);
      }
    }

node * search(node * current, int data){
      if(current == NULL){
        return NULL;
      } 
      else if(data == current->data){
         return current;
      } 
      else{
        if(data < current->data){
          return search(current->left, data);
        } else {
          return search(current->right, data);
        }
      }
    }

int main(){
    node * root = NULL;
    int N, num;
    string op;
    int i = 0;

    cin >> N;
    while(i < N){
        cin >> op >> num;
        if(op == "i"){
            insert(root, num);
        }
        if(op == "b"){
            node * result = search(root, num);
            if(result == NULL) cout << "Não" << endl;
            else cout << "Sim" << endl;
        }
        i++;
    }
    return 0;
}