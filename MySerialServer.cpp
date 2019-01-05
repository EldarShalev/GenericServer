//
// Created by Eldar on 03-Jan-19.
//

#include "MySerialServer.h"

struct my_thread_info {
    int socket;
    ClientHandler *clientHandler;
};

void MySerialServer::open(int port, ClientHandler *ch) {
    int opt = 1;
    struct sockaddr_in server, client;
    int serverDescriptor;
    pthread_t threadId;

    // Creating socket file descriptor
    if ((serverDescriptor = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(serverDescriptor, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);

    // Forcefully attaching socket to the port 8080
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
    socklen_t addrlen = sizeof(sockaddr_in);

    if (accept(serverDescriptor, (struct sockaddr *) &client, &addrlen)) {
        cout << "Connection accepted, starting listener thread" << endl;
    }

    my_thread_info info;
    info.socket = serverDescriptor;
    info.clientHandler = ch;

    if (pthread_create(&threadId, NULL, connectionHandler, (void *) &info) < 0) {
        perror("could not create thread");
        exit(EXIT_FAILURE);
    }
}

static void *connectionHandler(void *context) {
    my_thread_info info = *((my_thread_info*)context);

    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    char buffer[4096] = {0};
    while (true) {
        listen(info.socket, 5);
        read(info.socket, buffer, sizeof(buffer));

        stringstream in;
        ostringstream  out;
        in.read(buffer, sizeof(buffer));
//        TODO handle streams and client
        info.clientHandler->handleClient(buffer);

    }
}

void MySerialServer::stop() {
}

bool MySerialServer::isOpen() {
}
