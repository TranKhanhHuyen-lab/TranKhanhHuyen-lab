#include "MyList.h"

template<class T>
MyList<T>::MyList(int maxsize)
{
	this->maxsize = maxsize;
	count = 0;
	data = new T[maxsize];
}

template<class T>
MyList<T>::~MyList(void)
{
	if (data != NULL)
		delete []data;
}

template<class T>
bool MyList<T>::isEmpty()
{
	return (count == 0);
}

template<class T>
bool MyList<T>::isFull()
{
	return (count == maxsize);
}

template<class T>
void MyList<T>::insert1(T newElem)
{
	//chen vao cuoi ds
	if (isFull() == true)
		cout<<"List is full!!"<<endl;
	else
	{
		data[count] = newElem;
		count++;
	}
}

template<class T>
void MyList<T>::copy(T *source, T *des)
{
	for(int i = 0; i < count;i++)
		source[i] = des[i];
}

template<class T>
void MyList<T>::insert2(T newElem)
{
	if (isFull() == true)
	{
		T *backup = new T[maxsize];
		copy(backup,data);
		maxsize *= 2;
		delete []data;
		data = new T[maxsize];
		copy(data,backup);
	}
	data[count++] = newElem;
}

template<class T>
void MyList<T>::remove(T elem)
{
	int pos = - 1;
	for(int i = 0; i < count;i++)
		if (elem == data[i])
		{
			pos = i;
			break;
		}
	if (pos != -1)
	{
		for(int j = pos;j < count-1;j++)
			data[j] = data[j+1];
		count--;
	}
}

template<class T>
void MyList<T>::print()
{
	for(int i = 0; i < count;i++)
		cout<<data[i]<<" ";
	cout<<endl;
}