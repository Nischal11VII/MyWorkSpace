#include <iostream>
#include <cstring>
#include <thread>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/socket.h>


    void handleClient(int clientFD)
        {
            char buffer[1024];

            while(true)
                {
                    memset(buffer , 0 , sizeof(buffer));
                    int byteReceived = recv(clientFD, buffer, sizeof(buffer), 0);
                  
                    if(byteReceived <= 0)
                    {
                        std::cout << "Client Disconnected" << std::endl;
                        break;
                    }
                
                        std::cout << "Message from Client : " << buffer << std::endl;
                        
                        send(clientFD, buffer, byteReceived, 0);


                }
            
        close(clientFD);
        }


int main()
    {


        //create a socket
         int socket_fd = socket( AF_INET , SOCK_STREAM , 0);
        
         if (socket_fd == -1) {
    perror("socket creation failed");
        return -1;
         }



        // define ipv4 socket address
           sockaddr_in server;
          memset(&server , 0 , sizeof(server));

          server.sin_family = AF_INET;
          server.sin_port = htons(8080);
          server.sin_addr.s_addr = INADDR_ANY;
    


        // bind the socket to the ip address and port  

          //server is sockaddr_in and is casted to sockaddr..
     //    bind(socket_fd,(struct sockaddr*) &server , sizeof(server));
            
         if (bind(socket_fd, (struct sockaddr*)&server, sizeof(server)) == -1) {
    perror("bind failed");
        return -1;
         }


        //listen
//         listen(socket_fd , 2);

        
if (listen(socket_fd, 1) == -1) {
    perror("listen failed");
    return -1;
        
}



         std::cout << "Server is listening on port 8080.."<< std::endl;

        //accept
     
         while(true) {
         int clientfd = accept(socket_fd , nullptr , nullptr);
        
         std::cout << "new client connected" << std::endl;
        std::thread(handleClient , clientfd).detach();
         }


        // close the socket

        close(socket_fd);
        return 0;

    }
