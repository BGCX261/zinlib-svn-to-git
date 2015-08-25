#if !defined (__HEADERFILE_EXCEPTION_H__)
#define __HEADERFILE_EXCEPTION_H__
#include "Object.h"
#include "Exception_define.h"

#if defined (EXCEPTION_MESSAGE)
#undef EXCEPTION_MESSAGE
#endif
#define EXCEPTION_MESSAGE(code, message)	case code: return message;

enum _E_EXCEPTION
{
	// Common
	SUCCESS = 0,

	// Memory
	MEMORY_ALLOCATE_ERROR,
	MEMORY_FREE_ERROR,

	// Pointer
	POINTER_IS_NULL,
	POINTER_WRONG_INDEX,

	// NeuralNetwork
	NEURALNETWORK_IS_NOT_CONSTRUCT,
	NEURALNETWORK_WRONG_INPUT_SIZE,
	NEURALNETWORK_WRONG_OUTPUT_SIZE,

	// ETC
	UNKNOWN_ERROR

};

class Exception
: virtual public Object
{
public:
	static _c_ascii_string_t GetMessage(_result_t code)
	{
		EXCEPTION_START;

		switch(code)
		{
		// Common
		EXCEPTION_MESSAGE(SUCCESS,							"Success");
		// Memory
		EXCEPTION_MESSAGE(MEMORY_ALLOCATE_ERROR,			"Memory allocate error");
		EXCEPTION_MESSAGE(MEMORY_FREE_ERROR,				"Memory free error");
		// Pointer
		EXCEPTION_MESSAGE(POINTER_IS_NULL,					"Pointer is null error");
		EXCEPTION_MESSAGE(POINTER_WRONG_INDEX,				"Pointer wrong index error");
		// NeuralNetwork
		EXCEPTION_MESSAGE(NEURALNETWORK_IS_NOT_CONSTRUCT,	"Neural Network is not construct error");
		EXCEPTION_MESSAGE(NEURALNETWORK_WRONG_INPUT_SIZE,	"Neural Network wrong input size error");
		EXCEPTION_MESSAGE(NEURALNETWORK_WRONG_OUTPUT_SIZE,	"Neural Network wrong output size error");
		}

		return "Unknown error";

		EXCEPTION_END;
	}

	static void PrintException(const Exception & object);
	static void PrintException(_result_t code, _size_t line, _c_ascii_string_t function, _c_ascii_string_t file);
	static void PrintTraceException(const Exception & object);

protected:
	struct ExceptionMemberVariable
	{
		_result_t code;
		ExceptionLocation loaction;
		ExceptionLocation * tail;
	} member;

protected:
	virtual void insideInitialize(void);
	virtual void insideInitialize(const Exception & object);
	virtual void insideInitialize(_result_t code, _size_t line, _c_ascii_string_t function, _c_ascii_string_t file);
	virtual void insideClear(void);

public:
	Exception(void);
	Exception(const Exception & object);
	Exception(_result_t code, _size_t line, _c_ascii_string_t function, _c_ascii_string_t file);

public:
	virtual ~Exception(void);

public:
	virtual void operator=(const Exception & object);
	virtual _boolean_t operator==(const Exception & object);
	virtual _boolean_t operator!=(const Exception & object);

public:
	virtual void Initialize(void);
	virtual void Initialize(const Exception & object);
	virtual void Initialize(_result_t code, _size_t line, _c_ascii_string_t function, _c_ascii_string_t file);

public:
	virtual void CopyTo(const Exception & object);
	virtual _boolean_t EqualTo(const Exception & object) const;

public:
	_result_t GetCode(void) const;
	_size_t GetLine(void) const;
	_c_ascii_string_t GetFunction(void) const;
	_c_ascii_string_t GetFile(void) const;
	_c_ascii_string_t GetMessage(void) const;

public:
	void TraceLocation(_size_t line, _c_ascii_string_t function, _c_ascii_string_t file);

public:
	void PrintException(void) const;
	void PrintTraceException(void) const;

};

#endif
