#include "Socket.hpp"
#include "Server.hpp"

int main()
{
	Socket socket;
	Server server;

	socket.createServers();
	server.handleServers(socket);

	return 0;
}