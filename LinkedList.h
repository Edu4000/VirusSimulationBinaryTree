/**
 * @file LinkedList.h
 * @author TheDevs
 * @brief LinkedList class used in VirusSimulation
 * @version 0.1
 * @date 2021-10-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
using namespace std;

/**
 * @brief Node class that is used as pointer in LinkedList
 * 
 * @tparam var 
 */
template<typename var>
class Node{
	private:
	var data; // O(1)
	Node<var>* nextPtr; // O(1)
	Node<var>* prevPtr; // O(1)
	template<typename T>
	friend class LinkedList; // O(1)

	public:
	/**
	 * @brief Construct a new Node object. O(1)
	 * 
	 * @param data Data type var to be stored in Node
	 */
	Node(var data){ // O(1)
		this->data = data; // O(1)
		this->nextPtr = NULL; // O(1)
		this->prevPtr = NULL; // O(1)
	}

	/**
	 * @brief Overload operator of <<, used to print Node.data. O(1)
	 * 
	 * @param salida Out stream variable
	 * @param node The node object
	 * @return ostream& 
	 */
	friend ostream& operator <<(ostream & salida, const Node & node){ //O(1)
		salida << node.data;
		return salida;
	}
};

/**
 * @brief LinkedList class that is used in VirusSimulation
 * 
 * @tparam var 
 */
template<typename var>
class LinkedList{
	private:
	Node<var>* header; // O(1)
	Node<var>* last; // O(1)

	/**
	 * @brief Returns index of node where data is located in the list. Goes from last(-1) to header(-n). O(n)
	 * 
	 * @param index Default value of -1
	 * @param data Data to be found in LinkedList
	 * @param ptr Pointer to node whith data to be compared
	 * @return int - Index of data in Linked list
	 */
	int lastIndexOfRecursivo(int index, var data, Node<var> * ptr){ // O(n)
		if (ptr == NULL){
			return NULL; // O(1)
		}
		else if(data == ptr->data){
			return index; // O(1)
		}
		return lastIndexOfRecursivo(index - 1, data, ptr->prevPtr); // O(n)
	}

	/**
	 * @brief Returns index where data is located in the list. Goes from header(0) to last(n). O(n)
	 * 
	 * @param index Default value of 0
	 * @param data Data to be found in LinkedList
	 * @param ptr Pointer to node whith data to be compared
	 * @return int - Index of data in Linked list
	 */
	int indexOfRecursivo(int index, var data, Node<var> * ptr){ // O(n)
		if (ptr == NULL){
			return NULL; // O(1)
		}
		else if(data == ptr->data){
			return index; // O(1)
		}
		return indexOfRecursivo(index + 1, data, ptr->nextPtr); // O(n)
	}

	/**
	 * @brief Operator overload >, compares length of the LinkedList to another LinkedList. O(n)
	 * 
	 * @param linkedL LinkedList to be compared
	 * @return TRUE if THIS LinkedList is bigger than linkdeL, else return FALSE
	 */
	bool operator > (const LinkedList<var>& linkedL){ // O(n)
		return this->size() > linkedL.size(); // O(n)
	}

	/**
	 * @brief Operator overload <, compares length of the LinkedList to another LinkedList. O(n)
	 * 
	 * @param linkedL LinkedList to be compared
	 * @return TRUE if THIS LinkedList is smaller than linkdeL, else return FALSE
	 */
	bool operator < (const LinkedList<var>& linkedL){ // O(n)
		return this->size() < linkedL.size(); // O(n)
	}

	public:
	/**
	 * @brief Construct a new Linked List object, the first pointer will be header and last. O(1)
	 * 
	 * @param header Pointer to Node<var> which is the header
	 */
	LinkedList(Node<var>* header) { // O(1)
		this->header = header; // O(1)
		this->last = header; // O(1)
	}

	/**
	 * @brief Add new node with data to the first position (header). O(1)
	 * 
	 * @param data Data to be added to the LinkedList
	 */
	void addFirst(var data){
		Node<var>* new_node = new Node<var>(data);
		if (header == NULL){ // Linked list is empty
			header = last = new_node;
		}
		else{ // It points to one node
			new_node->nextPtr = header;
			header->prevPtr = new_node;
			header = new_node;
		}
	}

	/**
	 * @brief Add new node with data to the last position (last). O(1)
	 * 
	 * @param data Data to be added to the LinkedList
	 */
	void addLast(var data) {
		Node<var>* curr = header; // Current (temporal) pointer for iteration starts in the header pointer
		Node<var>* new_node = new Node<var>(data); // pointer to a new Node with data is created
		if (this->is_empty() == true) {
			header = last = new_node;
		} else {
			last->nextPtr = new_node;
			new_node->prevPtr = last;
			last = new_node;
		}
	}

	/**
	 * @brief Checks if the LinkedList is empty. O(1)
	 * 
	 * @return TRUE if LinkedList is empty, else FALSE
	 */
	bool is_empty(){
		return header == NULL ? true : false;	// O(1)
	}

	/**
	 * @brief Gets the data stored in the index indicated. O(n)
	 * 
	 * @param index Index where data is stored
	 * @return var - Data stored in the index position
	 */
	var get(int index){
		try {						// O(1)
			if (index < 0) {		// O(1)
				throw (index);		// O(1)
			} else {
				Node<var>* ptr = header;	// O(1)
				int i = 0;					// O(1)
				while (ptr != NULL) {		// O(n)
					if(i == index) {		// O(1)
						return ptr->data;	// O(1)
					}
					i++;					// O(1)
					ptr = ptr->nextPtr;		// O(1)
				}
				throw (index);	// O(1)
			}
		} catch (int index) {
			if (index < 0) {	// O(1)
				cout << "Error: Index must be above 0" << endl;			// O(1)
			} else {
				cout << "Error: Index out of bounds" << endl;			// O(1)
			}
			return NULL;
		}
	}

	/**
	 * @brief Gets data stored in header and erases the node that contains it. O(1)
	 * 
	 * @return var - Data stored in header
	 */
	var remove_front(){
		try {                        // O(1)
			if (header == last) {	 // O(1)
				var deletedNode = header->data;
				delete header;
				header = NULL;
				last = NULL;
				return deletedNode;
			}
			else if (header != NULL) {    // O(1)
				var deletedNode = header->data;
				header = header->nextPtr;
				header->prevPtr = NULL;
				return deletedNode;
			}
			else {            // O(1)
				throw;
			}
		}
		catch(std::length_error) {     // O(1)
			cout << "Lista vacía";
		}
	}

	/**
	 * @brief Gets data stored in last and erases the node that contains it. O(n)
	 * 
	 * @return var - Data stored in last
	 */
	var remove_last(){
		Node<var>* ptr = header;			// O(1)
		Node<var>* ptr2 = header->nextPtr;	// O(1)
		while(ptr2->nextPtr != NULL) {		// O(n)
			ptr = ptr->nextPtr;				// O(1)
			ptr2 = ptr2->nextPtr;			// O(1)
		}
		ptr->nextPtr = NULL;
		last = ptr;
		return ptr2->data;
	}

	/**
	 * @brief Adding data in desired index by inmtroducing new node in LinkedList. O(n)
	 * 
	 * @param data Data to be stored
	 * @param index Position where data will be stored in LinkedList
	 */
	void add_at(var data, int index){
		try {						// O(1)
			if (index < 0) {		// O(1)
				throw (index);		// O(1)
			} else {
				Node<var>* ptr = header;
				Node<var>* ptr2;	// O(1)
				if (index == 0) {
					ptr2 = ptr;
					header = new Node<var>(data);
					header->nextPtr = ptr2;
					return;
				} else {
					int i = 1;					// O(1)
					while (ptr != NULL) {		// O(n)
						if(i == index) {		// O(1)
							ptr2 = ptr->nextPtr;				// O(1)
							ptr->nextPtr = new Node<var>(data);	// O(1)
							ptr->nextPtr->nextPtr = ptr2;		// O(1)
							return;
						}
						i++;					// O(1)
						ptr = ptr->nextPtr;		// O(1)
					}
					throw (index);	// O(1)
				}
			}
		} catch (int index) {
			if (index < 0) {	// O(1)
				cout << "Error: Index must be above 0" << endl;			// O(1)
			} else {
				cout << "Error: Index out of bounds" << endl;			// O(1)
			}
		}
	}

	/**
	 * @brief Checks the size of the LinkedList. O(n)
	 * 
	 * @return int - Size of LinkedList
	 */
	int size() {
		Node<var>* curr = header;
		int i = 0;
		while (curr != NULL) {
			i++;
			curr = curr->nextPtr;
		}
		return i;
	}

	/**
	 * @brief Prints all the nodes in the LinkedList, from header to last. O(n)
	 * 
	 */
	void print() {
		Node<var>* ptr = header;
		while(ptr != NULL) {
			cout << ptr->data << ":";
			ptr = ptr->nextPtr;
		}
		cout << endl;
	}

	/**
	 * @brief Prints all the nodes in the LinkedList, from last to header. O(n)
	 * 
	 */
	void reverse() {
		Node<var>* ptr = last;
		while(ptr != NULL) {
			cout << ptr->data << ":";
			ptr = ptr->prevPtr;
		}
		cout << endl;
	}

	/**
	 * @brief Get the data of the first node (header). O(1)
	 * 
	 * @return var - Data stored in header
	 */
	var get_first() {
		if (header != NULL) {
			return header->data;
		} else {
			return var();
		}
	}

	/**
	 * @brief Get the data of the last node (last). O(1)
	 * 
	 * @return var - Data stored in last
	 */
	var get_last() {
		if (header != NULL) {
			return last->data;
		} else {
			return var();
		}
	}

	/**
	 * @brief Get the data of the first node (header). O(1)
	 * 
	 * @return var - Data stored in header
	 */
	var peekFirst() {
		if (header != NULL) {
			return header->data;
		} else {
			return var();
		}
	}

	/**
	 * @brief Get the data of the last node (last). O(1)
	 * 
	 * @return var - Data stored in last
	 */
	var peekLast() {
		if (header != NULL) {
			return last->data;
		} else {
			return var();
		}
	}

	// Metodos Recursivos Definidos en Private de LinkedList

	/**
	 * @brief Gets the index where data is stored, from last to header. O(n)
	 * 
	 * @param data Data to be found
	 * @return int - Index of position in LinkedList
	 */
	int lastIndexOf(var data) {
		return lastIndexOfRecursivo(-1, data, last);
	}

	/**
	 * @brief Gets the index where data is stored, from header to last. O(n)
	 * 
	 * @param data Data to be found
	 * @return int - Index of position in LinkedList
	 */
	int indexOf(var data) {
		return indexOfRecursivo(0, data, header);
	}

	// Metodos Adicionales Para Challenge (Reducen la complejidad comparado con el main)
	/**
	 * @brief Adds all the data that is stored in the nodes of the LinekdList. O(n)
	 * 
	 * @return int - The addition of all the nodes
	 */
	int sum() {
		Node<var>* ptr = this->header;	// O(1)
		int res = 0;
		while (ptr != NULL) {			// O(n)
			res += ptr->data;			// O(1)
			ptr = ptr->nextPtr;			// O(1)
		}
		return res;
	}

	/**
	 * @brief Looks for largest data stored in LinkedList. O(n)
	 * 
	 * @return var - Largest data in LinkedList
	 */
	var max() {
		Node<var>* ptr = this->header;	// O(1)
		var res = ptr->data;
		while (ptr != NULL) {			// O(n)
			if(res < ptr->data) {		// O(1)
				res = ptr->data;		// O(1)
			}
			ptr = ptr->nextPtr;			// O(1)
		}
		return res;
	}

	/**
	 * @brief Looks for smallest data stored in LinkedList. O(n)
	 * 
	 * @return var - Smallest data in LinkedList
	 */
	var min() {
		Node<var>* ptr = this->header;	// O(1)
		var res = ptr->data;
		while (ptr != NULL) {			// O(n)
			if(res > ptr->data) {		// O(1)
				res = ptr->data;		// O(1)
			}
			ptr = ptr->nextPtr;			// O(1)
		}
		return res;
	}

	// Methods for a Stack
	/**
	 * @brief Pushing data into the stack. O(1)
	 * 
	 * @param data Data to be pushed
	 */
	void push(var data) {
		addFirst(data);
	}

	/**
	 * @brief Retrieves data of stack and erases it. O(1)
	 * 
	 * @return var - Data to be poped
	 */
	var pop() {
		return this->remove_front();
	}

	/**
	 * @brief Takes a look at the top of the stack. O(1)
	 * 
	 * @return var - Data at the top of stack
	 */
	var peak() {
		if (is_empty()) {
			return NULL;
		}
		return header->data;
	}

	// Methods for a Queue
	/**
	 * @brief Adding a data to the queue. O(1)
	 * 
	 * @param data Data to be queued
	 */
	void queue(var data) {
		this-> addLast(data);
	}

	/**
	 * @brief Retrieves data and takes it out of the queue. O(1)
	 * 
	 * @return var - Data that is dequeued
	 */
	var dequeue() {
		try {                       // O(1)
			if (header == last) {	// O(1)   Only one data in queue
				var deletedNode = header->data;
				header = NULL;
				last = NULL;
				return deletedNode;
			}
			else if (header != NULL) {    // O(1)
				var deletedNode = header->data;
				header = header->nextPtr;
				header->prevPtr = NULL;
				return deletedNode;
			}
			else {            // O(1)
				throw;
			}
		}
		catch(std::length_error) {     // O(1)
			cout << "Lista vacía";
		}
	}

	// Dequeue Max
	var dequeueMax() {
		try {                       // O(1)
			if (header == last) {	// O(1)   Only one data in queue
				var deletedNode = header->data;
				header = NULL;
				last = NULL;
				return deletedNode;
			}
			else if (header != NULL) {    // O(1)
				Node<var>* ptr = header;
				Node<var>* ptr2;
				var max = this->max();

				while(ptr != NULL) {
					if (ptr->data == max) {
						if (ptr == header) {
							return this->remove_front();
						} else if (ptr == last) {
							return this->remove_last();
						} else {
							ptr2->nextPtr = ptr->nextPtr;
							ptr->nextPtr->prevPtr = ptr2;
							delete ptr;
							return max;
						}
					}
					ptr2 = ptr;
					ptr = ptr->nextPtr;
				}
			}
			else {            // O(1)
				throw;
			}
		}
		catch(std::length_error) {     // O(1)
			cout << "Lista vacía";
		}
	}

	// Dequeue Max
	var dequeueMin() {
		try {                       // O(1)
			if (header == last) {	// O(1)   Only one data in queue
				var deletedNode = header->data;
				header = NULL;
				last = NULL;
				return deletedNode;
			}
			else if (header != NULL) {    // O(1)
				Node<var>* ptr = header;
				Node<var>* ptr2;
				var min = this->min();

				while(ptr != NULL) {
					if (ptr->data == min) {
						if (ptr == header) {
							return this->remove_front();
						} else if (ptr == last) {
							return this->remove_last();
						} else {
							ptr2->nextPtr = ptr->nextPtr;
							ptr->nextPtr->prevPtr = ptr2;
							delete ptr;
							return min;
						}
					}
					ptr2 = ptr;
					ptr = ptr->nextPtr;
				}
			}
			else {            // O(1)
				throw;
			}
		}
		catch(std::length_error) {     // O(1)
			cout << "Lista vacía";
		}
	}

	var dequeueMaxO() {
		if (is_empty() == true)
		{
			throw -1;
		}
		var max = this->max(); // Este es el indice con valor minimo
		Node<var> * curr = header;
		Node<var> * next = NULL;
		while (true)
		{
			next = curr->nextPtr;
			if (next->data == max)
			{
				curr->nextPtr->nextPtr = next->nextPtr;
				next->prevPtr = curr;
				return max;
			}
			curr = curr->nextPtr;
		}
	}

	/**
	 * @brief Checks if data is stored in the LinkedList. O(n)
	 * 
	 * @param data Data to be searched in LinkedList
	 * @return TRUE if data is in LinkedList, else FALSE
	 */
	bool checkData(string data)
	{
		Node<var>* ptr = header; // Header of a linked list with servers
		string aux;

		while (ptr != NULL) // ptr->data = Node<Server> data
		{
			if (ptr->data == data)
			{
				return true;
			}
			else
			{
				ptr = ptr->nextPtr;
			}
		}
		return false;
	}

	/**
	 * @brief Operator overlad ==, checks if data is within the LinkedList. O(n)
	 * 
	 * @param data Data to be checked
	 * @return TRUE if data is in LinkedList, else FALSE
	 */
	bool operator == (string data)
	{
		return checkData(data); // Bool statement
	}

	/**
	 * @brief Measures the percentage of infected servers within the LinkedList. O(n)
	 * 
	 * @return float - Percentage of infected servers
	 */
	float infected() {
		Node<var> * ptr = header; // The current node <server> linked list
		float total = 0;
		float nodeNum = 0;
		while(ptr != NULL) {
			if(ptr->data == true){
				total++;
			}
			nodeNum++;
			ptr = ptr->nextPtr;
		}
		return total/nodeNum;
	}

	/**
	 * @brief Gets the percentage of infected in the LinkedList divided by a certain size. O(n)
	 * 
	 * @param size - Number of LinkedLists
	 * @return float - Percentage of infected within all LinkedLists
	 */
	float operator / (int size){
		return infected() / size;
	}

	/**
	 * @brief Operator overload <<, used to print the LinkedList. For general purpouse the only node printed is the header. O(1)
	 * 
	 * @param salida Out stream variable
	 * @param list The list object
	 * @return ostream& 
	 */
	friend ostream& operator <<(ostream & salida, const LinkedList & list)
	{
		salida << *list.header;
		return salida;
	}
};