#pragma once

template <class T>
class File
{
public:
	using size_type = unsigned long;
	File();
	~File();
	void Push(const T& valeur);
	T Pop();
	int& at(size_type);
	bool isEmpty();
	size_t Size();
	void resize(size_type);
	void clear();
	void reserve(size_type);
	size_type capacity() const;

private:
	T *tab;
	size_type nbElem;
	size_type cap;
};

