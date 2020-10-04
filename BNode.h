#include <list>
#include <iostream>

using namespace std;
template<typename T>
class BNode {
protected:
	int grado;
	T key;
	BNode<T> *parent;
private:
	list<BNode<T> *> children;
public:
	BNode (T k) : key {k} {};

	int GetGrado () {
		return grado;
	}

	void Print () {
		cout << key << " ";

		for (auto it : children) {
			cout << endl;
			it->Print ();
		}
	}

	template<typename U> friend class BinomialHeap;
};
