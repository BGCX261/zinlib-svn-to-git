#include "main.h"


class TestClass
: virtual public Object
{
public:
	void method(_result_t a)
	{
		EXCEPTION_START;

		method_1(a);

		EXCEPTION_END;
	}

	void method_1(_result_t a)
	{
		EXCEPTION_START;

		method_2(a);

		EXCEPTION_END;
	}

	void method_2(_result_t a)
	{
		EXCEPTION_START;

		method_3(a);

		EXCEPTION_END;
	}

	void method_3(_result_t a)
	{
		EXCEPTION_START;

		method_4(a);

		EXCEPTION_END;
	}

	void method_4(_result_t a)
	{
		EXCEPTION_START;

		THROW(a);

		EXCEPTION_END;
	}
};


int
main
(
		int argument_count,
		const char **argument_values
)
{
	EXCEPTION_START;

	Pointer<int> p;
	printf("%u\n", sizeof(int*));
	printf("%u\n", sizeof(Pointer<int>));
	printf("%u\n", sizeof(p));

	/*
	_int64_t a = 0xffFFffFF;
	_int32_t b = 0xffFFffFF;
	_uint32_t c = 0xffFFffFF;

	printf("%I64d\n", a);
	printf("%d\n", b);
	printf("%u\n", c);

	Pointer<int> test;
	int temp[10];

	for (int n=0; n<10; n++)
	{
		temp[n] = rand();
	}

	test.Initialize(0, 10);

	for (int n=0; n<10; n++)
	{
		STDOUT(STRING("%d\n"), test[n]);
	}
	 */
	NeuralNetwork nn;
	Pointer<_realnumber_t> input;
	Pointer<_realnumber_t> output;
	Pointer<_realnumber_t> target;

	nn.Initialize(2, 2, 1);
	input.Allocate(2);
	output.Allocate(1);
	target.Allocate(1);

	input[0] = 0.0L;
	input[1] = 0.0L;
	target[0] = 0.0L;
	nn.BackPropagation(input, target, 0.9L);

	input[0] = 0.0L;
	input[1] = 1.0L;
	target[0] = 1.0L;
	nn.BackPropagation(input, target, 0.9L);

	input[0] = 1.0L;
	input[1] = 0.0L;
	target[0] = 1.0L;
	nn.BackPropagation(input, target, 0.9L);

	input[0] = 1.0L;
	input[1] = 1.0L;
	target[0] = 0.0L;
	nn.BackPropagation(input, target, 0.9L);

	input[0] = 0.0L;
	input[1] = 0.0L;
	nn.Propagation(input, output);
	STDOUT(STRING("%lf\n"), output[0]);

	input[0] = 0.0L;
	input[1] = 1.0L;
	nn.Propagation(input, output);
	STDOUT(STRING("%lf\n"), output[0]);

	input[0] = 1.0L;
	input[1] = 0.0L;
	nn.Propagation(input, output);
	STDOUT(STRING("%lf\n"), output[0]);

	input[0] = 1.0L;
	input[1] = 1.0L;
	nn.Propagation(input, output);
	STDOUT(STRING("%lf\n"), output[0]);

	EXCEPTION_ALERT_STDOUT;

	return 0;
}
