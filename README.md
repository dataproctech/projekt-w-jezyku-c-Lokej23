# Klasyczna gra Pong w języku C

## 1. Technologie
- Język programowania: C
- Biblioteki: SDL2, SDL2_ttf
- System operacyjny: Windows/Linux

## 2. Mechanika gry
- Gracze odbijają piłkę między sobą.
- Gdy piłka przekroczy lewą lub prawą krawędź, gracz po przeciwnej stronie dostaje punkt.
- Gra kończy się po naciśnięciu przycisku `Esc`
- Zapisanie wyniku gry do pliku i wyświetlanie 10 ostatnich rund w menu.

### Sterowanie
- Rozpoczęcie gry: `Enter`
- Zakończenie gry: `Esc`

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
    - Punkty: w górnej części ekranu