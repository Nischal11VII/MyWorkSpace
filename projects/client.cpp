#include<iostream>
#include <string>
#include <thread>
#include <cstring>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
    {
        int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

        if (clientSocket == -1) {
    std::cout << "Socket creation failed!" << std::endl;
    return -1;
}

       sockaddr_in client;

        client.sin_family = AF_INET;
        client.sin_port = htons(8080);

        if(inet_pton( AF_INET , "127.0.0.1" ,&client.sin_addr) <= 0)
            {
                std::cout << "Invalid IP address breaking" << std::endl;
                return -1;
            }

        if(connect(clientSocket , (struct sockaddr*) &client , sizeof(client)) == -1)
        {
            std::cout << "Connection failed with server" << std::endl;
            return -1;
        }
            
            std::cout << "connected to the server. " << std::endl;
    
        std::string msg;

        while (true) {
            
            std::cout << "Enter a message to send(exit to stop) : ";

            std::getline(std::cin , msg);

            if(msg == "exit")
            {
                break;
            }

            send(clientSocket , msg.c_str() , msg.size() , 0);
            
            char buffer[1024];
            memset(buffer , 0 , sizeof(buffer));
           


           int bytesReceived = recv(clientSocket , buffer , sizeof(buffer) - 1 , 0);
if (bytesReceived == 0) {
    std::cout << "Server closed the connection" << std::endl;
    break;
}

if (bytesReceived < 0) {
    std::cout << "recv failed" << std::endl;
    break;
}

           buffer[bytesReceived] = '\n';
 
            std::cout << "echo from the server : " << buffer << std::endl;

        }

        close(clientSocket);
        
        return 0;


    }
