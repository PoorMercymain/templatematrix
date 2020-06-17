#pragma once

template <class T>
class container
{
	T* array;
	
	int lengthofarray;
	
public:
	container();
	void setlengthofarray(int value);
	
	int getlengthofarray();
	
	void droparrayelement(const char where[]);
	
	void droparrayelement(int index);
	
	T getelement(const char where[]);
	
	T getelement(int index);
	
	void addelement(const char where[], T element);
	
	void addelement(int index, T element);
	
	T* modifyelement(int index);
	void droparray();
};

template<class T>
inline container<T>::container()
{
	lengthofarray = 0;
}

template <class T>
void container<T>::setlengthofarray(int value) {
	T* buffer = new T[lengthofarray];
	for (int i = 0; i < lengthofarray; i++) {
		buffer[i] = array[i];
	}
	delete[] array;
	array = new T[value];
	if (value >= lengthofarray) {
		for (int i = 0; i < lengthofarray; i++) {
			array[i] = buffer[i];
		}
		
		
		
	}
	if (lengthofarray > value) {
		for (int i = 0; i < value; i++) {
			array[i] = buffer[i];
		}
	}
	lengthofarray = value;
	delete[] buffer;
	
}
















































template<class T>
int container<T>::getlengthofarray()
{
	return lengthofarray;
}







template<class T>
void container<T>::droparrayelement(const char where[])
{
	T* buffer = new T[lengthofarray];
	for (int i = 0; i < lengthofarray; i++) {
		buffer[i] = array[i];
	}
	delete[] array;
	array = new T[lengthofarray - 1];
	if (lengthofarray) {
	lengthofarray--;
	}
	if (where == "first") {
		for (int i = 0; i < lengthofarray ; i++) {
			array[i] = buffer[i + 1];
		}
	}
	else if (where == "last") {
		for (int i = 0; i < lengthofarray; i++) {
			array[i] = buffer[i];
		}
	}
	delete[] buffer;
}

































template<class T>
void container<T>::droparrayelement(int index)
{
	if (index < lengthofarray && index >= 0) {
		T* buffer = new T[lengthofarray];
		for (int i = 0; i < lengthofarray; i++) {
			buffer[i] = array[i];
		}
		delete[] array;
		array = new T[lengthofarray - 1];
		lengthofarray = lengthofarray - 1;
		for (int i = 0; i < index; i++) {
			array[i] = buffer[i];
		}
		if (index + 1 < lengthofarray) {
			for (int i = index + 1; i < lengthofarray; i++) {
				array[i - 1] = buffer[i];
			}
		}
		delete[] buffer;
	}

}

template<class T>
T container<T>::getelement(const char where[])
{
	if (where == "first") {
		return array[0];
	}
	if (where == "last") {
		return array[lengthofarray - 1];
	}
}

template<class T>
T container<T>::getelement(int index)
{
	if (index < lengthofarray && index >= 0) {
		return array[index];
	}
}

template<class T>
void container<T>::addelement(const char where[], T element)
{
	T* buffer = new T[lengthofarray];
	for (int i = 0; i < lengthofarray; i++) {
		buffer[i] = array[i];
	}
	delete[] array;
	array = new T[lengthofarray+1];
	lengthofarray++;
	if (where == "first") {
		array[0] = element;
		for (int i = 1; i < lengthofarray; i++) {

			array[i] = buffer[i];

		}
	}
	else if (where == "last") {
		for (int i = 0; i < lengthofarray - 1; i++) {
			array[i] = buffer[i];
		}
		array[lengthofarray - 1] = element;
	}
	delete[] buffer;
}

template<class T>
void container<T>::addelement(int index, T element)
{
	if (index < lengthofarray + 1 && index >= 0) {
		T* buffer = new T[lengthofarray];
		for (int i = 0; i < lengthofarray; i++) {
			buffer[i] = array[i];
		}
		delete[] array;
		array = new T[lengthofarray + 1];
		lengthofarray = lengthofarray + 1;
		for (int i = 0; i < index + 1; i++) {
			if (i == index) {
				array[i] = element;
			}
			else {
				array[i] = buffer[i];
			}
		}
		if (index + 1 < lengthofarray) {
			for (int i = index + 1; i < lengthofarray; i++) {
				array[i] = buffer[i - 1];
			}
		}
		delete[] buffer;
	}

}

template<class T>
T* container<T>::modifyelement(int index)
{
	return &array[index];
}

template<class T>
void container<T>::droparray()
{
	delete[] array;
}
