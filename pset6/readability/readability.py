import re
from cs50 import get_string


def coleman_lieu_index(string):
    letters  = len(re.sub(r"[\.\!\?\ \'\,]+", "", string))
    words = len(string.split())
    sentences = len(re.split(r'[.!?]+', string))-1

    L = letters * 100 / words
    S = sentences * 100 / words

    idx = round(0.0588 * L - 0.296 * S - 15.8)

    if idx < 1:
        return "Before Grade 1"
    elif idx > 16:
        return "Grade 16+"
    else:
        return f"Grade {idx}"


text = get_string("Text: ")
print(coleman_lieu_index(text))