#pragma once

template <class T>
class File
{
public:
	using size_type = unsigned long;
	File();
	~File();
	void PushBack(const T& valeur);
	void PushFront(const T& valeur);
	void pop_back();
	void pop_front();
	const T& front();
	const T& back();
	T& at(size_type index);
	bool isEmpty();
	size_t Size();
	void resize(size_type newSize);
	void clear();
	void reserve(size_type new_cap);
	size_t capacity() const;

private:
	T *tab;
	int head;
	size_type nbElem;
	size_type cap;
};

//Constructeur de la file
template<class T>
File<T>::File()	
{
	tab = nullptr;
	nbElem = 0;
	cap = 0;
	head = 0;
}

//Destructeur de la file
template<class T>
File<T>::~File()
{
	clear();
}

//M�thode PushBack de la file, elle permet d'ajouter des �l�ments � la fin de celle-ci
//Elle prends en param�tre la valeur que l'on veut ajouter � la file
template<class T>
void File<T>::PushBack(const T& valeur)
{
	if (nbElem == cap)
		reserve(2 * cap + 1);
	
	nbElem++;
	tab[(head + nbElem-1) % cap] = valeur;
	
}

//M�thode PushFront de la file, elle permet d'ajouter des �l�ments au d�but de la file
//Elle prends en param�tre la valeur que l'on veut ajouter � la file
template<class T>
void File<T>::PushFront(const T& valeur)
{
	if (nbElem == cap)
	{
		reserve(2 * cap + 1);
	}
	if (head <= 0)
	{
		head = cap;
	}
	head = head - 1;
	nbElem++;	
	tab[head] = valeur;
}

//M�thode popback de la file qui permet d'enlever un �l�ment � la fin de la file
template<class T>
void File<T>::pop_back()
{
	nbElem--;
	tab[nbElem] = T();
}

//M�thode popfront de la file qui permet d'enlever un �l�ment au d�but de la file
template<class T>
void File<T>::pop_front()
{
	nbElem--;
	tab[head] = T();
	head = (head + 1)%cap;

	//head = tab[head + 1];

	
}

//M�thode front qui retourne l'�l�ment au d�but de la file
template<class T>
const T& File<T>::front()
{
	return tab[head];
}

//M�thode back qui retourne l'�l�ment � la fin de la file
template<class T>
const T& File<T>::back()
{
	return tab[(head+nbElem-1)%cap];
}

//M�thode at qui retourne l'�l�ment � l'index pass� en param�tre
template<class T>
T& File<T>::at(size_type index)
{
	return tab[(head + index)%cap];
}

//M�thode isEmpty qui retourne si la file est vide ou non
template<class T>
bool File<T>::isEmpty()
{
	return nbElem == 0;
}

//M�thode qui retourne le size de la file
template<class T>
size_t File<T>::Size()
{
	return nbElem;
}

//M�thode qui change le size de la file
template<class T>
void File<T>::resize(size_type new_size)
{
	reserve(new_size);

	for (size_type i = new_size - 1; i < nbElem; ++i)
		tab[i] = T();

	nbElem = new_size;
}

//M�thode qui d�truit les �l�ments de la file
template<class T>
void File<T>::clear()
{
	nbElem = 0;
	cap = 0;
	delete[] tab;
	tab = nullptr;
}

//M�thode qui augmente la capacit� de la file
template<class T>
void File<T>::reserve(size_type new_cap)
{
	if (cap < new_cap)
	{
		auto tmp = tab;
		tab = new T[new_cap];

		size_type i = 0;

		for (; i < nbElem; ++i)
			tab[i] = tmp[(head+i)%cap];

		for (; i < new_cap; ++i)
			tab[i] = T();

		cap = new_cap;
		head = 0;
		delete[] tmp;
	}
}

//M�thode qui retourne la capacit� de la file
template<class T>
size_t File<T>::capacity() const
{
	return cap;
}
