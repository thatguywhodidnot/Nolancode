#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/socket.h>
// system level functions
#include <unistd.h>

// arp is the matching of an ip addr to a MAC addr
#include <arpa/inet.h>

//web server will fetch content from somewhere else and then display it

// Http uses port 80
#define SERVER_PORT 8080
#define MAXLINE 4096 //buffer size

void err_n_die(const char * errmessage);

void err_n_die(const char * errmessage){
    fprintf(stderr,"Something Worng... %s : %s \n", errmessage, strerror(errno));
    exit(EXIT_FAILURE);
}


int main(int argc, const char *argv[]){
    //if (argc != 2) err_n_die("usage: webcstuff <server IP>");

    int server_fd, new_socket;
    int opt =1;
    // buffer is space that the info read from file or socket will be stored in
    //need to init to zero with calloc because read() cant null terminate
    char *buffer = calloc(1024, 1);
    const char* message = "hello (Server)";


    // sockaddr_in is defined already in netinet/in.h
    //represents a IPv4 socket address
    //bind, connect and snedto need to be used on this struct
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);

    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    // AF_inet = ipv4 socket
    // Sock_stream = make it a TCP connection(which is what http server would use)
    // 0 means use the default port
    // socket() creates a socket which is what aloows for web connection
    if ((server_fd= socket(AF_INET, SOCK_STREAM,0))<0){
        err_n_die("socker fail");
    }


    // pass socket into the socket options function
    // SOL_SOCKet = level socket operates at(socket API layer)

    // | IMPORTANT | --> SOREUEADDR = allow port rebinding despite TIME_WAIT
    // TIME_WAIT is a TCP connaction state after connection is closed
    // when a server closes you would usually have to wait 60 secs to reuse port

    //opt as 1 means enable the option
    //last parameter is how many bytes being passed in the option val
    if (( setsockopt(server_fd,SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)))<0){
        err_n_die("socket options fail");
    }
    else printf("Socket options set \n - port rebinding for server quick restart");

    address.sin_family = AF_INET; // address family
    //address.sin_addr.s_addr = INADDR_ANY; 
    //server will bing any local IP
    
    //or

    inet_pton(AF_INET, "127.0.0.1", &address.sin_addr);
    // to turn string into IP

    address.sin_port =  htons(SERVER_PORT); //port number
    //htons is function that Convert 16-bit number to network order 
    //endian is order in which bytes are stored in computer mem big = large first, small = smallest first

    //socket() will create socket
    //bind() will bind socket to IP and PORT defined in sockaddr_in struct
    //listen() will prepare socket to accept() connections and pass a que length for system to wait

    if((bind(server_fd,(struct sockaddr*)&address, sizeof(address)))<0){
        err_n_die("Binding failed");
    }
    else printf(" - Socket binded to IP and PORT\n");

    if((listen(server_fd,3))<0){
        err_n_die("mf socket cant listen 4 shit");
    }
    else printf(" - socket is listening and ready for request acceptance\n");


    // accept() use  -> (socket, pointer to sockaddr struct, address holding size of addr buffer)
    if((new_socket = accept(server_fd, (struct sockaddr*)&client_addr, &addrlen))<0){
        err_n_die("accept error");
    }
    else printf(" - no accepting problem\n");

    //read() from unist.h -> (file or pipe or socket, buffer, max amount of bytes to go into buffer )
    if(read(new_socket, buffer, 1024-1)<0){
        err_n_die("read error");
    }
    else printf(" - reading created socket\n");


    //curl --http0.9 -X POST -H "Content-Type: application/json" -d 'Hello - from client' http://localhost:8080

    printf("\n    !message recieved from client!  \n");
    printf("%s\n", buffer);
    send(new_socket, message, strlen(message),0);
    printf("\n  !message sent!  \n");

    free(buffer);
    return 0;
}
