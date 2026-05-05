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
    int N, num, X;
    int i = 0;
    cin >> N;
      
    while(i < N){
        cin >> num;
        insert(root, num);
        i++;
    }
    
    cin >> X;    
    
    node * result = search(root, X);
    if(result == NULL) cout << "Nao encontrado" << endl;
    else cout << "Encontrado" << endl;
       
    return 0;
}