#include "Color.hpp"
#include <iomanip>

Color::Color() : redChannel(0), greenChannel(0), blueChannel(0) {}

Color::Color(int red, int green, int blue) {
  redChannel   = CLIP(red);
  greenChannel = CLIP(green);
  blueChannel  = CLIP(blue);
}

Color Color::fromPackedRgb(unsigned int packedRgb) {
  return Color(int((packedRgb >> 16) & 0xffu),
         int((packedRgb >> 8)  & 0xffu),
         int( packedRgb      & 0xffu));
}

Color Color::fromHexLiteral(const char* hexString) {
  if (!hexString || hexString[0] != '#') {
    throw std::invalid_argument("hex literal must start with #");
  }
  int digits[6];
  for (int i = 0; i < 6; ++i) {
    int val = ColorUtility::fromHexDigit(hexString[i + 1]);
    if (val < 0) {
      throw std::invalid_argument("invalid hex digit");
    }
    digits[i] = val;
  }
  return Color(digits[0]*16 + digits[1],
         digits[2]*16 + digits[3],
         digits[4]*16 + digits[5]);
}

const int	&	Color::operator[](int index) const
{
	if (index > 2 || index < 0)
		throw std::out_of_range("Color index");
	switch(index)
	{
		case 0:
			return redChannel;
		case 1:
			return greenChannel;
		case 2:
			return blueChannel;
		default:
			throw std::out_of_range("Color index");
	}
}

int	&	Color::operator[](int index)
{
	if (index > 2 || index < 0)
		throw std::out_of_range("Color index");
	switch(index)
	{
		case 0:
			return redChannel;
		case 1:
			return greenChannel;
		case 2:
			return blueChannel;
		default:
			throw std::out_of_range("Color index");
	}
}

Color	Color::operator+(const Color &rhs) const
{
	Color	newColor;

	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
			newColor.redChannel = (redChannel + rhs.redChannel) / 2;
		else if (i == 1)
			newColor.greenChannel = (greenChannel + rhs.greenChannel) / 2;
		else
			newColor.blueChannel = (blueChannel + rhs.blueChannel) / 2;
	}
	return newColor;
}

Color	Color::operator+(const std::vector<int> adjustments) const
{
	Color	newColor;
	int	size = adjustments.size();
	int	i = 0;
	int	adjustment = 0;

	while (i < 3)
	{
		if (i >= size)
			adjustment = 0;
		else
			adjustment = adjustments[i];

		if (i == 0)
			newColor.redChannel = CLIP(redChannel + adjustment);
		else if (i == 1)
			newColor.greenChannel = CLIP(greenChannel + adjustment);
		else
			newColor.blueChannel = CLIP(blueChannel + adjustment);
		i++;
	}
	return newColor;
}

// Suffix
Color	Color::operator++(int)
{
	Color	temp;
	temp = *this;

	redChannel = CLIP(redChannel + 1);
	greenChannel = CLIP(greenChannel + 1);
	blueChannel = CLIP(blueChannel + 1);
	return (temp);
}

// Prefix
Color	& Color::operator++()
{
	redChannel = CLIP(redChannel + 1);
	greenChannel = CLIP(greenChannel + 1);
	blueChannel = CLIP(blueChannel + 1);
	return (*this);
}

Color	& Color::operator--()
{
	redChannel = CLIP(redChannel - 1);
	greenChannel = CLIP(greenChannel - 1);
	blueChannel = CLIP(blueChannel - 1);
	return (*this);
}

Color			Color::operator*(int scale)
{
	Color	newColor(redChannel * scale,
					greenChannel * scale,
					blueChannel * scale);
	return newColor;	
}

Color			Color::operator()(int (*transform)(int)) const
{
	Color	newColor;

	newColor.redChannel = CLIP(transform(redChannel));
	newColor.greenChannel = CLIP(transform(greenChannel));
	newColor.blueChannel = CLIP(transform(blueChannel));
	return newColor;
}

bool			Color::operator==(const Color &rhs) const
{
	if (redChannel == rhs.redChannel
		&& greenChannel == rhs.greenChannel
		&& blueChannel == rhs.blueChannel)
		return true;
	return false;
}


std::ostream& operator<<(std::ostream& os, const Color& color) {
  os << '#' << std::hex << std::setfill('0') << std::setw(2) << color.red()
         << std::setw(2) << color.green()
         << std::setw(2) << color.blue() << std::dec;
  return os;
}

std::istream& operator>>(std::istream& is, Color& color) {
  std::string token;
  is >> token;
  color = Color::fromHexLiteral(token.c_str());
  return is;
}


