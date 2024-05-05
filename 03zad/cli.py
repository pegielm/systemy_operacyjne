import threading
import socket
import sys

nickname = input("welcome \n type exit to exit \n type your nickname")

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(('127.0.0.1', 12345))

def receive():
    while True: 
        try:
            message = client.recv(1024).decode('ascii')
            if message == 'NICK':
                client.send(nickname.encode('ascii'))
            elif message.split(':')[0] != nickname:
                print(message, end="\n")
            elif message == "serverstopped":
                client.close()
                sys.exit()
        except:
            print("error")
            client.close()
            break

def write():
    while True:
        inside = input("")
        if inside == 'exit':
            client.close()
            break
        message = f'{nickname}: {inside}'
        client.send(message.encode('ascii'))
        
receive_thread = threading.Thread(target=receive)
receive_thread.start()
write_thread = threading.Thread(target=write)
write_thread.start() 
