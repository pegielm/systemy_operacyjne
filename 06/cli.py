import threading
import socket
import sys
import ssl

host = '127.0.0.1'
port = 12345
nickname = input("welcome \n type exit to exit \n type your nickname")

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

context = ssl.SSLContext(ssl.PROTOCOL_TLS_CLIENT)
context.load_verify_locations('cercik.pem')  # Replace with the path to your CA certificate
wrapped_socket = context.wrap_socket(client, server_hostname=host)

wrapped_socket.connect((host, port))

def receive():
    while True: 
        try:
            message = wrapped_socket.recv(1024).decode('ascii')
            if message == 'NICK':
                wrapped_socket.send(nickname.encode('ascii'))
            elif message.split(':')[0] != nickname:
                print(message, end="\n")
            elif message == "serverstopped":
                wrapped_socket.close()
                sys.exit()
        except:
            print("error")
            wrapped_socket.close()
            break

def write():
    while True:
        inside = input("")
        if inside == 'exit':
            wrapped_socket.close()
            break
        message = f'{nickname}: {inside}'
        wrapped_socket.send(message.encode('ascii'))
        
receive_thread = threading.Thread(target=receive)
receive_thread.start()
write_thread = threading.Thread(target=write)
write_thread.start() 
