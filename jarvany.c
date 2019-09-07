 /** 
  * Be: int c, e
  * elek[e]: (v1, v2)
  * csucsok[c]: (fok, ell)
  * Inicializálás: csucsok
  * szamlalo = 0 fokú pontok száma
  * Ha szamlalo<c
  * 	maxindex = 0
  * 	ciklus amíg maxfok > 0
  * 		maxindex megkeresése
  * 		Ciklus i=1-től C-ig
  * 			ha csucsok[i].fok>csucsok[maxindex].fok
  * 				maxindex = i
  * 			elágazás vége
  * 		ciklus vége
  * 		csucsok[maxindex].fok = 0
  * 	ciklus vége
  * elágazás vége
  * Ki: szamlalo
  *  */
