#pragma once

#if __GNUC__ > 5

template<typename It>
concept bool Iterator() {
	return requires(It& it) {
		//{++it}->It&;
		{*it};
	};
}

template<typename It>
concept bool ForwardIterator() {
	return Iterator<It>() && requires(It& it) {
		{it++}->It&;
		{*it++};
	};
}

template<typename It>
concept bool BidirectionalIterator() {
	return ForwardIterator<It>() && requires(It& it) {
		{--it}->It&;
		{it--}->It&;
		{*it--};
	};
}

template<typename It>
concept bool RandomAccessIterator() {
	return Iterator<It>() && requires(It& it, int index) {
		{it += index }->It&;
		{it -= index }->It&;
		{it + index }->It;
		{index + it }->It;
	};
}

template<typename T, typename U = T>
concept bool Equality_comparable() {
  return requires (T a, U b)
  {
    { a == b } -> bool;
    { a != b } -> bool;
  };
}

template<typename R>
concept bool Range() {
  return requires (R range)
  {
    { range.begin() }->Iterator;
    { range.end() }->Iterator;
  };
}

template<typename T> requires requires() { typename T::value_type; }
  using ValueType = typename T::value_type;
#endif