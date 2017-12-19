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

template<class T>
Pile<T>::Pile()
{

}

template<class T>
Pile<T>::~Pile()
{
	container.clear();
}

template<class T>
const T& Pile<T>::Top()const
{
	return container.back();
}

template<class T>
void Pile<T>::Push(const T& valeur)
{
	container.push_back(valeur);
}

template<class T>
T Pile<T>::Pop()
{
	T save = container.back();
	container.pop_back();
	return save;
}

template<class T>
bool Pile<T>::isEmpty()
{
	return container.empty();
}

template<class T>
size_t Pile<T>::Size()
{
	return container.size();
}