from cs50 import SQL
import sys
import csv


if (len(sys.argv) != 2):
    print("Usage: python import.py characters.csv")

db = SQL("sqlite:///students.db")

with open(sys.argv[1]) as csv_file:
    csv_reader = csv.reader(csv_file, delimiter=',')
    next(csv_reader)
    for row in csv_reader:
        name, house, birth = row
        if (len(name.split()) == 3):
            first, middle, last = name.split()
            params = (first, middle, last, house, birth)
            db.execute(f"INSERT INTO students (first,middle,last,house,birth) VALUES (?,?,?,?,?)", params)
        elif (len(name.split()) == 2):
            first, last = name.split()
            middle = None
            params = (first, last, house, birth)
            db.execute(f"INSERT INTO students (first, middle, last,house,birth) VALUES (?,NULL,?,?,?)", params)