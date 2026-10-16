packetsSent=218
print("Packet sent if ideal condition:",200)
print("Packets sent:",packetsSent)
print("Packet loss:",packetsSent-200,f"({100*(packetsSent-200)/200}% packet loss)")