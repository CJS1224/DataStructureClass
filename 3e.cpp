#include <bits/stdc++.h>

using namespace std;

template <class T>
class Node {
public:
  Node(T data, Node *left, Node *right) {
    this -> data = data;
    this -> left = left;
    this -> right = right;
  }
  T data;
	int level;
	Node *left, *right;
  Node *prev = NULL;
  Node *next = NULL;
};

template <class T>
class Linked_List {
  public:
    Linked_List(Node<T> *node) {
      head = node;
      tail = node;
    }
    void add(Node<T> *node) {
      tail -> next = node;
      node -> prev = tail;
      tail = node;
    }
    Node<T> *getHead() {
      return head;
    }
    void literal() {
      Node<T> *current = head;
      while(current) {
        cout << head -> data << " ";
        current = current -> next;
      }
    }

  private:
    Node<T> *head;
    Node<T> *tail;
};

template <class T>
class Base_List {
  public:
    Base_List() {
      next = NULL;
      data = NULL;
    }
    Base_List(Node<T> *node) {
      next = NULL;
      data = new Linked_List<T>(node);
    }

    void add(Base_List<T> *current, Node<T> *node) {
      Base_List<T> *exist = find(current, node -> data);
      if(exist) {
        exist -> getData() -> add(node);
      }else {
        Base_List<T> *Blist = new Base_List<T>(node);
        while(current -> getNext()) {
          current = current -> getNext();
        }
        current -> setNext(Blist);
      }
    }

    Base_List<T> *find(Base_List<T> *current, T data) {
      current = current -> getNext();
      while(current) {
        if(current -> getData() -> getHead() -> data == data) {
          return current;
        }
        current = current -> getNext();
      }
      return NULL;
    }

    void literal(Base_List<T> *current) {
      current = current -> getNext();
      while (current) {
        current -> getData() -> literal();
        current = current -> getNext();
        cout << endl;
      }
    }
    Base_List<T> *getNext() {
      return next;
    }
    void setNext(Base_List<T> *next) {
      this -> next = next;
    }

    Linked_List<T> *getData() {
      return data;
    }

  private:
    Base_List<T> *next;
    Linked_List<T> *data;
};


template <class T>
class Tree {
public:
  Tree() {}
	Tree(int amount) {
		root = NULL;
    //cout<<typeid(ZZzzz).name();
	}
	void insert(T data) {
    Node<T> *node = new Node<T>(data, NULL, NULL);
		insert(&root, node, 0);
	}
  // ======
	void levelorder(Base_List<T> *list = NULL) {
    if (root == NULL) {
      return;
    }
    // Create an empty queue for level order traversal
    queue<Node<T> *> q;

    // Enqueue Root and initialize height
    q.push(root);

    while (q.empty() == false) {
      // Print front of queue and remove it from queue
      Node<T> *node = q.front();
      if(list) {
        list -> add(list, node);
      }
      if(!list) {
        cout << "Data: " <<node -> data << "\t" << "Level: " <<node -> level <<endl;
      }

      q.pop();

      /* Enqueue left child */
      if (node->left != NULL) {
        q.push(node->left);
      }
      /*Enqueue right child */
      if (node->right != NULL) {
        q.push(node->right);
      }
    }
	}
private:
	Node<T> *root;
	void insert(Node<T> **r, Node<T> *n, int lev) {
		if(*r == NULL) {
      n -> level = lev;
      *r = n;
    }
		else if(n->data > (*r)->data) {
      insert(&((*r)->right), n, lev + 1);
    }
		else {
      insert(&((*r)->left), n, lev + 1);
    }
	}
};

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  Tree<int> *tree = new Tree<int>();
  for(int j = 0 ; j < 50 ; j ++) {
    if(j<5) {
      tree -> insert(rand());
    }else if(j<7) {
      tree -> insert(55);
    }else if(j<10) {
      tree -> insert(77);
    }else if(j<16) {
      tree -> insert(33);
    }else if(j<20) {
      tree -> insert(999);
    }else {
      tree -> insert(rand());
    }
  }
	tree -> levelorder();
  cout<<endl;
  Base_List<int> *list = new Base_List<int>();
  tree -> levelorder(list);
  list -> literal(list);
	cout << endl;
  return 0;
}
