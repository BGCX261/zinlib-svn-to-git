#include "Object.h"

#include <typeinfo>



_boolean_t
Object::IsEqualZinClassName
(
		const Object & object1,
		const Object & object2
)
{
	return IS_EQUAL(typeid(object1), typeid(object2));
}



_c_ascii_string_t
Object::GetZinClassName
(
		const Object & object
)
{
	return typeid(object).name();
}



_boolean_t
Object::operator
== (
		const Object & object
)
{
	return object.EqualTo(object);
}



_boolean_t
Object::operator
!= (
		const Object & object
)
{
	return IS_FALSE(this->EqualTo(object));
}



_boolean_t Object::EqualTo(const Object & object) const
{
	return _true_v;
}



_c_ascii_string_t
Object::GetZinClassName
(
		void
)
{
	return Object::GetZinClassName(*this);
}
