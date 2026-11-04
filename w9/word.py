import string
def readtxt(name):
    f = open(name, "r")
    l = dict()
    words = f.read().translate(str.maketrans("", "", string.punctuation)).split()
    f.close()
    for word in words:
        if word in l.keys():
            l[word] += 1
        else:
            l[word] = 1
    out = dict(sorted(l.items()))
    f = open("test_count.txt", 'w')
    for word in out.items():
        f.write(f"{word[0]}:{word[1]}\n")
    f.close()

readtxt("test.txt")