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

//-----constructors-----
//default constructor
	List();

//copy constructor
//move constructor

//destructor
	~List();

//-----capacity-----
//return list size
	size_t size();
//checks whether the container is empty
	bool empty();

//-----modifiers-----
//clears the contents
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
	void insert(size_t position, size_t count, T value);
//erases the element at the given position
	void erase(size_t position);
	void erase(size_t first, size_t last);
//chenges List size
	void resize(size_t new_size, T value = 0);
//changes the contents of 2 list
	void swap(List<T>& other);

//-----element access-----
//access to the first element
	T& front();
//access to the last element
	T& back();

//-----operations-----
//moves elements from another list
	void splice(size_t position, List<T>& other);
//reverses the order of the elements in the container
	void reverse();
//removes all consecutive duplicate elements from the container
	void unique();


private:
	Node* head;
};

#include "SingleLinkedList.hpp"
