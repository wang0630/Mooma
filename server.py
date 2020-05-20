import socket
hostname = '127.0.0.1'
port = 6666 
addr = (hostname,port)
srv = socket.socket()
srv.bind(addr)
srv.listen(5)
print("Waiting for connection...")
while True:
    connect_socket,client_addr = srv.accept()
    print('一位不願透漏姓名的熊頭前來捧場 : ' + str(client_addr))
    while True:
        cmd = input()
        connect_socket.send(bytes(cmd,encoding='gbk'))
        recv = connect_socket.recv(1024)
        print(str(recv,encoding='utf-8',errors='ignore'))
    connect_socket.close()