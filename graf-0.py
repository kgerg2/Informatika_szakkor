# coding=UTF-8
import pygame

class Pont:
	def __init__(self, koord):
		self.koord = tuple(map(int, koord))
		self.ert = float("inf")
		self.szomszedok = []
		
	def __str__(self):
		return str(self.koord)

# Beolvasás

with open("graf-0.csv") as be:
	szel, mag, pontdb, eldb = tuple(map(int, be.readline().split(";")))
	
	pontok = []
	for _ in range(pontdb):
		pontok.append(Pont(be.readline().split(";")[1:3]))
		
	elek = []
	for _ in range(eldb):
		elek.append(list(map(lambda x: int(x)-1, be.readline().split(";")[:3])))
		elek[-1][2] += 1
		pontok[elek[-1][0]].szomszedok.append((elek[-1][1], elek[-1][2]))
		pontok[elek[-1][1]].szomszedok.append((elek[-1][0], elek[-1][2]))
		
	#print(pontok)
	#print(elek)

# pygame betöltése, háttér	

kezd = int(input("Kezdőpont sorszáma: "))
cel = int(input("Célpont sorszáma: "))

pontok[kezd].ert = 0
ismert = {kezd}

for i, ert in pontok[kezd].szomszedok:
	pontok[i].ert = ert
	
perem = {(pontok[ssz].ert, ssz) for ssz, _ in pontok[kezd].szomszedok}

while len(perem)>0:
	minert, minssz = min(perem)
	
	perem.remove((minert, minssz))
	ismert.add(minssz)
	if minssz == cel:
		break
	
	for i, ert in pontok[minssz].szomszedok:
		if i not in ismert:
			if pontok[i].ert > minert + ert:
				pontok[i].ert = minert + ert
			perem.add((pontok[i].ert, i))

print(pontok[cel].ert)

pygame.init()
screen = pygame.display.set_mode((szel, mag))
pygame.draw.rect(screen, (255, 255, 255), (0, 0, szel, mag))

pygame.font.init()
betu = pygame.font.SysFont("calibri", 16)
szoveg = betu.render("Gráf", False, (0, 0, 0))
screen.blit(szoveg, (10, 10))

# fő ciklus

vege = False
while not vege:
	# Program vége-e
	
	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			vege = True
	
	# Pontok kirajzolása
	
	for pont in pontok:
		pygame.draw.circle(screen, (0, 0, 0), pont.koord, 5)
		
	for el in elek:
		pygame.draw.line(screen, (0, 0, 0), pontok[el[0]].koord, pontok[el[1]].koord, 1)
		
	# Rajzolás vége
		
	pygame.display.flip()
