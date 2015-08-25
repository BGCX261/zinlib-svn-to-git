#if !defined (__HEADERFILE_EXCEPTION__DEFINE_H__)
#define __HEADERFILE_EXCEPTION__DEFINE_H__


#if defined (COMPILER_MSVC)
#define __PRETTY_FUNCTION__		__FUNCSIG__
#endif


#if defined (THROW)
#undef THROW
#endif
#define THROW(code)				(throw Exception(code, __LINE__, __PRETTY_FUNCTION__, __FILE__))


#if defined (EXCEPTION_START)
#undef EXCEPTION_START
#endif
#define EXCEPTION_START 		try {


#if defined (EXCEPTION_END)
#undef EXCEPTION_END
#endif
#define EXCEPTION_END																	\
	}																					\
	catch (Exception & e)																\
	{																					\
		if ((e.GetFunction() != __PRETTY_FUNCTION__) || (e.GetFile() != __FILE__))		\
		{																				\
			e.TraceLocation(__LINE__, __PRETTY_FUNCTION__, __FILE__);					\
		}																				\
		throw e;																		\
	}																					\
	catch (...)																			\
	{																					\
		THROW(UNKNOWN_ERROR);															\
	}																					\


#if defined (EXCEPTION_ALERT_STDOUT)
#undef EXCEPTION_ALERT_STDOUT
#endif
#define EXCEPTION_ALERT_STDOUT																	\
	}																							\
	catch (Exception & e)																		\
	{																							\
		e.TraceLocation(__LINE__, __PRETTY_FUNCTION__, __FILE__);								\
		e.PrintTraceException();																\
	}																							\
	catch (...)																					\
	{																							\
		Exception::PrintException(UNKNOWN_ERROR, __LINE__, __PRETTY_FUNCTION__, __FILE__);		\
	}																							\


#if defined (MEMORY_ALLOCATE)
#undef MEMORY_ALLOCATE
#endif
#define MEMORY_ALLOCATE(type, pointer, size)	\
	{											\
		(pointer) = new type[(size)];			\
		if (pointer == _null_v)					\
		{										\
			THROW(MEMORY_ALLOCATE_ERROR);		\
		}										\
	}											\


#if defined (MEMORY_FREE)
#undef MEMORY_FREE
#endif
#define MEMORY_FREE(pointer)			\
	{									\
		try								\
		{								\
			delete [] (pointer);		\
		}								\
		catch (...)						\
		{								\
			pointer = 0;				\
			THROW(MEMORY_FREE_ERROR);	\
		}								\
	}									\


typedef struct ExceptionLocationType
{
	unsigned int line;
	_c_ascii_string_t function;
	_c_ascii_string_t file;
	ExceptionLocationType * next;
} ExceptionLocation;

#endif
