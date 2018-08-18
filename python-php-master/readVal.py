import os
import time
import datetime
import random
from time import strftime


def valRead():
    a = random.randint(0,1023)
    
    return a




while 1:

    val = valRead()
    print val
    datetimeWrite = (time.strftime("%Y-%m-%d ") + time.strftime("%H:%M:%S"))
    print datetimeWrite
    print ""
    time.sleep(1)
    
