from random import randint
from math import ceil
from random import sample
import time

def random_generator(run):
    out = open("data.in", "a")

    fuel = 700  # maximul de km pe care se poate deplasa masina fara sa opreasca
    max_range = 1000000  # distanta maxima la care se poate deplase masina

    for case_number in range(run):
        # masina se poate deplasa pe o distanta de cel putin 400 km si cel mult FUEL km
        m = randint(400, fuel)
        # destinatia se alfa la cel putin 1000 km departare si la maxim max_range km departare
        destination = randint(600 + m, max_range)
        # sunt cel putin n_must_fill benzinarii la care trebuie sa opreasca
        # si cel mult destination/10 + n_must_fill benzinarii optionale
        n_must_fill = ceil(destination / m)
        n = n_must_fill + randint(0, destination // 10)

        arr1 = [0]
        r_value = 0
        while r_value < destination:
            r_value = r_value + m - randint(1, 100)
            arr1.append(r_value)

        arr2 = list(sample(range(1, destination - 1), n - 1))
        arr2.append(destination)

        arr = list(set(arr1) | set(arr2))

        arr.sort()

        n = len(arr) - 2
        # START TESTARE

        for iterator in range(1, n + 2):
            assert (arr[iterator] - arr[iterator - 1] <= m)
            assert arr[iterator] != arr[iterator - 1]
            assert arr[iterator] > arr[iterator - 1]

        # STOP TESTARE

        out.write("%d\n" % n)
        out.write("%d\n" % m)

        for iterator in arr:
            out.write("%s\n" % iterator)

    out.close()
