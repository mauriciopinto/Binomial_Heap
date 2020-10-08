#include "BinomialHeap.h"

int main () {
	BinomialHeap<int> z;
	
	BNode<int> *a = new BNode<int>(10);
	BNode<int> *b = new BNode<int>(2);
	BNode<int> *c = new BNode<int>(3);
	BNode<int> *d = new BNode<int>(1);
  	BNode<int> *e = new BNode<int>(5);
  	BNode<int> *f = new BNode<int>(4);
  	BNode<int> *g = new BNode<int>(6);

  	z.Insert(a);
  	z.Insert(b);
  	z.Insert(c);
  	z.Insert(d);
  	z.Insert(e);
  	z.Insert(f);
  	z.Insert(g);
	//z.Delete(d);
  	z.Print();
	cout << "___________________________" << endl;
	auto n = z.Find (2);
	n->Print ();
	//z.GenerateGraph ();
}
