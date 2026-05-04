

obj_list =[]


class plyr:
    def __init__(self,name):
        self.name = name


def create_plyr(name):
    tmp = plyr(name)
    obj_list.append(tmp)

names = ['nolan','neena','nyah']
for name in names:
    create_plyr(name)

for plyr in obj_list:
    print(plyr.name)
