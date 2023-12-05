template <typename T>
class List {
public:
	size_t m_size;

	class Node {
		T m_value;
		Node* next;

//	parametrized constructor
		Node(T value);
//	destructor
		~Node();
	};

//adds new element at the end
	void push_back(T value);
//adds new element to the beggining
	void push_front(T value);
//removes last element
	void pop_back();
//removes the first element
	void pop_front();
	
//constructors
//
//default constructor
//copy constructor
//move constructor

private:
	Node* head;
};
