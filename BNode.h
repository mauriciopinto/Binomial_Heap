#include <list>
#include <iostream>
#include <fstream>

using namespace std;
template<typename T>
class BNode {
protected:
	int grado;
	T key;
	BNode<T> *parent = nullptr;
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
		cout << endl;
	}

	void GenerateGraph (ofstream *ofile) {
		for (auto it = children.begin (); it != children.end (); it++) {
			*ofile << key << " -> " << (*it)->key << ";" << endl;
			(*it)->GenerateGraph (ofile);
		}
	}
	
	int GetKey () {
		return key;
	}

	template<typename U> friend class BinomialHeap;
};
