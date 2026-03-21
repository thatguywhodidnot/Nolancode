
import zombies

game_off = True



def run_game():
    while game_off == False:
        print(f'{p1.name} is at {p1.location}')
        user_move = input('>')
        match user_move:
            case "walk":
                print('dir?')
            case 'inventory':
                print('have nothing')
if __name__ == '__main__':
    zombies.menu()
