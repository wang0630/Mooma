import tkinter as tk
import tkinter.scrolledtext as scrolledtext
import math
from server import MoomaServer

def cmd():
    print('execute')

def send_cmd():
    in_cmd = cmd_entry.get()
    index = host_list.curselection()[0]
    res = mooma.send_command(mooma.socket_list[index], in_cmd)
    txt.insert('end', res)
    txt.insert('end', '\n')

def update_hosts():
    host_list.delete(0, tk.END)
    for item in mooma.socket_list:
        host_list.insert('end', item)

window = tk.Tk()
window.title('Mooma')
window.geometry('800x600')
#window.configure(background='white')
mooma = MoomaServer()
mooma.start_listening()
header_label = tk.Label(window, text='Mooooooooooooma')
header_label.pack()

mid_frame = tk.Frame(window)
mid_frame.pack(side=tk.TOP)

host_frame = tk.Frame(mid_frame)
host_frame.pack(side=tk.LEFT)
host_label = tk.Label(host_frame, text='Select a connected host')
host_label.pack(side=tk.TOP)
host_list = tk.Listbox(host_frame) 
for item in mooma.socket_list:
    host_list.insert('end', item)
host_list.pack()
refresh_btn = tk.Button(host_frame, text='Refresh', command=update_hosts)
refresh_btn.pack()

cmd_frame = tk.Frame(mid_frame)
cmd_frame.pack(side=tk.RIGHT)
cmd_label = tk.Label(cmd_frame, text='Choose a command')
cmd_label.pack(side=tk.TOP)
cmd_btn = tk.Button(cmd_frame, text='Cmd', command=cmd)
cmd_btn.pack()
cmd_label2 = tk.Label(cmd_frame, text='Enter other windows command')
cmd_label2.pack(side=tk.TOP)
cmd_entry = tk.Entry(cmd_frame)
cmd_entry.pack(side=tk.LEFT)
cmd_btn2 = tk.Button(cmd_frame, text='Send', command=send_cmd)
cmd_btn2.pack(side=tk.RIGHT)

txt = scrolledtext.ScrolledText(window, undo=True)
txt['font'] = ('consolas', '12')
txt.pack(expand=True)

window.mainloop()
