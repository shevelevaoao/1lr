#include <iostream>
using namespace std;

template<typename T>
class List
{
public:
	List();
	~List();
	void pop_front();
	void push_back(T data);
	void clear();
	int GetSize() { return Size; }
	T& operator[](const int index);
	void push_front(T data);
	void insert(T data, int index);
	void removeAt(int index);
	void pop_back();
	void changeAt(int index, T data);
	void is_empty();
void change_2_elems(int first_index, int second_index);
private:


	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<T>* head;
};


template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}


template<typename T>
List<T>::~List()
{
	clear();
}


template<typename T>
void List<T>::pop_front()
{
	Node<T>* temp = head;

	head = head->pNext;

	delete temp;

	Size--;

}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);

	}

	Size++;
}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}


template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;

	Node<T>* current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::insert(T data, int index)
{

	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* newNode = new Node<T>(data, previous->pNext);

		previous->pNext = newNode;

		Size++;
	}





}

template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}


		Node<T>* toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;

		Size--;
	}

}

template<typename T>
void List<T>::pop_back()
{
	removeAt(Size - 1);
}

template<typename T>
void List<T>::changeAt(int index, T data)
{
	if (index <= 0)
		push_front(data);
	else
	{
		Node<T>* current = this->head;
		for (int i = 0; i < index - 1; i++)
			current = current->pNext;
		current->data = data;
	}
}

template<typename T>
void List<T>::is_empty()
{
	if (!this->GetSize())
		cout << "Список пуст" << endl;
	else
		cout << "Список не пуст" << endl;
}

template<typename T>
void List<T>::change_2_elems(int first_index, int second_index)
{
	if (first_index == second_index || this->GetSize() < 2)
	{
		return;
	}
	Node<T>* elem_a = new Node<T>;
	Node<T>* prev_elem_a = this->head;
	Node<T>* elem_b = new Node<T>;
	Node<T>* prev_elem_b = this->head;
	Node<T>* temp = new Node<T>;

	int counter = 0;
	if (first_index > second_index)
	{
		int temp = first_index;
		first_index = second_index;
		second_index = temp;
	}



	for (int i = 1; i < first_index; i++)
	{
		prev_elem_a = prev_elem_a->pNext;
	}
	elem_a = prev_elem_a->pNext;
	if (first_index < 1)
	{
		elem_a = prev_elem_a;
	}
	for (int i = 1; i < second_index; i++)
	{
		prev_elem_b = prev_elem_b->pNext;
	}
	elem_b = prev_elem_b->pNext;

	if (first_index < 1)
	{
		this->head = elem_b;
	}
	else
	{
		prev_elem_a->pNext = elem_b;
	}
	prev_elem_b->pNext = elem_a;//
	temp = elem_a->pNext;
	elem_a->pNext = elem_b->pNext;
	elem_b->pNext = temp;
}



int main()
{

	setlocale(LC_ALL, "ru");

	List<int> list;
	int length, index_1, index_2, elem;

	cout << "Введите размер списка: ";
	cin >> length;
	cout << "Введите значения элементов" << endl;
	for (int i = 0; i < length; i++)
	{
		cin >> elem;
		list.push_back(elem);
	}
	cout << "введите индекс первого элемента: ";
	cin >> index_1;
	cout << "введите индекс второго элемента: ";
	cin >> index_2;
	list.change_2_elems(index_1, index_2);
	cout << "Изменённый список" << endl;
	for (int i = 0; i < length; i++)
	{
		cout << i << " -> " << list[i] << endl;
	}
	return 0;
}