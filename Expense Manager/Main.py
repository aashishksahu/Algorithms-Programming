"""
    CLI Expanse Manager

    Simple CL application to store transaction details in a database
    author: Aashish K Sahu
"""

import sqlite3
import ExpanseManager as em
import os

# check whether functions in ExpanseManager class are correct
assert hasattr(em, "Structs")
assert hasattr(em, "Parser")

"""
In this script a database connection will be made using sqlite3 and the 
date, amount and description will be stored in a table
"""


# Extend the exception class and create a database error handler
class DBError(Exception):
    pass


def create_conn():
    """
    Create a database and a table and connect to the script, first check if the database already
    exists.
    """
    try:
        conn = sqlite3.connect("ExpenseDB.db")

        return conn
    except DBError:
        print("Something Went wrong! press any key to exit..")
        input()
        exit()


# STEP 1: create connection
db_con = create_conn()
try:
    # STEP 2: create cursor to execute queries
    _Cursor = db_con.cursor()
    # STEP 3: create table
    _Cursor.execute('''CREATE TABLE IF NOT EXISTS manage
    (month text NOT NULL, date text NOT NULL, amount FLOAT NOT NULL, desc text);''')
except DBError:
    print("Couldn't create table!")
    exit()


# STEP 4: Finally running the main program loop
print("#" * 10 + "  Expense manager  " + "#" * 10)
print("\n where did you spend your money?")

# main program loop exits when ext flag is set to False
ext = True
while ext:
    if input("press y to print records: ") == 'y':
        _Cursor.execute("SELECT * FROM manage order by month")
        print("S.No | Month | Day | Amount | Description")
        for j,i in enumerate(_Cursor.fetchall()):
            print(j+1, ".  |", i[0], " |", i[1], " |", i[2], " |", i[3])

    print("\n Enter Response or press y to exit..")
    # user input
    txt = input("> ")

    try:
        # pass the text input to the Parser
        if txt != 'y':
            details = em.Parser(txt).checker()
            _Cursor.execute('''INSERT INTO manage (month, date, amount, desc) VALUES (?,?,?,?)''', (details["month"],
                                                                                                    details["date"],
                                                                                                    details["amount"],
                                                                                                    details["desc"]))
            db_con.commit()
        else:
            # if y is entered exit the loop
            break
    except:
        print("Please give correct input with date, amount and description...")
        continue



# after execution exit the program
exit()
