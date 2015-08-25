#include "NeuralNetwork.h"
#include "Exception.h"

#include <math.h>
#include <stdlib.h>
#include <time.h>



void
NeuralNetwork::insideInitialize
(
		void
)
{
	EXCEPTION_START;

	this->member.input_size = 0;
	this->member.hidden_size = 0;
	this->member.output_size = 0;
	this->member.weight.Initialize(0);
	this->member.bias.Initialize(0);
	this->member.activated_value.Initialize(0);
	this->member.error.Initialize(0);
	this->member.deltha.Initialize(0);

	EXCEPTION_END;
}



void
NeuralNetwork::insideInitialize
(
		const NeuralNetwork & object
)
{
	EXCEPTION_START;

	if ((object.member.input_size == 0 || object.member.hidden_size == 0 || object.member.output_size == 0) ||
			(object.member.weight.GetSize() == 0 || object.member.bias.GetSize() == 0))
	{
		this->insideInitialize();
		return;
	}

	this->member.input_size = object.member.input_size;
	this->member.hidden_size = object.member.hidden_size;
	this->member.output_size = object.member.output_size;

	this->member.weight.CopyTo(object.member.weight);
	this->member.bias.CopyTo(object.member.bias);
	this->member.activated_value.CopyTo(object.member.activated_value);
	this->member.error.CopyTo(object.member.error);
	this->member.deltha.CopyTo(object.member.deltha);

	EXCEPTION_END;
}



void
NeuralNetwork::insideInitialize
(
		_size_t input_size,
		_size_t hidden_size,
		_size_t output_size
)
{
	EXCEPTION_START;

	_size_t buffer_size;
	register _index_t n;

	if (input_size == 0 || hidden_size == 0 || output_size == 0)
	{
		this->insideInitialize();
		return;
	}

	this->member.input_size = input_size;
	this->member.hidden_size = hidden_size;
	this->member.output_size = output_size;

	srand(static_cast<unsigned int>(time(NULL)));

	buffer_size = (this->member.input_size + this->member.output_size) * this->member.hidden_size;
	this->member.weight.Initialize(buffer_size);
	for (n=0; n<buffer_size; n++)
	{
		this->member.weight[n] = (static_cast<_realnumber_t>(rand() % 1000) / 1000.0L);
	}

	buffer_size = this->member.input_size + this->member.hidden_size;
	this->member.bias.Initialize(buffer_size);
	for (n=0; n<buffer_size; n++)
	{
		this->member.bias[n] = (static_cast<_realnumber_t>(rand() % 1000) / 1000.0L);
	}

	buffer_size = this->member.input_size + this->member.hidden_size + this->member.output_size;
	this->member.activated_value.Initialize(buffer_size);
	for (n=0; n<buffer_size; n++)
	{
		this->member.activated_value[n] = 0.0L;
	}

	buffer_size = this->member.input_size + this->member.hidden_size + this->member.output_size;
	this->member.error.Initialize(buffer_size);
	for (n=0; n<buffer_size; n++)
	{
		this->member.error[n] = 0.0L;
	}

	buffer_size = this->member.hidden_size + this->member.output_size;
	this->member.deltha.Initialize(buffer_size);
	for (n=0; n<buffer_size; n++)
	{
		this->member.deltha[n] = 0.0L;
	}

	EXCEPTION_END;
}



void
NeuralNetwork::insideClear
(
		void
)
{}



NeuralNetwork::NeuralNetwork
(
		void
)
{
	EXCEPTION_START;

	this->insideInitialize();

	EXCEPTION_END;
}



NeuralNetwork::NeuralNetwork
(
		const NeuralNetwork & object
)
{
	EXCEPTION_START;

	this->insideInitialize(object);

	EXCEPTION_END;
}



NeuralNetwork::NeuralNetwork
(
		_size_t input_size,
		_size_t hidden_size,
		_size_t output_size
)
{
	EXCEPTION_START;

	this->insideInitialize(input_size, hidden_size, output_size);

	EXCEPTION_END;
}



NeuralNetwork::~NeuralNetwork
(
		void
)
{
	EXCEPTION_START;

	this->insideClear();

	EXCEPTION_END;
}



void
NeuralNetwork::operator
= (
		const NeuralNetwork & object
)
{
	EXCEPTION_START;

	this->Initialize(object);

	EXCEPTION_END;
}



_boolean_t
NeuralNetwork::operator
== (
		const NeuralNetwork & object
)
{
	EXCEPTION_START;

	return this->EqualTo(object);

	EXCEPTION_END;
}



_boolean_t
NeuralNetwork::operator
!= (
		const NeuralNetwork & object
)
{
	EXCEPTION_START;

	return IS_FALSE(this->EqualTo(object));

	EXCEPTION_END;
}



void
NeuralNetwork::Initialize
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
NeuralNetwork::Initialize
(
		const NeuralNetwork & object
)
{
	EXCEPTION_START;

	this->insideClear();
	this->insideInitialize(object);

	EXCEPTION_END;
}



void
NeuralNetwork::Initialize
(
		_size_t input_size,
		_size_t hidden_size,
		_size_t output_size
)
{
	EXCEPTION_START;

	this->insideClear();
	this->insideInitialize(input_size, hidden_size, output_size);

	EXCEPTION_END;
}



void
NeuralNetwork::CopyTo
(
		const NeuralNetwork & object
)
{
	EXCEPTION_START;

	this->Initialize(object);

	EXCEPTION_END;
}



_boolean_t
NeuralNetwork::EqualTo
(
		const NeuralNetwork & object
)
const
{
	EXCEPTION_START;

	if (this->member.input_size != object.member.input_size)
	{
		return _false_v;
	}

	if (this->member.hidden_size != object.member.hidden_size)
	{
		return _false_v;
	}

	if (this->member.output_size != object.member.output_size)
	{
		return _false_v;
	}

	if (this->member.weight != object.member.weight)
	{
		return _false_v;
	}

	if (this->member.bias != object.member.bias)
	{
		return _false_v;
	}

	if (this->member.activated_value != object.member.activated_value)
	{
		return _false_v;
	}

	if (this->member.error != object.member.error)
	{
		return _false_v;
	}

	if (this->member.deltha != object.member.deltha)
	{
		return _false_v;
	}

	return _true_v;

	EXCEPTION_END;
}

void
NeuralNetwork::Propagation
(
		const Pointer<_realnumber_t> & input,
		Pointer<_realnumber_t> & output
)
{
	EXCEPTION_START;

	_realnumber_t net;
	register _index_t i;
	register _index_t j;

	if ((this->member.input_size == 0) ||
			(this->member.hidden_size == 0) ||
			(this->member.output_size == 0))
	{
		THROW(NEURALNETWORK_IS_NOT_CONSTRUCT);
	}
	if (input.GetSize() != this->member.input_size)
	{
		THROW(NEURALNETWORK_WRONG_INPUT_SIZE);
	}

	output.Resize(this->member.output_size);

	for (i=0; i<this->member.input_size; i++)
	{
		this->member.activated_value[i] = input[i];
	}

	for (i=0; i<this->member.hidden_size; i++)
	{
		net = 0.0L;
		for (j=0; j<this->member.input_size; j++)
		{
			net += this->member.weight[ (this->member.input_size + this->member.output_size) * i + j ]
			                            * this->member.activated_value[j];
		}
		this->member.activated_value[this->member.input_size + i] =
			1.0L / (1.0L + exp(-(net + this->member.bias[i])));
	}

	for (i=0; i<this->member.output_size; i++)
	{
		net = 0.0L;
		for (j=0; j<this->member.hidden_size; j++)
		{
			net += this->member.weight[ (this->member.input_size + this->member.output_size) * j + this->member.input_size + i]
			                            * this->member.activated_value[this->member.input_size + j];
		}
		this->member.activated_value[this->member.input_size + this->member.hidden_size + i] =
			1.0L / (1.0L + exp(-(net + this->member.bias[this->member.input_size + i])));
		output[i] = this->member.activated_value[this->member.input_size + this->member.hidden_size + i];
	}

	EXCEPTION_END;
}



_realnumber_t
NeuralNetwork::BackPropagation
(
		const Pointer<_realnumber_t> & input,
		const Pointer<_realnumber_t> & target,
		_realnumber_t learn_rate
)
{
	EXCEPTION_START;

	_realnumber_t error;
	_realnumber_t net;
	register _index_t i;
	register _index_t j;

	if ((this->member.input_size == 0) ||
			(this->member.hidden_size == 0) ||
			(this->member.output_size == 0))
	{
		THROW(NEURALNETWORK_IS_NOT_CONSTRUCT);
	}
	if (input.GetSize() != this->member.input_size)
	{
		THROW(NEURALNETWORK_WRONG_INPUT_SIZE);
	}
	if (target.GetSize() != this->member.output_size)
	{
		THROW(NEURALNETWORK_WRONG_OUTPUT_SIZE);
	}

	for (i=0; i<this->member.input_size; i++)
	{
		this->member.activated_value[i] = input[i];
	}

	for (i=0; i<this->member.hidden_size; i++)
	{
		net = 0.0L;
		for (j=0; j<this->member.input_size; j++)
		{
			net += this->member.weight[ (this->member.input_size + this->member.output_size) * i + j ]
			                            * this->member.activated_value[j];
		}
		this->member.activated_value[this->member.input_size + i] =
			1.0L / (1.0L + exp(-(net + this->member.bias[i])));
	}

	error = 0;

	for (i=0; i<this->member.output_size; i++)
	{
		net = 0.0L;
		for (j=0; j<this->member.hidden_size; j++)
		{
			net += this->member.weight[ (this->member.input_size + this->member.output_size) * j + this->member.input_size + i]
			                            * this->member.activated_value[this->member.input_size + j];
		}
		this->member.activated_value[this->member.input_size + this->member.hidden_size + i] =
			1.0L / (1.0L + exp(-(net + this->member.bias[this->member.input_size + i])));

		this->member.error[this->member.input_size + this->member.hidden_size + i] =
			target[i] - this->member.activated_value[this->member.input_size + this->member.hidden_size + i];

		this->member.deltha[this->member.hidden_size + i] =
			this->member.activated_value[this->member.input_size + this->member.hidden_size + i] *
			(1 - this->member.activated_value[this->member.input_size + this->member.hidden_size + i]) *
			this->member.error[this->member.input_size + this->member.hidden_size + i];

		error += this->member.error[this->member.input_size + this->member.hidden_size + i];
	}

	for (i=0; i<this->member.hidden_size; i++)
	{

	}
	return error;

	EXCEPTION_END;
}
