#if !defined (__HEADERFILE_COMMON_TYPE_H__)
#define __HEADERFILE_COMMON_TYPE_H__
#include "define.h"

#if defined (LANGUAGE_CPLUSPLUS)
typedef bool								_boolean_t;
#elif defined (LANGUAGE_C)
typedef int									_boolean_t;
#endif

typedef signed char							_int8_t;
typedef unsigned char						_uint8_t;

typedef signed short						_int16_t;
typedef unsigned short						_uint16_t;

typedef signed int							_int32_t;
typedef unsigned int						_uint32_t;

typedef signed long long					_int64_t;
typedef unsigned long long					_uint64_t;

typedef _uint8_t							_1byte_t, _8bit_t, _byte_t;
typedef _uint16_t							_2byte_t, _16bit_t;
typedef _uint32_t							_4byte_t, _32bit_t;

typedef _int32_t							_result_t;
typedef _uint32_t							_size_t;
typedef _size_t								_index_t;
typedef _int64_t							_iterator_t;

typedef double								_realnumber_t;

typedef char *								_ascii_string_t;
typedef const char *						_c_ascii_string_t;
typedef wchar_t *							_unicode_string_t;
typedef const wchar_t *						_c_unicode_string_t;

#if defined (UNICODE)
typedef wchar_t								_letter_t;
typedef wchar_t *							_string_t;
typedef const wchar_t *						_c_string_t;
#else
typedef char								_letter_t;
typedef char *								_string_t;
typedef const char *						_c_string_t;
#endif

#endif
