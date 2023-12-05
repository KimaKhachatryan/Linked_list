//default constructor for List class
template <typename T> 
List<T>::List()
{
	head = nullptr;
	m_size = 0;
}

//destructor
template <typename T>
List<T>::~List()
{
	Node* tmp = head;
	while (tmp->next) {
		tmp = tmp->next;
		delete tmp;
	}
	delete tmp->next;
	head = nullptr;
}

//parametrized constructor for Node class
template <typename T>
List<T>::Node::Node(T value)
{
	m_value = value;
	next = nullptr;
}

//returns List size
template <typename T>
size_t List<T>::size()
{
	return m_size;
}

//adds new element at the end
template <typename T>
void List<T>::push_back(T value)
{
	if (!head) {
		head = new Node (value);
	} else {
		Node* tmp = head;
		while (tmp->next) {
			tmp= tmp->next;
		}

		tmp->next = new Node (value);
	}
}

//adds new element to the beggining
template <typename T>
void List<T>::push_front(T value)
{
	Node* tmp = head;
	head = new Node (value);
	head->next = tmp;
}

//removes last element of the list
template <typename T>
void List<T>::pop_back()
{
	if (head) {
		Node* tmp = head;
		while (tmp->next) {
			tmp = tmp->next;
		}

		delete tmp;
	} else {
		std::cout << "Out of range" << std::endl;
		exit(0);
	}
}

//removes the first element
template <typename T>
void List<T>::pop_front()
{
	if (head) {
		Node* tmp = head-next;
		delete head;
		head = tmp;
	} else {
		std::cout << "Out of range" << std::endl;
		exit(0);
	}

