#include "list.h"


void list::coppy(const node * from_first, const node * from_last)
{
	first = nullptr;
	last = nullptr;
	node **to = &first;
	const node *from = from_first;
	while (from != from_last->next) {
		node *prev = *to;
		*to = new node;
		(*to)->prev = prev;
		(*to)->data = from->data;
		to = &(*to)->next;
		from = from->next;
	}
	*to = nullptr;
	last = *to;
}

void list::delite_list()
{
	while (first)
	{
		last = first->next;
		delete first;
		first = nullptr;
		first = last;
	}
	delete last;
	first = nullptr;
	last = nullptr;
}

list::~list()
{
	delite_list();
}

list::list(const list & l)
{
	coppy(l.first,l.last);
}

list & list::operator=(const list & l)
{
	delite_list();
	coppy(l.first, l.last);
	return *this;
}

void list::push_back(const datatype & x)
{
	if (last = nullptr)
	{
		last = new node;
		last->prev = nullptr;
		first = last;
	}
	else
	{
		last->next = new node;
		last->next->prev = last;
		last = last->next;
	}
	last->data = x;
	last->next = nullptr;
}

void list::push_front(const datatype & x)
{
	if (first = nullptr)
	{
		first = new node;
		first->prev = nullptr;
		last=first;
	}
	else
	{
		first->prev = new node;
		first->prev->next = first;
		first = first->prev;
	}
	first->data = x;
	first->prev = nullptr;
}

list::datatype list::back() const
{
	if (!last) throw std::out_of_range("Попытка доступа к элементу пустого списка");
	return last->data;
}

list::datatype list::front() const
{
	if (!first) throw std::out_of_range("Попытка доступа к элементу пустого списка");
	return first->data;
}

void list::pop_front()
{
	node *tmp = first->next;
	delete first;
	first = tmp;
	first->prev = nullptr;
}

void list::pop_back()
{
	node *tmp = last->prev;
	delete last;
	last = tmp;
	last->next = nullptr;
}

bool list::emptiness()
{
	return first==nullptr;
}

size_t list::cout_list()
{
	int i = 0;
	node *tmp = first;
	while (tmp!=nullptr)
	{
		tmp->next;
		++i;
	}
	return i;
}

list::iterator list::begin()
{
	return iterator(this, first);
}

list::iterator list::end()
{
	return iterator(this, last);
}

list::iterator list::find(const datatype & x) const
{
	node *tmp = first;
	while (tmp != nullptr)
	{
		tmp->next;
		if (tmp->data == x) break;
	}
	return iterator(this, tmp);
}

void list::insert(const iterator & it, const datatype & x)
{
	node *tmp = new node;
	tmp->data = x;
	tmp->next = it.current;
	tmp->prev = it.current->prev;
	it.current->prev->next = tmp;
	tmp->next->prev = tmp;
}

void list::remove(const iterator & it)
{
	it.current->prev->next = it.current->next;
	it.current->next->prev = it.current->prev;
	//delete it.current;
	
}

list::datatype & list::iterator::operator*()
{
	return current->data;
}

list::iterator & list::iterator::operator++()
{
	 *++current;
	 return *this;
}

list::iterator list::iterator::operator++(int)
{
	 *current++;
	 return *this;
}

bool list::iterator::operator==(const iterator & it) const
{
	return current==it.current && collection==it.collection;
}

bool list::iterator::operator!=(const iterator & it) const
{
	return !operator==(it);
}
