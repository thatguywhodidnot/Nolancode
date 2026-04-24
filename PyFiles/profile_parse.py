import json


with open("profiles.json","r") as profiles:
    user_data = json.load(profiles)

for i in range(3):
    print(f"\n{user_data[i]['profile_name']}\n")

def profile_load( user_data):
    print("profiles 1,2,3\n")
    prof = int(input("enter profile you would like\n>"))-1
    print(f"You are {user_data[prof]['profile_name']}\n")
    print(f"{user_data[prof]['details']}")
    
profile_load(user_data)
