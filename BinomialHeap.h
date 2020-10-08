#include "BNode.h"
#include <stdlib.h>
#include <bits/stdc++.h>
#include <algorithm>

template<typename T>
bool ValueCmp (BNode<T> * const a, BNode<T> *const b);

template<typename T>
class BinomialHeap {
private:
	int size {0};
	list<BNode<T> *> heap_list;
	BNode<T> *min = nullptr;
public:
	BinomialHeap () {};

	void Insert (BNode<T> *temp) {
		if (!min || min->key >= temp->key)
			min = temp;

		heap_list.push_back (temp);
		size++;
		heap_list.sort (ValueCmp<T>);
		Compress ();
	}
	
	T GetMin () {
		return min->key;
	}
public:
	void DeleteMin () {
		heap_list.remove (min);
		auto aux = min->children;
		size--;
		for (auto it : aux) {
			it->parent = nullptr;
			Insert (it);
		}
		min = nullptr;
		T min_key = INT_MAX;
		for (auto it : heap_list) {
			if (it->key < min_key) {
				min_key = it->key;
				min = it;
			}
		}
	}

	BNode<T> * Search(BNode<T> * node, T value){
    		if(node->key == value)
      			return node;
		
		BNode<T> *temp;
		for(auto it:node->children) {
      			temp = Search(it, value);
			if (temp)
				return temp;
		}

		return nullptr;
	}


	BNode<T> * Find(T value){
		for(auto node : heap_list){
			auto ret = Search(node, value);
        		if (ret)
         			return ret;
		}
		return nullptr;
  	}
	
	void DecreaseKey (BNode<T> *node, T value) {
		BNode<T> *temp = node;
		BNode<T> *tempParent = node->parent;
		bool end = false;
		int tempKey;
		temp->key = value;
		while (tempParent != nullptr && end) {
			end = true;
			if (temp->key < tempParent->key) {
				tempKey = temp->key;
				temp->key = tempParent->key;
				tempParent->key = tempKey;
				end = false;
			}
			temp = tempParent;
			tempParent = temp->parent;
		}
		if (!tempParent && temp->key < min->key)
			min = temp;
	}
private:
	void Merge (BinomialHeap<T> H) {
		for (auto it : H.heap_list) 
			Insert (*it);
	}
	
	void Union (BNode<T> *node1, BNode<T> *node2) {
		if (node1->grado != node2->grado)
			return;
		if (node1->key < node2->key) {
			node1->children.push_back (node2);
			node2->parent = node1;
			node1->grado++;
			heap_list.remove (node2);
		}
		else {
			node2->children.push_back (node1);
			node1->parent = node2;
			node2->grado++;
			heap_list.remove (node1);
		}
		size--;
	}

	void Compress () {
		auto it = heap_list.begin ();
		auto it1 = heap_list.begin ();
		it1++;

		while (it1 != heap_list.end ()) {
			if ((*it)->grado == (*it1)->grado) {
				Union (*it, *it1);
				it = heap_list.begin ();
				it1 = heap_list.begin ();
				it1++;
			}
			else {
				it++;
				it1++;
			}
		}
	}
public:
	void Print () {
		for (auto it : heap_list) {
			cout << "node" << endl;
			it->Print ();
			cout << endl;
		}
	}

	void Delete (BNode<T> *node) {
		DecreaseKey (node, INT_MIN);
		DeleteMin ();
	}

	int GetSize () {
		return size;
	}

	void GenerateGraph () {
		ofstream ofile;
		ofile.open ("graph.gv", ios::trunc);

		ofile << "graph BinomialHeap {" << endl;
		for (auto it = heap_list.begin (); it != heap_list.end (); it++) {
			if (next (it, 1) != heap_list.end ())
				ofile << (*it)->key << " -> " << (*(next (it, 1)))->key << ";" << endl;
			(*it)->GenerateGraph (&ofile);
		}
		ofile << "}";
	}

	void InputData (string filename) {
		ifstream ifile;
		//Completar
	}
};

template<typename T>
bool ValueCmp (BNode<T> * const a, BNode<T> *const b) {
	return a->GetGrado () < b->GetGrado ();
}
