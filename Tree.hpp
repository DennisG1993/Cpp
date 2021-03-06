#ifndef TREE_HPP
#define TREE_HPP
//#include "Node.hpp"
namespace ariel {

  struct Node{
  	int data;
    Node* parent;
  	Node *Lchild;
  	Node *Rchild;

    Node(int value){
      data = value;
      parent = nullptr;
      Lchild = nullptr;
      Rchild = nullptr;
    }

    ~Node(){
        delete this->Lchild;
        delete this->Rchild;
    }

  };

class Tree{
private:
  Node* treeRoot;
  int length;

public:
  Node* recursiveInsert(Node*,int, int&);
  bool  recursivecontains(Node*,int);
  Node* recursiveRemove(Node *, int, int&);
  int recursiverelative(Node *, int, int);
  int FsmallestData(Node*);
  void recursiverprint(Node*,int);

  Tree(); 
  ~Tree();
  void insert(int);
  void remove(int);
  int size();
  bool contains(int);
  int root();
  int parent(int);
  int left(int);
  int right(int);
  void print();
};
};
#endif
