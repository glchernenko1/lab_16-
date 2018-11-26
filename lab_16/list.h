#pragma once
#include <iostream>
class list
{
private:
	typedef int datatype;

	struct node 
	{
		datatype data;
		node *prev, *next;
	};

	node *first, *last;

	void coppy(const node * from_first, const node * from_last);
	void delite_list();

public:
	list() :first(nullptr), last(nullptr) {};
	~list();
	list(const list &l);
	list &operator=(const list &l);
	// Добавление элемента в конец
	void push_back(const datatype &x);
	// Добавление элемента в начало
	void push_front(const datatype &x);
	// Получение последнего элемента
	datatype back() const;
	datatype front() const;
	void pop_front();
	void pop_back();
	bool emptiness();
	size_t cout_list();




	class iterator {

		// Указатель на узел списка
		node *current;

		// Указатель на список
		const list *collection;

		// Закрытый конструктор
		// доступен только в дружественных классах 
		iterator(const list *collection, node *current);
	public:
		// Разименование
		datatype &operator*();

		// Инкремент (префиксный)
		iterator &operator++();
		// Инкремент (постфиксный)
		iterator operator++(int);

		// Сравнение на равенство
		bool operator==(const iterator &it) const;
		// Сравнение на неравенство
		bool operator!=(const iterator &it) const;

		// Объявляем класс, 
		// которому можно создавать итераторы
		friend class list;
	};

	iterator begin();
	// Получение итератора за концом списка
	iterator end();

	// Поиск элемента с заданным значением в списке
	// и возвращение итератора, указывающего на него.
	// В случае, если элемент с заданным значением не найден,
	// Возвращается итератор list::end()
	iterator find(const datatype &x) const;

	// Вставка элемента, перед элементом на который указывает итератор
	void insert(const iterator &it, const datatype &x);

	// Удаление элемента на который указывает итератор
	void remove(const iterator &it);



};

