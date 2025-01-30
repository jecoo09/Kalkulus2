# Kalkulus2
## Notes
masukan sesuai lokasi file matplotlibcpp.h
``` bash
#include "C:/test3d/include/matplotlibcpp.h"
```

versi yang digunakan
``` bash
Python 3.12.2
matplotlib  3.9.2
```

## Lokasi file (berbeda tiap orang) 
C:\test3d>

## Input terminal untuk compile
input diterminal dengan urutan 

```bash
g++ (lokasi file cpp) -o (nama file exe) -I (path include python) -I (path ke arrayobject.h) -I (lokasi matplotlibcpp.h) -L (path libs python) -l(versi python kalian)
```

contoh :

```bash
g++ src\main.cpp -o output -I C:\Python312\include -I C:\Python312\Lib\site-packages\numpy\_core\include -I C:\test3d\include -L C:\Python312\libs -lpython312
```
g++ algo.cpp -o algo -I C:\Python312\include -I C:\Python312\Lib\site-packages\numpy\_core\include -I C:\test3d\include -L C:\Python312\libs -lpython312

```bash
g++ coba.cpp -o progres2d -I C:\Python312\Lib\site-packages\numpy\_core\include -I C:\test3d\include -L C:\Python312\libs -lpython312
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
benerin fungsi dri progres2d.cpp dan coba.cpp

## sisanya belajar sendiri, dah gede