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

template<class T>
Box* Liste<T>::erase(Box* iterator)
{
	
}

template<class T>
Liste<T>::iterator Liste<T>::Insert(iterator pos, const T& value)
{
	insert(pos, value);
}

template<class T>
Liste<T>::iterator Liste<T>::erase(iterator pos)
{

}

template<class T>
void Liste<T>::push_back(const T& value)
{
	insert(apres, value);
}

template<class T>
void Liste<T>::pop_back()
{

}

template<class T>
void Liste<T>::push_front(const T& value)
{
	insert(avant, value);
}

template<class T>
void Liste<T>::pop_front()
{

}

template<class T>
T& Liste<T>::back()
{
	return apres;
}

template<class T>
T& Liste<T>::front()
{
	return avant;
}

template<class T>
void Liste<T>::clear()
{
	avant = nullptr;
	apres = nullptr;
	sz = 0;
}

template<class T>
size_t Liste<T>::size() const
{
	return sz;
}

template<class T>
bool Liste<T>::empty() const
{
	return sz == 0;
}

template<class T>
Liste<T>::iterator Liste<T>::begin()
{
	front();
}

template<class T>
Liste<T>::iterator Liste<T>::end()
{
	back();
}