# Pauliaus Pociaus objektinio programavimo 4 užduotis. (VU ISI 1 kursas)

## Vektoriaus implementacija, visos funkcijos parašytos remiantis [cppreference](http://en.cppreference.com/w/cpp/container/vector) suteikta informacija



## Dokumentacija
Norėdami peržiūrėti dokumentaciją, nusiklonuokite repozitoriją, eikite į aplanką Doxygen ir atsidarykite index.html .


## Greičio matavimai - išvados
* Implementuotas vektorius daugumoje situacijų yra ~2 kartus greitesnis už std::vector


## Greičio matavimai: Debug

### no flags (-g)

|Duomenu kiekis                    |PVector     |std::vector     |
|----------------------------------|-----------------|----------------|
| n = 10000 | 0.00568463 s. | 0.00029927 s. |
| n = 100000 | 0.00129658 s. | 0.0026932 s. |
| n = 1000000 | 0.00718079 s. | 0.0180555 s. |
| n = 10000000 | 0.081883 s. | 0.215113 s. |
| n = 100000000 | 1.12888 s. | 2.33664 s. |

### -o1

|Duomenu kiekis                    |PVector     |std::vector     |
|----------------------------------|-----------------|----------------|
| n = 10000 | 0.00528673 s. | 0.00049856 s. |
| n = 100000 | 0.00139686 s. | 0.00179581 s. |
| n = 1000000 | 0.00708069 s. | 0.0186506 s. |
| n = 10000000 | 0.0815877 s. | 0.191107 s. |
| n = 100000000 | 0.974662 s. | 2.09978 s. |

### -o2

|Duomenu kiekis                    |PVector     |std::vector     |
|----------------------------------|-----------------|----------------|
| n = 10000 | 0.00972527 s. | 0.00049875 s. |
| n = 100000 | 0.00119682 s. | 0.00349081 s. |
| n = 1000000 | 0.0101239 s. | 0.0218416 s. |
| n = 10000000 | 0.0816816 s. | 0.191934 s. |
| n = 100000000 | 1.03642 s. | 2.31217 s. |

### -o3

|Duomenu kiekis                    |PVector     |std::vector     |
|----------------------------------|-----------------|----------------|
| n = 10000 | 0.0069812 s. | 0.0002992 s. |
| n = 100000 | 0.0008977 s. | 0.00359053 s. |
| n = 1000000 | 0.0097739 s. | 0.0231805 s. |
| n = 10000000 | 0.0884705 s. | 0.199064 s. |
| n = 100000000 | 1.06405 s. | 2.4178 s. |

## Greičio matavimai: Release

### no flags (-g)

|Duomenu kiekis                    |PVector     |std::vector     |
|----------------------------------|-----------------|----------------|
| n = 10000 | 0.00269276 s. | 0.00019943 s. |
| n = 100000 | 0.00079809 s. | 0.00139622 s. |
| n = 1000000 | 0.00842847 s. | 0.00608413 s. |
| n = 10000000 | 0.0577456 s. | 0.0658785 s. |
| n = 100000000 | 0.874354 s. | 0.833498 s. |

### -o1

|Duomenu kiekis                    |PVector     |std::vector     |
|----------------------------------|-----------------|----------------|
| n = 10000 | 0.0090756 s. | 0.00019944 s. |
| n = 100000 | 0.00099787 s. | 0.00199615 s. |
| n = 1000000 | 0.00807853 s. | 0.0199525 s. |
| n = 10000000 | 0.0883925 s. | 0.212246 s. |
| n = 100000000 | 1.13783 s. | 2.3713 s. |

### -o2

|Duomenu kiekis                    |PVector     |std::vector     |
|----------------------------------|-----------------|----------------|
| n = 10000 | 0.00558525 s. | 0.00039733 s. |
| n = 100000 | 0.00179524 s. | 0.00229373 s. |
| n = 1000000 | 0.00767942 s. | 0.0177528 s. |
| n = 10000000 | 0.0827793 s. | 0.204277 s. |
| n = 100000000 | 1.15013 s. | 2.61383 s. |

### -o3

|Duomenu kiekis                    |PVector     |std::vector     |
|----------------------------------|-----------------|----------------|
| n = 10000 | 0.00548556 s. | 0.00039869 s. |
| n = 100000 | 0.00189481 s. | 0.00249188 s. |
| n = 1000000 | 0.00718079 s. | 0.0206307 s. |
| n = 10000000 | 0.0839762 s. | 0.195894 s. |
| n = 100000000 | 0.867825 s. | 2.07747 s. |


## Įdiegimas naudojant `GCC`kompiliatorių 

- `git clone https://github.com/PauliusPoc/OOP-Task-4.git`
- `cd OOP Task 4`
- `cmake . -G "MinGW Makefiles"`
- `mingw32-make`
- `.\OOP Task 4`


