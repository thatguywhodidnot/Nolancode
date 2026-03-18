
import random

#given first trade is 185 call on nvdia



stockprice = 60
x = stockprice
total_profit = 0 
for i in range(0,51):
    daily_increase = random.uniform(.05,.1)
    
    daily_profit = (x*daily_increase)
    
    print(f"total profit on day {i+1} is  {total_profit+daily_profit}\n")     
    total_profit += daily_profit
    x = stockprice + (total_profit//stockprice*stockprice)
