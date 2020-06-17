import socket
import threading

class MoomaServer():
    def __init__(self):
        self.connection_list = []
        self.hostname = '127.0.0.1'
        self.port = 6666 
        self.addr = (self.hostname, self.port)
        self.srv = socket.socket()
        self.srv.bind(self.addr)
    
    def accept_connection(self): 
        while True:
            connect_socket,client_addr = self.srv.accept()
            self.connection_list.append([connect_socket,client_addr])
            print('一位不願透漏姓名的熊頭前來捧場 : ' + str(client_addr))
    
    def start_listening(self):
        self.srv.listen(5)
        print("Waiting for connection...")
        # Create thread to accept new Pedobears ᶘᵒᴥᵒᶅ
        t = threading.Thread(target = self.accept_connection)
        t.start()

    def send_command(self, sock, cmd):
        sock.send(bytes(cmd,encoding='gbk'))
        recv = sock.recv(1024)
        print(str(recv,encoding='utf-8',errors='ignore'))
        return str(recv,encoding='utf-8',errors='ignore')

    def remove_disconnected(self):
        remaining = []
        for connection in self.connection_list:
            sock = connection[0]
            try:
                sock.send(bytes('CHECK_STATUS',encoding='gbk'))
                sock.recv(1024)
                remaining.append(connection)
            except:
                sock.close()
        self.connection_list = remaining

    def run(self):
        self.start_listening()
        while True:
            cmd = input()
            for connection in self.connection_list:
                self.send_command(connection[0], cmd)


if __name__ == '__main__':
    server = MoomaServer()
    server.run()