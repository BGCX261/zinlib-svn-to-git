#include "Exception.h"

#include <stdio.h>



void
ExceptionPrintLocation
(
		_size_t line,
		_c_ascii_string_t function,
		_c_ascii_string_t file
)
{
	EXCEPTION_START;

	ASCII_STDOUT(" > %s: %u\n   %s\n", file, line, function);

	EXCEPTION_END;
}



void
Exception::PrintException
(
		const Exception & object
)
{
	EXCEPTION_START;

	Exception::PrintException(
			object.member.code,
			object.member.tail->line,
			object.member.tail->function,
			object.member.tail->file);

	EXCEPTION_END;
}



void
Exception::PrintException
(
		_result_t code,
		_size_t line,
		_c_ascii_string_t function,
		_c_ascii_string_t file
)
{
	EXCEPTION_START;

	ASCII_STDOUT(
			"Exception Code : %d\nException Message : %s\nLocation :\n",
			code,
			Exception::GetMessage(code));
	ExceptionPrintLocation(line, function, file);

	EXCEPTION_END;
}



void
Exception::PrintTraceException
(
		const Exception & object
)
{
	EXCEPTION_START;

	ExceptionLocation * next;

	Exception::PrintException(
			object.member.code,
			object.member.loaction.line,
			object.member.loaction.function,
			object.member.loaction.file);

	next = object.member.loaction.next;
	while (next != _null_v)
	{

		ExceptionPrintLocation(next->line, next->function, next->file);
		next = next->next;
	}

	EXCEPTION_END;
}



void
Exception::insideInitialize
(
		void
)
{
	EXCEPTION_START;

	this->member.code = SUCCESS;
	this->member.loaction.line = 0;
	this->member.loaction.function = "";
	this->member.loaction.file = "";
	this->member.loaction.next = _null_v;
	this->member.tail = &this->member.loaction;

	EXCEPTION_END;
}



void
Exception::insideInitialize
(
		const Exception & object
)
{
	EXCEPTION_START;

	ExceptionLocation * source;
	ExceptionLocation ** dastination;

	this->member.code = object.member.code;
	this->member.loaction.line = object.member.loaction.line;
	this->member.loaction.function = object.member.loaction.function;
	this->member.loaction.file = object.member.loaction.file;

	if (object.member.loaction.next == _null_v)
	{
		this->member.loaction.next = _null_v;
		this->member.tail = &this->member.loaction;
	}
	else
	{
		dastination = &(this->member.loaction.next);
		source = object.member.loaction.next;
		while (_true_v)
		{
			MEMORY_ALLOCATE(ExceptionLocation, *(dastination), 1);
			(*(dastination))->line = source->line;
			(*(dastination))->function = source->function;
			(*(dastination))->file = source->file;
			(*(dastination))->next = _null_v;

			if (source->next == _null_v)
			{
				this->member.tail = (*(dastination));
				break;
			}

			dastination = &((*(dastination))->next);
			source = source->next;
		}
	}

	EXCEPTION_END;
}



void
Exception::insideInitialize
(
		_result_t code,
		_size_t line,
		_c_ascii_string_t function,
		_c_ascii_string_t file
)
{
	EXCEPTION_START;

	this->member.code = code;
	this->member.loaction.line = line;
	this->member.loaction.function = function;
	this->member.loaction.file = file;
	this->member.loaction.next = _null_v;
	this->member.tail = &this->member.loaction;

	EXCEPTION_END;
}



void
Exception::insideClear
(
		void
)
{
	EXCEPTION_START;

	ExceptionLocation * location;
	ExceptionLocation * temp;

	location = this->member.loaction.next;
	while (location != _null_v)
	{
		temp = location;
		location = location->next;
		MEMORY_FREE(temp);
	}

	EXCEPTION_END;
}



Exception::Exception
(
		void
)
{
	EXCEPTION_START;

	this->insideInitialize();

	EXCEPTION_END;
}



Exception::Exception
(
		const Exception & object
)
{
	EXCEPTION_START;

	this->insideInitialize(object);

	EXCEPTION_END;
}



Exception::Exception
(
		_result_t code,
		_size_t line,
		_c_ascii_string_t function,
		_c_ascii_string_t file
)
{
	EXCEPTION_START;

	this->insideInitialize(code, line, function, file);

	EXCEPTION_END;
}



Exception::~Exception
(
		void
)
{
	EXCEPTION_START;

	this->insideClear();

	EXCEPTION_END;
}



void
Exception::operator
= (
		const Exception & object
)
{
	EXCEPTION_START;

	this->Initialize(object);

	EXCEPTION_END;
}



_boolean_t
Exception::operator
== (
		const Exception & object
)
{
	EXCEPTION_START;

	return this->EqualTo(object);

	EXCEPTION_END;
}



_boolean_t
Exception::operator
!= (
		const Exception & object
)
{
	EXCEPTION_START;

	return IS_FALSE(this->EqualTo(object));

	EXCEPTION_END;
}



void
Exception::Initialize
(
		void
)
{
	EXCEPTION_START;

	this->insideClear();
	this->insideInitialize();

	EXCEPTION_END;
}



void
Exception::Initialize
(
		const Exception & object
)
{
	EXCEPTION_START;

	this->insideClear();
	this->insideInitialize(object);

	EXCEPTION_END;
}



void
Exception::Initialize
(
		_result_t code,
		_size_t line,
		_c_ascii_string_t function,
		_c_ascii_string_t file
)
{
	EXCEPTION_START;

	this->insideClear();
	this->insideInitialize(code, line, function, file);

	EXCEPTION_END;
}



void
Exception::CopyTo
(
		const Exception & object
)
{
	EXCEPTION_START;

	this->Initialize(object);

	EXCEPTION_END;
}



_boolean_t
Exception::EqualTo
(
		const Exception & object
)
const
{
	EXCEPTION_START;

	const ExceptionLocation * source;
	const ExceptionLocation * destination;

	if (this->member.code != object.member.code)
	{
		return _false_v;
	}

	if (this->member.loaction.line != object.member.loaction.line)
	{
		return _false_v;
	}

	if (this->member.loaction.function != object.member.loaction.function)
	{
		return _false_v;
	}

	if (this->member.loaction.file != object.member.loaction.file)
	{
		return _false_v;
	}

	source = this->member.loaction.next;
	destination = object.member.loaction.next;

	do
	{
		if ((source != _null_v) && (destination != _null_v))
		{
			if (source->line != destination->line)
			{
				return _false_v;
			}

			if (source->function != destination->function)
			{
				return _false_v;
			}

			if (source->file != destination->file)
			{
				return _false_v;
			}
		}
		else if (((source == _null_v) &&  (destination != _null_v)) ||
				((source != _null_v) && (destination == _null_v)))
		{
			return _false_v;
		}
		else
		{
			break;
		}
		source = source->next;
		destination = destination->next;
	}
	while (true);

	return _true_v;

	EXCEPTION_END;
}



_result_t
Exception::GetCode
(
		void
)
const
{
	EXCEPTION_START;

	return this->member.code;

	EXCEPTION_END;
}



_size_t
Exception::GetLine
(
		void
)
const
{
	EXCEPTION_START;

	return this->member.loaction.line;

	EXCEPTION_END;
}



_c_ascii_string_t
Exception::GetFunction
(
		void
)
const
{
	EXCEPTION_START;

	return this->member.loaction.function;

	EXCEPTION_END;
}



_c_ascii_string_t
Exception::GetFile
(
		void
)
const
{
	EXCEPTION_START;

	return this->member.loaction.file;

	EXCEPTION_END;
}



_c_ascii_string_t
Exception::GetMessage
(
		void
)
const
{
	EXCEPTION_START;

	return Exception::GetMessage(this->member.code);

	EXCEPTION_END;
}



void
Exception::TraceLocation
(
		_size_t line,
		_c_ascii_string_t function,
		_c_ascii_string_t file
)
{
	EXCEPTION_START;

	MEMORY_ALLOCATE(ExceptionLocation, this->member.tail->next, 1);

	this->member.tail = this->member.tail->next;

	this->member.tail->line = line;
	this->member.tail->function = function;
	this->member.tail->file = file;
	this->member.tail->next = _null_v;

	EXCEPTION_END;
}



void
Exception::PrintException
(
		void
)
const
{
	EXCEPTION_START;

	Exception::PrintException(*this);

	EXCEPTION_END;
}



void
Exception::PrintTraceException
(
		void
)
const
{
	EXCEPTION_START;

	Exception::PrintTraceException(*this);

	EXCEPTION_END;
}
