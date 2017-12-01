#pragma once
template <class T>
class Liste
{
	struct Box
	{
		T value;
		Box* next;
		Box* previous;
		Box(const T& value, Box* next) :value(value), next(next) {}
		Box(const T& value, Box* previous) :value(value), previous(previous){}
	};

	Liste(const Liste&) = delete;

	Box *first, *last;
	size_t sz;

public:
	Liste();
	~Liste();
	void Insert(Box* iterator, T valeur);

	T& front();
	T& back();
	const T& front() const;
	const T& back() const;

	bool empty() const;
	size_t size() const;
};

template<class T>
inline Liste<T>::Liste()
{
	first = nullptr;
	last = nullptr;
	sz = 0;
}

template<class T>
inline Liste<T>::~Liste()
{

}

template<class T>
inline void Liste<T>::Insert(Box* iterator, T value)
{
	if (iterator->next != nullptr)
	{
		iterator->next = new Box(value, iterator->next->next);
		//iterator = iterator->next;
	}
	else if (iterator->next == nullptr)
	{
		iterator->next = new Box(value, nullptr);
		last = iterator->next;
	}
	else
	{
		iterator = last = first = new Box(value, nullptr);
	}

	sz++;
	
}