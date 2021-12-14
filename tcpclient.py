import socket

clientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
clientSocket.connect(("192.168.1.43", 80)) #change this with your board's local IP address, you don't have to change the port

def send_over_server(data):
    clientSocket.send(str(data).encode())

def sendRGB(r, g, b):
    send_over_server('r')
    send_over_server(r)
    send_over_server('g')
    send_over_server(g)
    send_over_server('b')
    send_over_server(b)
