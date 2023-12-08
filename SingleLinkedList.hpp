///default constructor for List class
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

/////////////////////////////////////////////////////////////
////////////////--CAPACITY--/////////////////////////////////


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

/////////////////////////////////////////////////////////////
////////////////--MODIFIERS--////////////////////////////////

//changes List size(default fills with 0)
template <typename T>
void List<T>::resize(size_t new_size, T value)
{
	if (!new_size) {
		this->clear();
	} else if (new_size == this->m_size) {
		return;
	} 

	if (new_size > this->m_size) {
		if (!head) {
			head = new Node (value);
			Node* tmp = head;

			for (size_t i = 1; i < new_size; ++i) {
				tmp->next = new Node (value);
				tmp = tmp->next;
			}
		} else {
			Node* tmp = head;
			for (size_t i = 1; i < this->m_size; ++i) {
				tmp = tmp->next;		
			}

			for (size_t i = 1; i < new_size; ++i) {
				tmp->next = new Node (value);
				tmp = tmp->next;
			}
		}
	} else {
		Node* tmp = head;

		for (size_t i = 1; i < new_size; ++i) {
			tmp = tmp->next;
		}
 
		Node* erasable = nullptr;
		for (size_t i = new_size; i < this->m_size; ++i) {
			erasable = tmp->next;
			tmp->next = erasable->next;
			delete erasable;
		}
	}

	this->m_size = new_size;
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

//inserts the element (or elements) at the given position
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

template <typename T>
void List<T>::insert(size_t position, size_t count, T value) 
{
	if (count == 0) {
		return;
	} 

	if (!head) {
		if (!position) {
			head = new Node (value);
			Node* tmp = head;

			for (size_t i = 1; i < count; ++i) {
				tmp->next = new Node(value);
				tmp = tmp->next;	
			}
		} else {
			std::cout << "Segmentation fault" << std::endl;
			exit(0);
		}
	} else if (position >= this->m_size) {
		std::cout << "Segmentation fault" << std::endl;
		exit(0);
	} else if (position == 0) {
		Node* right = head;
		head = new Node (value);
		Node* left = head;

		for (size_t i = 1; i < count; ++i) {
			left->next = new Node (value);
			left = left->next;
		}

		left->next = right;
	} else {
		Node* right = head;
		Node* left = nullptr;

		for (size_t i = 1; i < position; ++i) {
			right = right->next;
		}

		left = right->next;

		for (size_t i = 0; i < count; ++i) {
			right->next = new Node (value);
			right = right->next;
		}

		right->next = left;
	}

	this->m_size += count;
}
//erases the element at the given position
template <typename T>
void List<T>::erase(size_t position) 
{
	if (!head) {
		std::cout << "Out of range" << std::endl;
		exit(0);
	} else if (position >= this->m_size) {
		std::cout << "Segmentation fault" << std::endl;
		exit(0);
	} else if (position == 0) {
		this->pop_front();
	} else if (position == this->m_size - 1) {
		this->pop_back();
	} else {
		Node* tmp = head;
		for (size_t i = 1; i < position; ++i) {
			tmp = tmp->next;	
		}
	
		Node* deleted = tmp->next;
		tmp->next = deleted->next;
		delete deleted;
	}

	--this->m_size;
}

template <typename T>
void List<T>::erase(size_t first, size_t last)
{
	if (!head) {
		std::cout << "Segmentation fault" << std::endl;
		exit(0);
	} else if (first > last || first >= this->m_size || last >= this->m_size) {	
		std::cout << "Out of range" << std::endl;
		exit(0);
	} else if (first == 0 && last == this->m_size - 1) {
		this->clear();
	} else if (first == last) {
		this->erase(first);
	}

	if (first == 0) {
		Node* tmp = nullptr;
		for(size_t i = first; i <= last; ++i) {
			tmp = head->next;
			delete head;
			head = tmp;
		}
	} else {
		Node* left = head;
		for(size_t i = 1; i < first; ++i) {
			left = left->next;
		}

		Node* erasable = left->next;
		Node* right = nullptr;

		for(size_t i = first; i <= last; ++i) {
			right = erasable->next;
			delete erasable;
			erasable = right;
		}

		if (last == this->m_size - 1) {
			left->next = nullptr;
		} else {
			left->next = right;
		}
	}

	this->m_size -= last - first + 1;
}

//swaps the contents of 2 list
template<typename T>
void List<T>::swap(List<T>& other)
{
	if (this->head != other.head) {
		std::swap(this->head, other.head);
		std::swap(this->m_size, other.m_size);
	}
}

/////////////////////////////////////////////////////////////
//////////////////--ACCESS--/////////////////////////////////

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

/////////////////////////////////////////////////////////////
//////////////////--OPERATIONS--/////////////////////////////

//moves elements from another list
template <typename T>
void List<T>::splice(size_t position, List<T>& other)
{
	if (!head) {
		if (!position) {
			head = other.head;
		} else {
			std::cout << "Segmentation fault" << std::endl;
			exit(0);
		}
	} else if (position >= this->m_size) {
		std::cout << "Out of range" << std::endl;
		exit(0);
	}else if (position == 0) {
		Node* tmp = other.head;
		for (size_t i = 1; i < other.m_size; ++i) {
			other.head = other.head->next;
		}

		other.head->next = this->head;
		this->head = tmp;
	} else {
		Node* left = this->head;
		Node* right = nullptr;

		for (size_t i = 1; i < position; ++i) {
			left = left->next;
		}

		right = left->next;
		left->next = other.head;

		for (size_t i = 1; i < other.m_size; ++i) {
			other.head = other.head->next;
		}

		other.head->next = right;
	}

	this->m_size += other.m_size;
	other.head = nullptr;
	other.m_size = 0; 
}

//reverses the order of the elements in the container
template <typename T>
void List<T>::reverse()
{
	if (this->m_size < 2) {
		return;
	}

	Node* tmp = nullptr;

	tmp = head;
	head = head->next;
	Node* next_node = head->next;
	head->next = tmp;	
	tmp->next = nullptr;

	for (size_t i = 2; i < this->m_size; ++i) {
		tmp = head;
		head = next_node;
		next_node = head->next;
		head->next = tmp;	
	}
}

//removes all consecutive duplicate elements from the container
template <typename T>
void List<T>::unique()
{
	if (this->m_size < 2) {
		return;
	}

	Node* u_ptr = head;
	Node* tmp = head->next;
	T unique = head->m_value;

	while (tmp->next) {
		if (tmp->m_value == unique) {
			u_ptr->next = tmp->next;
			delete tmp;
			--this->m_size;
		} else {
			unique = tmp->m_value;
			u_ptr = tmp;
		}

		tmp = u_ptr->next;
	}

	if (tmp->m_value == unique) {
		delete tmp;
		u_ptr = nullptr;
		--this->m_size;
	}
}

