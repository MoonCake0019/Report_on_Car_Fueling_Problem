import matplotlib.pyplot as plt
import numpy as np
import matplotlib.ticker as ticker
from matplotlib.offsetbox import AnchoredText

GRAFIC = open("data_grafic.txt", "r")

n = int(GRAFIC.readline())
m = int(GRAFIC.readline())
refill = int(GRAFIC.readline())

gas_station_nr = []

for iterator in range(refill):
    data = int(GRAFIC.readline())
    gas_station_nr.append(data)

gas_station_km = []

for iterator in range(refill):
    data = int(GRAFIC.readline())
    gas_station_km.append(data)


def grafic_1():
    plt.style.use("fivethirtyeight")
    # Choose some nice levels
    levels = np.tile([-5, 5, -3, 3, -1, 1], int(np.ceil(len(gas_station_km) / 6)))[:len(gas_station_km)]

    fig, ax = plt.subplots(figsize=(15, 7), constrained_layout=True)

    markerline, stemline, baseline = ax.stem(gas_station_km, levels,
                                             linefmt="C3-", basefmt="k-", use_line_collection=True)

    plt.setp(markerline, mec="k", mfc="w", zorder=3)

    # Shift the markers to the baseline by replacing the y-data by zeros.
    markerline.set_ydata(np.zeros(len(gas_station_km)))

    # annotate lines
    vert = np.array(['top', 'bottom'])[(levels > 0).astype(int)]

    for d, l, r, va in zip(gas_station_km, levels, gas_station_nr, vert):
        ax.annotate(r, xy=(d, l), xytext=(-3, np.sign(l) * 3), textcoords="offset points", va=va, ha="right")

    # format x axis with intervals
    ax.get_xaxis().set_major_locator(ticker.AutoLocator())
    ax.get_xaxis().set_minor_locator(ticker.AutoMinorLocator())
    plt.setp(ax.get_xticklabels(), rotation=30, ha="right")

    # remove y axis and spines
    ax.get_yaxis().set_visible(False)
    for spine in ["left", "top", "right"]:
        ax.spines[spine].set_visible(False)

    anchored_text = AnchoredText("Destinatia: %d km \nFuel: %d" % (gas_station_km[refill - 1], m), loc='upper left')
    ax.add_artist(anchored_text)

    ax.margins(y=0.3)
    ax.set(title="OPRIRI")  # TITLU
    plt.xlabel(" Distanta parcursa(km) ")
    plt.ylabel(" No. benzinariei")

    plt.show()


def grafic_2():
    plt.style.use("fivethirtyeight")

    names = ['nr. benzinarii', 'nr. opriri', 'fuel']
    y_pos = np.arange(len(names))
    info = [n, refill, m]

    plt.title("Rezultate")
    plt.bar(y_pos, info, align='center', alpha=0.5)
    plt.xticks(y_pos, names)
    plt.tight_layout()

    plt.show()


def grafic_3():
    plt.style.use("fivethirtyeight")

    slices = [refill, n - refill + 1]
    labels = ["Nr. Opriri", "Nr. Benzinarii Sarite"]

    plt.pie(slices, labels=labels, startangle=90, autopct='%1.1f%%', wedgeprops={'edgecolor': 'black'})

    plt.title("Rezultate")
    plt.tight_layout()
    plt.show()


grafic_1()
grafic_2()
grafic_3()

GRAFIC.close()
