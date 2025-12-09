#include <cstddef>
#include <initializer_list>
#include <cstdlib>
#include <stdexcept>

// NOTE: rememeber to check the size and capacity management on each method

template <typename T>
class Vector
{
private:
	size_t m_size;
	size_t m_capacity;
	T *m_arr;

	// this is wrong since what you want is a pointer to the memory block
	// T* m_arr[];

	void Resize(const size_t newCapacity); // done

public:
	Vector();																	 // done
	Vector(std::initializer_list<T> initList); // done
	~Vector();																 // done

	void PushFront(const T &val); // done
	void PushBack(const T &val);	// done
	const bool Pop(const size_t index);
	void Clear(); // done

	const int Size() const;			// done
	const int Capacity() const; // done
	T *Reserve(size_t size);		// done

	T &operator[](size_t index);						 // done
	const T &operator[](size_t index) const; // done
};

template <typename T>
Vector<T>::Vector(std::initializer_list<T> initList)
{
	m_capacity = m_size = initList.size();
	m_arr = Reserve(m_size);

	if (m_arr == nullptr)
	{
		throw std::runtime_error("Allocation error: an error ocurred on memory allocation");
	}

	// NOTE: wrong: can't use indexing on an initializer list
	//
	// for(int i = 0; i < initList.size(); i++){
	// 	m_arr[i] = initList[i];
	// }

	// NOTE: wrong again, m_arr is currently just a contiguous memory space, this approach might
	// work with primitive types, but not for a vector of custom objects
	//
	// int i = 0;
	// for(const T& val : initList){
	// 	m_arr[i++] = val;
	// }

	int i = 0;
	for (const T &val : initList)
	{
		new (m_arr + i++) T(val);
	}
}

template <typename T>
Vector<T>::Vector()
{
	m_capacity = 10;
	m_size = 0;
	m_arr = Reserve(m_size);
	// T* buffer = Reserve(m_size);

	if (m_arr == nullptr)
	{ // done
		throw std::runtime_error("Allocation error: an error ocurred on memory allocation");
	}

	// NOTE: wrong for empty constructor
	// you don't have to initialize the buffer with default values,
	// malloc automatically fills the buffer with garbage, if it's filled
	// with actual values, then it's not placing, it's replacing
	//
	// for(int i = 0; i < m_capacity; i++){
	// 	new (buffer + i++) T();
	// }
}

// wrong, you can't range iterate over it, since it's not an array of pointers.
// also, i'm just deleting copies here.
// template <typename T>
// void Vector<T>::Clear(){
// 	for(T val : m_arr){
// 		val.~T();
// 	}
// }

template <typename T>
void Vector<T>::Clear(){
	for(int i = 0; i < m_size; i++){
		m_arr[i].~T();
	}
	m_size = 0;
}

template <typename T>
Vector<T>::~Vector()
{
	Clear();
	free(m_arr);
}

// not contemplating size 1 vectors, nor empty vectors (recently allocated)
template <typename T>
void Vector<T>::PushFront(const T &val)
{

	if (m_size > 0)
	{
		T aux = m_arr[0];
		T aux2 = m_arr[1];

		if (m_size >= m_capacity)
		{
			Resize(m_capacity * 2);
			m_capacity *= 2;
		}

		// wrong, iterating over capacity, meaning, over garbage values
		// for(int i = 1; i < m_capacity; i++){

		for (int i = (int)m_size; i > 0; i--)
		{
			m_arr[i] = m_arr[i - 1];
		}
	}

	m_size++;
	m_arr[0] = val;
}

template <typename T>
void Vector<T>::PushBack(const T &val)
{
	if (m_size >= m_capacity)
	{
		Resize(m_capacity * 2);
	}

	m_size++;
	m_arr[m_size - 1] = val;
}

// TODO: missing shifting all elements after delete
template <typename T>
const bool Vector<T>::Pop(const size_t index){
	if(index > m_size){
		std::runtime_error("Runtime Error: Index out of bounds");
	}

	for(int i = 0; i < m_size; i++){
		if(i == index){
			m_arr[i].~T();
			return true;
		}
	}

	return false;
}

// returns a reference to the original pointer to avoid copies.
template <typename T>
T *Vector<T>::Reserve(size_t s)
{
	T *buffer = static_cast<T *>(malloc(sizeof(T) * s));
	return buffer;
}

template <typename T>
const int Vector<T>::Size() const
{
	return static_cast<int>(m_size);
}

template <typename T>
const int Vector<T>::Capacity() const
{
	return static_cast<int>(m_capacity);
}

template <typename T>
T &Vector<T>::operator[](size_t index)
{
	return m_arr[index];
}

template <typename T>
const T &Vector<T>::operator[](size_t index) const
{
	return m_arr[index];
}

// private methods
template <typename T>
void Vector<T>::Resize(const size_t newCapacity)
{
	// wrong, passing raw new capacity, meaning, not pacing a new capacity for the type specified
	// pass capacity times the size of the type
	// T* ptr = static_cast<T*>(realloc(m_arr, newCapacity));

	T *ptr = static_cast<T *>(realloc(m_arr, (newCapacity * sizeof(T))));

	if (ptr == nullptr)
	{
		throw std::runtime_error("Runtime Error: error reallocation vector");
		return;
	}

	m_arr = ptr;
}
