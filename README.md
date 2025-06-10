# Klasyczna gra Pong w języku C

## 1. Technologie
- Język programowania: C
- Biblioteka: SDL2
- System operacyjny: Windows/Linux

## 2. Mechanika gry
- Przed rozpoczęciem gry należy podać nazwy, kolory paletek oraz docelowy wynik aby wygrać.
- Następie gracze odbijają piłkę między sobą.
- Gdy piłka przekroczy lewą lub prawą krawędź, gracz po przeciwnej stronie dostaje punkt.
- Gra kończy się gdy jeden z graczy zdobędzie podaną wcześniej ilość punktów.
- Zapisanie wyniku gry do pliku.

### Sterowanie
- **Gracz 1**
    - Góra: `W`
    - Dół: `S`
- **Gracz 2**
    - Góra: `UP`
    - Dół: `DOWN`

## 3. Interfejs
- Rozmiar okna: 800x600 px
- Tło: Czarne
- **Obiekty**
    - Paletki (2): prostokąty 10x100 px
    - Piłka: kwadrat 10x10 px
    - Punkty: w górnej częsci ekranu

## 4. Dźwięki
- Dźwięk odbijania się piłki od paletki
- Dźwięk informujący o zakończeniu gry