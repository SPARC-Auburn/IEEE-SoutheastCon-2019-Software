#pragma once

#include <vector>

//An iterator that wraps around instead of having a beginning and end. It can be optionally reversed. Good for contour data.

template<typename elementType>
class WrapIterator {
	bool incElseDec;
	int index;
	
public:
	std::vector<elementType>* container;
	
	WrapIterator(std::vector<elementType>& containerIn, bool incrementElseDec, int initialIndex = 0) : container{&containerIn}, incElseDec{incrementElseDec}, index{initialIndex} {
		assert(initialIndex >= 0 && initialIndex < containerIn.size());
	}
	
	WrapIterator& operator++() {		//prefix
		if(incElseDec) {
			index = getIncrement();
		}
		else {
			index = getDecrement();
		}
		return *this;
	}
	
	WrapIterator& operator--() {
		if(incElseDec) {
			index = getDecrement();
		}
		else {
			index = getIncrement();
		}
		return *this;
	}
	
	elementType* operator->() const {
		return &(*container)[index];
	}
	
	elementType& operator*() const {
		return (*container)[index];
	}
	
	bool operator==(const WrapIterator<elementType>& other) {		//Does not check that the containers are the same
		return other.index == index;
	}
	
	bool operator!=(const WrapIterator<elementType>& other) {
		return !operator==(other);
	}
	
	WrapIterator<elementType> next() const {
		return WrapIterator<elementType>(*container, incElseDec, incElseDec ? getIncrement() : getDecrement());
	}
	
	WrapIterator<elementType> prev() const {
		return WrapIterator<elementType>(*container, incElseDec, incElseDec ? getDecrement() : getIncrement());
	}
	
	bool isAdjacentTo(const WrapIterator<elementType>& other) const {
		return std::max(index, other.index) - std::min(index, other.index) == 1 || (std::max(index, other.index) == container->size() - 1 && std::min(index, other.index) == 0);
	}
	
	int getIndex() const {
		return index;
	}
	
private:
	int getIncrement() const {
		return (index == container->size() - 1) ? 0 : index + 1;
	}
	
	int getDecrement() const {
		return index == 0 ? container->size() - 1 : index - 1;
	}
};