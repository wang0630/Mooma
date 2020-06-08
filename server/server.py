import socket
import threading

class MoomaServer():
    def __init__(self):
        self.socket_list = []
        self.hostname = '127.0.0.1'
        self.port = 6666 
        self.addr = (self.hostname, self.port)
        self.srv = socket.socket()
    
    def acceptConnection(self): 
        while True:
            connect_socket,client_addr = self.srv.accept()
            self.socket_list.append(connect_socket)
            print('一位不願透漏姓名的熊頭前來捧場 : ' + str(client_addr))
    
    def run(self):
        self.srv.bind(self.addr)
        self.srv.listen(5)
        print("Waiting for connection...")

        # Create thread to accept new Pedobears ᶘᵒᴥᵒᶅ
        t = threading.Thread(target = self.acceptConnection)
        t.start()

        while True:
            cmd = input()
            for sock in self.socket_list:
                sock.send(bytes(cmd,encoding='gbk'))
                recv = sock.recv(1024)
                print(str(recv,encoding='utf-8',errors='ignore'))


if __name__ == '__main__':
    server = MoomaServer()
    server.run()