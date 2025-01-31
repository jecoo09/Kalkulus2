# Kalkulus2
## Notes

download python, matplotlib, dan juga numpy

gunakan file yang di include kalau mau yang lebih jernih terminalnya

## Input terminal untuk compile
input diterminal dengan urutan 

```bash
g++ (lokasi file cpp) -o (nama file exe) -I (path include python) -I (path ke arrayobject.h) -I (lokasi matplotlibcpp.h) -L (path libs python) -l(versi python kalian)
```

contoh :

```bash
g++ algo.cpp -o algo -I C:\Python312\include -I C:\Python312\Lib\site-packages\numpy\_core\include -I C:\test3d\include -L C:\Python312\libs -lpython312
```

atau


```bash
g++ coba.cpp -o progres2d -I C:\Python312\Lib\site-packages\numpy\_core\include -L C:\Python312\libs -lpython312
```

## Cara run program
input :

```bash
lokasi file exe dari program kalian
```

contoh :

```bash
./output.exe
```

## next update?
Trial error, sisanya done