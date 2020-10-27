from cs50 import SQL
import sys
import csv


if (len(sys.argv) != 2):
    print("python roster.py Gryffindor")

db = SQL("sqlite:///students.db")

house = sys.argv[1]

rows = db.execute(f"SELECT * FROM students WHERE house='{house}' ORDER BY last, first ASC")
for row in rows:
    id, first, middle, last, house, birth = list(row.values())
    if middle == None:
        print(f"{first} {last}, born {birth}")
    else:
        print(f"{first} {middle} {last}, born {birth}")