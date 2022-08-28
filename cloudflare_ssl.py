"""
date: 2022-08-28
"""

import socket
import ssl

# SET VARIABLES
hostIP = '104.16.124.96'
hostname = 'www.cloudflare.com'
message = b'GET / HTTP/1.1\r\n\r\n'

# CREATE SOCKET
sock = socket.create_connection((hostIP, 443))

# WRAP SOCKET
context = ssl.create_default_context()
ssock = context.wrap_socket(sock, server_hostname=hostname)

# REQUEST AND RESPONSE
ssock.send(message)
data = ssock.recv(8192)
print(data)

# CLOSE SOCKET CONNECTION
ssock.close()
sock.close()
