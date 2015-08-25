#if !defined (__HEADERFILE_COMMON_DEFINE_H__)
#define __HEADERFILE_COMMON_DEFINE_H__
#include "config.h"



// Environment
#if defined (OS_WIN32)
#undef OS_WIN32
#endif
#if defined (OS_WIN64)
#undef OS_WIN64
#endif
#if defined (_WIN32_WCE)
#undef _WIN32_WCE
#endif
#if defined (OS_LINUX)
#undef OS_LINUX
#endif
#if defined (_WIN32)
#define OS_WIN32
#elif defined (_WIN64)
#define OS_WIN64
#elif defined (_WIN32_WCE)
#define OS_WIN32_CE
#else
#define OS_LINUX
#endif

#if defined (COMPILER_MSVC)
#undef COMPILER_MSVC
#endif
#if defined (GNU_COMPILER)
#undef GNU_COMPILER
#endif
#if defined (_MSC_VER)
#define COMPILER_MSVC
#else
#define GNU_COMPILER
#endif

#if defined (LANGUAGE_CPLUSPLUS)
#undef LANGUAGE_CPLUSPLUS
#endif
#if defined (LANGUAGE_C)
#undef LANGUAGE_C
#endif
#if defined (__cplusplus)
#define LANGUAGE_CPLUSPLUS
#else
#define LANGUAGE_C
#endif



// values
#if defined (_null_v)
#undef _null_v
#endif
#if defined (LANGUAGE_CPLUSPLUS)
#define _null_v			(0)
#elif defined (LANGUAGE_C)
#define _null_v			((void *) 0)
#endif

#if defined (_true_v)
#undef _true_v
#endif
#if defined (LANGUAGE_CPLUSPLUS)
#define _true_v			(true)
#elif defined (LANGUAGE_C)
#define _true_v			(1)
#endif

#if defined (_false_v)
#undef _false_v
#endif
#if defined (LANGUAGE_CPLUSPLUS)
#define _false_v			(false)
#elif defined (LANGUAGE_C)
#define _false_v			(0)
#endif



// Check
#if defined (IS_TRUE)
#undef IS_TRUE
#endif
#if defined (LANGUAGE_CPLUSPLUS)
#define IS_TRUE(condition)			(condition)
#elif defined (LANGUAGE_C)
#define IS_TRUE(condition)			((condition) == _true_v? _true_v: _false_v)
#endif

#if defined (IS_FALSE)
#undef IS_FALSE
#endif
#if defined (LANGUAGE_CPLUSPLUS)
#define IS_FALSE(condition)			(!condition)
#elif defined (LANGUAGE_C)
#define IS_FALSE(condition)			((condition) == _false_v? _true_v: _false_v)
#endif

#if defined (IS_EQUAL)
#undef IS_EQUAL
#endif
#if defined (LANGUAGE_CPLUSPLUS)
#define IS_EQUAL(value1, value2)			((value1) == (value2))
#elif defined (LANGUAGE_C)
#define IS_EQUAL(value1, value2))			(((value1) == (value2))? _true_v: _false_v)
#endif

#if defined (IS_NOT_EQUAL)
#undef IS_NOT_EQUAL
#endif
#if defined (LANGUAGE_CPLUSPLUS)
#define IS_NOT_EQUAL(value1, value2)			((value1) != (value2))
#elif defined (LANGUAGE_C)
#define IS_NOT_EQUAL(value1, value2))			(((value1) != (value2))? _true_v: _false_v)
#endif




// Memory Allocate
#if !defined (MEMORY_ALLOCATE)
#define MEMORY_ALLOCATE(type, pointer, size)	((pointer) = new type[(size)])
#endif

#if !defined (MEMORY_FREE)
#define MEMORY_FREE(pointer)					(delete [] (pointer))
#endif



// Letter, String
#if defined (UNICODE)

#if defined (LETTER)
#undef LETTER
#endif
#define LETTER(letter)							(L ## letter)
#if defined (_STR)
#undef _STR
#endif
#define _STR(string)							(L ## string)
#if defined (STRING_LENGTH)
#undef STRING_LENGTH
#endif
#define STRING_LENGTH(string)					wcslen(string)
#if defined (STRING_COMPARE)
#undef STRING_COMPARE
#endif
#define STRING_COMPARE(string1, string2)		wcscmp(string1, string2)
#if defined (STRING_COPY)
#undef STRING_COPY
#endif
#define STRING_COPY(source, destination)		wcscpy(source, destination)

#else

#if defined (LETTER
#undef LETTER
#endif
#define LETTER(letter)							(letter)
#if defined (_STR
#undef _STR
#endif
#define _STR(string)							(string)
#if defined (STRING_LENGTH
#undef STRING_LENGTH
#endif
#define STRING_LENGTH(string)					strlen(string)
#if defined (STRING_COMPARE
#undef STRING_COMPARE
#endif
#define STRING_COMPARE(string1, string2)		strcmp(string1, string2)
#if defined (STRING_COPY
#undef STRING_COPY
#endif
#define STRING_COPY(source, destination)		STRING_COPY(source, destination)

#endif

#if defined (STRING)
#undef STRING
#endif
#define STRING(string)							_STR(string)



// Standard Output
#if defined (ASCII_STDOUT)
#undef ASCII_STDOUT
#endif
#define ASCII_STDOUT(string, ...)				printf(string, __VA_ARGS__)

#if defined (UNICODE_STDOUT)
#undef UNICODE_STDOUT
#endif
#define UNICODE_STDOUT(string, ...)				wprintf(string, __VA_ARGS__)


#if defined (STDOUT)
#undef STDOUT
#endif
#if defined (UNICODE)
#define STDOUT(string, ...)						UNICODE_STDOUT(string, __VA_ARGS__)
#else
#define STDOUT(string, ...)						ASCII_STDOUT(string, __VA_ARGS__)
#endif

#endif
