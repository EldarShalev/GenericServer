//
// Created by Eldar on 12-Jan-19.
//

#include <vector>
#include "MyParallelServer.h"
#include <string>
#include <cstring>
#include <string.h>

const char OS_Delimiter = '\n';


using std::string;
using std::stringstream;


class my_thread_info {
public:
    int serverSocket;
    int clientSocket;
    ClientHandler *clientHandler;
};

vector<string> MyParallelServer::parseVector(vector<string> vic1) {
    vector<string> parsedVector;
    string temp;
    for (vector<string>::iterator it = vic1.begin(); it < vic1.end(); ++it) {
        for (char &ch: *it) {
            // TODO - CHANGE THIS TO UBUNTU
            if (ch == '\r') {
                parsedVector.push_back(temp);
                temp = "";
            } else if (ch == 'e') {
                return parsedVector;
            } else if (ch == '\n') {
                continue;
            } else {
                temp += ch;
            }
        }
    }
}

static void *connectionHandler(void *context) {
    my_thread_info info = *((my_thread_info *) context);
    vector<string> vic;
    std::string prefix("end");
    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    bool continueReading = true;
    while (continueReading) {
        char buffer[4096] = {0};
        read(info.clientSocket, buffer, sizeof(buffer));
        if (buffer[0] != '\0') {
            string s = buffer;
            vic.push_back(buffer);
            if (s.find("end") != string::npos) {
                continueReading = false;
                vector<string> final = MyParallelServer::parseVector(vic);
                string solution = info.clientHandler->handleClient(final);
                send(info.clientSocket, solution.c_str(), strlen(solution.c_str()), 0);

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
    int indexOfThread = 0;
    pthread_t threadId[50];
    while (indexOfThread < 1) {
        socklen_t addrlen = sizeof(sockaddr_in);
        int acceptConnection;
        if (acceptConnection = accept(serverDescriptor, (struct sockaddr *) &client, &addrlen)) {
            cout << "Connection accepted, starting listener thread" << endl;
        }

        my_thread_info info;
        info.serverSocket = serverDescriptor;
        info.clientHandler = handler;
        info.clientSocket = acceptConnection;

        int index = pthread_create(&threadId[indexOfThread], NULL, connectionHandler, (void *) &info);
        if (index < 0) {
            perror("could not create thread");
            exit(EXIT_FAILURE);
        }
        indexOfThread++;
    }
    for (int j = 0; j < indexOfThread; j++) {
        pthread_join(threadId[j], NULL);
    }

}

void MyParallelServer::stop() {

}

bool MyParallelServer::isOpen() {

}