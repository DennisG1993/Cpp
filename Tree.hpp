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
  Node* recursiveInsert(Node*,int, int&); //done
  bool  recursivecontains(Node*,int); // done
  Node* recursiveRemove(Node *, int, int&);
  int recursiverelative(Node *, int, int);
  int FsmallestData(Node*);// done
  void recursiverprint(Node*,int);

  Tree(); // done
  ~Tree();
  void insert(int); // done
  void remove(int); //done
  int size(); // done
  bool contains(int); // done
  int root(); //done
  int parent(int); //done
  int left(int); //done
  int right(int); //done
  void print();
};
};
#endif
