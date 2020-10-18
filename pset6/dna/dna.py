import sys
import csv
import re


# <re.Match object; span=(start, end), match='str'>
# finds a repeating subsequence in a string and outputs
# the legth of the longest one
def match_str(string, subsequence):
    match = re.finditer(rf"({subsequence})+", string)
    max_value = 0
    for m in match:
        span = m.end() - m.start()
        if span > max_value:
            max_value = span
    longest_repeating_sequence = max_value / len(subsequence)
    return int(longest_repeating_sequence)


csv_filename = sys.argv[1]
sequence_filename = sys.argv[2]

f = open(sequence_filename, "r")
sequence = f.read()

with open(csv_filename, mode='r') as csv_file:
    csv_reader = csv.reader(csv_file)
    column_names = next(csv_reader)
    # for each STR (the column names minus the first one)
    # it computes its longest run of consecutive repeats in the DNA sequence
    strs = [match_str(sequence, c) for c in column_names[1:]]
    match = False
    # it iterates over the people (rows) in order to find a matching number of strs 
    for person in csv_reader:
        l = list(map(int, person[1:]))
        if(l == strs):
            print(person[0])
            match = True
    if(match == False):
        print("No match")