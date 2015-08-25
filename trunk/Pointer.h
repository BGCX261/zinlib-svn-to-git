#if !defined (__HEADERFILE_POINTER_H__)
#define __HEADERFILE_POINTER_H__
#include "Object.h"

template <typename __TYPE__>
class Pointer
//: virtual public Object
{
protected:
	struct PointerMemberVariable
	{
		__TYPE__ * memory;
		_size_t size;
	} member;

protected:
	void insideInitialize(void);
	void insideInitialize(const Pointer<__TYPE__> & object);
	void insideInitialize(_size_t size);
	void insideInitialize(const __TYPE__ * memory, _size_t size);
	void insideClear(void);

public:
	Pointer(void);
	Pointer(const Pointer<__TYPE__> & object);
	Pointer(_size_t size);
	Pointer(const __TYPE__ * memory, _size_t size);

public:
	~Pointer(void);

public:
	void operator=(const Pointer<__TYPE__> &object);
	_boolean_t operator==(const Pointer<__TYPE__> & object) const;
	_boolean_t operator!=(const Pointer<__TYPE__> & object) const;
	__TYPE__ &operator[](_iterator_t index);
	__TYPE__ &operator[](_iterator_t index) const;

public:
	void Initialize(void);
	void Initialize(const Pointer<__TYPE__> & object);
	void Initialize(_size_t size);
	void Initialize(const __TYPE__ * memory, _size_t size);

public:
	void CopyTo(const Pointer<__TYPE__> & object);
	_boolean_t EqualTo(const Pointer<__TYPE__> & object) const;

public:
	void Allocate(_size_t size);
	void Free(void);
	void Resize(_size_t size);
	void Increase(_size_t size);
	void Decrease(_size_t size);

public:
	__TYPE__ GetAt(_iterator_t index) const;
	void SetAt(_iterator_t index, __TYPE__ value);
	_size_t GetSize(void) const;

};

#include "Pointer_implement.h"

#endif
