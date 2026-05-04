import os
import time


player_list = []


def typeout(words):
    for char in words:
        print(char, end='',flush=True)
        time.sleep(.1)

def clear_screen(): 
    os.system('clear')

def flash(word):
    for i in range(7):
        clear_screen()
        print(word)
        sleep(.5)

class player:
    def __init__(self, name):
        self.name = name
        self.location = [0,0]

    def intro(self, name):
        introduction =' has risen...'
        typeout(name); time.sleep(.3); typeout(introduction)

def create_player():
    clear_screen()
    print('Player creation screeen\n\n')
    name = input('Enter Player name: \n>')
    p = player(name)
    clear_screen()
    p.intro(name)
    time.sleep(2)
    return p

def player_select():
    for i in player_list:
        print(i.name)    

    if len(player_list) > 5:
        print("one player needs to be removed before another is added")
    else:
        plyr_choice = input(">") 
        for plyr in player_list:
            if plyr.name.lower() == plyr_choice.lower():
                flash(plyr.name)
                return plyr
    

    
#menu will have: 
#start game
#player select
#new player

def print_menu():
    clear_screen()
    print("\n\nMENU".center(12),'\n\n')
    print('1> Start Game' )    
    print('2> Player Select' )    
    print('3> New Player' )    
    print('4> Quit Game' )    

def menu():
    clear_screen()
    print_menu()
    loop = True
    while(loop == True):
        choice = input('\n>')
        match choice:
            case '1':
                print('game not ready')
                print_menu()
            case '2':
                current_plyr = player_select()
                print_menu()
            case '3':
                current_plyr = create_player()
                player_list.append(current_plyr)
                print_menu()
            case '4':
                loop = False
                



