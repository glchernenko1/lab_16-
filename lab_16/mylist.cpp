#include "mylist.h"


void mylist::coppy(const node * from_first, const node * from_last)
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

void mylist::delite_mylist()
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

mylist::~mylist()
{
	delite_mylist();
}

mylist::mylist(const mylist & l)
{
	coppy(l.first,l.last);
}

mylist & mylist::operator=(const mylist & l)
{
	delite_mylist();
	coppy(l.first, l.last);
	return *this;
}

void mylist::push_back(const datatype & x)
{
	if (last == nullptr)
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

void mylist::push_front(const datatype & x)
{
	if (first == nullptr)
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

mylist::datatype mylist::back() const
{
	if (!last) throw std::out_of_range("Попытка доступа к элементу пустого списка");
	return last->data;
}

mylist::datatype mylist::front() const
{
	if (!first) throw std::out_of_range("Попытка доступа к элементу пустого списка");
	return first->data;
}

void mylist::pop_front()
{
	node *tmp = first->next;
	delete first;
	first = tmp;
	first->prev = nullptr;
}

void mylist::pop_back()
{
	node *tmp = last->prev;
	delete last;
	last = tmp;
	last->next = nullptr;
}

bool mylist::emptiness()
{
	return first==nullptr;
}

size_t mylist::cout_mylist()
{
	int i = 0;
	node *tmp = first;
	while (tmp!=nullptr)
	{
		tmp=tmp->next;
		++i;
	}
	return i;
}

mylist::iterator mylist::begin()
{
	return iterator(this, first);
}

mylist::iterator mylist::end()
{
	return iterator(this, last->next);
}

mylist::iterator mylist::find(const datatype & x) const
{
	node *tmp = first;
	while (tmp != nullptr)
	{
		tmp->next;
		if (tmp->data == x) break;
	}
	return iterator(this, tmp);
}

void mylist::insert(const iterator & it, const datatype & x)
{
	node *tmp = new node;
	tmp->data = x;
	tmp->next = it.current;
	tmp->prev = it.current->prev;
	it.current->prev->next = tmp;
	tmp->next->prev = tmp;
}

void mylist::remove(const iterator & it)
{
	it.current->prev->next = it.current->next;
	it.current->next->prev = it.current->prev;
	delete it.current;
	
}

mylist::datatype & mylist::iterator::operator*()
{
	return current->data;
}

mylist::iterator & mylist::iterator::operator++()
{
	 current=current->next;
	 return *this;
}

mylist::iterator mylist::iterator::operator++(int)
{
	current = current->next;
	 return *this;
}

mylist::iterator & mylist::iterator::operator--()
{
	current = current->prev;
	return *this;
}

mylist::iterator mylist::iterator::operator--(int)
{
	current = current->prev;
	return *this;
}

bool mylist::iterator::operator==(const iterator & it) const
{
	return current==it.current && collection==it.collection;
}

bool mylist::iterator::operator!=(const iterator & it) const
{
	return !operator==(it);
}


std::istream & operator>>(std::istream & is, mylist & l)
{	
	mylist::datatype a;
	size_t t;
	is >> t;
	for (int i = 0; i < t; ++i)
	{
		
		
		is >> a;
		l.push_back(a);
	}
	return is;
}

std::ostream &operator<<(std::ostream &os, mylist &l)
{
	os << l.cout_mylist() << " ";
	for (mylist::iterator i = l.begin(); i != l.end(); ++i) {
		os << *i << " ";
	}
	return os;
}


void mylist::  sort()
{
	
	iterator prev=begin();
	for (; prev.current->next != nullptr; ++prev);
	for (iterator i = begin(); i!= end(); ++i)
	{
		for (iterator r = begin(); r != prev; ++r)
		{
			
			if (*r <r.current->next->data)
			{
				std::swap(*r, r.current->next->data);
				
			}
		}
		
	}
}