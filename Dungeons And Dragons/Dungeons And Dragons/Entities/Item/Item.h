#pragma once
#include "../../Helpers/String/String.h"

class Item {
	String name;
	size_t percentIncrease;

public:
	Item(const String& name, size_t percent);

	const String& getName() const;
	size_t getPercentIncrease() const;

	void setName(const String& name);
	void setPercent(size_t percent);

	virtual ~Item() = default;
};
