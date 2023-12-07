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
	if (head) {
		Node* tmp = head;
		while (head->next) {
			head = head->next;
			delete tmp;
			tmp = head;
		}
		delete head;
		head = nullptr;
	}
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

//checks whether the contaoner is empty
template <typename T>
bool List<T>::empty()
{
	return this->m_size;
}

//clears the contents
template <typename T>
void List<T>::clear()
{
	if (!head) {
		return;
	}

	Node* tmp = head;

	while (tmp->next) {
		tmp = tmp->next;
		delete tmp;
	}
	delete tmp->next;

	head = nullptr;
	this->m_size = 0;
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
			tmp = tmp->next;
		}

		tmp->next = new Node (value);
	}

	++this->m_size;
}

//adds new element to the beggining
template <typename T>
void List<T>::push_front(T value)
{
	if (head) {
		Node* tmp = head;
		head = new Node (value);
		head->next = tmp;
	} else {
		head = new Node (value);
	}

	++this->m_size;
}

//removes last element of the list
template <typename T>
void List<T>::pop_back()
{
	if (head) {
		if (!this->m_size) {
			delete head;
			head = nullptr;
		} else {
			Node* tmp = head;
		
			for (size_t i = 2; i < m_size; ++i) {
				tmp = tmp->next;
			}

			delete tmp->next;
			tmp->next = nullptr;
		}

		--this->m_size;
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
		Node* tmp = head->next;
		delete head;
		head = tmp;
	
		--this->m_size;
	} else {
		std::cout << "Out of range" << std::endl;
		exit(0);
	}
}

//inserts the element at the given position
template <typename T>
void List<T>::insert(size_t position, T value) 
{
	if (!this->head || !this->m_size) {
		if (position == 0) {
			head = new Node (value);
		} else {
			std::cout << "Segmentation fault" << std::endl;
			exit(0);
		}
	} else if (position >= this->m_size) {
		std::cout << "Segmentation fault" << std::endl;
		exit(0);
	} else if (position == 0) {
		Node* tmp = head;
		head = new Node (value);
		head->next = tmp;
	} else {
		Node* tmp = head; 
		for (size_t i = 1; i < position; ++i) {
			tmp = tmp->next;
		}

		Node* new_node = new Node (value);
		new_node->next = tmp->next;
		tmp->next = new_node;
	}

	++this->m_size;
}
//access to the first element
template <typename T>
T& List<T>::front()
{
	if (!head) {
		std::cout << "Out of range" << std::endl;
		exit(0);
	} 
	
	return head->m_value;
}

//access to the last element
template <typename T>
T& List<T>::back()
{
	if (!head) {
		std::cout << "Out of range" << std::endl;
		exit(0);
	} 

	Node* tmp = head;
	while (tmp->next) {
		tmp = tmp->next;
	}
	
	return tmp->m_value;
}
