
import tkinter as tk    
import math
import pyautogui as ag
from sympy import *
import time
import pygame
pygame.mixer.init()


calc=tk.Tk()
calc.title('Calculator By Nolan')


numbox=tk.Entry(calc, width=35)


numbers=[[0,1,2,3,],
         [4,5,6,7,],
         [8,9,'+','-'],
         ['/','*',]
]

numbox.grid(row=0, column=0, columnspan=4, padx=5, pady=5)
should_clear = False

slap = pygame.mixer.Sound('click01.wav')
bruh= pygame.mixer.Sound('Bruh02.wav')
def typenum(num):
    global should_clear
    if should_clear:
        clear()
        should_clear=False
    numbox.insert(tk.END,str(num))
    slap.play()


def calculate(event=None):
    global should_clear
    try:
        expr=numbox.get()
        ans=eval(expr)
        print(ans)
        numbox.delete(0, tk.END)
        numbox.insert(tk.END,ans)
        slap.play()
        should_clear = True


    except Exception as e:
        print('invalid expression')    
        numbox.delete(0, tk.END)
        numbox.insert(tk.END,'Bruh')
        bruh.play()
        should_clear = True


def make_but(text,command):
    return tk.Button(calc,width=3,height=4, command=command, text=text)

def clear():
    numbox.delete(0, tk.END)


for row_index,row in enumerate(numbers):

    for col_index,i in enumerate(row):

        one=make_but(i,lambda i=i: typenum(i))
        one.grid(row = row_index+1, column = col_index,padx=2, pady=2)


equal_but=make_but('=',calculate)
equal_but.grid(row=4,column=3)

numbox.bind("<=>", calculate)






calc.geometry('500x500')
calc.mainloop()