#pragma once
#include <algorithm> 

template <class T>
class Liste
{
	struct Box
	{
		T value;
		Box *next, *previous;
		Box(const T& value, Box*N = nullptr, Box*P = nullptr) {}
		~Box() { previous = next = nullptr; }
	};

	Liste(const Liste&) = delete;

	Box avant;
	Box apres;
	size_t sz;

	Box* insert(Box* iterator, const T& value);
	Box* erase(Box* iterator);

public:
	class iterator;
	Liste();
	~Liste();
	Liste(const Liste& other);
	Liste& operator=(const Liste& other);
	void swap(Liste& other);

	iterator Insert(iterator pos, const T& value);
	iterator erase(iterator pos);

	void push_back(const T&);
	void pop_back();
	void push_front(const T&);
	void pop_front();

	T& back();
	T& front();

	void clear();
	size_t size()const;
	bool empty()const;

	iterator begin();
	iterator end();

	void reverse();
	void splice(iterator pos, Liste& other);
};

template <typename T>
class Liste<T>::iterator
{
	friend class Liste<T>;
private:
	Box* POINTEUR;
public:
	iterator(Box*value=nullptr) :POINTEUR(value) {}

	T& operator*()const
	{
		return &POINTEUR;
	}

	T* operator->()const { return &(POINTEUR->CONTENU); }

	iterator& operator++()
	{
		++POINTEUR;
		return &POINTEUR;
	}
	
	iterator operator++(int)
	{
		POINTEUR++;
		return POINTEUR;
	}

	iterator& operator--()
	{
		--POINTEUR;
		return &POINTEUR;
	}

	iterator operator--(int)
	{
		POINTEUR--;
		return POINTEUR;
	}

	bool operator==(const iterator&droite)const
	{
		return POINTEUR == droite.POINTEUR;
	}

	bool operator!=(const iterator&droite)const
	{
		return POINTEUR != droite.POINTEUR;
	}
};




template<class T>
inline Liste<T>::Liste()
{
	first->next = last;
	last->previous = first;
	sz = 0;
}

template<class T>
inline Liste<T>::~Liste()
{

}

template<class T>
inline Liste<T>::Liste(const Liste&)
{
	*this = other;
}

template<class T>
void Liste<T>::swap(Liste& other)
{
	std::swap(avant, other.avant);
	std::swap(sz, other.sz);
	std::swap(apres, other.apres);
}

template<class T>
Box* Liste<T>::insert(Box* iterator, const T& value)
{
	iterator->previous->next = iterator->previous = new Box(value, iterator->previous->suivant, iterator->previous);
	return iterator->previous;
}
//template<class T>
//inline void Liste<T>::Insert(Box* iterator, T value)
//{
//	if (iterator->next != nullptr && iterator->previous == nullptr)
//	{
//		iterator = new Box(value, iterator->next);
//	}

//	else if (iterator->next != nullptr)
//	{
//		iterator = new Box(value, iterator->previous,iterator->next);
//		//iterator = iterator->next;
//	}
//	else if (iterator->next == nullptr)
//	{
//		iterator = new Box(value, iterator->previous);
//		last = iterator->next;
//	}
//	else
//	{
//		iterator = last = first = new Box(value, nullptr);
//	}

//	sz++;
	
//}