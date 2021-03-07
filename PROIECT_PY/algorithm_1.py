def algorithm_1(n, m, gas_station, case_number):
    out = open("data_out.txt", "a")
    graphic = open("data_grafic.txt", "a")

    skip_case = 0
    count = []
    destination = gas_station[n + 1]
    last_station = gas_station[0]  # ultima statie, pornind de la origine( i.e 0 )
    station_number = 0  # indicele statiei
    refill = 0  # numarul de opriri pe care le-a realizat soferul

    for iterator in range(1, n + 2):
        # CAZUL IN CARE BENZINARIILE SUNT LA DISTANTE PREA MARI
        if gas_station[iterator] - gas_station[iterator - 1] > m:
            out.write("TESTUL: %d metoda 1\n" % case_number)
            out.write("\nSoferul nu poate ajunge la destinatie\n")
            skip_case = 1

    if skip_case == 0:
        while station_number <= n:
            # distanta pe care o parcurgem de la ultima alimentare
            distance = 0
            # ne deplasamm ( i.e distanta parcursa creste )
            # atat timp cat distanta este mai mica ca m si cat timp nu am ajuns la destinatie
            while (distance < m) and (station_number <= n):
                if (distance >= (gas_station[station_number] - last_station)) and (
                        (m - distance) >= (gas_station[station_number + 1] - gas_station[station_number])):
                    # daca putem ajunge la statia urmatoare atunci crestem numarul statiei
                    station_number = station_number + 1
                distance = distance + 1
            # memoram pozitia ultimei statii unde am alimentat
            last_station = gas_station[station_number]

            if station_number <= n:
                # memoram indicele statiei unde am alimentat
                count.append(station_number)
                refill = refill + 1
                station_number = station_number + 1
        out.write("TESTUL: %d metoda 1\n" % case_number)
        out.write("Soferul masinii vrea sa parcurga o distanta de :%d km\n" % destination)
        out.write("Cu un plin masina poate sa se deplaseze pe o distanta de %d km\n" % m)
        out.write("Pentru a avea un consum optim soferul trebuie sa opreasca de: %d ori\n" % refill)
        out.write("Pentru a alimenta acesta va opri la benzinariile cu numarul : ")

        # DATE PT FORMAREA GRAFICULUI #
        graphic.write("%d\n" % n)
        graphic.write("%d\n" % m)
        graphic.write("%d\n" % refill)

        for iterator in count:
            out.write("%s " % iterator)
            graphic.write("%s \n" % iterator)
        out.write("\n")

        for iterator in count:
            graphic.write("%s \n" % gas_station[iterator])

    graphic.close()
    out.close()
