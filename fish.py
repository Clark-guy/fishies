# fish bowl
# by blood trash

import time as t
import os

#define screen size

#refreshScreen
def refreshScreen():
    outString = ""
    for x in range(20):
        outString += "\n"
        for y in range(20):
            outString += "o"
    os.system("clear")
    print(outString)


def updateFish():
    pass


if __name__ == "__main__":
    while(1):
        t.sleep(.2)
        updateFish()
        refreshScreen()
