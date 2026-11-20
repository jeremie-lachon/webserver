#ifndef ACUSTOMSOCKET_H
# define ACUSTOMSOCKET_H

# include <iostream>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/socket.h>
# include <sys/epoll.h>
# include <ctime>
# include <list>
# include <map>

enum
{
	OWNER,
	CLIENT,
	CGI
};

class ACustomSocket
{
	protected:
		int type;
		int	sock;
	public:
		static std::map<int, ACustomSocket *> allSockets;
		static std::list<ACustomSocket *>socketsToFree;
		static int epol; 
		ACustomSocket(int typ);
		virtual ~ACustomSocket();
		int		getSock(void) const;
		int		isWhat() const;
		int 	setNonblock();
		int		addToEpoll();
		void	resetSocket();
		

};

#endif
