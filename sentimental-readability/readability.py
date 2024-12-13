from cs50 import get_string

def check_letters(text):
    cnt = 0
    for i in range(len(text)):
        if text[i].isalpha():
            cnt += 1
    return cnt

def check_words(text):
    cnt = 1
    for i in range(len(text)):
        if text[i] == ' ':
            cnt += 1
    return cnt

def check_sentences(text):
    cnt = 0
    for i in range(len(text)):
        if text[i] == '.' or text[i] == '!' or text[i] == '?':
            cnt += 1
    return cnt


def main():
    text =  get_string("Text: ")
    text = text.upper()

    letters = check_letters(text)
    words = check_words(text)
    sentences =  check_sentences(text)

    l = float(letters) / float(words) * 100.0
    s = float(sentences) / float(words) * 100.0
    index = round(0.0588 * l - 0.296 * s - 15.8)
    if  index >= 16.0:
        print("Grade 16+")
    elif index < 1.0:
        print("Before Grade 1 ")
    else:
        print("Grade ", int(index))


main()
