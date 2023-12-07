template <typename T>
class List {
public:
	size_t m_size;

	class Node {
	public:
		T m_value;
		Node* next;

//	parametrized constructor
		Node(T value);
	};
//default constructor
	List();
//destructor
	~List();
//return list size
	size_t size();
//checks whether the container is empty
	bool empty();
//clear the contents
	void clear();
//adds new element at the end
	void push_back(T value);
//adds new element to the beggining
	void push_front(T value);
//removes last element
	void pop_back();
//removes the first element
	void pop_front();
//insert the element at the given position
	void insert(size_t position, T value);
//access to the first element
	T& front();
//access to the last element
	T& back();
	
//constructors
//
//default constructor
//copy constructor
//move constructor

private:
	Node* head;
};

#include "SingleLinkedList.hpp"
