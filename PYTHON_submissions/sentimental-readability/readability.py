from cs50 import get_string
import re


def main():
    text = get_string("Text: ")

    avg_letters = count_letters(text) / count_words(text) * 100
    avg_sentences = count_sentences(text) / count_words(text) * 100

    index = round(0.0588 * avg_letters - 0.296 * avg_sentences - 15.8)

    if index > 16:
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {index}")


def count_letters(text):

    text_lower = text.lower()

    letters = 0
    for character in text_lower:
        if ord(character) >= ord("a") and ord(character) <= ord("z"):
            letters += 1
    return letters


def count_words(text):

    arr_text = text.split(" ")
    len_words = len(arr_text)

    return len_words


def count_sentences(text):

    sentences = re.findall(r"[.!?]+", text)
    len_sentences = len(sentences)

    return len_sentences


main()
