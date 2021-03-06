#include "LinkedList.h"

template<typename T>
class Nodo{
    private:
		// Definition Complexity O(1)
    	T data;
        Nodo<T>* left;
        Nodo<T>* right;
        template<typename U>
        friend class BST;
    public:
		// Constructor O(1)
        Nodo(T data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

template<typename T>
class BST{
	private:
	// Definition Complexity O(1)
	Nodo<T> * root;

	// insertion 			O(n)
	void insert(Nodo<T> * & nodo, T data){
		if(nodo== NULL)		// O(1)
		{
			nodo = new Nodo<T>(data);
		}
		else	// O(n)
		{
			if(data < nodo->data)		// O(1)
			{
				insert(nodo->left, data);	// O(n)
			}
			else if(data > nodo->data)	// O(1)
			{
				insert(nodo->right, data);	// O(n)
			}
		}
	}

	// preOrden				O(n)
	void preOrden(Nodo<T> * & nodo){
		if(nodo != NULL)	// O(1)
		{
			cout << *nodo->data << " -- ";	// O(1)
			preOrden(nodo->left);		// O(n)
			preOrden(nodo->right);		// O(n)
		}
	}

	// postOrden			O(n)
	void postOrden(Nodo<T> * & nodo){
		if(nodo != NULL)	// O(1)
		{
			postOrden(nodo->left);		// O(n)
			postOrden(nodo->right);		// O(n)
			cout << *nodo-> data << " -- ";	// O(1)
		}
	}

	// InOrden				O(n)
	void inOrden(Nodo<T> * & nodo){
		if(nodo != NULL)	// O(1)
		{
			inOrden(nodo->left);		// O(n)
			cout << *nodo-> data << " -- ";	// O(1)
			inOrden(nodo->right);		// O(n)
		}
	}

	// Total Infected
	float total_infected(Nodo<T> *& nodo, int size)
	{
		float total = 0;
		if(nodo != NULL)	// O(1)
		{
			total += *nodo->data / size;
			total += total_infected(nodo->left, size);
			total += total_infected(nodo->right, size);

			return total;
		}
		return 0;
	}

	bool searchIP(Nodo<T> *& nodo, string data)
	{
		if (nodo == NULL)
		{
			return false;
		} // *nodo->data is a linked list
		else if (*nodo->data == data)
		{
			return true;
		}
		else
		{
			if (searchIP(nodo->left, data) || searchIP(nodo->right, data))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}

	// search				O(n)
	bool search(Nodo<T> * & nodo, T data){
		if (nodo == NULL)	// O(1)
		{
			return false;	// O(1)
		}
		else if (nodo->data == data)	// O(1)
		{
			return true;	// O(1)
		}
		else if (data > nodo->data)		// O(1)
		{
			return search(nodo->right, data);	// O(n)
		}
		else	// O(1)
		{
			return search(nodo->left, data);	// O(n)
		}
	}
	
	// Length				O(n)
	int length(Nodo<T> * &nodo) {
		if(nodo == NULL) {	// O(1)
			return 0;		// O(1)
		} else {
			int num = 1;	// O(1)
			num += length(nodo->left);		// O(n)
			num += length(nodo->right);		// O(n)
			return num;		// O(1)
		}
	}

	// max					O(n)
	T max(Nodo<T> * &nodo) {
		if (this->isEmpty()){	// O(1)
			throw -1;			// O(1)
		}
		Nodo<T> * aux = nodo;
		while(aux->right != NULL) {	// O(n)
			aux = aux->right;		// O(1)
		}
		return aux->data;	// O(1)
	}

	// min					O(n)
	T min(Nodo<T> * &nodo) {
		if (this->isEmpty()){	// O(1)
			throw -1;			// O(1)
		}
		Nodo<T> * aux = nodo;
		while(aux->left != NULL) {	// O(n)
			aux = aux->left;		// O(1)
		}
		return aux->data;	// O(1)
	}

	// levels				O(n)
	void levels(Nodo<T> * &nodo) {
		LinkedList<Nodo<T>*> fila = LinkedList<Nodo<T>*>(NULL);	// O(1)
		fila.queue(nodo);	// O(n)
		Nodo<T>* aux;		// O(1)

		while(!fila.is_empty()) {	// O(n)
			aux = fila.dequeue();	// O(1)

			cout << *aux->data << " -- ";	// O(1)

			if(aux->left != NULL) {		// O(1)
				fila.queue(aux->left);	// O(1)
			}
			if(aux->right != NULL) {	// O(1)
				fila.queue(aux->right);	// O(1)
			}
		}
		cout << endl;	// O(1)
	}

	// ancestors			O(n)
	void ancestors(Nodo<T> * & nodo, T data){
		if (nodo->data == data){	// O(1)
			return;		// O(1)
		}

		cout << nodo->data << ":";	// O(1)

		if (data > nodo->data){		// O(1)
			ancestors(nodo->right, data);	// O(n)
		} else {
			ancestors(nodo->left, data);	// O(n)
		}
	}

	// Flatten				O(n)
	void flatten(Nodo<T> * & nodo, LinkedList<T> &list) {
		if(nodo != NULL){	// O(1)
			list.addLast(nodo->data);	// O(n)
			flatten(nodo->left, list);	// O(n)
			flatten(nodo->right, list);	// O(n)
		}
	}

	// Missions				O(n)
	int missions(Nodo<T> * & nodo)
    {
        if (nodo == NULL)	// O(1)
        {
            return 0;		// O(1)
        }

        int left = missions(nodo->left);	// O(n)
        int right = missions(nodo->right);	// O(n)

        if (left > right)
        {
            return(left + 1);	// O(1)
        }
        else
        {
            return(right + 1);	// O(1)
        }
    }

	// Gadgets				O(n)
	int gadgets(Nodo<T> * & node, T data, int count)
    {
        if (node->data == data)	// O(1)
        {
             return count;	// O(1)
         }
         else if (data < node->data)	// (1)
         {
             return gadgets(node->left, data, count+1);	// O(n)
         }
         else if (data > node->data)	// O(1)
         {
             return gadgets(node->right, data, count+1);// O(n)
        }
        return 0;		// O(1)
    }

	// Is Full
	bool is_full(Nodo<T> * & node) // O(log(n))
	{
		if (node == NULL) // O(1)
		{
			return true; // O(1)
		}
		else if ((node->left == NULL && node->right != NULL) || (node->left != NULL && node->right == NULL)) // O(1)
		{
			return false; // O(1)
		}
		return (is_full(node->left)) && (is_full(node->right)); // O(log(n))
	}

	// Leaf Counter
	int leaf_count(Nodo<T> * & node) // O(log(n))
	{
		if (node == NULL) // O(n)
		{
			return 0; // O(n)
		}
		else if (node->left == NULL && node->right == NULL) // O(n)
		{
			return 1; // O(n)
		}

		int res = leaf_count(node->left) + leaf_count(node->right); // O(log(n))
		return res; // O(1)
	}

	// Is Perfect
	bool is_perfect(Nodo<T> * & node) // O(log(n))
	{
		if (node == NULL) // O(n)
		{
			return 0; // O(n)
		}
		else if (node->left == NULL && node->right == NULL) // O(n)
		{
			return 1; // O(n)
		}
		return is_perfect(node->left) == is_perfect(node->right); // O(log(n))
	}

	// Is degenerate
	bool is_degenerate(Nodo<T> * & node)
	{
		if (node->right == NULL && node->left == NULL) // Checks if there are any children of a node
		{
			return true;
		}
		else if (node->right == NULL && node->left != NULL) // Checks if only left child exist
		{
			return is_degenerate(node->left);
		} else if (node->left == NULL && node->right != NULL) // Checks if only right child exist
		{
			return is_degenerate(node->right);
		}
		else // Else both exist, so its not a degenerate tree
		{
			return false;
		}
	}

	public:
	BST(){
		root = NULL;	//	O(1)
	}

	T first()
	{
		return this->root->data;
	}

	void insert(T data){		// O(n)
		if(isEmpty()){
			root = new Nodo<T>(data);	// O(1)
		}else{
			insert(root, data);			// O(n)
		}
	}

	bool search(T data){	// O(n)
		return search(this->root, data);	// O(n)
	}

	bool isEmpty(){			// O(n)
		return root == NULL;	// O(n)
	}

	// preOrden()		O(n)
	void preOrden(){
		preOrden(root);		// O(n)
		cout << endl;
	}
	// postOrden()		O(n)
	void postOrden(){
		postOrden(root);	// O(n)
		cout << endl;
	}
	// inOrden()		O(n)
	void inOrden(){
		inOrden(root);	// O(n)
		cout << endl;
	}

	// length()			O(n)
	int lenght(){
		if(this->isEmpty()) {	// O(1)
			return 0;			// O(1)
		}
		return length(root);	// O(n)
	}

	T max() {	// O(n)
		return (max(this->root));	// O(n)
	}

	T min() {	// O(n)
		return (min(this->root));	// O(n)
	}

	void villianLevels(){	// O(n^2)
		levels(this->root);	// O(n^2)
	}

	void sequels(T data){ // O(n)
		(search(data)) ? ancestors(this->root, data) : throw -1; // O(n)
		cout << endl; 	// O(1)
	}

	LinkedList<T> loves() {	// O(n)
		LinkedList<T> res = LinkedList<T>(NULL);	// O(1)
		flatten(this->root, res);		// O(n)
		return res;			// O91
	}

	int missions()	// O(n)
    {
        return missions(this->root);	// O(n)
    }

	int gadgets(T data)	// O(n)
    {
        if (isEmpty())	// O(1)
        {
            return 0;	// O(1)
        }
        else
        {
            return gadgets(root, data, 0);	// O(n)
        }
    }

	bool is_full()
	{
		return is_full(root);
	}

	int leaf_count()
	{
		return leaf_count(root);
	}

	bool is_perfect()
	{
		return is_full(root) && is_perfect(root);
	}

	bool is_degenerate()
	{
		if (isEmpty()) // Checks if BST is empty
		{
			return false;
		}
		else // If its not empty, then it does the algorithm to determine if its a degenerate tree
		{
			return is_degenerate(root);
		}
	}

	bool searchIP(string data)
	{
		return searchIP(root, data);
	}

	float infected_percent(){
		int size = lenght();
		return total_infected(root, size);
	}
};
