#if !defined (__HEADERFILE_POINTER__IMPLEMENT_H__)
#define __HEADERFILE_POINTER__IMPLEMENT_H__
#include "Exception.h"



template <typename __TYPE__>
void
Pointer<__TYPE__>::insideInitialize
(
		void
)
{
	EXCEPTION_START;

	this->member.memory = _null_v;
	this->member.size = 0;

	EXCEPTION_END;
}



template <typename __TYPE__>
void
Pointer<__TYPE__>::insideInitialize
(
		const Pointer<__TYPE__> & object
)
{
	EXCEPTION_START;

	register _index_t n;

	if (object.member.size == 0)
	{
		this->insideInitialize();
	}
	else
	{
		this->member.size = object.member.size;
		MEMORY_ALLOCATE(__TYPE__, this->member.memory, this->member.size);

		for (n=0; n<this->member.size; n++)
		{
			(*(this->member.memory+n)) = (*(object.member.memory+n));
		}
	}

	EXCEPTION_END;
}



template <typename __TYPE__>
void
Pointer<__TYPE__>::insideInitialize
(
		_size_t size
)
{
	EXCEPTION_START;

	if (size == 0)
	{
		this->insideInitialize();
	}
	else
	{
		this->member.size = size;
		MEMORY_ALLOCATE(__TYPE__, this->member.memory, this->member.size);
	}

	EXCEPTION_END;
}



template <typename __TYPE__>
void
Pointer<__TYPE__>::insideInitialize
(
		const __TYPE__ * memory,
		_size_t size
)
{
	EXCEPTION_START;

	register _index_t n;

	if (memory == _null_v)
	{
		THROW(POINTER_IS_NULL);
	}

	if (size == 0)
	{
		this->insideInitialize();
	}
	else
	{
		this->member.size = size;
		MEMORY_ALLOCATE(__TYPE__, this->member.memory, this->member.size);

		for (n=0; n<this->member.size; n++)
		{
			(*(this->member.memory+n)) = (*(memory+n));
		}
	}

	EXCEPTION_END;
}



template <typename __TYPE__>
void
Pointer<__TYPE__>::insideClear
(
		void
)
{
	EXCEPTION_START;

	if (this->member.memory != _null_v)
	{
		MEMORY_FREE(this->member.memory);
	}

	EXCEPTION_END;
}



template <typename __TYPE__>
Pointer<__TYPE__>::Pointer
(
		void
)
{
	EXCEPTION_START;

	this->insideInitialize();

	EXCEPTION_END;
}



template <typename __TYPE__>
Pointer<__TYPE__>::Pointer
(
		const Pointer<__TYPE__> & object
)
{
	EXCEPTION_START;

	this->insideInitialize(object);

	EXCEPTION_END;
}



template <typename __TYPE__>
Pointer<__TYPE__>::Pointer
(
		_size_t size
)
{
	EXCEPTION_START;

	this->insideInitialize(size);

	EXCEPTION_END;
}



template <typename __TYPE__>
Pointer<__TYPE__>::Pointer
(
		const __TYPE__ * memory,
		_size_t size
)
{
	EXCEPTION_START;

	this->insideInitialize(memory, size);

	EXCEPTION_END;
}



template <typename __TYPE__>
Pointer<__TYPE__>::~Pointer
(
		void
)
{
	EXCEPTION_START;

	this->insideClear();

	EXCEPTION_END;
}



template <typename __TYPE__>
void
Pointer<__TYPE__>::operator
= (
		const Pointer<__TYPE__> & object
)
{
	EXCEPTION_START;

	this->Initialize(object);

	EXCEPTION_END;
}



template <typename __TYPE__>
_boolean_t
Pointer<__TYPE__>::operator
== (
		const Pointer<__TYPE__> & object
)
const
{
	EXCEPTION_START;

	return this->EqualTo(object);

	EXCEPTION_END;
}



template <typename __TYPE__>
_boolean_t
Pointer<__TYPE__>::operator
!= (
		const Pointer<__TYPE__> & object
)
const
{
	EXCEPTION_START;

	return IS_FALSE(this->EqualTo(object));

	EXCEPTION_END;
}



template <typename __TYPE__>
__TYPE__ &
Pointer<__TYPE__>::operator
[] (
		_iterator_t index
)
{
	EXCEPTION_START;

	if (index < 0 || index >= this->member.size)
	{
		THROW(POINTER_WRONG_INDEX);
	}

	return *(this->member.memory + static_cast<_index_t>(index));

	EXCEPTION_END;
}



template <typename __TYPE__>
__TYPE__ &
Pointer<__TYPE__>::operator
[] (
		_iterator_t index
)
const
{
	EXCEPTION_START;

	if (index < 0 || index >= this->member.size)
	{
		THROW(POINTER_WRONG_INDEX);
	}

	return *(this->member.memory + static_cast<_index_t>(index));

	EXCEPTION_END;
}



template <typename __TYPE__>
void
Pointer<__TYPE__>::Initialize
(
		void
)
{
	EXCEPTION_START;

	this->insideClear();
	this->insideInitialize();

	EXCEPTION_END;
}



template <typename __TYPE__>
void
Pointer<__TYPE__>::Initialize
(
		const Pointer<__TYPE__> & object
)
{
	EXCEPTION_START;

	this->insideClear();
	this->insideInitialize(object);

	EXCEPTION_END;
}



template <typename __TYPE__>
void
Pointer<__TYPE__>::Initialize
(
		_size_t size
)
{
	EXCEPTION_START;

	this->insideClear();
	this->insideInitialize(size);

	EXCEPTION_END;
}



template <typename __TYPE__>
void
Pointer<__TYPE__>::Initialize
(
		const __TYPE__ * memory,
		_size_t size
)
{
	EXCEPTION_START;

	this->insideClear();
	this->insideInitialize(memory, size);

	EXCEPTION_END;
}



template <typename __TYPE__>
void
Pointer<__TYPE__>::Allocate
(
		_size_t size
)
{
	EXCEPTION_START;

	this->Initialize(size);

	EXCEPTION_END;
}



template <typename __TYPE__>
void
Pointer<__TYPE__>::Free
(
		void
)
{
	EXCEPTION_START;

	this->Initialize();

	EXCEPTION_END;
}



template <typename __TYPE__>
void
Pointer<__TYPE__>::Resize
(
		_size_t size
)
{
	EXCEPTION_START;

	__TYPE__ * buffer;
	register _index_t n;

	if (size == 0)
	{
		this->Initialize();
	}
	else if (size != this->member.size)
	{
		MEMORY_ALLOCATE(__TYPE__, buffer, size);

		if (size < this->member.size)
		{
			for (n=0; n<size; n++)
			{
				*(buffer + n) = *(this->member.memory + n);
			}
		}
		else
		{
			for (n=0; n<this->member.size; n++)
			{
				*(buffer + n) = *(this->member.memory + n);
			}
		}

		this->member.size = size;

		MEMORY_FREE(this->member.memory);
		this->member.memory = buffer;
	}

	EXCEPTION_END;
}



template <typename __TYPE__>
void
Pointer<__TYPE__>::Increase
(
		_size_t size
)
{
	EXCEPTION_START;

	__TYPE__ * buffer;
	register _index_t n;

	if (size != 0)
	{
		if (this->member.size == 0)
		{
			this->Initialize(size);
		}
		else
		{
			MEMORY_ALLOCATE(__TYPE__, buffer, this->member.size + size);

			for (n=0; n<this->member.size; n++)
			{
				*(buffer + n) = *(this->member.memory + n);
			}

			this->member.size = this->member.size + size;

			MEMORY_FREE(this->member.memory);
			this->member.memory = buffer;
		}
	}

	EXCEPTION_END;
}



template <typename __TYPE__>
void
Pointer<__TYPE__>::Decrease
(
		_size_t size
)
{
	EXCEPTION_START;

	__TYPE__ * buffer;
	register _index_t n;

	if (size != 0)
	{
		if (this->member.size == 0 || this->member.size <= size)
		{
			this->Initialize();
		}
		else
		{
			MEMORY_ALLOCATE(__TYPE__, buffer, this->member.size - size);

			for (n=0; n<this->member.size - size; n++)
			{
				*(buffer + n) = *(this->member.memory + n);
			}

			this->member.size = this->member.size - size;

			MEMORY_FREE(this->member.memory);
			this->member.memory = buffer;
		}
	}

	EXCEPTION_END;
}



template <typename __TYPE__>
void
Pointer<__TYPE__>::CopyTo
(
		const Pointer<__TYPE__> & object
)
{
	EXCEPTION_START;

	this->Initialize(object);

	EXCEPTION_END;
}



template <typename __TYPE__>
_boolean_t
Pointer<__TYPE__>::EqualTo
(
		const Pointer<__TYPE__> & object
)
const
{
	EXCEPTION_START;

	register _index_t n;

	if (this->member.size == object.member.size)
	{
		for (n=0; n<this->member.size; n++)
		{
			if ((*(this->member.memory+n)) != (*(object.member.memory+n)))
			{
				return _false_v;
			}
		}
	}

	return _true_v;

	EXCEPTION_END;
}



template <typename __TYPE__>
__TYPE__
Pointer<__TYPE__>::GetAt
(
		_iterator_t index
)
const
{
	EXCEPTION_START;

	if (index < 0 || index >= this->member.size)
	{
		THROW(POINTER_WRONG_INDEX);
	}

	return *(this->member.memory + static_cast<_index_t>(index));

	EXCEPTION_END;
}



template <typename __TYPE__>
void
Pointer<__TYPE__>::SetAt
(
		_iterator_t index,
		__TYPE__ value
)
{
	EXCEPTION_START;

	if (index < 0 || index >= this->member.size)
	{
		THROW(POINTER_WRONG_INDEX);
	}

	*(this->member.memory + static_cast<_index_t>(index)) = value;

	EXCEPTION_END;
}



template <typename __TYPE__>
_size_t
Pointer<__TYPE__>::GetSize
(
		void
)
const
{
	EXCEPTION_START;

	return this->member.size;

	EXCEPTION_END;
}

#endif
