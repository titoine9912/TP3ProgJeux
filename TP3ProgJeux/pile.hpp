#pragma once
#include <vector>

template <class T>
class Pile
{
public:
	using size_type = unsigned long;
	Pile();
	~Pile();
	const T& Top() const;
	void Push(const T& valeur);
	T Pop();
	bool isEmpty();
	size_t Size();
private:
	Pile(const Pile&) = delete;
	std::vector<T> container;
};

//Constructeur de la classe Pile
template<class T>
Pile<T>::Pile()
{

}

//Destructeur de la classe Pile
template<class T>
Pile<T>::~Pile()
{
	container.clear();
}

//Méthode qui retourne l'élément sur le dessus de la pile
template<class T>
const T& Pile<T>::Top()const
{
	return container.back();
}

//Méthode qui ajoute un élément sur le dessus de la pile
template<class T>
void Pile<T>::Push(const T& valeur)
{
	container.push_back(valeur);
}

//Méthode qui enlève un élément sur le dessus de la pile
template<class T>
T Pile<T>::Pop()
{
	T save = container.back();
	container.pop_back();
	return save;
}

//Méthode qui retourne si la pile est vide ou non
template<class T>
bool Pile<T>::isEmpty()
{
	return container.empty();
}

//Méthode qui retourne le size de la pile
template<class T>
size_t Pile<T>::Size()
{
	return container.size();
}