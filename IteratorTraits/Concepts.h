#pragma once

#if __GNUC__ > 5

template<typename It>
concept bool Iterator() {
	return requires(It& it) {
		{++it}->It&;
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

#endif