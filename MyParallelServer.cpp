//
// Created by Eldar on 12-Jan-19.
//

#include <vector>
#include "MyParallelServer.h"


class my_thread_info {
public:
    int serverSocket;
    int clientSocket;
    ClientHandler *clientHandler;
};

static void *connectionHandler(void *context) {
    my_thread_info info = *((my_thread_info *) context);
    vector<string> vic;

    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    bool continueReading = true;
    char buffer[4096] = {0};
    while (continueReading) {
        read(info.clientSocket, buffer, sizeof(buffer));
        if (buffer[0] != '\0') {
            vic.push_back(buffer);
            if (buffer == "end\n\r") {
                continueReading = false;
                info.clientHandler->handleClient(vic);
            }
        }

    }
}


void MyParallelServer::open(int port, ClientHandler *handler) {
    int opt = 1;
    struct sockaddr_in server, client;
    int serverDescriptor;

    // Creating serverSocket file descriptor
    if ((serverDescriptor = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == 0) {
        perror("serverSocket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching serverSocket to the port 8080
    if (setsockopt(serverDescriptor, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);

    // Forcefully attaching serverSocket to the port 8080
    if (bind(serverDescriptor, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(serverDescriptor, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    //Accept and incoming connection
    cout << ("Waiting for incoming connections...") << endl;
    int i = 0;
    while (1) {
        pthread_t threadId[50];
        socklen_t addrlen = sizeof(sockaddr_in);
        int acceptConnection;
        if (acceptConnection = accept(serverDescriptor, (struct sockaddr *) &client, &addrlen)) {
            cout << "Connection accepted, starting listener thread" << endl;
        }

        my_thread_info info;
        info.serverSocket = serverDescriptor;
        info.clientHandler = handler;
        info.clientSocket = acceptConnection;

        int index = pthread_create(&threadId[i], NULL, connectionHandler, (void *) &info);
        if (index < 0) {
            perror("could not create thread");
            exit(EXIT_FAILURE);
        }
        i++;
        //pthread_join(threadId, NULL);
    }
}

void MyParallelServer::stop() {

}

bool MyParallelServer::isOpen() {

}