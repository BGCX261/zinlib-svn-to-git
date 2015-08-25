#if !defined (__HEADERFILE_OBJECT_H__)
#define __HEADERFILE_OBJECT_H__
#include "Common/type.h"

class Object
{
public:
	static _boolean_t IsEqualZinClassName(const Object & object1, const Object & object2);

protected:
	static _c_ascii_string_t GetZinClassName(const Object & object);

public:
	virtual _boolean_t operator==(const Object & object);
	virtual _boolean_t operator!=(const Object & object);

public:
	virtual _boolean_t EqualTo(const Object & object) const;

public:
	virtual _c_ascii_string_t GetZinClassName(void);

};

#endif
