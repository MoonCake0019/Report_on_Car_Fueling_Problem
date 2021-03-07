def algorithm_2(n, m, gas_station, case_number):
    out = open("data_out.txt", "a")

    skip_case = 0
    count = []
    # destinatia
    destination = gas_station[n + 1]
    # indicele statiei
    station_number = 0
    #  numarul de opriri pe care le-a realizat soferul
    refill = 0

    for iterator in range(1, n + 2):
        # CAZUL IN CARE BENZINARIILE SUNT LA DISTANTE PREA MARI
        if gas_station[iterator] - gas_station[iterator - 1] > m:
            out.write("TESTUL: %d metoda 2\n" % case_number)
            out.write("\nSoferul nu poate ajunge la destinatie\n")
            skip_case = 1

    if skip_case == 0:
        while station_number <= n:
            # indicele ultimei statii unde am oprit pornind de la origine ( i.e 0 )
            last_station = station_number

            while (station_number <= n) and (gas_station[station_number + 1] - gas_station[last_station] <= m):
                station_number = station_number + 1

            if station_number <= n:
                # memoram indicele statiei unde am alimentat
                count.append(station_number)
                refill = refill + 1

        out.write("TESTUL: %d metoda 2\n" % case_number)
        out.write("Soferul masinii vrea sa parcurga o distanta de :%d km\n" % destination)
        out.write("Cu un plin masina poate sa se deplaseze pe o distanta de %d km\n" % m)
        out.write("Pentru a avea un consum optim soferul trebuie sa opreasca de: %d ori\n" % refill)
        out.write("Pentru a alimenta acesta va opri la benzinariile cu numarul : ")

        for iterator in count:
            out.write("%s " % iterator)

    out.write("\n")
    out.close()
