from algorithm_1 import algorithm_1
from algorithm_2 import algorithm_2


IN = open("C:\\Users\\ASUS\\Desktop\\P1\\GENERATOR_TESTE\\data.in", "r")
open("data_out.txt", "w").close()
open("data_grafic.txt.", "w").close()

no_test = int(IN.readline())

for case_number in range(no_test):
    n = int(IN.readline())
    m = int(IN.readline())
    gas_station = []

    for iterator in range(n + 2):
        data = int(IN.readline())
        gas_station.append(data)
    # rulam prima metoda pentru rezolvarea problemei
    algorithm_1(n, m, gas_station, case_number)
    # rulam a doua metoda pentru rezolvarea problemei
    algorithm_2(n, m, gas_station, case_number)

IN.close()
