from cs50 import get_int

s = " "
a = "#"

while True:
    ans = get_int("Heigth: ")
    if (ans <= 0 or ans > 8):
        continue
    else:
        for i in range(ans):
            print(f"{s*(ans-i-1)}{a*(i+1)}  {a*(i+1)}")
        break