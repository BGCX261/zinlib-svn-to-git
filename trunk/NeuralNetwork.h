#if !defined (__HEADERFILE_NEURALNETWORK_H__)
#define __HEADERFILE_NEURALNETWORK_H__
#include "Object.h"
#include "Pointer.h"

class NeuralNetwork
: virtual public Object
{
protected:
	struct NeuralNetworkMemberVariable
	{
		_size_t input_size;
		_size_t hidden_size;
		_size_t output_size;
		Pointer<_realnumber_t> weight;
		Pointer<_realnumber_t> bias;
		Pointer<_realnumber_t> activated_value;
		Pointer<_realnumber_t> error;
		Pointer<_realnumber_t> deltha;
	} member;

protected:
	virtual void insideInitialize(void);
	virtual void insideInitialize(const NeuralNetwork & object);
	virtual void insideInitialize(_size_t input_size, _size_t hidden_size, _size_t output_size);
	virtual void insideClear(void);

public:
	NeuralNetwork(void);
	NeuralNetwork(const NeuralNetwork & object);
	NeuralNetwork(_size_t input_size, _size_t hidden_size, _size_t output_size);

public:
	virtual ~NeuralNetwork(void);

public:
	virtual void operator=(const NeuralNetwork & object);
	virtual _boolean_t operator==(const NeuralNetwork & object);
	virtual _boolean_t operator!=(const NeuralNetwork & object);

public:
	virtual void Initialize(void);
	virtual void Initialize(const NeuralNetwork & object);
	virtual void Initialize(_size_t input_size, _size_t hidden_size, _size_t output_size);

public:
	virtual void CopyTo(const NeuralNetwork & object);
	virtual _boolean_t EqualTo(const NeuralNetwork & object) const;

public:
	_realnumber_t & ActivatedValueOfInput(_index_t i, _index_t j);
	_realnumber_t & ActivatedValueOfHidden(_index_t i, _index_t j);
	_realnumber_t & ActivatedValueOfOutput(_index_t i, _index_t j);
	_realnumber_t & WeightBetweenInputAndHidden(_index_t i, _index_t j);
	_realnumber_t & WeightBetweenHiddenAndOuput(_index_t i, _index_t j);
	_realnumber_t & DelthaOfHidden(_index_t i);
	_realnumber_t & DelthaOfOutput(_index_t i);

public:
	void Propagation(const Pointer<_realnumber_t> & input, Pointer<_realnumber_t> & output);
	_realnumber_t BackPropagation(const Pointer<_realnumber_t> & input, const Pointer<_realnumber_t> & target, _realnumber_t learn_rate);

};

#endif
