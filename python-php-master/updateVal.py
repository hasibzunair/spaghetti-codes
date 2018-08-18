
import os
import time
import datetime
import random
import MySQLdb
from time import strftime
 

# Variables for MySQL
db = MySQLdb.connect(host="localhost", user="root",passwd="44455566", db="val_database")
cur = db.cursor()

#sql = """DELETE FROM valLog WHERE value = %s  """, (459)
sql = """UPDATE valLog SET value = 1000 WHERE value = %s """, (414)
try:
    print "Updating to database..."
    # Execute the SQL command
    cur.execute(*sql)
    # Commit your changes in the database
    db.commit()
    print "Update Complete"
 
except:
      # Rollback in case there is any error
      db.rollback()
      print "Failed writing to database"
      
db.close()
