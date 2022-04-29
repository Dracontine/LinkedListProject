#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class LinkedList
{

public:
	struct Node { // makes the Node like elements innit
		Node* next;
		Node* prev;
		T data;
	};



	// Behaviors
	void PrintForward() const;    //declarations
	void PrintReverse() const;
	void PrintForwardRecursive(const Node* node) const;
	void PrintReverseRecursive(const Node* node) const;

	//Accessors
	unsigned int NodeCount() const;
	void FindAll(vector<Node*>& outData, const T& value) const;
	const Node* Find(const T& data) const;
	Node* Find(const T& data);
	const Node* GetNode(unsigned int index) const;
	Node* GetNode(unsigned int index);
	Node* Head();
	const Node* Head() const;
	Node* Tail();
	const Node* Tail() const;

	//Insertion
	void AddHead(const T& data);
	void AddTail(const T& data);
	void AddNodesHead(const T* data, unsigned int count);
	void AddNodesTail(const T* data, unsigned int count);
	void InsertAfter(Node* node, const T& data);
	void InsertBefore(Node* node, const T& data);
	void InsertAt(const T& data, unsigned int index);

	//Removal
	bool RemoveHead();
	bool RemoveTail();
	unsigned int Remove(const T& data);
	bool RemoveAt(unsigned int index);
	void Clear();

	//Operators
	const T& operator[](unsigned int index) const;
	T& operator[](unsigned int index);
	bool operator==(const LinkedList<T>& rhs) const;
	LinkedList<T>& operator=(const LinkedList<T>& rhs);

	//Construction/Destruction
	LinkedList();
	LinkedList(const LinkedList<T>& list);
	~LinkedList();

	Node* head; //location of the node
	Node* tail;
	unsigned int counter; // amount of nodes in the system


};

template <typename T>
LinkedList<T>::LinkedList() {
	head = nullptr;  // defualt constructor
	tail = nullptr;
	counter = 0;
}

template <typename T>
LinkedList<T>::~LinkedList() {
	Node* temp1 = head;
	while (temp1 != nullptr) { // destructor
		head = head->next;
		delete temp1;
		temp1 = head;
	}


	counter = 0;
	head = nullptr;
	tail = nullptr;

}

template <typename T>
void LinkedList<T>::AddHead(const T& data) {     //makes a new head
	Node* nodeNew = new Node;  // creates a new node to store location and the data
	nodeNew->data = data;

	if (head == nullptr) { // as said in professor foxes video number 2
		head = nodeNew;
		tail = nodeNew;
	}
	else {
		nodeNew->next = head;    //if there is a location var then they move the head location by one and the previous head location given to the new node and it is assigned as the head.
		head->prev = nodeNew;
		head = nodeNew;
	}
	counter++; //add to lists of nodes.
}

template<typename T>
void LinkedList<T>::AddTail(const T& data) { // makes the new tail of the data nodes
	Node* nodeNew = new Node; //creates new tail node and gives the node the data
	nodeNew->data = data;


	if (tail == nullptr) {
		tail = nodeNew;
		head = nodeNew;
	}
	else {
		nodeNew->prev = tail;
		tail->next = nodeNew; // sets it so the new node is after the the tail then makes the new node the tail then tail is set as the new node
		tail = nodeNew;

	}
	counter++; // add/counts the lsit of nodes
}

template <typename T>
void LinkedList<T>::AddNodesHead(const T* data, unsigned int count) { /* adds multiple new head nodes in order. takes in an array and gives each data a point in the node list */
	for (int i = count - 1; i > -1; i--) {
		AddHead(data[i]);
	}
}

template <typename T>
void LinkedList<T>::AddNodesTail(const T* data, unsigned int count) { // adds the array of nodes to the end of the list and nupdates the tail to the new trail. loops the add tail function to make more and add to node list
	for (unsigned int i = 0; i < count; i++) {
		AddTail(data[i]);
	}

}

template <typename T>
unsigned int LinkedList<T>::NodeCount() const { // returns the amountof nodes
	return counter;
}

template <typename T>
void LinkedList<T>::PrintForward() const { // create a temporary  node which is equal to the head then the loop iterates it through the list printing all the values.
	Node* temp = head;

	for (unsigned int i = 0; i < counter; i++) {
		cout << temp->data << endl;
		temp = temp->next;
	}
}

template <typename T>
void LinkedList<T>::PrintReverse() const {
	Node* temp = tail;

	for (unsigned int i = 0; i < counter; i++) {
		cout << temp->data << endl;
		temp = temp->prev;
	}
}
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Head() {
	return head;
}
template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Head() const {
	return head;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Tail() {
	return tail;
}

template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Tail() const {
	return tail;
}

template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) const {
	Node* tempthree = head;
	if (counter <= index) {
		throw out_of_range("Error");
	}
	for (unsigned int i = 0; i < index; i++) {
		tempthree = tempthree->next;
		if (tempthree == nullptr) {
			throw out_of_range("Error");
		}
	}
	return tempthree;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) {
	Node* tempthree = head;
	if (counter <= index) {
		throw out_of_range("Error");
	}
	for (unsigned int i = 0; i < index; i++) {
		tempthree = tempthree->next;
		if (tempthree == nullptr) {
			throw out_of_range("Error");
		}
	}
	return tempthree;
}

template <typename T>
T& LinkedList<T>::operator[](unsigned int index) {
	Node* temp = GetNode(index);
	return temp->data;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data) {
	Node* temp = head;

	while (temp != nullptr) {
		if (temp->data == data) {

			return temp;
		}
		temp = temp->next;
	}
	return nullptr;
}

template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data) const {
	Node* temp = head;
	while (temp != nullptr) {
		if (temp->data == data) {
			return temp;
		}
		temp = temp->next;
	}
	return nullptr;
}

template <typename T>
void LinkedList<T>::FindAll(vector<Node*>& outData, const T& value) const {
	Node* temp = head;
	for (unsigned int i = 0; i < counter; i++) {
		if (temp->data == value) {

			outData.push_back(temp);

		}
		temp = temp->next;
	}
}
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list) {
	Node* temp = list.head;
	head = nullptr;    //creates a copy of the data so intilizes the data as a defualt constrictor would do then gets temp array as the temp head and they uses the while loop
	tail = nullptr;
	counter = 0;
	while (temp != nullptr) {

		this->AddTail(temp->data);  //takes the data and assigns the node the data of that node part
		temp = temp->next; //changes the locations to the next location then reruns to loop to assign that new location node the data and keeps going until the tail

	}
}
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs) {
	Node* tempz = this->head;  //makes two temp pointers that allows tempz to get the value of whats next from the data and successfully copy it
	Node* temp;
	while (tempz != nullptr) {

		temp = tempz->next;
		delete tempz;
		tempz = temp;
	}
	Node* copy = rhs.head; //same thing as copy constructor just iterates through copying the data value and what location the data value would be stored
	head = nullptr;
	tail = nullptr;
	counter = 0;

	while (copy != nullptr) {
		this->AddTail(copy->data);
		copy = copy->next;
	}
	return *this;
}

template <typename T>
void LinkedList<T>::InsertAfter(Node* node, const T& data) {
	Node* newNode = new Node(); //first two just assign the data
	newNode->data = data;
	newNode->prev = node; //these two give the previus and next value from the node we get before it
	newNode->next = node->next;
	node->next = newNode; //assigns the node that we were given intially a value the new next value since we put this new node after it
	(node->next)->prev = newNode;  // assigns the node in the fornt of it the value of the newNOde we inserting previous to it.
	counter++;
}

template <typename T>
void LinkedList<T>::InsertBefore(Node* node, const T& data) {
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = node;
	newNode->prev = node->prev;
	node->prev = newNode;
	(node->prev)->next = newNode;
	counter++;
}

template <typename T>
void LinkedList<T>::InsertAt(const T& data, unsigned int index) {
	Node* temp = head;

	if (index == counter) {
		AddTail(data);
	}
	else {
		for (int i = 0; i < index; i++) {
			temp = temp->next;
		}
		InsertBefore(temp, data);
	}
}

template <typename T>
bool LinkedList<T>::operator==(const LinkedList<T>& rhs) const {
	Node* tempuno = this->head;
	Node* tempdos = rhs.head;

	for (int i = 0; i < this->numOfNode; i++) {
		if (tempdos->data != tempuno->data) {
			return false;
		}
		tempuno = tempuno->next;
		tempdos = tempdos->next;
	}
	return true;

}

template <typename T>
void LinkedList<T>::PrintForwardRecursive(const Node* node) const {
	if (node == nullptr) { // if node doesnt exist nothing is printed
		return;
	}
	else { //if there is a node it runs the recursion
		cout << node->data << endl;
		PrintForwardRecursive(node->next);
	}
}

template <typename T>
void LinkedList<T>::PrintReverseRecursive(const Node* node) const {
	if (node == nullptr) {
		return; // if node doesnt exist nothing is printed
	}
	else {//if there is a node it runs the recursion
		cout << node->data << endl;
		PrintReverseRecursive(node->prev);
	}
}

template <typename T>
bool LinkedList<T>::RemoveHead() {

	if (counter == 1) { // if there is only one value in the list
		delete head;

		tail = nullptr;
		head = nullptr;

		counter--;
		return true;
	}
	else if (counter > 1) { // if there is more then one in the list

		Node* front = tail;

		front = head->next;
		front->prev = nullptr; //assings the Node the next value then actually deltes the node then assigns the empty tail with the head and re loops

		delete head;
		head = front;
		counter--;

		return true;
	}
	return false;
}

template <typename T>
bool LinkedList<T>::RemoveTail() {

	if (counter == 1) { // if there is only one value in the list
		delete tail;

		tail = nullptr;
		head = nullptr;

		counter--;
		return true;
	}
	else if (counter > 1) { // if there is more then one in the list

		Node* back = tail;

		back = tail->prev;
		back->next = nullptr; //assings the Node the previous value then actually deltes the node then assigns the empty tail with the tail and re loops

		delete tail;
		tail = back;
		counter--;

		return true;
	}
	return false;
}

template <typename T>
unsigned int LinkedList<T>::Remove(const T& data) {
	unsigned int numNodesRemoved = 0; //creates a number for the amount of nodes being removed and how the index is being subrtacted
	Node* temp = head;
	Node* tempdos;
	unsigned int counter = 0;// makes two temp nodes to help delte the values by assigning the second one the value of the next one before delteing it

	while (temp != nullptr) {

		tempdos = temp->next;

		if (temp->data == data) {// the process of removing a node at that certain point
			RemoveAt(counter);
			numNodesRemoved++;
		}

		else {
			counter++;
		}

		temp = tempdos;
	}
	return numNodesRemoved;
}


template <typename T>
bool LinkedList<T>::RemoveAt(unsigned int index) {

	if (counter <= index) { //if the vaue they call for is greater then the value
		return false;
	}

	else if (index == (counter - 1)) {
		return RemoveTail(); // if the index is the tail function
	}

	else if (index == 0) { //if 0 its the first so just call that
		return RemoveHead();
	}

	else {
		Node* temp = head; // iterates through and finds the value to delete
		for (unsigned int i = 0; i < index; i++) {
			temp = temp->next;
		}
		if (temp->next != nullptr) //if its right before the tail sets tail qual to one before one delted
			temp->next->prev = temp->prev;
		if (temp->prev != nullptr) //if its right after the head sets head qqual to one before one delted
			temp->prev->next = temp->next;

		delete temp; //deallocate memory and deletes node
		counter--;
		return true;
	}
}

template <typename T>
void LinkedList<T>::Clear() {  //clears the whole node and deletes them all and sends the all the elements to defualt values;
	Node* temp = head;
	head = nullptr;
	tail = nullptr;
	counter = 0;
	while (temp != nullptr) {
		delete temp;
		temp = temp->next;
	}
}