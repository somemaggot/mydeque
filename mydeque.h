// mydeque.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>

template<typename T>
class myDeque {
	public:
		~myDeque();
		void push_back(T& in);
		void push_back(T&& in);
		void push_front(T& in);
		void push_front(T&& in);
		bool pop_back(T* out);
		bool pop_front(T* out);
		bool check_front(T* out);
		bool check_back(T* out);

		void print();
	private:
		struct node {
			node* next;
			node* prev;
			T data;
		};
		node* first = NULL;
		node* last = NULL;
};

// TODO: Reference additional headers your program requires here.
template <typename T>
myDeque<T>::~myDeque() {
	node* iter = first;
	node* next = NULL;
	while (iter != NULL) {
		next = iter->next;
		delete iter;
		iter = next;
	}
}

template <typename T>
void myDeque<T>::push_back(T& in) {
	node* newLast = new node;
	newLast->data = in;
	newLast->next = NULL;
	newLast->prev = last;
	if (last != NULL) {
		last->next = newLast;
	}
	else {
		first = newLast;
	}
	last = newLast;
}

template <typename T>
void myDeque<T>::push_back(T&& in) {
	node* newLast = new node;
	newLast->data = std::move(in);
	newLast->next = NULL;
	newLast->prev = last;
	if (last != NULL) {
		last->next = newLast;
	}
	else {
		first = newLast;
	}
	last = newLast;
}

template <typename T>
void myDeque<T>::push_front(T& in) {
	node* newFirst = new node;
	newFirst->data = in;
	newFirst->prev = NULL;
	newFirst->next = first;
	if (first != NULL) {
		first->prev = newFirst;
	}
	else {
		last = newFirst;
	}
	first = newFirst;
}

template <typename T>
void myDeque<T>::push_front(T&& in) {
	node* newFirst = new node;
	newFirst->data = std::move(in);
	newFirst->prev = NULL;
	newFirst->next = first;
	if (first != NULL) {
		first->prev = newFirst;
	}
	else {
		last = newFirst;
	}
	first = newFirst;
}

template <typename T>
bool myDeque<T>::pop_back(T* out) {
	if (last != NULL) {
		*T = last->data;
		last = last->prev;
		delete last->next;
		last->next = NULL;
		return true;
	}
	return false;
}

template <typename T>
bool myDeque<T>::pop_front(T* out) {
	if (first != NULL) {
		*out = first->data;
		first = first->next;
		delete first->prev;
		first->prev = NULL;
		return true;
	}
	return false;
}

template <typename T>
bool myDeque<T>::check_back(T* out) {
	if (last != NULL) {
		*out = last->data;
		return true;
	}
	return false;
}

template <typename T>
bool myDeque<T>::check_front(T* out) {
	if (first != NULL) {
		*T = first->data;
		return true;
	}
	return false;
}

template<typename T>
void myDeque<T>::print() {
	node* iter = first;
	while (iter != NULL) {
		std::cout << iter->data << std::endl;
		iter = iter->next;
	}
}