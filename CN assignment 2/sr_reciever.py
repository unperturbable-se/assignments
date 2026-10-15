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

buffer=[]


client_socket=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
client_socket.bind(('127.0.0.1',5678))
server_socket=('127.0.0.1',1234)
packetsRecieved=set()
i=0
while i in range(5) or len(packetsRecieved)>=5:
    packet,addr=recieve_packet(client_socket)
    if packet["sequence"]==i:
        packetsRecieved.add(i)
        buffer.append([packet["sequence"],packet["value"]])
        buffer.sort(key=lambda x: x[0])
        i=buffer[-1][0]
        acknowledgement["sequence"]=packet["sequence"]
        send_packet(acknowledgement,client_socket,addr) 
        for seq,val in buffer: 
            print(f"--------Packet{seq}:{val}--------")
        buffer.clear()
    else:
        print(f"buffered packet {packet['sequence']}")
        buffer.append([packet["sequence"],packet["value"]])
        acknowledgement["sequence"]=packet["sequence"]
        send_packet(acknowledgement,client_socket,addr)  
        packetsRecieved.add(packet["sequence"])