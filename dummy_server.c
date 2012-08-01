/* ========================================================================
 * $Id: dummy_server.c 41 2005-10-30 23:39:47Z s0undt3ch $
 * ========================================================================
 *             $URL: http://ipkungfu.ufsoft.org/svn/tags/ipkungfu-0.6.1/dummy_server.c $
 * $LastChangedDate: 2005-10-30 17:39:47 -0600 (Sun, 30 Oct 2005) $
 *             $Rev: 41 $
 *   $LastChangedBy: s0undt3ch $
 * ========================================================================
*/

/*	A simple server that binds to
 *	a user-specified port and does nothing
 */

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <errno.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <sys/wait.h>
    #include <signal.h>

    void sigchld_handler(int s)
    {
		  while(waitpid(-1,NULL,WNOHANG) > 0);
    }

    void usage(char *progname) 
    {
		 fprintf(stderr, "usage: %s <listen_port> <max_connections_in_queue>\n",progname ? progname : "" );
    }

    int main(int argc, char *argv[])
    {
      int myport;  // the port users will be connecting to
		int backlog;  // how many pending connections queue will hold
		int sockfd, new_fd;  // listen on sock_fd, new connection on new_fd
      struct sockaddr_in my_addr;    // my address information
      struct sockaddr_in their_addr; // connector's address information
      int sin_size;
      struct sigaction sa;
      int yes=1;

	if(argc != 3){ 	// If the correct number of arguments are not passed, show usage()
  	   usage(argv[0]);
  	   exit(0);
	}
	
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("socket");
      exit(1);
	}

   if (setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(yes)) == -1) {
		perror("setsockopt");
      exit(1);
	}

  	myport  = strtol(argv[1],NULL,10);
  	backlog = strtol(argv[2],NULL,10);
        
	my_addr.sin_family = AF_INET;         // host byte order
   my_addr.sin_port = htons(myport);     // short, network byte order
   my_addr.sin_addr.s_addr = INADDR_ANY; // automatically fill with my IP
   memset(&(my_addr.sin_zero), '\0', 8); // zero the rest of the struct

   if (bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr)) == -1) {
		perror("bind");
      exit(1);
	}

   if (listen(sockfd, backlog) == -1) {
      perror("listen");
      exit(1);
   }

   sa.sa_handler = sigchld_handler; // reap all dead processes
   sigemptyset(&sa.sa_mask);
   sa.sa_flags = SA_RESTART;
   if (sigaction(SIGCHLD, &sa, NULL) == -1) {
      perror("sigaction");
      exit(1);
   }

   while(1) {  // main accept() loop
		sin_size = sizeof(struct sockaddr_in);
		if ((new_fd = accept(sockfd, (struct sockaddr *)&their_addr,&sin_size)) == -1) {
			perror("accept");
         continue;
      }
	}
	
	return 0;
	 
	} 
