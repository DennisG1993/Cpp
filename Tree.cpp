#include "Tree.hpp"
#include <iostream>

namespace ariel {
Tree::Tree(){
  this->length = 0;
  this->treeRoot = nullptr;
}

Tree::~Tree(){
  delete this->treeRoot;
}

void Tree::insert(int data){
  int success = 0;
  this->treeRoot = recursiveInsert(this->treeRoot, data, success);
  if(success){
    this->length += 1;
  }
}

Node* Tree::recursiveInsert(Node* current, int data,int &success){
  if(!current){ //if current node = nullptr(0)
    success = 1;
    return new Node(data);
  }
//  try{ // deleting the try/catch seince the test catches the exceptions
    if(data < current->data){
      current->Lchild = recursiveInsert(current->Lchild, data, success);
      current->Lchild->parent = current;
    }
    else if(data > current->data){
      current->Rchild = recursiveInsert(current->Rchild, data, success);
      current->Rchild->parent = current;
    }
    else{// the data we try to insert already exists.
      throw "The inserted number already exists.";

    }
//  }

//  catch(const char* exception){  // deleting the try/catch seince the test catches the exception
  //  std::cout<<"Error: " << exception<<std::endl;
    //throw "Error"; //throwing another error just for the sake of your test since i cought my own.....
 //}
  return current;
}

int Tree::size(){
  return this->length;
}

int Tree::root(){
  if(this->length){
    return this ->treeRoot->data;
  }
  else{
    std::cout<<"This Tree is empty, 0 will be returned by default."<<std::endl;
    return 0;
  }
}

bool Tree::contains(int data){
  return recursivecontains(this->treeRoot, data);
}

bool Tree::recursivecontains(Node * current, int data){
  if(!current){
    return false;
  }
  else if(data == current->data){
    return true;
  }
  return data < current->data ?
   recursivecontains(current->Lchild, data) : recursivecontains(current->Rchild, data);
}

int Tree::FsmallestData(Node* current){
  if(current->Lchild == nullptr){
    return current->data;
  }
  return FsmallestData(current->Lchild);
}

Node* Tree::recursiveRemove(Node* current, int data, int &success){
  //try{ // deleting the try/catch seince the test catches the exception
    if(!current){
      success = 0;
      throw "The number you're trying to remove doesn't exist";
    }
    else if(data == current->data){
    if(current->Lchild == nullptr && current->Rchild == nullptr){
      return nullptr;
      }
      else if(current->Rchild == nullptr){
        return current->Lchild;
        }
    else if(current->Lchild == nullptr){
      return current->Rchild;
      }
    int smallestValue = FsmallestData(current->Rchild);
    current->data = smallestValue;
    current->Rchild = recursiveRemove(current->Rchild, smallestValue, success);
    return current;
    }
    else if(data < current->data){
      current->Lchild = recursiveRemove(current->Lchild, data, success);
      return current;
    }
    current->Rchild = recursiveRemove(current->Rchild, data, success);
    return current;
  //}
  //catch(const char* exception){  // deleting the try/catch seince the test catches the exception
  //  std::cout<<"Error: " << exception<<std::endl;
  //  throw "Error"; //throwing another error just for the sake of your test since i cought my own.....
    return nullptr;
// }
}

void Tree::remove(int data){
  int success = 1;
  this->treeRoot = recursiveRemove(this->treeRoot, data, success);
  if(success){
    this->length -=1;
  }
}

int Tree::recursiverelative(Node* current, int data, int relative){
  //relative 1 is a parent, 2 Lchild and 3 Rchild.
  if(!current){
    throw "There is no node with the number your'e searching for hence no relative hence returining default -9990/n";
    return -999;
  }
  else if(data == current->data){
    if(relative == 1 && (current->parent )){return current->parent->data;}
    else if(relative == 2 && (current->Lchild)){return current->Lchild->data;}
    else if(relative == 3 && (current->Rchild)){return current->Rchild->data;}
    else throw "The number is found but the node doesnt have the relative your'e searching for";
  }
  return data < current->data ?
   recursiverelative(current->Lchild, data, relative) : recursiverelative(current->Rchild, data, relative);
}

int Tree::parent(int data){
  return recursiverelative(this->treeRoot, data, 1);
}

int Tree::left(int data){
  return recursiverelative(this->treeRoot, data, 2);
}

int Tree::right(int data){
  return recursiverelative(this->treeRoot, data, 3);
}
void Tree::print(){
  recursiverprint (treeRoot,32);
}
void Tree::recursiverprint (Node* current , int spaces ){
  if(current == nullptr){return;}

    for(int i = 0; i < spaces; i++){
      std::cout << ' ';}
    std::cout << "   " << current->data << std::endl;
    recursiverprint(current->Rchild, spaces+ 4 );
    recursiverprint(current->Lchild, spaces - 4);

}
};
