import math, time

class Pont:
    def __init__(self, x, y=None):
        if type(x) in [map, list, tuple]:
            self.x, self.y = tuple(x)
        else:
            self.x = x
            self.y = y
    def __repr__(self):
        return "(%d, %d)" % (self.x, self.y)
    def __add__(a, b):
        if type(b) == Pont:
            return Pont(a.x + b.x, a.y + b.y)
        else:
            return Pont(a.x + b, a.y + b)
    def __sub__(a, b):
        if type(b) == Pont:
            return Pont(a.x - b.x, a.y - b.y)
        else:
            return Pont(a.x - b, a.y - b)
    def __eq__(self, value):
        return value.x == self.x and value.y == self.y

def meredekseg(a, b):
    """Két Pont által meghatározott egyenes meredekségét adja meg
        (függőleges esetén +- végtelent, egyezők esetén 0-t)"""
    try:
        return (b-a).y/(b-a).x
    except ZeroDivisionError:
        if (b-a).y > 0:
            return math.inf
        elif (b-a).y < 0:
            return -math.inf
        else:
            return 0

def tavolsag(a, b):
    """Megadja két Pont távolságát."""
    return math.sqrt((b.x-a.x)**2 + (b.y-a.y)**2)

# fájlnév (módosítandó igénynek megfelelően)
fajl = "wall.01"

with open(fajl) as be:
    db, tav = tuple(map(int, be.readline().split()))
    pontok = be.readlines()
    pontok = [Pont(map(int, pont.split())) for pont in pontok]

#print(pontok)
start = time.perf_counter()

# legalsó pont megkeresése (azok közül a legbaloldali)

y = min([p.y for p in pontok])
x = min([p.x for p in pontok if p.y == y])
pont = Pont(x, y)
burok = 2*math.pi*tav

# ettől szigorúan jobbra és egyenlőséget is megengedve följebb lévők megkeresése (ezek közül fogunk választani)
lista = [p for p in pontok if p.x > pont.x and p.y >= pont.y]

while len(lista)>0:
    # a legkisebb meredekségű megkeresése
    mered = min([meredekseg(pont, p) for p in lista])
    # azonosak közül a legjobboldali
    x = max([p.x for p in lista if meredekseg(pont, p) == mered])
    y = min([p.y for p in lista if p.x == x])
    burok += tavolsag(pont, Pont(x, y))
    # ez a pont is a burok része
    pont = Pont(x, y)
    # további keresés az ettől jobbra-föl lévőkben (ld. az előbb)
    lista = [p for p in pontok if p.x > pont.x and p.y >= pont.y]

# legjobboldalitól fel

lista = [p for p in pontok if p.x <= pont.x and p.y > pont.y]

while len(lista)>0:
    mered = min([meredekseg(pont, p) for p in lista])
    y = max([p.y for p in lista if meredekseg(pont, p) == mered])
    x = max([p.x for p in lista if p.y == y])
    burok += tavolsag(pont, Pont(x, y))
    pont = Pont(x, y)
    lista = [p for p in pontok if p.x <= pont.x and p.y > pont.y]

# legfelsőtől balra

lista = [p for p in pontok if p.x < pont.x and p.y <= pont.y]

while len(lista)>0:
    mered = min([meredekseg(pont, p) for p in lista])
    x = min([p.x for p in lista if meredekseg(pont, p) == mered])
    y = max([p.y for p in lista if p.x == x])
    burok += tavolsag(pont, Pont(x, y))
    pont = Pont(x, y)
    lista = [p for p in pontok if p.x < pont.x and p.y <= pont.y]

# legbaloldalitól le

lista = [p for p in pontok if p.x >= pont.x and p.y < pont.y]

while len(lista)>0:
    mered = min([meredekseg(pont, p) for p in lista])
    y = min([p.y for p in lista if meredekseg(pont, p) == mered])
    x = min([p.x for p in lista if p.y == y])
    burok += tavolsag(pont, Pont(x, y))
    pont = Pont(x, y)
    lista = [p for p in pontok if p.x >= pont.x and p.y < pont.y]

print("A burok: " + str(burok))
print(time.perf_counter() - start)

# a hosszhoz hozzáadódik egy megadott távolságnyi sugarú körvonal
hossz = 2*math.pi*tav
for i in range(len(burok)-1):
    hossz += tavolsag(burok[i], burok[i+1])

print("Ennek a hossza (görbe részekkel): " + str(round(hossz)))

#eredmény összehasonlítása a valóssal
try:
    with open(fajl + "a") as f:
        print("A burok hossza valójában: " + f.readline())
except:
    print("Az eredmény ellenőrzése a megadott fájlból (" + fajl + "a) nem lehetséges.")