import socket
import threading

class MoomaServer():
    def __init__(self):
        self.socket_list = []
        self.hostname = '127.0.0.1'
        self.port = 6666 
        self.addr = (self.hostname, self.port)
        self.srv = socket.socket()
        self.srv.bind(self.addr)
    
    def accept_connection(self): 
        while True:
            connect_socket,client_addr = self.srv.accept()
            self.socket_list.append(connect_socket)
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

    def run(self):
        self.start_listening()
        while True:
            cmd = input()
            for sock in self.socket_list:
                self.send_command(sock, cmd)


if __name__ == '__main__':
    server = MoomaServer()
    server.run()