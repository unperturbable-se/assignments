import pickle
import socket
import random
import time

def send_packet(packet:dict,sock:socket.socket,addr:tuple):
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
    "sequence":1,
    "type":"packet",
    "value":123
}


server_socket=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
server_socket.settimeout(1.0)
server_socket.bind(('127.0.0.1',1234))
dest_address=('127.0.0.1',5678)

messages=[random.randint(100,900) for i in range(200)]
sent=[False]*200
window=0
windowSize=3
packetsSent=0

try:
    remaining= [ i for i in range(200) if sent[i]==False ]
    while remaining:
        remaining= [ i for i in range(200) if sent[i]==False ]
        for i in range(0,3):
            if i>=len(remaining):break
            packet["sequence"],packet["value"]=remaining[i],messages[remaining[i]]
            send_packet(packet,server_socket,dest_address)
            packetsSent+=1
        try:
            while True:
                ack,addr=recieve_packet(server_socket)
                acknowledgement=ack
                print(f"Ack {ack['sequence']} received")
                sent[ack["sequence"]]=True

        except socket.timeout:
            pass
except KeyboardInterrupt:
    print("Closing server...")

print("Packet sent if ideal condition:",200)
print("Packets sent:",packetsSent)
print("Packet loss:",packetsSent-200,f"({100*(packetsSent-200)/200}% packet loss)")
