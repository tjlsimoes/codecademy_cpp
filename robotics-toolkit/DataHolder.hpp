template <typename T>
class DataHolder
{
	private:
		T	storedValue;
		T	minValue;
		T	maxValue;
	
	public:
		DataHolder(T val, T min, T max) : minValue(min), maxValue(max)
		{
			if (val >= minValue && val <= maxValue)
				storedValue = val;
			else if (val > maxValue)
			{
				storedValue = maxValue;
				std::cout << "WARNING: " << val << "is too high!"
				<< " Setting value to " << maxValue << "!"
				<< std::endl;
			}
			else if (val < minValue)
			{
				storedValue = minValue;
				std::cout << "WARNING: " << val << "is too low!"
				<< " Setting value to " << minValue << "!"
				<< std::endl;
			}
		};

		void	setValue(T newValue)
		{
			if (newValue >= minValue && newValue <= maxValue)
				storedValue = newValue;
			else if (newValue > maxValue)
			{
				storedValue = maxValue;
				std::cout << "WARNING: " << newValue << " is too high!"
				<< " Setting value to " << maxValue << "!"
				<< std::endl;
			}
			else if (newValue < minValue)
			{
				storedValue = minValue;
				std::cout << "WARNING: " << newValue << " is too low!"
				<< " Setting value to " << minValue << "!"
				<< std::endl;
			}
		}

		T	getValue()
		{
			return storedValue;
		}
};

template <>
class DataHolder<std::string>
{
	private:
		std::string	storedValue;
	
	public:
		DataHolder(std::string val) : storedValue(val)
		{};

		void	setValue(std::string newString)
		{
			storedValue = newString;
		}

		std::string	getValue()
		{
			return storedValue;
		}
};