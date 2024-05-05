import threading
import socket
import sys
import ssl

host = '127.0.0.1'
port = 12345

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((host, port))
server.listen()



clients = []
nicknames = []

def broadcast(message):
    for client in clients:
        client.send(message)
        
def handle(client):
    while True:
        try:
            message = client.recv(1024)
            print(message.decode('ascii'))
            if message.decode('ascii').split()[1] == "stop":
                print("server stopped")
                broadcast("serverstopped".encode('ascii'))
                server.close()
                sys.exit()
            broadcast(message)
        except:
            index = clients.index(client)
            clients.remove(client)
            client.close()
            nickname = nicknames[index]
            print(f'{nickname} left'.encode('ascii'))
            nicknames.remove(nickname)
            break
        
def receive():
    while True:
        client, address = server.accept()
        ssl_socket = ssl.wrap_socket(client, server_side=True, keyfile="kliucz.pem", certfile="cercik.pem", ssl_version=ssl.PROTOCOL_TLS)
        print(f'connected with{str(address)}')
        
        ssl_socket.send('NICK'.encode('ascii'))
        nickname = ssl_socket.recv(1024).decode('ascii')
        nicknames.append(nickname)
        clients.append(ssl_socket)
        
        print(f'client nickname is {nickname}')
        broadcast(f'{nickname} joined'.encode('ascii'))
        ssl_socket.send('connected :)'.encode('ascii'))
        
        thread = threading.Thread(target=handle, args=(ssl_socket,))
        thread.start()

print('listening on port 12345...')
receive()