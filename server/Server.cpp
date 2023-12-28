#include "Server.hpp"


void Server::handleServers(Socket socket)
{
	FD_SET(socket.getServerSocket(), &master_read_fds);
	fdmax = socket.getServerSocket();

	while(42)
	{
		tmp_read_fds = master_read_fds;
		if (select(fdmax+1, &tmp_read_fds, NULL, NULL, NULL) == -1)
		{
			perror("select");
			exit(1);
		}

		// run through the existing connections looking for data to read
		for (int i = 0; i <= fdmax; i++)
		{
			// if (FD_ISSET(i, &tmp_read_fds)) // we got one
			// {
				// if (i == socket.getServerSocket())	// handle new connections
				// {
				// 	socklen_t sin_size;
				// 	sin_size = sizeof(Client.getClientAddress());
				// 	Client.setClientSocket(accept(socket.getServerSocket(), (struct sockaddr *)&Client.getClientAddress(), &sin_size));
				// 	if (client_fd == -1)
				// 		perror("accept");
				// 	else
				// 	{
				// 		FD_SET(client_fd, &master); // add to master set
				// 		if (client_fd > fdmax)	// keep track of the max
				// 			fdmax = client_fd;
				// 		std::cout << "New connection from " << inet_ntoa(client_addr.sin_addr) << " on socket " << client_fd << std::endl;
				// 	}
				// }
		}

	}

	

}
Server::Server()
{
}

Server::~Server() { }