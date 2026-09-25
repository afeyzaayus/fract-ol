# fract-ol

`fract-ol`, 42 projesi kapsamında geliştirilen MiniLibX tabanlı bir fraktal görselleştirme uygulamasıdır.
Şu anda iki fraktal türü desteklenir:

- **Mandelbrot**
- **Julia**

## Gereksinimler

- Linux
- `cc` (C derleyicisi)
- `make`
- X11 geliştirme kütüphaneleri (MiniLibX için)

## Kurulum ve Derleme

Proje kök dizininde:

```bash
make
```

Bu komut, önce `minilibx-linux` kütüphanesini sonra da `fractol` çalıştırılabilir dosyasını üretir.

Temizlik komutları:

```bash
make clean
make fclean
make re
```

## Çalıştırma

### Mandelbrot

```bash
./fractol Mandelbrot
```

### Julia

Julia için iki adet sayı parametresi gerekir (`re` ve `im`):

```bash
./fractol Julia <re> <im>
```

Örnek:

```bash
./fractol Julia -0.7 0.27015
```

## Kontroller

- **Mouse Wheel Up**: Yakınlaştır
- **Mouse Wheel Down**: Uzaklaştır
- **Arrow Keys**: Görüntüyü kaydır
- **ESC**: Uygulamadan çık
- **Pencereyi kapatma (X)**: Uygulamadan çık

## Notlar

- Geçersiz argümanlarda program `Invalid arguments!!` çıktısı verir.
- Program penceresi boyutu varsayılan olarak `400x400` pikseldir.
