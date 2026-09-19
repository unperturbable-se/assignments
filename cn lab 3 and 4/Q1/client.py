import socket

def get_output(connection):
    message = connection.recv(1024).decode('utf-8')
    return message


def send_input(connection):
    message=input()
    connection.sendall(message.encode('utf-8'))


client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect(('127.0.0.1', 65432))

data=""
while True:
    data=get_output(client_socket)
    if data=="Terminate" or data=="": break
    print(data)
    send_input(client_socket)

client_socket.close()