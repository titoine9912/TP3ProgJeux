#pragma once
#include <algorithm> 
#include <string.h>
template <class T>
class Liste
{
private:
	Liste(const Liste&) = delete;

	struct Box
	{
		T value;
		Box *next, *previous;
		Box(const T& value, Box*N = nullptr, Box*P = nullptr) :value(value), next(N), previous(P) {}
		~Box() { previous = next = nullptr; }
	};

	Box avant;
	Box apres;
	size_t sz;

	Box* insert(Box* iterator, const T& value);
	Box* Erase(Box* iterator);

public:
	class iterator;
	Liste();
	~Liste();
	//	Liste(const Liste& other);
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

template <class T>
class Liste<T>::iterator
{
	friend class Liste<T>;
private:
	Box* POINTEUR;
public:
	iterator(Box*value = nullptr) :POINTEUR(value) {}

	T& operator*()const
	{
		return POINTEUR->value;
	}

	T* operator->()const { return &(POINTEUR->value); }

	iterator& operator++()
	{
		POINTEUR = POINTEUR->next;
		return *this;
	}

	iterator operator++(int)
	{
		Box* temp = POINTEUR;
		POINTEUR = POINTEUR->next;
		return temp;
	}

	iterator& operator--()
	{
		POINTEUR = POINTEUR->previous;
		return *this;
	}

	iterator operator--(int)
	{
		Box* temp = POINTEUR;
		POINTEUR = POINTEUR->previous;
		return temp;
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
inline Liste<T>::Liste() :avant(T()), apres(T()), sz(0)
{
	avant.next = &apres;
	apres.previous = &avant;
	sz = 0;
}

template<class T>
inline Liste<T>::~Liste()
{
	clear();
}

//template<class T>
//inline Liste<T>::Liste(const Liste&)
//{
//	*this = other;
//}

template<class T>
void Liste<T>::swap(Liste& other)
{
	std::swap(avant, other.avant);
	std::swap(sz, other.sz);
	std::swap(apres, other.apres);
}

template<class T>
typename Liste<T>::Box * Liste<T>::insert(Box * iterator, const T & value)
{
	//iterator->previous->next = (iterator->previous = new Box(value, iterator->previous->next, iterator->previous));
	Box* temp = new Box(value, iterator->previous->next, iterator->previous);
	iterator->previous->next = temp;
	iterator->previous = temp;

	sz++;
	return iterator->previous;
}

template<class T>
typename Liste<T>::Box * Liste<T>::Erase(Box * iterator)
{
	Box* temp = iterator->next;
	iterator->previous->next = iterator->next;
	iterator->next->previous = iterator->previous;
	delete iterator;
	sz--;

	return temp;
}

template<class T>
typename Liste<T>::iterator Liste<T>::Insert(iterator pos, const T& value)
{
	return insert(pos.POINTEUR, value);
}

template<class T>
typename Liste<T>::iterator Liste<T>::erase(iterator pos)
{
	Liste<T>::iterator temp = Erase(pos.POINTEUR);
	return temp;
}

template<class T>
void Liste<T>::push_back(const T& value)
{
	insert(&apres, value);
}

template<class T>
void Liste<T>::pop_back()
{
	Erase(apres.previous);
}

template<class T>
void Liste<T>::push_front(const T& value)
{
	insert(avant.next, value);
}

template<class T>
void Liste<T>::pop_front()
{
	Erase(avant.next);
}

template<class T>
T& Liste<T>::back()
{
	return apres.previous->value;
}

template<class T>
T& Liste<T>::front()
{
	return avant.next->value;
}

template<class T>
void Liste<T>::clear()
{
	while (size() > 0)
	{
		pop_back();
	}
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
typename Liste<T>::iterator Liste<T>::begin()
{
	return avant.next;
}

template<class T>
typename Liste<T>::iterator Liste<T>::end()
{
	return &apres;
}

template<class T>
void Liste<T>::reverse()
{
	avant = apres;
	apres = avant;
	if (sz % 2 == 0)
	{
		for (int i = 1; i < sz / 2; i++)
		{
			avant->next = apres->previous;
		}
	}
}

template<class T>
void Liste<T>::splice(iterator pos, Liste& other)
{
	other.end() = pos;
	other.begin() = pos.POINTEUR->previous;
	pos.POINTEUR->previous = other.begin().POINTEUR;
	pos.POINTEUR->next = other.end().POINTEUR->previous;
	other.avant = apres;
	other.apres = avant;

}