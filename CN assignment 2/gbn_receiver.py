import pickle
import socket

def send_packet(packet:dict,sock:socket,addr):
    bytes=pickle.dumps(packet)
    sock.sendto(bytes,addr)

def recieve_packet(sock:socket):
    bytes,addr=sock.recvfrom(4096)
    packet=pickle.loads(bytes)
    return packet,addr

acknowledgement={
    "sequence":0,
    "type":"ack",
    "value":None
}

packet={
    "sequence":0,
    "type":"packet",
    "value":123
}


client_socket=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
client_socket.bind(('127.0.0.1',5678))
server_socket=('127.0.0.1',1234)

for i in range(200):
    while True:
        packet,addr=recieve_packet(client_socket)
        if packet["sequence"]==i:
            print(f"Packet number {i}:",packet["value"])
            acknowledgement["sequence"]=i
            send_packet(acknowledgement,client_socket,addr)
            break
        else:
            acknowledgement["sequence"]=i-1
            send_packet(acknowledgement,client_socket,addr)            
