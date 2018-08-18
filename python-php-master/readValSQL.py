
import os
import time
import datetime
import random
import MySQLdb
from time import strftime
 

# Variables for MySQL
db = MySQLdb.connect(host="localhost", user="root",passwd="44455566", db="val_database")
cur = db.cursor()
 
def valRead():
    a = random.randint(0,1023)
    return a

 
while True:
    val = valRead()
    print val
    datetimeWrite = (time.strftime("%Y-%m-%d ") + time.strftime("%H:%M:%S"))
    print datetimeWrite
    sql = ("""INSERT INTO valLog (datetime,value) VALUES (%s,%s)""",(datetimeWrite,val))
   # sql = """INSERT INTO valLog (datetime,value) VALUES (%s,%s)""" , (datetimeWrite,val)
    try:
        print "Writing to database..."
        # Execute the SQL command
        cur.execute(*sql)
        # Commit your changes in the database
        db.commit()
        print "Write Complete"
 
    except:
        # Rollback in case there is any error
        db.rollback()
        print "Failed writing to database"
    break; 
    
