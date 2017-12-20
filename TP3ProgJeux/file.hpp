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

//Méthode PushBack de la file, elle permet d'ajouter des éléments à la fin de celle-ci
//Elle prends en paramètre la valeur que l'on veut ajouter à la file
template<class T>
void File<T>::PushBack(const T& valeur)
{
	if (nbElem == cap)
		reserve(2 * cap + 1);
	
	nbElem++;
	tab[(head + nbElem-1) % cap] = valeur;
	
}

//Méthode PushFront de la file, elle permet d'ajouter des éléments au début de la file
//Elle prends en paramètre la valeur que l'on veut ajouter à la file
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

//Méthode popback de la file qui permet d'enlever un élément à la fin de la file
template<class T>
void File<T>::pop_back()
{
	nbElem--;
	tab[nbElem] = T();
}

//Méthode popfront de la file qui permet d'enlever un élément au début de la file
template<class T>
void File<T>::pop_front()
{
	nbElem--;
	tab[head] = T();
	head = (head + 1)%cap;

	//head = tab[head + 1];

	
}

//Méthode front qui retourne l'élément au début de la file
template<class T>
const T& File<T>::front()
{
	return tab[head];
}

//Méthode back qui retourne l'élément à la fin de la file
template<class T>
const T& File<T>::back()
{
	return tab[(head+nbElem-1)%cap];
}

//Méthode at qui retourne l'élément à l'index passé en paramètre
template<class T>
T& File<T>::at(size_type index)
{
	return tab[(head + index)%cap];
}

//Méthode isEmpty qui retourne si la file est vide ou non
template<class T>
bool File<T>::isEmpty()
{
	return nbElem == 0;
}

//Méthode qui retourne le size de la file
template<class T>
size_t File<T>::Size()
{
	return nbElem;
}

//Méthode qui change le size de la file
template<class T>
void File<T>::resize(size_type new_size)
{
	reserve(new_size);

	for (size_type i = new_size - 1; i < nbElem; ++i)
		tab[i] = T();

	nbElem = new_size;
}

//Méthode qui détruit les éléments de la file
template<class T>
void File<T>::clear()
{
	nbElem = 0;
	cap = 0;
	delete[] tab;
	tab = nullptr;
}

//Méthode qui augmente la capacité de la file
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

//Méthode qui retourne la capacité de la file
template<class T>
size_t File<T>::capacity() const
{
	return cap;
}
