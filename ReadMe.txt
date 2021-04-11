1. Autor: Jakub Cimochowski AiR 104
2. Biblioteka BezierCurve zawiera klasę BezierCurve reprezentująca krzywą beziera.
3. Środowiska: VisualStudio, CodeBlocks
4. Testowanie: Native Unit Test z użyciem funkcji AreEqual, IsTrue, IsFalse
5. Funkcje klasy:

Prywatne:
-isPointEqual - sprawdz czy punkty kontrolne są takie same

Publiczne:
-getPoint - getter punktów kontrolnych
- curvePos - podaje koordynaty krzywej w zależności od t
- setPoint - zmienia punkt kontrolny na nowy
- movePoint - przesuwa punkt kontrolny o wektor
- move - przesuwa całą krzywą o wektor
- isClosed - sprawdza czy krzywa jest "zamknięta"
- isEqual - sprawdza czy krzywe są takie same
