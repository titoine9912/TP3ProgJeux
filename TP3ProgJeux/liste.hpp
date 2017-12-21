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
	//M�thode qui incr�mente l'it�rateur de 1
	iterator& operator++()
	{
		POINTEUR = POINTEUR->next;
		return *this;
	}
	//M�thode qui incr�mente l'it�rateur de 1
	iterator operator++(int)
	{
		Box* temp = POINTEUR;
		POINTEUR = POINTEUR->next;
		return temp;
	}

	//M�thode qui d�sincr�mente l'it�rateur de 1
	iterator& operator--()
	{
		POINTEUR = POINTEUR->previous;
		return *this;
	}
	//M�thode qui d�sincr�mente l'it�rateur de 1 
	iterator operator--(int)
	{
		Box* temp = POINTEUR;
		POINTEUR = POINTEUR->previous;
		return temp;
	}
	//M�thode qui retourne si un it�rateur est �gale � un autre
	bool operator==(const iterator&droite)const
	{
		return POINTEUR == droite.POINTEUR;
	}
	//M�thode qui retourne si un it�rateur n'est pas �gale � un autre
	bool operator!=(const iterator&droite)const
	{
		return POINTEUR != droite.POINTEUR;
	}
};



//Constructeur de la liste
template<class T>
inline Liste<T>::Liste() :avant(T()), apres(T()), sz(0)
{
	avant.next = &apres;
	apres.previous = &avant;
	sz = 0;
}

//destructeur de la liste
template<class T>
inline Liste<T>::~Liste()
{
	clear();
}

//M�thode qui interchange les contenus de deux listes
//Elle re�oit en param�tre l'autre liste
template<class T>
void Liste<T>::swap(Liste& other)
{
	std::swap(avant, other.avant);
	std::swap(sz, other.sz);
	std::swap(apres, other.apres);
}

//M�thode qui ins�re une box dans une list
//Elle re�oit en param�tre la position � laquelle on veut ins�rer et la valeur que l'on veut donner � la nouvelle box
//Elle retourne la boite suivant la place qu'on la ins�rer
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

//D�truit une box dans la liste
//Elle recoit en param�tre la position de la box que l'on veut d�truire
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

//Insert un �l�ment dans la liste
template<class T>
typename Liste<T>::iterator Liste<T>::Insert(iterator pos, const T& value)
{
	return insert(pos.POINTEUR, value);
}

//efface un �l�ment dans la liste
template<class T>
typename Liste<T>::iterator Liste<T>::erase(iterator pos)
{
	Liste<T>::iterator temp = Erase(pos.POINTEUR);
	return temp;
}

//ajoute un �l�ment � la fin de la liste
template<class T>
void Liste<T>::push_back(const T& value)
{
	insert(&apres, value);
}

//efface un �l�ment � la fin de la liste
template<class T>
void Liste<T>::pop_back()
{
	Erase(apres.previous);
}

//ajoute un �l�ment au d�but de la liste
template<class T>
void Liste<T>::push_front(const T& value)
{
	insert(avant.next, value);
}

//efface un �l�ment au d�but de la liste
template<class T>
void Liste<T>::pop_front()
{
	Erase(avant.next);
}

//Retourne la valeur du dernier �l�ment de la liste
template<class T>
T& Liste<T>::back()
{
	return apres.previous->value;
}

//Retourne la valeur du premier �l�ment de la liste
template<class T>
T& Liste<T>::front()
{
	return avant.next->value;
}

//efface la liste
template<class T>
void Liste<T>::clear()
{
	while (size() > 0)
	{
		pop_back();
	}
}

//retourne le size de la liste
template<class T>
size_t Liste<T>::size() const
{
	return sz;
}

//Retourne si la liste est vide ou non
template<class T>
bool Liste<T>::empty() const
{
	return sz == 0;
}

//retourne un it�rateur sur le d�but de la liste
template<class T>
typename Liste<T>::iterator Liste<T>::begin()
{
	return avant.next;
}

//retourne un it�rateur sur la fin de la liste
template<class T>
typename Liste<T>::iterator Liste<T>::end()
{
	return &apres;
}

//inverse les �l�ments de la liste
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

//ins�re le contenu d'une autre liste dans la liste actuelle
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