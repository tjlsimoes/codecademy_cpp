#include <iostream>
#include "Packet.hpp"

using namespace std;

int main() {
	Packet udpPacket(PacketType::DATA, Protocol::UDP);
	udpPacket.validatePacket();
	udpPacket.displayInfo();

	std::cout << "----------------------------------" << std::endl;

	Packet tcpPacket(PacketType::CONTROL, Protocol::TCP);
	tcpPacket.validatePacket();
	tcpPacket.displayInfo();

	std::cout << "----------------------------------" << std::endl;

	Packet unknownPacket(PacketType::UNKNOWN, Protocol::TCP);
	unknownPacket.validatePacket();
	unknownPacket.displayInfo();
	return 0;
}
