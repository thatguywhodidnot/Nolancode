

class lego:
    def __init__(self, name , piece_count):
        self.piece_count = piece_count
        print(f"the {name} lego set has arrived and has {piece_count} pieces")

    def build_time(self):
        smartness = int(input('what is you IQ?\n>'))
        build_time = 7
        if smartness < 100:
            build_time = 12
        elif smartness > 200:
            build_time = 5
        print(f'based on your IQ, it will take you {build_time} hours to complete this set')
        

        


death_star = lego('death star', 300)

print(death_star.piece_count)
death_star.build_time()