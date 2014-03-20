#ifndef _RING_
#define _RING_

template<class T> class chain {
private:
	T _data;
	chain * _next;

	chain * find(int index);
	const chain * nfind(int index) const; //used to support const use.
	chain * ninsert(chain * pos, chain * data); //insert a new node after pos.
	chain * ndelete(chain * pos); //delete the node after pos

public:
	chain();
	int size() const;
	bool empty();
	void clear();
	bool push(T t, int index = 0); //insert a new data after index
	bool push_back(T t);
	bool pop(int index = 1); //delete the data at index
	bool pop_back();
	const T& at(int index = 1) const; //visit the data at index
	T& at(int index = 1); //visit the data at index
	const T& at_back() const;
	T& at_back();
};

template<class T> chain<T> * chain<T>::find(int index) {
	if (index <= 0)
		return 0;
	chain<T> * temp = this;
	for (int i = 0; i < index - 1; i++) {
		temp = temp->_next;
		if (temp == this)
			return 0;
	}
	return temp;
}
template<class T> const chain<T> * chain<T>::nfind(int index) const {
	if (index <= 0)
		return 0;
	const chain<T> * temp = this;
	for (int i = 0; i < index - 1; i++) {
		temp = temp->_next;
		if (temp == this)
			return 0;
	}
	return temp;
}
template<class T> chain<T> * chain<T>::ninsert(chain<T> *pos, chain<T> *data) {
	data->_next = pos->_next;
	pos->_next = data;
	return data;
}
template<class T> chain<T> * chain<T>::ndelete(chain<T> *pos) {
	chain<T> * temp = pos->_next;
	pos->_next = temp->_next;
	delete temp;
	return pos;
}
template<class T> chain<T>::chain() {
	_next = this;
}
template<class T> int chain<T>::size() const {
	int i = 0;
	for (const chain<T> * temp = this; temp->_next != this;
			i++, temp = temp->_next)
		;
	return i;
}
template<class T> bool chain<T>::empty() {
	if (_next == this)
		return true;
	else
		return false;
}
template<class T> void chain<T>::clear() {
	while (_next != this)
		ndelete(this);
}
template<class T> bool chain<T>::push(T t, int index) {
	chain<T> * pos = find(index + 1);
	if (pos == 0)
		return false;
	chain<T> * data = new chain<T>;
	if (data == 0)
		return false;
	data->_data = t;
	ninsert(pos, data);
	return true;
}
template<class T> bool chain<T>::pop(int index) {
	chain<T> * pos = find(index);
	if (pos == 0)
		return false;
	ndelete(pos);
	return true;
}
template<class T> bool chain<T>::push_back(T t) {
	return push(t, size());
}
template<class T> bool chain<T>::pop_back() {
	return pop(size());
}
template<class T> const T& chain<T>::at(int index) const {
	return nfind(index)->_next->_data;
}
template<class T> T& chain<T>::at(int index) {
	return nfind(index)->_next->_data;
}
template<class T> const T& chain<T>::at_back() const {
	return at(size());
}
template<class T> T& chain<T>::at_back() {
	return at(size());
}

#endif
