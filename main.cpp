#include "BinomialHeap.h"

int main () {
	BinomialHeap<int> z;
/*	
	BNode<int> *a = new BNode<int>(10);
	BNode<int> *b = new BNode<int>(2);
	BNode<int> *c = new BNode<int>(3);
	BNode<int> *d = new BNode<int>(1);
  	BNode<int> *e = new BNode<int>(5);
  	BNode<int> *f = new BNode<int>(4);
  	BNode<int> *g = new BNode<int>(6);
*/  
  	z.Insert(10);
  	z.Insert(2);
  	z.Insert(3);
  	z.Insert(1);
  	z.Insert(5);
  	z.Insert(4);
  	z.Insert(6);
  	z.Print();
}
