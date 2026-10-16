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
packetsRecieved=[(False,-1)]*200
i=0
while i<200:
    packet,addr=recieve_packet(client_socket)
    index,value=packet["sequence"],packet["value"]
    if packet["sequence"]==i:
        packetsRecieved[index]=1,value
        while i<200:
            recieved,value=packetsRecieved[i]
            if not recieved:
                break
            acknowledgement["sequence"]=i
            send_packet(acknowledgement,client_socket,addr) 
            print(f"--------Packet{i}:{value}--------")
            i+=1
    else:
        print(f"buffered packet {index}")
        packetsRecieved[index]=True,value
        acknowledgement["sequence"]=packet["sequence"]
        send_packet(acknowledgement,client_socket,addr)  